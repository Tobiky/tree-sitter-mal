from tree_sitter import Node
from typing import Tuple
from lang import PARSER as parser

ASTNode = Tuple[str, object]


class ParseTreeVisitor:
    def visit(self, node: Node) -> ASTNode | list[ASTNode] | None:
        # Function name of child class handling the node type
        function_name = f'visit_{node.type}'
        # Default to skip, in case a specific visitor can't be found
        # Generally the case for anonymous nodes (keywords etc) or
        # named nodes (rules) that do not have a vistor implemented yet.
        visitor = getattr(self, function_name, self.skip)
        # Use visitor implementaiton
        return visitor(node)

    def skip(self, node: Node) -> ASTNode | list[ASTNode] | None:
        values = []
        for child in node.children:
            if visitor_value := self.visit(child):
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
        self.visit(tree.root_node)

    # Named visit_{rule name in grammar.js}
    def visit_define_declaration(self, node: Node) -> ASTNode:
        key = node.child_by_field_name("id").text
        value = node.child_by_field_name("value").text

        # Need to call decode because the text field is a `bytes` type.
        print(f"Found definition -> {key.decode()}: '{value.decode()}'")

        # Iterate children nodes for whatever reason
        # self.skip(node)

        return ("defines", {key.decode(): value.decode()})
