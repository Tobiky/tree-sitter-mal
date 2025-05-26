#from simple import MalCompiler
# or
from fast import MalCompiler


# Example Python source code
source_code = b'''
#version: "1.2.3"
category Test 
developer info : "something"
{
    asset foo {
        let a = b
        let b = c
        let c = d
        | testStep 
            @ tomas 
            { C, A } 
            [ test(5.5) + 1 - test2(6)^7 / (8 * wrong()) + 999 ]
            developer info : "tomas2"
            modeler info : "tomas3"
    }
    abstract asset bar { }
    asset bar1 extends bar { }
    abstract asset foo1 extends foo { }
}
category Test1 {
}    
'''
'''
    // 
    // 
    // 
'''

# Run the visitor pattern on the tree
compiler = MalCompiler()
compiler.compile(source_code)
