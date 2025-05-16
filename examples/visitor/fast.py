from tree_sitter import TreeCursor, Range
from typing import Tuple
from collections.abc import MutableMapping, MutableSequence
from pathlib import Path
from lang import PARSER as parser
from mal_analyzer import malAnalyzer

ASTNode = Tuple[str, object]

'''
This function is crucial to use instead of cursor.goto_next_sibling()

Although the `comment` node is included as an extra in the
TreeSitter grammar, it still shows up in the AST.
For this reason, this function exists to go to the next node,
while ignoring `comment` node.

It returns a boolean which states if there are any nodes left
and if the current node is not a comment.
'''
def go_to_sibling(cursor: TreeCursor) -> bool:
    found_sibling = cursor.goto_next_sibling()
    while cursor.node.type=='comment' and found_sibling:
        found_sibling = cursor.goto_next_sibling()
    return found_sibling and cursor.node.type!='comment'

class ParseTreeVisitor:
    def __init__(self):
        self.current_file: Path = None
        self.visited_files: set[Path] = set()
        self.path_stack: list[Path] = []
        self.analyzer = malAnalyzer()

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
            result = self.visit(tree.walk())

        self.path_stack.pop()

        return result

    def visit(self, cursor, params = None):
        function_name = f'visit_{cursor.node.type}' # obtain the appropriate function
        visitor = getattr(self, function_name, self.skip)
        hasChild = cursor.goto_first_child() # enter node's children
        result = visitor(cursor) if not params else visitor(cursor, params)

        if hasChild:
            cursor.goto_parent() # leave node's children

        analyzer_method_name: str = f'check_{cursor.node.type}'
        analyzer_method: function | None = getattr(self.analyzer, analyzer_method_name, None)

        if analyzer_method:
            arguments = analyzer_method.__code__.co_argcount
            if arguments in [2, 3]:
                {
                    3: lambda: analyzer_method(cursor.node, result),
                    2: lambda: analyzer_method(cursor.node)
                }[arguments]()
            else:
                raise ValueError(f'Unexpected number of arguments: {arguments}')

        return result

    def visit_source_file(self, cursor: TreeCursor) -> ASTNode | list[ASTNode] | None:
        langspec = {
            "formatVersion": "1.0.0",
            "defines": {},
            "categories": [],
            "assets": [],
            "associations": [],
        }

        # Go to first declaration
        while True:
            if (cursor.node.type == 'comment'):
                go_to_sibling(cursor)

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
            if not go_to_sibling(cursor):
                break

        for key in ("categories", "assets", "associations"):
            unique = []
            for item in langspec[key]:
                if item not in unique:
                    unique.append(item)
            langspec[key] = unique

        return langspec

    def skip(self, _,):
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
        while go_to_sibling(cursor):
            if visitor_value := self.visit(cursor):
                values.append(visitor_value)
        match len(values):
            case 0:
                return None
            case 1:
                return values[0]
            case _:
                return values

    def visit_comment(self, cursor: TreeCursor, params=None):
        return (None, None)

