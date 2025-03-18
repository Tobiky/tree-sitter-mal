from tree_sitter import TreeCursor
from lang import PARSER as parser


class ParseTreeVisitor:
    def visit(self, cursor: TreeCursor):
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

    def skip(self, cursor: TreeCursor):
        self.visit(cursor)
        while cursor.goto_next_sibling():
            self.visit(cursor)


# Concrete visitor to process function definitions
class MalCompiler(ParseTreeVisitor):
    def compile(self, source: bytes):
        tree = parser.parse(source)
        self.visit(tree.walk())

    def visit_define_declaration(self, cursor: TreeCursor):
        # '#' (identity) ':' (string)
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

        # Need to call decode because the text field is a `bytes` type.
        print(f"Found definition -> {key.decode()}: '{value.decode()}'")

        return ("defines", {key: value})
