/**
 * @file IT systems are growing in complexity and the threat from cyberattacks is increasing. Threat modeling is a process that can be used to analyze potential attacks to IT systems in order to facilitate secure design. Meta Attack Language (MAL) is a threat modeling language framework for the creation of domain specific languages (DSL). MAL is developed at KTH Royal Institute of Technolog
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

  word: $ => $.identity,

  conflicts: $ => [
    // FIXME: Conflict at end of association when there shouldn't be one
    [$.association]
  ],

  precedences: $ => [
    [ 'binary_exp', 'binary_mul', 'binary_plus', ]
  ],

  rules: {
    source_file: $ => repeat($.declaration),

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
      field('id', $.identity),
      field('meta', repeat($.meta)),
      '{',
      field('assets', repeat($.asset)),
      '}',
    ),

    asset: $ => seq(
      optional(alias('abstract', 'abstract')),
      'asset',
      field('id', $.identity),
      field('extends', optional(seq('extends', $.identity))),
      field('meta', repeat($.meta)),
      '{',
      field('body', repeat(choice($.attack_step, $.asset_variable))),
      '}',
    ),

    asset_variable: $ => seq(
      'let',
      field('id', $.identity),
      '=',
      field('value', $._asset_expr),
    ),

    attack_step: $ => seq(
      field('step_type', choice(
        '|',
        '&',
        '#',
        'E',
        '!E',
      )),
      field('id', $.identity),
      optional(field('tag', seq('@', $.identity))),
      optional(field('cias', seq(
        '{',
        commaSep1($.cia),
        '}',
      ))),
      optional(seq('[', field('ttc', $._ttc), ']')),
      field('meta', repeat($.meta)),
      optional(field('detector', $.detector)),
      optional(field('preconditions', $.preconditions)),
      optional(field('reaches', $.reaching)),
    ),

    detector: $ => seq(
      // Increase //! precidence to overrule comments
      choice('!', token(prec(1, '//!'))),
      optional(field('name', $.detector_name)),
      field('context', $.detector_context),
    ),

    detector_name: $ => sep1($.identity, '.'),

    detector_context: $ => seq(
      '(',
      commaSep1($.detector_context_asset),
      ')',
    ),

    detector_context_asset: $ => seq(
      field('id', $.identity),
      field('label', $.identity),
    ),

    preconditions: $ => seq(
      '<-', 
      field('condition', commaSep1($._asset_expr))
    ),

    reaching: $ => seq(
        field('operator', choice('+>', '->')),
        field('reaches', commaSep1($._asset_expr))
    ),

    // No use in being known since there is only one place these can occur.
    // Might want to bring forward for the sake of querrying.
    _ttc: $ => choice(
      $._ttc_parenthesized,
      $.ttc_primary,
      $.ttc_binop,
    ),

    _ttc_parenthesized: $ => seq('(', $._ttc, ')'),

    ttc_primary: $ => choice(
      $.integer,
      $.identity,
      $.ttc_distribution,
    ),

    ttc_distribution: $ => seq(
      field('id', $.identity),
      '(',
      field('values', commaSep1($.integer)),
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
          field('left', $._ttc),
          field('operator', operator),
          field('right', $._ttc),
        )),
      )
    ),

    _asset_expr: $ => choice(
      $._asset_expr_parenthesized,
      $.asset_expr_primary,
      $.asset_expr_binop,
      $.asset_expr_unop,
      $.asset_expr_type,
    ),

    _asset_expr_parenthesized: $ => seq(
      '(',
      $._asset_expr,
      ')',
    ),

    asset_expr_primary: $ => choice(
      $.identity,
      $.asset_variable_substitution
    ),

    asset_variable_substitution: $ => seq(
      field('id', $.identity),
      '(',
      ')',
    ),

    asset_expr_type: $ => prec.left('binary_exp', seq(
      field('expression', $._asset_expr),
      '[',
      field('type_id', $.identity),
      ']',
    )),

    asset_expr_binop: $ => choice(
      ...[
        ['\\/', 'binary_plus'],
        ['/\\', 'binary_mul'],
        ['-', 'binary_mul'],
        ['.', 'binary_exp'],
      ].map(([operator, precedence, associativity]) =>
        (associativity === 'right' ? prec.right : prec.left)(precedence, seq(
          field('left', $._asset_expr),
          field('operator', operator),
          field('right', $._asset_expr),
        )),
      )
    ),

    asset_expr_unop: $ => choice(
      ...[
        // For now only one unary operator so use binary precedences
        ['*', 'binary_exp'],
      ].map(([operator, precedence, associativity]) =>
        (associativity === 'right' ? prec.right : prec.left)(precedence, seq(
          field('expression', $._asset_expr),
          field('operator', operator),
        )),
      )
    ),

    define_declaration: $ => seq(
      '#',
      field('id', $.identity),
      ':',
      field('value', $.string)
    ),

    associations_declaration: $ => seq(
      'associations',
      '{',
      repeat($.association),
      '}',
    ),

    association: $ => seq(
      field('left_id', $.identity),
      '[', field('left_field_id', $.identity), ']',
      field('left_mult', $.multiplicity),
      '<--',
      field('id', $.identity),
      '-->',
      field('right_mult', $.multiplicity),
      '[', field('right_field_id', $.identity), ']',
      field('right_id', $.identity),
      field('meta', repeat($.meta)),
    ),

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


    meta: $ => seq(
      field('id', $.identity),
      'info',
      ':',
      field('info', $.string),
    ),

    string: _ => token(seq('"', /(?:\\"|[^"])*/, '"')),
    integer: _ => token(/[0-9]+/),
    identity: _ => token(/[a-zA-Z0-9_]+/),

    star: _ => token('*'),
    cia: _ => token(/[CIA]/)
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
