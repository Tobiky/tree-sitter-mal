from tree_sitter import Node
from lang import PARSER as parser


class ParseTreeVisitor:
    def visit(self, node: Node):
        # Function name of child class handling the node type
        function_name = f'visit_{node.type}'
        # Default to skip, in case a specific visitor can't be found
        # Generally the case for anonymous nodes (keywords etc) or
        # named nodes (rules) that do not have a vistor implemented yet.
        visitor = getattr(self, function_name, self.skip)
        # Use visitor implementaiton
        return visitor(node)

    def skip(self, node: Node):
        for child in node.children:
            visitor_value = self.visit(child)
            if visitor_value:
                yield visitor_value


# Concrete visitor to process function definitions
class MalCompiler(ParseTreeVisitor):
    def compile(self, source: bytes):
        tree = parser.parse(source)
        self.visit(tree.root_node)

    def visit_define_declaration(self, node: Node):
        key = node.child_by_field_name("id").text
        value = node.child_by_field_name("value").text

        # Need to call decode because the text field is a `bytes` type.
        print(f"Found definition -> {key.decode()}: '{value.decode()}'")

        # Iterate children nodes for whatever reason
        # self.skip(node)

        return ("defines", {key: value})