# Concrete visitor to process function definitions
class MalCompiler(ParseTreeVisitor):

    # Named visit_{rule name in grammar.js}
    def visit_define_declaration(self, cursor: TreeCursor) -> ASTNode:
        ###############################
        # '#' (identity) ':' (string) #
        ###############################

        # skip '#' node
        go_to_sibling(cursor)
        # grab (identity) node
        key = cursor.node.text
        # next node
        go_to_sibling(cursor)
        # skip ':' node
        go_to_sibling(cursor)
        # grab (string) node
        value = cursor.node.text

        return ("defines", {key.decode(): value.decode().strip("\"")})

    def visit_category_declaration(self, cursor: TreeCursor) -> ASTNode:
        ############################################
        # 'category' (id) (meta)* '{' (asset)* '}' #
        ############################################

        category = {}

        # skip 'category'
        go_to_sibling(cursor)
        # grab (identity) 
        category["name"] = cursor.node.text.decode()
        # next node
        go_to_sibling(cursor)

        # grab (meta)
        #
        # Since it is optional, we have to make sure we are dealing with a 
        # grammar rule
        meta = {}
        while (cursor.node.is_named):
            info = self.visit(cursor)
            meta[info[0]] = info[1]
            go_to_sibling(cursor)
        category["meta"] = meta

        # skip '{' node 
        go_to_sibling(cursor)

        # grab (asset)
        assets = []
        while (cursor.node.is_named):
            asset = self.visit(cursor, category["name"])
            assets.append(asset)
            go_to_sibling(cursor)

        # next node and skip '}' node
        go_to_sibling(cursor), cursor.goto_next_sibling()

        return ("categories", ([category], assets))

    def visit_include_declaration(self, cursor: TreeCursor):
        ####################
        # 'include' (file) #
        ####################

        # skip 'include'
        go_to_sibling(cursor)

        return ("include", cursor.node.text.decode().strip('"'))

    def visit_meta(self, cursor: TreeCursor) -> ASTNode:
        ############################
        # (id) 'info' ':' (string) #
        ############################

        # grab (id) node
        id = cursor.node.text.decode()

        # next node 
        go_to_sibling(cursor)
        # skip 'info' node
        go_to_sibling(cursor)
        # skip ':' node
        go_to_sibling(cursor)

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
            go_to_sibling(cursor) # We must go to 'asset'

        # skip 'asset'
        go_to_sibling(cursor)
    
        # grab (id)
        name = cursor.node.text.decode()
        go_to_sibling(cursor)

        # grab (extends id)?
        superAsset = None 
        if (cursor.node.text.decode() == 'extends'):
            go_to_sibling(cursor) # move to the id 
            superAsset = cursor.node.text.decode() # get the text
            go_to_sibling(cursor) # move to the meta

        # grab (meta)*
        meta = {}
        while (cursor.node.is_named):
            info = self.visit(cursor)
            meta[info[0]] = info[1]
            go_to_sibling(cursor)

        # skip '{'
        go_to_sibling(cursor)

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

            if not go_to_sibling(cursor):
                break

        return (variables, steps)

    def visit_asset_variable(self, cursor: TreeCursor) -> ASTNode:
        ##########################
        # 'let' (id) '=' (value) #
        ##########################
        
        ret = {}

        # skip 'let'
        go_to_sibling(cursor)

        # grab id
        ret["name"] = cursor.node.text.decode()
        go_to_sibling(cursor)

        # skip '='
        go_to_sibling(cursor)

        ret["stepExpression"] = self.visit(cursor)

        # TODO visit step expression

        return ("variable", ret)

    def visit_attack_step(self, cursor: TreeCursor) -> ASTNode:
        ##############################################################################################################
        # (step_type) (id) ( '@' (id) )* ( '{' (cias) '}' )?  (ttc)? (meta)* (detector)? (preconditions)? (reaches)? #
        ##############################################################################################################

        # grab (step_type)
        # use raw text bytes to avoid decoding as much as possible
        step_type_btext = cursor.node.text
        step_type_bindings = {
            b'&': 'and',
            b'|': 'or',
            b'#': 'defense',
            b'E': 'exist',
            b'!E': 'notExist'
        }
        # decode value only if its really necessary (no binding found)
        if (step_type := step_type_bindings.get(step_type_btext)) is None:
            step_type = step_type_btext.decode()
        go_to_sibling(cursor)

        # grab (id)
        name = cursor.node.text.decode()
        go_to_sibling(cursor)

        # process all ( '@' (id) ) we might have
        tags = []

        # TODO change grammar to make (@ id)* instead of (@ id)?
        while (cursor.node.text.decode() == '@'):
            go_to_sibling(cursor) # skip '@'
            tags.append(cursor.node.text.decode()) # grab (id)
            if not go_to_sibling(cursor): # move to next symbol, break if last
                break

        # process all ( '{' (cias) '}' ) we might have
        risk = None
        if (cursor.node.text.decode() == '{'):
            go_to_sibling(cursor) # skip '{'
            risk = self.visit(cursor)  # grab (cias)
            go_to_sibling(cursor) # go to '}' 
            go_to_sibling(cursor) # and skip it

        ttc = None
        if (cursor.node.type == 'ttc'):
            # visit ttc
            ttc = self.visit(cursor)
            go_to_sibling(cursor)

        meta = {}
        while (cursor.node.type == 'meta'):
            info = self.visit(cursor)
            meta[info[0]] = info[1]
            if not go_to_sibling(cursor): # in case there is nothing after the meta
                break

        detectors = {}
        while (cursor.node.type == 'detector'):
            detector = self.visit(cursor)
            detector[detector['name']] = detector
            if not go_to_sibling(cursor): # in case there is nothing after the meta
                break

        requires = None
        if (cursor.node.type == 'preconditions'):
            requires = self.visit(cursor)
            go_to_sibling(cursor)

        reaches = None
        if (cursor.node.type == 'reaching'):
            reaches = self.visit(cursor)
            go_to_sibling(cursor)

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

    def visit_detector(self, cursor: TreeCursor):
        ####################################################################
        # ('!' | '//!') (detector_name)? (detector_context) (type)? (ttc)? #
        ####################################################################

        # skip bang 
        go_to_sibling(cursor)

        # grab detector_name
        detector_name = None
        if cursor.field_name == 'name':
            detector_name = cursor.node.text.decode()
            go_to_sibling(cursor)

        # grab detector_context
        detector_context = self.visit(cursor)
        go_to_sibling(cursor)

        # grab id
        detector_type = None
        if cursor.field_name == 'type':
            detector_name = cursor.node.text.decode()
            go_to_sibling(cursor)
        
        # grab ttc
        detector_ttc = None
        if cursor.field_name == 'ttc':
            detector_ttc = self.visit(ttc)
            go_to_sibling(cursor)

        return {
            "name": detector_name,
            "context": detector_context,
            "type": detector_type,
            "tprate": detector_ttc,
        }

    def visit_detector_context(self, cursor: TreeCursor):
        ####################################################################
        # '(' (detector_context_asset) (',' (detector_context_asset))* ')' #
        ####################################################################

        # skip '('
        go_to_sibling(cursor)

        # grab detector_context_asset
        context = {}
        label, asset = self.visit(cursor)
        context[label] = asset
        go_to_sibling(cursor)

        while cursor.node.text.decode() != ')':
            # skip ','
            go_to_sibling(cursor)
            # grab another detector_context_asset
            label, asset = self.visit(cursor)
            context[label] = asset
            go_to_sibling(cursor)

        return context

    def visit_detector_context_asset(self, cursor: TreeCursor):
        ###############
        # (type) (id) #
        ###############
        asset = cursor.node.text.decode()
        label = cursor.node.text.decode()

        return (label, asset)

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

            ret = go_to_sibling(cursor)
            if not ret: # no more ',' -> done
                break

            # Otherwise, process the next CIA
            go_to_sibling(cursor)

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
        go_to_sibling(cursor)

        return self._visit_intermediary_ttc_expr(cursor)

    def _visit_intermediary_ttc_expr(self, cursor: TreeCursor):
        ###################################################################################################
        # '(' (intermediary_ttc_expr) ')' | (integer) | (float) | (id) | (ttc_distribution) | (ttc_binop) #
        ###################################################################################################

        # check if we have '(', in this case it's a parenthesized expression
        if (cursor.node.text.decode() == '('):
            go_to_sibling(cursor) # skip '('
            result = self._visit_intermediary_ttc_expr(cursor) # visit the expression
            go_to_sibling(cursor) # skip ')'
            return result


        # if we have an id, just return it 
        elif (cursor.node.type == 'identifier'):
            text = cursor.node.text.decode()
            return {
                "type": "function",
                "name": text,
                "arguments": []
            }
        
        # if we have a number (integer/float) we need to construct
        # the dictionary correctly
        elif (cursor.node.type == 'float' or cursor.node.type=='integer'):
            ret = {"type": "number"}
            ret['value'] = self.visit(cursor)
            return ret

        # otherwise visit the node
        return self.visit(cursor)

    def visit_float(self, cursor: TreeCursor):
        ret = float(cursor.node.text.decode())

        return ret

    def visit_integer(self, cursor: TreeCursor):
        ret = float(cursor.node.text.decode())

        return ret

    def visit_ttc_binop(self, cursor: TreeCursor):
        #########################################################################
        # (intermediary_ttc_expr) ('+'|'-'|'*'|'/'|'^') (intermediary_ttc_expr) #
        #########################################################################

        # grab first (intermediary_ttc_expr)
        lhs = self._visit_intermediary_ttc_expr(cursor)
        go_to_sibling(cursor)

        # grab operation type
        operation = cursor.node.text.decode()
        operation_type = 'addition' if operation == '+' else \
                      'subtraction' if operation == '-' else \
                      'multiplication' if operation == '*' else \
                      'division' if operation == '/' else \
                      'exponentiation'
        go_to_sibling(cursor)

        # grab second (intermediary_ttc_expr)
        rhs = self._visit_intermediary_ttc_expr(cursor)

        return {"type":operation_type, "lhs":lhs, "rhs": rhs}

    def visit_ttc_distribution(self, cursor: TreeCursor):
        ############################################
        # (id) '(' (number)* ( ',' (number) )* ')' #
        ############################################
        
        # grab (id)
        name = cursor.node.text.decode()
        go_to_sibling(cursor)
        
        # skip '('
        go_to_sibling(cursor)
        
        # parse function arguments
        args = []
        while (cursor.node.type in ('float', 'integer')):
            # obtain the number 
            arg = self.visit(cursor)
            args.append(arg)
            # move to next symbol, if it's not a comma then done
            go_to_sibling(cursor)
            if (cursor.node.text.decode() != ','):
                break
            # otherwise, ignore the comma
            go_to_sibling(cursor)

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
        go_to_sibling(cursor)
        
        ret = {}
        ret["overrides"] = True
        ret["stepExpressions"] = [self.visit(cursor)]

        while (go_to_sibling(cursor)): # check if we have a ','
            go_to_sibling(cursor) # ignore the ','
            ret["stepExpressions"].append(self.visit(cursor))

        return ret

    def visit_reaching(self, cursor: TreeCursor):
        ################################################
        # ( '+>' | '->' ) (reaches) ( ',' (reaches) )* #
        ################################################

        ret = {}

        # Get type of reaches
        ret["overrides"] = True if cursor.node.text.decode()=='->' else False
        go_to_sibling(cursor)

        # Visit the steps
        ret["stepExpressions"] = [self.visit(cursor)]

        while (go_to_sibling(cursor)): # check if we have a ','
            go_to_sibling(cursor) # ignore the ','
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
            go_to_sibling(cursor) # ignore the '('
            ret = self._visit_inline_asset_expr(cursor)
            go_to_sibling(cursor) # ignore the ')'
        else:
            ret = self.visit(cursor)

        return ret

    def visit_asset_variable_substitution(self, cursor: TreeCursor):
        ################
        # (id) '(' ')' #
        ################

        return {
            "type": "variable",
            "name": cursor.node.text.decode()
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
        go_to_sibling(cursor)

        # Skip '['
        go_to_sibling(cursor)

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
        go_to_sibling(cursor)

        # Get the type of operation
        optype = 'collect' if cursor.node.text.decode()=='.'             \
                 else 'union' if cursor.node.text.decode()=='\\/'        \
                 else 'intersection' if cursor.node.text.decode()=='/\\' \
                 else 'difference'
        go_to_sibling(cursor)

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
        go_to_sibling(cursor)

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

        # The following logic was implemented to deal with how TreeSitter
        # deals with indents and new lines

        # We start by obtaining the column where the target node starts,
        original_node_column = original_node.start_point.column

        # We get the parent's text and split it into the original
        # lines (as written in the code)
        tokenStream = parent_node.text.decode()
        tokenStream = tokenStream.split('\n')
        tokenStream_split = None

        # If the parent and the target are defined in the same line,
        # then we must remove the start point from the original column,
        # since TreeSitter deletes the indent
        if original_node.start_point.row == parent_node.start_point.row:
            tokenStream_split = tokenStream[0]
            original_node_column = original_node.start_point.column - parent_node.start_point.column
        # However, if they are in different rows, the indent must be included,
        # so we use the same column
        else:
            tokenStream_split = tokenStream[original_node.start_point.row-parent_node.start_point.row]

        # Afterwards, we just do the normal checks, knowing what column to start in
        tokenStream_split = tokenStream_split[original_node_column+len(original_node.text.decode()):]
        for char in tokenStream_split:
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
        go_to_sibling(cursor)

        # skip '{'
        go_to_sibling(cursor)

        # visit all associations
        associations = []
        while cursor.node.text.decode() != '}':
            associations.append(self.visit(cursor))
            go_to_sibling(cursor)

        return ('associations', associations)

    def visit_association(self, cursor: TreeCursor):
        ##############################################################################################
        # (id) '[' (id) ']' (multiplicity) '<--' (id) '-->' (multiplicity) '[' (id) ']' (id) (meta)* #
        ##############################################################################################

        # Get 1st id - left asset
        left_asset = cursor.node.text.decode()
        go_to_sibling(cursor)

        # skip '['
        go_to_sibling(cursor)

        # Get 2nd id - left field
        left_field = cursor.node.text.decode()
        go_to_sibling(cursor)

        # skip ']'
        go_to_sibling(cursor)

        # Get left multiplicity
        left_multiplicity = self.visit(cursor)
        go_to_sibling(cursor)

        # skip '<--'
        go_to_sibling(cursor)

        # Get 3rd id - name of the association
        name = cursor.node.text.decode()
        go_to_sibling(cursor)

        # skip '-->'
        go_to_sibling(cursor)

        # Get right multiplicity
        right_multiplicity = self.visit(cursor)
        go_to_sibling(cursor)

        # skip '['
        go_to_sibling(cursor)

        # Get 4th id - right field
        right_field = cursor.node.text.decode()
        go_to_sibling(cursor)

        # skip ']'
        go_to_sibling(cursor)

        # Get 5th id - right asset
        right_asset = cursor.node.text.decode()

        # Get all metas
        meta = {}
        while go_to_sibling(cursor):
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
        go_to_sibling(cursor)

        # skip '..'
        go_to_sibling(cursor)

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

