; Brackets
[
 "{"
 "}"
 "("
 ")"
 "["
 "]"
] @punctuation.bracket

; Operators
[
 "+"
 "-"
 "*"
 "/"
 "^"
 "\\/"
 "/\\"
 ".."
 "<--"
 "-->"
 "+>"
 "->"
 "<-"
 "@"
 "!"
 "//!"
 "|"
 "&"
 "#"
 "E"
 "!E"
] @operator

; To ensure that they are not interpreted as operators elsewhere (e.g. detector names)
(asset_expr_binop
  "." @operator)
