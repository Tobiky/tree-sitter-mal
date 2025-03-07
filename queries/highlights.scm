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

(asset_variable "=" @operator)

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
] @keyword

; Delimiters
"," @punctuation.delimiter

(detector_name "." @punctuation.delimiter)

; Special
(cia) @constant.builtin
(meta) @comment
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
  [id: (identity)
   extends: (identity)] @type)
(detector_context_asset
  type: (identity) @type
  id: (identity) @property)
(asset_variable_substitution
  id: (identity) @property)
(asset_variable
  id: (identity) @property)

(asset_expr [(identity) @function
             (asset_expr_binop
               left: (_)*
               operator: "."
               right: (identity) @function .)])

(asset_expr_binop
  left: [(identity) @property
         (asset_expr_binop)]
  operator: ((_) @operator (#not-eq? @operator "."))
  right: [(identity) @property
         (asset_expr_binop)])

; Miscellaneous
(comment) @comment
(attack_step tag: (identity) @tag)
