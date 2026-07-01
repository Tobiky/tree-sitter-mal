/**
 * @file IT systems are growing in complexity and the threat from cyberattacks is increasing. Threat modeling is a process that can be used to analyze potential attacks to IT systems in order to facilitate secure design. Meta Attack Language (MAL) is a threat modeling language framework for the creation of domain specific languages (DSL). MAL is developed at KTH Royal Institute of Technology.
 * @author Andreas Hammarstrand <andreas.hammarstrand@gmail.com>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: "mal",

  extras: $ => [
    /[ \t\r\n]+/,
    $.comment,
  ],

  word: $ => $.identifier,

  conflicts: $ => [
    // FIXME: Conflict at end of association when there shouldn't be one
    [$.association],
    // DynaMAL: identifier could reduce to dyn_role (in frgmt) or dyn_operand (end of left/right)
    [$.dyn_role, $.dyn_operand],
    [$.dyn_role, $.dyn_modify_sentence],
    [$.dyn_corporeal, $.dyn_precondition],
    [$.dyn_frgmt_or_sub, $.dyn_precondition],
    [$.dyn_substitution],
  ],

  precedences: $ => [
    [ 'binary_exp', 'binary_mul', 'binary_plus', ]
  ],

  rules: {
    source_file: $ => choice(
      repeat($.declaration),
      $.dyn_specification,
    ),

    // http://stackoverflow.com/questions/13014947/regex-to-match-a-c-style-multiline-comment/36328890#36328890
    // Additionally, set 0 precidence so behavior can be overwritten when necessary.
    // For example: Detectors have //! accepted as part of backwards compatability.
    comment: _ => token(prec(0, choice(
      seq('//', /[^\r\n\u2028\u2029]*/),
      seq(
        '/*',
        /[^*]*\*+([^/*][^*]*\*+)*/,
        '/',
      ),
    ))),

    declaration: $ => choice(
      $.include_declaration,
      $.category_declaration,
      $.define_declaration,
      $.associations_declaration,
    ),

    include_declaration: $ => seq(
      'include',
      field('file', $.string)
    ),

    category_declaration: $ => seq(
      'category',
      field('id', $.identifier),
      field('meta', repeat($.meta)),
      '{',
      field('assets', repeat($.asset_declaration)),
      '}',
    ),

    // An asset for a category
    asset_declaration: $ => seq(
      optional(alias('abstract', 'abstract')),
      'asset',
      field('id', $.identifier),
      field('extends', optional(seq('extends', $.identifier))),
      field('meta', repeat($.meta)),
      '{',
      optional(field('body', $.asset_definition)),
      '}',
    ),

    asset_definition: $ => repeat1(choice($.attack_step, $.asset_variable)),

    // A varaible within an asset
    asset_variable: $ => seq(
      'let',
      field('id', $.identifier),
      '=',
      field('value', $.asset_expr),
    ),

    // Attack step for an asset
    attack_step: $ => seq(
      field('step_type', $.step_type),
      optional(field('causal_mode', $.step_causal_mode)),
      field('id', $.identifier),
      optional(field('tag', repeat(seq('@', $.identifier)))),
      optional(field('cias', seq(
        '{',
        $.cias,
        '}',
      ))),
      optional(field('ttc', $.ttc)),
      field('meta', repeat($.meta)),
      optional(field('detector', repeat($.detector))),
      optional(field('preconditions', $.preconditions)),
      optional(field('reaches', $.reaching)),
    ),

    step_type: $ => token(choice(
      '|',
      '&',
      '#',
      'E',
      '!E',
    )),

    step_causal_mode: $ => choice(
      'action',
      'effect',
    ),

    cias: $ => commaSep1($.cia),

    // Detector for attack steps
    detector: $ => seq(
      // Increase //! precidence to overrule comments
      choice('!', token(prec(1, '//!'))),
      field('name', $.detector_name),
      optional(field('context', $.detector_context)),
      optional(field('type', $.identifier)),
      optional(field('tp_fp_rate', $.tp_fp_rate)),
    ),

    detector_name: $ => sep1($.identifier, '.'),

    detector_context: $ => seq(
      '(',
      commaSep1($.detector_context_reference),
      ')',
    ),

    detector_context_reference: $ => seq(
      field('ctx_step', $.asset_expr),
      field('id', $.identifier),
    ),

    // True positive and false positive rates for detector.
    tp_fp_rate: $ => seq(
      '[',
      choice(
        $.tp_fp_pair,
        $.tpr_only,
        $.fpr_only
      ),
      ']',
    ),

    tp_fp_pair: $ => choice(
      seq(
        field('tpr_key', 'tpr'),
        ':',
        field('tp_rate', $._number),
        ',',
        field('fpr_key', 'fpr'),
        ':',
        field('fp_rate', $._number),
      ),
      seq(
        field('fpr_key', 'fpr'),
        ':',
        field('fp_rate', $._number),
        ',',
        field('tpr_key', 'tpr'),
        ':',
        field('tp_rate', $._number),
      )
    ),

    tpr_only: $ => seq(
      field('tpr_key', 'tpr'),
      ':',
      field('tp_rate', $._number),
    ),

    fpr_only: $ => seq(
      field('fpr_key', 'fpr'),
      ':',
      field('fp_rate', $._number),
    ),

    // Precondition for attack steps
    preconditions: $ => seq(
      '<-', 
      field('condition', commaSep1($.asset_expr))
    ),

    // Inheritence or lead to/from other identities for attack steps
    reaching: $ => seq(
        field('operator', choice('+>', '->')),
        field('reaches', commaSep1($.asset_expr))
    ),


    // Time-To-Compromise probabilty distributions
    ttc: $ => seq(
      '[',
      $._ttc_expr,
      ']',
    ),

    // No use in being known since there is only one place these can occur.
    // Might want to bring forward for the sake of querrying.
    _ttc_expr: $ => choice(
      $._ttc_parenthesized,
      $._ttc_primary,
      $.ttc_binop,
    ),

    _ttc_parenthesized: $ => seq('(', $._ttc_expr, ')'),

    _ttc_primary: $ => choice(
      $._number,
      $.identifier,
      $.ttc_distribution,
    ),

    ttc_distribution: $ => seq(
      field('id', $.identifier),
      '(',
      field('values', optional(commaSep1($._number))),
      ')',
    ),

    ttc_binop: $ => choice(
      ...[
        ['+', 'binary_plus'],
        ['-', 'binary_plus'],
        ['*', 'binary_mul'],
        ['/', 'binary_mul'],
        ['^', 'binary_exp', 'right'],
      ].map(([operator, precedence, associativity]) =>
        (associativity === 'right' ? prec.right : prec.left)(precedence, seq(
          field('left', $._ttc_expr),
          field('operator', operator),
          field('right', $._ttc_expr),
        )),
      )
    ),

    // Expression to define relations between assets
    asset_expr: $ => $._inline_asset_expr,

    // In order to ensure that asset_expr only occurs as a root node all of 
    // the grammar logic is placed inside this inline node
    _inline_asset_expr: $ => choice(
      // alias to ._ to inline
      seq('(', $._inline_asset_expr, ')', ),
      $._asset_expr_primary,
      $.asset_expr_binop,
      $.asset_expr_unop,
      $.asset_expr_type,
    ),


    _asset_expr_primary: $ => choice(
      $.identifier,
      $.asset_variable_substitution
    ),

    asset_variable_substitution: $ => seq(
      field('id', $.identifier),
      '(',
      ')',
    ),

    asset_expr_type: $ => prec.left('binary_exp', seq(
      field('expression', $._inline_asset_expr),
      '[',
      field('type_id', $.identifier),
      ']',
    )),

    asset_expr_binop: $ => choice(
      ...[
        ['\\/', 'binary_plus'],
        ['/\\', 'binary_plus'],
        ['-', 'binary_plus'],
        ['.', 'binary_mul'],
      ].map(([operator, precedence, associativity]) =>
        (associativity === 'right' ? prec.right : prec.left)(precedence, seq(
          field('left', $._inline_asset_expr),
          field('operator', operator),
          field('right', $._inline_asset_expr),
        )),
      )
    ),

    asset_expr_unop: $ => choice(
      ...[
        // For now only one unary operator so use binary precedences
        ['*', 'binary_exp'],
      ].map(([operator, precedence, associativity]) =>
        (associativity === 'right' ? prec.right : prec.left)(precedence, seq(
          field('expression', $._inline_asset_expr),
          field('operator', operator),
        )),
      )
    ),

    // Define values, i.e. global string constants
    define_declaration: $ => seq(
      '#',
      field('id', $.identifier),
      ':',
      field('value', $.string)
    ),

    // Define associations between categories, assets, etc. 
    // Quantitive relationships like in UML/relational database.
    associations_declaration: $ => seq(
      'associations',
      '{',
      repeat($.association),
      '}',
    ),

    association: $ => seq(
      field('left_id', $.identifier),
      '[', field('left_field_id', $.identifier), ']',
      field('left_mult', $.multiplicity),
      '<--',
      field('id', $.identifier),
      '-->',
      field('right_mult', $.multiplicity),
      '[', field('right_field_id', $.identifier), ']',
      field('right_id', $.identifier),
      field('meta', repeat($.meta)),
    ),

    // Multiplicity of an association, * for unbounded, range for bounded, and integer for exact.
    multiplicity: $ => choice(
      $._multiplicity_atom,
      $.multiplicity_range,
    ),

    _multiplicity_atom: $ => choice(
      $.integer,
      $.star,
    ),

    multiplicity_range: $ => seq(
      field('start', $._multiplicity_atom),
      '..',
      field('end', $._multiplicity_atom),
    ),

    // Meta information for category, asset, or otherwise.
    meta: $ => seq(
      field('id', $.identifier),
      'info',
      ':',
      field('info', alias($.string, $.meta_string)),
    ),

    // Primitives/Primaries/Atoms
    string: _ => token(seq('"', /(?:\\"|[^"])*/, '"')),
    _number: $ => choice($.integer, $.float),
    integer: _ => token(/[0-9]+/),
    float: _ => token(/(:?[0-9]+(:?[.][0-9]*)?|[.][0-9]+)/),
    identifier: _ => token(/[a-zA-Z0-9_]+/),

    star: _ => token('*'),
    cia: _ => token(/[CIA]/),

    // ===========================================================
    // DynaMAL grammar rules
    // All identifier nodes are alias($.identifier, $.dyn_identifier) so that
    // they share the 'identifier' token pattern (the word token) without
    // introducing a conflicting duplicate token rule.
    // ===========================================================

    dyn_specification: $ => seq(
      repeat1($.dyn_expression),
      optional($.dyn_associations),
    ),

    dyn_expression: $ => $.dyn_resource,

    dyn_resource: $ => seq(
      $.dyn_header,
      optional($.dyn_info),
      '{',
      optional($.dyn_actionspace),
      '}',
    ),

    dyn_header: $ => seq(
      optional('abstract'),
      'asset',
      $.dyn_name,
      optional(seq('extends', $.dyn_name)),
    ),

    dyn_name: $ => alias($.identifier, $.dyn_identifier),

    // info block: repeat1 so the node only appears when at least one entry exists
    dyn_info: $ => repeat1($.dyn_info_entry),

    dyn_info_entry: $ => seq(
      $.dyn_info_type,
      'info',
      ':',
      $.string,
    ),

    dyn_info_type: $ => choice(
      $.dyn_user_info,
      $.dyn_dev_info,
      $.dyn_mod_info,
    ),

    dyn_user_info: _ => 'user',
    dyn_dev_info: _ => 'developer',
    dyn_mod_info: _ => 'modeler',

    dyn_actionspace: $ => repeat1(choice(
      $.dyn_action,
      $.dyn_evaluation,
    )),

    dyn_action: $ => seq(
      choice($.dyn_attack, $.dyn_defense),
      $.dyn_label,
      optional($.dyn_repeatable),
      optional($.dyn_probability),
      optional($.dyn_info),
      repeat($.dyn_actions),
    ),

    dyn_attack: _ => token(choice('|', '&', 'E', '!E')),
    dyn_defense: _ => token('#'),

    dyn_label: $ => alias($.identifier, $.dyn_identifier),

    dyn_repeatable: _ => token(choice('repeat', 'once')),

    dyn_probability: $ => seq(
      '[',
      alias($.identifier, $.dyn_identifier),
      optional(seq('(', optional(commaSep1($.float)), ')')),
      ']',
    ),

    dyn_evaluation: $ => seq(
      $.dyn_condition,
      $.dyn_label,
      optional($.dyn_probability),
      optional($.dyn_info),
      $.dyn_requires,
      repeat1($.dyn_actions),
    ),

    dyn_condition: _ => token(choice('if', 'unless')),

    dyn_requires: $ => seq(
      '<-',
      $.dyn_cond_sentence,
      repeat(seq(',', $.dyn_cond_sentence)),
    ),

    dyn_cond_sentence: $ => seq(
      repeat($.dyn_frgmt_or_sub),
      $.dyn_precondition,
      optional($.dyn_cast),
    ),

    dyn_precondition: $ => choice(
      $.dyn_role,
      $.dyn_cast,
      $.dyn_substitution,
    ),

    dyn_actions: $ => choice($.dyn_static, $.dyn_dynamic),

    dyn_static: $ => seq(
      choice('->', '+>'),
      $.dyn_static_sentence,
      repeat(seq(',', $.dyn_static_sentence)),
    ),

    dyn_static_sentence: $ => seq(
      repeat($.dyn_frgmt_or_sub),
      $.dyn_label,
    ),

    dyn_dynamic: $ => choice($.dyn_arrange, $.dyn_modify),

    dyn_arrange: $ => choice($.dyn_add, $.dyn_remove),

    dyn_add: $ => seq(
      token(choice('A>', '+A>')),
      $.dyn_add_sentence,
      repeat(seq(',', $.dyn_add_sentence)),
    ),

    dyn_add_sentence: $ => seq(
      $.dyn_left_add,
      '/',
      $.dyn_right_add,
    ),

    dyn_left_add: $ => seq(
      repeat($.dyn_frgmt_or_sub),
      $.dyn_operand,
      optional($.dyn_cast),
    ),

    dyn_right_add: $ => seq(
      optional($.dyn_edge_ops),
      repeat($.dyn_frgmt_or_sub),
      $.dyn_operand,
      optional($.dyn_cast),
    ),

    dyn_remove: $ => seq(
      token(choice('R>', '+R>')),
      $.dyn_remove_sentence,
      repeat(seq(',', $.dyn_remove_sentence)),
    ),

    dyn_remove_sentence: $ => seq(
      $.dyn_left_remove,
      '/',
      $.dyn_right_remove,
    ),

    dyn_left_remove: $ => seq(
      repeat($.dyn_frgmt_or_sub),
      $.dyn_operand,
      optional($.dyn_cast),
    ),

    dyn_right_remove: $ => seq(
      optional($.dyn_edge_ops),
      repeat($.dyn_frgmt_or_sub),
      $.dyn_operand,
      optional($.dyn_cast),
    ),

    dyn_modify: $ => seq(
      token(choice('M>', '+M>')),
      $.dyn_modify_sentence,
      repeat(seq(',', $.dyn_modify_sentence)),
    ),

    dyn_modify_sentence: $ => seq(
      repeat($.dyn_frgmt_or_sub),
      alias($.identifier, $.dyn_identifier),
      $.dyn_probability,
      ',',
    ),

    // Fragment-or-substitution: a path segment ending with a collect/set operator
    dyn_frgmt_or_sub: $ => choice(
      $.dyn_frgmt,
      $.dyn_substitution,
    ),

    dyn_frgmt: $ => seq(
      optional($.dyn_recursive),
      choice($.dyn_corporeal, $.dyn_ephemeral),
      optional($.dyn_cast),
      choice($.dyn_collect_ops, $.dyn_set_ops),
    ),

    dyn_corporeal: $ => $.dyn_role,

    dyn_ephemeral: $ => seq('<', repeat1($.dyn_frgmt_or_sub), '>'),

    dyn_role: $ => alias($.identifier, $.dyn_identifier),

    dyn_cast: $ => seq('[', $.dyn_asset, ']'),

    dyn_asset: $ => alias($.identifier, $.dyn_identifier),

    dyn_operand: $ => alias($.identifier, $.dyn_identifier),

    dyn_substitution: $ => seq(
      $.dyn_macro_name,
      '(',
      ')',
      optional($.dyn_cast),
      optional(choice($.dyn_collect_ops, $.dyn_set_ops)),
    ),

    dyn_macro_name: $ => alias($.identifier, $.dyn_identifier),

    dyn_edge_ops: _ => '~',

    dyn_collect_ops: $ => choice($.dyn_collect, $.dyn_recursive),
    dyn_collect: _ => '.',
    dyn_recursive: _ => '*',

    dyn_set_ops: _ => token(choice('\\/', '/\\', '-')),

    dyn_associations: $ => seq(
      'associations',
      '{',
      repeat($.dyn_association),
      '}',
    ),

    dyn_association: $ => seq(
      $.dyn_name,
      '[', $.dyn_role, ']',
      $.dyn_cardinality,
      '<--', alias($.identifier, $.dyn_identifier), '-->',
      $.dyn_cardinality,
      '[', $.dyn_role, ']',
      $.dyn_name,
      optional($.dyn_info),
    ),

    dyn_cardinality: $ => choice(
      seq($.dyn_cardinal, '..', $.dyn_cardinal),
      $.dyn_cardinal,
    ),

    dyn_cardinal: $ => choice(
      $.dyn_asterisk,
      $.integer,
    ),

    dyn_asterisk: _ => '*',

    // dyn_identifier is not defined as a standalone rule; it is produced only
    // via alias($.identifier, $.dyn_identifier) at each usage site above.
  },
});

/**
 * Creates a rule to match one or more of the rules separated by a given token.
 *
 * @param {Rule} rule
 * @param {Token} token
 *
 * @returns {SeqRule}
 */
function sep1(rule, token) {
  return seq(rule, repeat(seq(token, rule)));
}

/**
 * Creates a rule to match one or more of the rules separated by a comma
 *
 * @param {Rule} rule
 *
 * @returns {SeqRule}
 */
function commaSep1(rule) {
  return sep1(rule, ',');
}
