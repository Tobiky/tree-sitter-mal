from simple import MalCompiler
# or
# from fast import MalCompiler


# Example Python source code
source_code = b'''
#version: "1.2.3"
'''

# Run the visitor pattern on the tree
compiler = MalCompiler()
compiler.compile(source_code)
