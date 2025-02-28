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
(association ["<--" "-->"] @operator)

(ttc_binop
  [
   "+"
   "-"
   "/"
   "^"
   "*"
   ] @operator)

(attack_step
  [
   "|"
   "&"
   "#"
   "E"
   "!E"
   "@"
   ] @operator)

(detector ["!" "//!"] @operator)

(preconditions "<-" @operator)

(reaching ["+>" "->"] @operator)

(define_declaration "#" @operator)

(asset_expr_binop 
  [
   "\\/"
   "/\\"
   "-"
   "."
   ] @operator)

(asset_expr_unop "*" @operator)

(multiplicity_range ".." @operator)


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
(ttc (identity) @type)
(category_declaration id: (identity) @module)
(association
  left_id: (identity) @type
  left_field_id: (identity) @property
  right_field_id: (identity) @property
  right_id: (identity) @type)
(asset_declaration
  id: (identity) @type
  extends: (identity) @type)

; Miscellaneous
(comment) @comment
(attack_step tag: (identity) @tag)
