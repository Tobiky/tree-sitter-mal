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

  rules: {
    source_file: $ => repeat($.declaration),

    // http://stackoverflow.com/questions/13014947/regex-to-match-a-c-style-multiline-comment/36328890#36328890
    comment: _ => token(choice(
      seq('//', /[^\r\n\u2028\u2029]*/),
      seq(
        '/*',
        /[^*]*\*+([^/*][^*]*\*+)*/,
        '/',
      ),
    )),

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
      '}',
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
  }
});
