from tree_sitter import TreeCursor, Range
from typing import Tuple
from collections.abc import MutableMapping, MutableSequence
from pathlib import Path
from lang import PARSER as parser

ASTNode = Tuple[str, object]


class ParseTreeVisitor:
    def __init__(self):
        self.current_file: Path = None
        self.visited_files: set[Path] = set()
        self.path_stack: list[Path] = []

    def compile(self, malfile: Path | str):
        current_file = Path(malfile)

        if not current_file.is_absolute() and self.path_stack:
            # Only for the first file self.path_stack will be empty.
            current_file = self.path_stack[-1] / current_file

        if current_file in self.visited_files:
            # Avoid infinite loops due to recursive includes
            return {}

        self.visited_files.add(current_file)
        self.path_stack.append(current_file.parent)

        result = None
        with open(current_file, 'rb') as f:
            source = f.read()
            tree = parser.parse(source)
            result = self.visitMal(tree.walk())

        self.path_stack.pop()

        return result

    def visit(self, cursor, params = None):
        function_name = f'visit_{cursor.node.type}' # obtain the appropriate function
        visitor = getattr(self, function_name, self.skip)
        hasChild = cursor.goto_first_child() # enter node's children
        result = visitor(cursor) if not params else visitor(cursor, params)
        if hasChild:
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
            elif key == "include":
                included_file = self.compile(value)
                for k, v in langspec.items():
                    if isinstance(v, MutableMapping):
                        langspec[k].update(included_file.get(k, {}))
                    if isinstance(v, MutableSequence) and k in included_file:
                        langspec[k].extend(included_file[k])

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

        # visit asset_definition
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

        # TODO change grammar to make (@ id)* instead of (@ id)?
        while (cursor.node.text.decode() == '@'):
            cursor.goto_next_sibling() # skip '@'
            tags.append(cursor.node.text.decode()) # grab (id)
            if not cursor.goto_next_sibling(): # move to next symbol, break if last
                break

        # process all ( '{' (cias) '}' ) we might have
        risk = None
        if (cursor.node.text.decode() == '{'):
            cursor.goto_next_sibling() # skip '{'
            risk = self.visit(cursor)  # grab (cias)
            cursor.goto_next_sibling() # go to '}' 
            cursor.goto_next_sibling() # and skip it

        ttc = None
        if (cursor.node.type == 'ttc'):
            # visit ttc
            ttc = self.visit(cursor)
            cursor.goto_next_sibling()

        meta = {}
        while (cursor.node.type == 'meta'):
            info = self.visit(cursor)
            meta[info[0]] = info[1]
            if not cursor.goto_next_sibling(): # in case there is nothing after the meta
                break

        detectors = {}
        if (cursor.node.type == 'detector' ):
            # TODO visit detector
            pass

        requires = None
        if (cursor.node.type == 'preconditions' ):
            requires = self.visit(cursor)
            cursor.goto_next_sibling()

        reaches = None
        if (cursor.node.type == 'reaching'):
            reaches = self.visit(cursor)
            cursor.goto_next_sibling()

        ret = {
            "name":name,
            "meta": meta,
            "detectors": detectors,
            "type":step_type,
            "tags":tags,
            "risk": risk,
            "ttc": ttc,
            "requires":requires,
            "reaches": reaches,
            }

        return ("step", ret)

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
            val = self.visit(cursor)
            risk.update(val)

            ret = cursor.goto_next_sibling()
            if not ret: # no more ',' -> done
                break

            # Otherwise, process the next CIA
            cursor.goto_next_sibling()

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

    def visit_ttc(self, cursor: TreeCursor):
        ##################################
        # '[' (intermediary_ttc_exp) ']' #
        ##################################

        # skip '['
        cursor.goto_next_sibling()

        return self._visit_intermediary_ttc_expr(cursor)

    def _visit_intermediary_ttc_expr(self, cursor: TreeCursor):
        ###################################################################################################
        # '(' (intermediary_ttc_expr) ')' | (integer) | (float) | (id) | (ttc_distribution) | (ttc_binop) #
        ###################################################################################################

        # check if we have '(', in this case it's a parenthesized expression
        if (cursor.node.text.decode() == '('):
            cursor.goto_next_sibling() # skip '('
            return self._visit_intermediary_ttc_expr(cursor) # visit the expression

        # if we have an id, just return it 
        elif (cursor.node.type == 'identifier'):
            return cursor.node.text.decode()

        # otherwise visit the node
        return self.visit(cursor)

    def visit_float(self, cursor: TreeCursor):
        ret = {"type": "number"}
        ret["value"] = float(cursor.node.text.decode())

        return ret

    def visit_integer(self, cursor: TreeCursor):
        ret = {"type": "number"}
        ret["value"] = float(cursor.node.text.decode())

        return ret

    def visit_ttc_binop(self, cursor: TreeCursor):
        #########################################################################
        # (intermediary_ttc_expr) ('+'|'-'|'*'|'/'|'^') (intermediary_ttc_expr) #
        #########################################################################

        # grab first (intermediary_ttc_expr)
        lhs = self._visit_intermediary_ttc_expr(cursor)
        cursor.goto_next_sibling()

        # grab operation type
        operation = cursor.node.text.decode()
        operation_type = 'addition' if operation == '+' else \
                      'subtraction' if operation == '-' else \
                      'multiplication' if operation == '*' else \
                      'multiplication' if operation == '/' else \
                      'exponentiation'
        cursor.goto_next_sibling()

        # grab second (intermediary_ttc_expr)
        rhs = self._visit_intermediary_ttc_expr(cursor)

        return {"type":operation_type, "lhs":lhs, "rhs": rhs}

    def visit_ttc_distribution(self, cursor: TreeCursor):
        ############################################
        # (id) '(' (number)* ( ',' (number) )* ')' #
        ############################################
        
        # grab (id)
        name = cursor.node.text.decode()
        cursor.goto_next_sibling()
        
        # skip '('
        cursor.goto_next_sibling()
        
        # parse function arguments
        args = []
        while (cursor.node.type in ('float', 'integer')):
            # obtain the number 
            arg = self.visit(cursor)
            args.append(arg)
            # move to next symbol, if it's not a comma then done
            if (cursor.node.text.decode() != ','):
                break
            # otherwise, ignore the comma
            cursor.goto_next_sibling()

        return {
                "type": "function",
                "name": name,
                "arguments": args
            }

    def visit_preconditions(self, cursor: TreeCursor):
        ##########################################
        # '<-' (asset_expr) (',' (asset_expr) )* #
        ##########################################

        # Skip '<-'
        cursor.goto_next_sibling()
        
        ret = {}
        ret["overrides"] = True
        ret["stepExpressions"] = [self.visit(cursor)]

        while (cursor.goto_next_sibling()): # check if we have a ','
            cursor.goto_next_sibling() # ignore the ','
            ret["stepExpressions"].append(self.visit(cursor))

        return ret

    def visit_reaching(self, cursor: TreeCursor):
        ################################################
        # ( '+>' | '->' ) (reaches) ( ',' (reaches) )* #
        ################################################

        ret = {}

        # Get type of reaches
        ret["overrides"] = True if cursor.node.text.decode()=='->' else False
        cursor.goto_next_sibling()

        # Visit the steps
        ret["stepExpressions"] = [self.visit(cursor)]

        while (cursor.goto_next_sibling()): # check if we have a ','
            cursor.goto_next_sibling() # ignore the ','
            ret["stepExpressions"].append(self.visit(cursor))

        return ret

    def visit_asset_expr(self,cursor: TreeCursor):
        return self._visit_inline_asset_expr(cursor)

    def _visit_inline_asset_expr(self, cursor: TreeCursor):
        #############################################################################################################################################
        # '(' (_inline_asset_expr) ')' | (id) | (asset_variable_substitution) | (asset_expr_binop) | (asset_expr_unop) | (asset_expr_type) #
        #############################################################################################################################################

        # The objective of this function is to mimick the _inline_asset_expr
        # In other words, this function will figure out the type of the node it just received,
        # pretending that it was an _inline_asset_expr

        ret = {}

        if (cursor.node.type=='identifier'):
            ret["type"] = self._resolve_part_ID_type(cursor)
            ret["name"] = cursor.node.text.decode()
        elif (cursor.node.text.decode() == '('):
            cursor.goto_next_sibling() # ignore the '('
            ret = self._visit_inline_asset_expr(cursor)
        else:
            ret = self.visit(cursor)

        return ret

    def visit_asset_variable_substitution(self, cursor: TreeCursor):
        ################
        # (id) '(' ')' #
        ################

        return {
            "type": "variable",
            "name": self.cursor.text.decode()
            }

    def visit_asset_expr_type(self, cursor: TreeCursor):
        #####################################
        # (_inline_asset_expr) '[' (id) ']' #
        #####################################

        # On the ANTLR version, we would visit the subtypes from left to right,
        # so we would have to store them recursively. However, in the TreeSitter
        # version, we are starting from right to left, so we can just visit
        # the `lhs` and return the current subtype

        # Visit the inline expr
        stepExpression = self._visit_inline_asset_expr(cursor)
        cursor.goto_next_sibling()

        # Skip '['
        cursor.goto_next_sibling()

        # Get the subType
        subType = cursor.node.text.decode()

        return {
                "type": "subType",
                "subType": subType,
                "stepExpression": stepExpression
            }

    def visit_asset_expr_binop(self, cursor: TreeCursor):
        ########################################################################
        # (_inline_asset_expr) ( '\/' | '/\' | '-' | '.') (_inline_asset_expr) #
        ########################################################################
        
        # Get the lhs
        lhs = self._visit_inline_asset_expr(cursor)
        cursor.goto_next_sibling()

        # Get the type of operation
        optype = 'collect' if cursor.node.text.decode()=='.'             \
                 else 'union' if cursor.node.text.decode()=='\\/'        \
                 else 'intersection' if cursor.node.text.decode()=='/\\' \
                 else 'difference'
        cursor.goto_next_sibling()

        # Get the rhs
        rhs = self._visit_inline_asset_expr(cursor)
        return {
            "type": optype,
            "lhs": lhs,
            "rhs": rhs
        }

    def visit_asset_expr_unop(self, cursor: TreeCursor):
        #############################
        # (_inline_asset_expr)  '*' #
        #############################
        
        # Get the associated expression
        expr = self._visit_inline_asset_expr(cursor)
        cursor.goto_next_sibling()

        return {
            "type": "transitive",
            "stepExpression": expr
        }

    def _resolve_part_ID_type(self, cursor: TreeCursor):
        # Figure out if we have a `field` or an `attackStep`
        original_node = cursor.node

        parent_node = original_node.parent

        while parent_node and parent_node.type != 'reaching':
            # The idea is to go up the tree. If we find a "reaching" node,
            # we still need to determine if it's a field or a an attackStep
            parent_node = parent_node.parent

        if not parent_node:
            # If we never find a "reaching" node, eventually we will go to
            # the top of the tree, and we won't be able to go further up.
            # In this case, we originally were in a `let` or `precondition`,
            # which only accepts fields
            return "field"

        # We want to know if there is any `.` after the context.
        # If there is, we have a field (as an attackStep does not
        # have attributes)
        #
        # To do this, we will find the start position of the  the original
        # node in the text. Each rule matches to one line in the end,
        # so this node will be in the same row as its parent node and in
        # a column inside the range of columns of its parent. So, we 
        # just have to split the whole text of the parent starting at the
        # original node's position and iterate from there until the end of
        # the text.

        original_node_column = original_node.start_point.column
        tokenStream = parent_node.text
        tokenStream_split = tokenStream[original_node_column:]
        for char in tokenStream_split:
            char = chr(char)
            if char == '.':
                return "field"      # Only a field can have attributes
            if char == ',':
                return "attackStep" # A `,` means we are starting a new reaches

        return "attackStep"

    def visit_associations_declaration(self, cursor: TreeCursor):
        #########################################
        # 'associations' '{' (association)* '}' #
        #########################################

        # skip 'associations'
        cursor.goto_next_sibling()

        # skip '{'
        cursor.goto_next_sibling()

        # visit all associations
        associations = []
        while cursor.node.text.decode() != '}':
            associations.append(self.visit(cursor))
            cursor.goto_next_sibling()

        return ('associations', associations)

    def visit_association(self, cursor: TreeCursor):
        ##############################################################################################
        # (id) '[' (id) ']' (multiplicity) '<--' (id) '-->' (multiplicity) '[' (id) ']' (id) (meta)* #
        ##############################################################################################

        # Get 1st id - left asset
        left_asset = cursor.node.text.decode()
        cursor.goto_next_sibling()

        # skip '['
        cursor.goto_next_sibling()

        # Get 2nd id - left field
        left_field = cursor.node.text.decode()
        cursor.goto_next_sibling()

        # skip ']'
        cursor.goto_next_sibling()

        # Get left multiplicity
        left_multiplicity = self.visit(cursor)
        cursor.goto_next_sibling()

        # skip '<--'
        cursor.goto_next_sibling()

        # Get 3rd id - name of the association
        name = cursor.node.text.decode()
        cursor.goto_next_sibling()

        # skip '-->'
        cursor.goto_next_sibling()

        # Get right multiplicity
        right_multiplicity = self.visit(cursor)
        cursor.goto_next_sibling()

        # skip '['
        cursor.goto_next_sibling()

        # Get 4th id - right field
        right_field = cursor.node.text.decode()
        cursor.goto_next_sibling()

        # skip ']'
        cursor.goto_next_sibling()

        # Get 5th id - right asset
        right_asset = cursor.node.text.decode()

        # Get all metas
        meta = {}
        while cursor.goto_next_sibling():
            res = self.visit(cursor)
            meta[res[0]] = res[1]

        association = {
            "name" : name,
            "meta" : meta,
            "leftAsset" : left_asset,
            "leftField" : left_field,
            "leftMultiplicity" : left_multiplicity,
            "rightAsset" : right_asset,
            "rightField" : right_field,
            "rightMultiplicity" : right_multiplicity,
        }

        self._process_multitudes(association)

        return association

    def visit_multiplicity(self, cursor: TreeCursor):
        ###############################################
        # (_multiplicity_atom) | (multiplicity_range) #
        ###############################################

        if cursor.node.type == 'multiplicity_range':
            return self.visit(cursor)

        # Otherwise we need to visit an intermediary function for 
        # atomic multiplicity expressions
        min = self._visit_multiplicity_atom(cursor)
        return {
            "min": min,
            "max": None,
        }

    def visit_multiplicity_range(self, cursor: TreeCursor):
        ##################################################
        # (_multiplicity_atom) '..' (_multiplicity_atom) #
        ##################################################

        min = self._visit_multiplicity_atom(cursor)
        cursor.goto_next_sibling()

        # skip '..'
        cursor.goto_next_sibling()

        max = self._visit_multiplicity_atom(cursor)

        return {
            "min": min,
            "max": max,
        }

    def _visit_multiplicity_atom(self, cursor: TreeCursor):
        ######################
        # (integer) | (star) #
        ######################
        return cursor.node.text.decode()

    def _process_multitudes(self, association):
        mult_keys = [
            # start the multatoms from right to left to make sure the rules
            # below get applied cleanly
            "rightMultiplicity.max",
            "rightMultiplicity.min",
            "leftMultiplicity.max",
            "leftMultiplicity.min",
        ]

        for mult_key in mult_keys:
            key, subkey = mult_key.split(".")

            # upper limit equals lower limit if not given
            if subkey == "max" and association[key][subkey] is None:
                association[key][subkey] = association[key]["min"]

            if association[key][subkey] == "*":
                # 'any' as lower limit means start from 0
                if subkey == "min":
                    association[key][subkey] = 0

                # 'any' as upper limit means not limit
                else:
                    association[key][subkey] = None

            # cast numerical strings to integers
            if (multatom := association[key][subkey]) and multatom.isdigit():
                association[key][subkey] = int(association[key][subkey])

