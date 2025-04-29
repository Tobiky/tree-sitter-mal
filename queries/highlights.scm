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
"include" @keyword.import
[
  "category"
  "asset"
] @keyword.type
[
  "abstract"
  "extends"
  "associations"
] @keyword.modifier
"let" @keyword

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
 (star)
] @number
(float) @number.float

; Semantic objects
(define_declaration id: (identity) @constant)
(ttc_distribution id: (identity) @function.builtin)
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
  id: (identity) @variable)
(asset_variable
  id: (identity) @variable)

(asset_expr (identity) @property)
(asset_expr [(identity) @function
             (asset_expr_binop
               left: (_)*
               operator: "."
               right: (identity) @function)] .)

; Miscellaneous
(comment) @comment
(attack_step tag: (identity) @tag
             (#not-match? @tag "hidden|debug|trace"))
(attack_step tag: (identity) @tag.builtin
             (#match? @tag.builtin "hidden|debug|trace"))
