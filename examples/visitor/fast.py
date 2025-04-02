from tree_sitter import TreeCursor
from typing import Tuple
from lang import PARSER as parser

ASTNode = Tuple[str, object]


class ParseTreeVisitor:
    def visit(self, cursor, params = None):
        function_name = f'visit_{cursor.node.type}' # obtain the appropriate function
        visitor = getattr(self, function_name, self.skip)
        cursor.goto_first_child() # enter node's children
        result = visitor(cursor) if not params else visitor(cursor, params)
        cursor.goto_parent() # leave node's children
        return result

    def visitMal(self, cursor: TreeCursor) -> ASTNode | list[ASTNode] | None:
        langspec = {
            "formatVersion": "1.0.0",
            "defines": {},
            "categories": [],
            "assets": [],
            "associations": [],
        }

        # Go to first declaration
        cursor.goto_first_child()

        while True:
            # Obtain node type of declaration
            cursor.goto_first_child()

            # Visit declaration
            result = self.visit(cursor)

            key, value = result
            if key == "categories":
                category, assets = value
                langspec["categories"].extend(category)
                langspec["assets"].extend(assets)
            elif key == "defines":
                langspec[key].update(value)
            elif key == "associations":
                langspec[key].extend(value)

            # Go back to declaration
            cursor.goto_parent()

            # Attempt to move to next declaration. If not possible, done processing
            if not cursor.goto_next_sibling():
                break

        for key in ("categories", "assets", "associations"):
            unique = []
            for item in langspec[key]:
                if item not in unique:
                    unique.append(item)
            langspec[key] = unique

        return langspec

    def skip(self, _):
        pass

    def _visit(self, cursor: TreeCursor) -> ASTNode | list[ASTNode] | None:
        # Function name of child class handling the node type
        function_name = f'visit_{cursor.node.type}'

        # Enter into the node
        has_children = cursor.goto_first_child()

        # Default to skip, in case a specific visitor can't be found
        # Generally the case for anonymous nodes (keywords etc) or
        # named nodes (rules) that do not have a vistor implemented yet.
        visitor = getattr(self, function_name, self.skip)

        # Use visitor implementation
        visitor_value = visitor(cursor)

        # Exit the node
        if has_children:
            cursor.goto_parent()

        return visitor_value

    def _skip(self, cursor: TreeCursor) -> ASTNode | list[ASTNode] | None:
        values = []
        if visitor_value := self.visit(cursor):
            values.append(visitor_value)
        while cursor.goto_next_sibling():
            if visitor_value := self.visit(cursor):
                values.append(visitor_value)
        match len(values):
            case 0:
                return None
            case 1:
                return values[0]
            case _:
                return values


