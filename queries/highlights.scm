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
 "#"
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
 "E"
 "!E"
] @operator

; To ensure that they are not interpreted as operators elsewhere (e.g. detector names)
(asset_expr_binop
  "." @operator)

; Keywords
[
  "include"
  "category"
  "abstract"
  "asset"
  "extends"
  "let"
  "associations"
  "info"
] @keyword

; Delimiters
"," @punctuation.delimiter
":" @punctuation.delimiter

(detector_name "." @punctuation.delimiter)

; Special
(cia) @constant.builtin
(meta id: (identity) @attribute)

; Primitives
(string) @string

[
 (integer)
 (float)
 (star)
] @number

; Semantic objects
(define_declaration id: (identity) @constant)
(ttc_distribution id: (identity) @function)