# Concrete visitor to process function definitions
class MalCompiler(ParseTreeVisitor):
    def compile(self, source: bytes):
        tree = parser.parse(source)
        self.visitMal(tree.walk())

    # Named visit_{rule name in grammar.js}
    def visit_define_declaration(self, cursor: TreeCursor) -> ASTNode:
        ###############################
        # '#' (identity) ':' (string) #
        ###############################

        # skip '#' node
        cursor.goto_next_sibling()
        # grab (identity) node
        key = cursor.node.text
        # next node
        cursor.goto_next_sibling()
        # skip ':' node
        cursor.goto_next_sibling()
        # grab (string) node
        value = cursor.node.text

        return ("defines", {key.decode(): value.decode().strip("\"")})

    def visit_category_declaration(self, cursor: TreeCursor) -> ASTNode:
        ############################################
        # 'category' (id) (meta)* '{' (asset)* '}' #
        ############################################

        category = {}

        # skip 'category'
        cursor.goto_next_sibling()
        # grab (identity) 
        category["name"] = cursor.node.text.decode()
        # next node
        cursor.goto_next_sibling()

        # grab (meta)
        #
        # Since it is optional, we have to make sure we are dealing with a 
        # grammar rule
        meta = {}
        while (cursor.node.is_named):
            info = self.visit(cursor)
            meta[info[0]] = info[1]
            cursor.goto_next_sibling()
        category["meta"] = meta

        # skip '{' node 
        cursor.goto_next_sibling()

        # grab (asset)
        assets = []
        while (cursor.node.is_named):
            asset = self.visit(cursor, category["name"])
            assets.append(asset)
            cursor.goto_next_sibling()

        # next node and skip '}' node
        cursor.goto_next_sibling(), cursor.goto_next_sibling()

        return ("categories", ([category], assets))

    def visit_meta(self, cursor: TreeCursor) -> ASTNode:
        ############################
        # (id) 'info' ':' (string) #
        ############################

        # grab (id) node
        id = cursor.node.text.decode()

        # next node 
        cursor.goto_next_sibling()
        # skip 'info' node
        cursor.goto_next_sibling()
        # skip ':' node
        cursor.goto_next_sibling()

        # grab (string) node
        info_string = cursor.node.text.decode().strip('"')

        return (id, info_string)

    def visit_asset_declaration(self, cursor: TreeCursor, category: str) -> ASTNode:
        ##############################################################################
        # (abstract)? 'asset' (id) (extends id)? (meta)* '{' (asset_definition)* '}' #
        ##############################################################################
        
        # grab (abstract)?
        isAbstract = cursor.node.text.decode() == 'abstract'
        if (isAbstract):
            cursor.goto_next_sibling() # We must go to 'asset'

        # skip 'asset'
        cursor.goto_next_sibling()
    
        # grab (id)
        name = cursor.node.text.decode()
        cursor.goto_next_sibling()

        # grab (extends id)?
        superAsset = None 
        if (cursor.node.text.decode() == 'extends'):
            cursor.goto_next_sibling() # move to the id 
            superAsset = cursor.node.text.decode() # get the text
            cursor.goto_next_sibling() # move to the meta

        # grab (meta)*
        meta = {}
        while (cursor.node.is_named):
            info = self.visit(cursor)
            meta[info[0]] = info[1]
            cursor.goto_next_sibling()

        # skip '{'
        cursor.goto_next_sibling()

        # TODO visit asset_definition
        variables, attackSteps = [], []
        if (cursor.node.is_named):
            variables, attackSteps = self.visit(cursor)
        
        return {"name": name,
                "meta": meta,
                "category": category,
                "isAbstract": isAbstract,
                "superAsset": superAsset,
                "variables":variables,
                "attackSteps": attackSteps}

    def visit_asset_definition(self, cursor: TreeCursor) -> ASTNode:
        #######################
        # (variable)* (step)* #
        #######################

        variables, steps = [], []
        while True:
            definition, result = self.visit(cursor)

            if definition=='variable':
                variables.append(result)
            elif definition=='step':
                steps.append(result)

            if not cursor.goto_next_sibling():
                break

        return (variables, steps)

    def visit_asset_variable(self, cursor: TreeCursor) -> ASTNode:
        ##########################
        # 'let' (id) '=' (value) #
        ##########################
        
        ret = {}

        # skip 'let'
        cursor.goto_next_sibling()

        # grab id
        ret["name"] = cursor.node.text.decode()
        ret["stepExpression"] = None

        # TODO visit step expression

        return ("variable", ret)

    def visit_attack_step(self, cursor: TreeCursor) -> ASTNode:
        ###############################################################################################################
        # (step_type) (id) ( '@' (id) )* ( '{' (cias) '}' )?  (ttc)? (meta)* (detector)? (preconditions)? (reaches)? #
        ###############################################################################################################

        # grab (step_type)
        step_type = cursor.node.text.decode()
        cursor.goto_next_sibling()

        # grab (id)
        name = cursor.node.text.decode()
        cursor.goto_next_sibling()

        # process all ( '@' (id) ) we might have
        tags = []
        while (cursor.node.text.decode() == '@'):
            cursor.goto_next_sibling() # skip '@'
            tags.append(cursor.node.text.decode()) # grab (id)
            cursor.goto_next_sibling() # move to next symbol

        # process all ( '{' (cias) '}' ) we might have
        risk = None
        if (cursor.node.text.decode() == '{'):
            cursor.goto_next_sibling() # skip '{'
            risk = self.visit(cursor)  # grab (cias)
            cursor.goto_next_sibling() # go to '}' 
            cursor.goto_next_sibling() # and skip it

        if (cursor.node.type == 'ttc'):
            # TODO
            # visit ttc
            pass

        while (cursor.node.type == 'meta'):
            # TODO
            # visit meta
            break

        if (cursor.node.type == 'detector' ):
            # TODO visit detector
            pass

        if (cursor.node.type == 'preconditions' ):
            # TODO visit preconditions
            pass

        if (cursor.node.type == 'reaches' ):
            # TODO visit reaches
            pass

    def visit_cias(self, cursor: TreeCursor):
        ######################
        # (cia) (',' (cia))* #
        ######################
        risk = {
            "isConfidentiality": False,
            "isIntegrity": False,
            "isAvailability": False,
        }

        while True:
            risk.update(self.visit(cursor))
            cursor.goto_next_sibling() # go to ','
            # if we can't go to the next CIA break
            if not cursor.goto_next_sibling(): 
                break

        return risk
    
    def visit_cia(self, cursor: TreeCursor):
        ###############
        # 'C'|'I'|'A' #
        ###############
        cia = cursor.node.text.decode()

        key = (
            "isConfidentiality"
            if cia == 'C'
            else "isIntegrity"
            if cia == 'I'
            else "isAvailability"
            if cia == 'A'
            else None
        )

        return {key: True}
        
