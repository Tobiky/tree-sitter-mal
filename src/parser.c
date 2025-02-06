#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 48
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 33
#define ALIAS_COUNT 0
#define TOKEN_COUNT 19
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 13
#define MAX_ALIAS_SEQUENCE_LENGTH 14
#define PRODUCTION_ID_COUNT 9

enum ts_symbol_identifiers {
  sym_identity = 1,
  sym_comment = 2,
  anon_sym_include = 3,
  anon_sym_category = 4,
  anon_sym_LBRACE = 5,
  anon_sym_RBRACE = 6,
  anon_sym_POUND = 7,
  anon_sym_COLON = 8,
  anon_sym_associations = 9,
  anon_sym_LBRACK = 10,
  anon_sym_RBRACK = 11,
  anon_sym_LT_DASH_DASH = 12,
  anon_sym_DASH_DASH_GT = 13,
  anon_sym_DOT_DOT = 14,
  anon_sym_info = 15,
  sym_string = 16,
  sym_integer = 17,
  sym_star = 18,
  sym_source_file = 19,
  sym_declaration = 20,
  sym_include_declaration = 21,
  sym_category_declaration = 22,
  sym_define_declaration = 23,
  sym_associations_declaration = 24,
  sym_association = 25,
  sym_multiplicity = 26,
  sym__multiplicity_atom = 27,
  sym_multiplicity_range = 28,
  sym_meta = 29,
  aux_sym_source_file_repeat1 = 30,
  aux_sym_category_declaration_repeat1 = 31,
  aux_sym_associations_declaration_repeat1 = 32,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identity] = "identity",
  [sym_comment] = "comment",
  [anon_sym_include] = "include",
  [anon_sym_category] = "category",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_POUND] = "#",
  [anon_sym_COLON] = ":",
  [anon_sym_associations] = "associations",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_LT_DASH_DASH] = "<--",
  [anon_sym_DASH_DASH_GT] = "-->",
  [anon_sym_DOT_DOT] = "..",
  [anon_sym_info] = "info",
  [sym_string] = "string",
  [sym_integer] = "integer",
  [sym_star] = "star",
  [sym_source_file] = "source_file",
  [sym_declaration] = "declaration",
  [sym_include_declaration] = "include_declaration",
  [sym_category_declaration] = "category_declaration",
  [sym_define_declaration] = "define_declaration",
  [sym_associations_declaration] = "associations_declaration",
  [sym_association] = "association",
  [sym_multiplicity] = "multiplicity",
  [sym__multiplicity_atom] = "_multiplicity_atom",
  [sym_multiplicity_range] = "multiplicity_range",
  [sym_meta] = "meta",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_category_declaration_repeat1] = "category_declaration_repeat1",
  [aux_sym_associations_declaration_repeat1] = "associations_declaration_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identity] = sym_identity,
  [sym_comment] = sym_comment,
  [anon_sym_include] = anon_sym_include,
  [anon_sym_category] = anon_sym_category,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_POUND] = anon_sym_POUND,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_associations] = anon_sym_associations,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_LT_DASH_DASH] = anon_sym_LT_DASH_DASH,
  [anon_sym_DASH_DASH_GT] = anon_sym_DASH_DASH_GT,
  [anon_sym_DOT_DOT] = anon_sym_DOT_DOT,
  [anon_sym_info] = anon_sym_info,
  [sym_string] = sym_string,
  [sym_integer] = sym_integer,
  [sym_star] = sym_star,
  [sym_source_file] = sym_source_file,
  [sym_declaration] = sym_declaration,
  [sym_include_declaration] = sym_include_declaration,
  [sym_category_declaration] = sym_category_declaration,
  [sym_define_declaration] = sym_define_declaration,
  [sym_associations_declaration] = sym_associations_declaration,
  [sym_association] = sym_association,
  [sym_multiplicity] = sym_multiplicity,
  [sym__multiplicity_atom] = sym__multiplicity_atom,
  [sym_multiplicity_range] = sym_multiplicity_range,
  [sym_meta] = sym_meta,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_category_declaration_repeat1] = aux_sym_category_declaration_repeat1,
  [aux_sym_associations_declaration_repeat1] = aux_sym_associations_declaration_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_identity] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_include] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_category] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUND] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_associations] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_DASH_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_DASH_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_info] = {
    .visible = true,
    .named = false,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_integer] = {
    .visible = true,
    .named = true,
  },
  [sym_star] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_include_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_category_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_define_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_associations_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_association] = {
    .visible = true,
    .named = true,
  },
  [sym_multiplicity] = {
    .visible = true,
    .named = true,
  },
  [sym__multiplicity_atom] = {
    .visible = false,
    .named = true,
  },
  [sym_multiplicity_range] = {
    .visible = true,
    .named = true,
  },
  [sym_meta] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_category_declaration_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_associations_declaration_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_end = 1,
  field_file = 2,
  field_id = 3,
  field_info = 4,
  field_left_field_id = 5,
  field_left_id = 6,
  field_left_mult = 7,
  field_meta = 8,
  field_right_field_id = 9,
  field_right_id = 10,
  field_right_mult = 11,
  field_start = 12,
  field_value = 13,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_end] = "end",
  [field_file] = "file",
  [field_id] = "id",
  [field_info] = "info",
  [field_left_field_id] = "left_field_id",
  [field_left_id] = "left_id",
  [field_left_mult] = "left_mult",
  [field_meta] = "meta",
  [field_right_field_id] = "right_field_id",
  [field_right_id] = "right_id",
  [field_right_mult] = "right_mult",
  [field_start] = "start",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 2},
  [4] = {.index = 4, .length = 2},
  [5] = {.index = 6, .length = 2},
  [6] = {.index = 8, .length = 2},
  [7] = {.index = 10, .length = 7},
  [8] = {.index = 17, .length = 8},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_file, 1},
  [1] =
    {field_id, 1},
  [2] =
    {field_id, 1},
    {field_value, 3},
  [4] =
    {field_id, 1},
    {field_meta, 2},
  [6] =
    {field_id, 0},
    {field_info, 3},
  [8] =
    {field_end, 2},
    {field_start, 0},
  [10] =
    {field_id, 6},
    {field_left_field_id, 2},
    {field_left_id, 0},
    {field_left_mult, 4},
    {field_right_field_id, 10},
    {field_right_id, 12},
    {field_right_mult, 8},
  [17] =
    {field_id, 6},
    {field_left_field_id, 2},
    {field_left_id, 0},
    {field_left_mult, 4},
    {field_meta, 13},
    {field_right_field_id, 10},
    {field_right_id, 12},
    {field_right_mult, 8},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(13);
      ADVANCE_MAP(
        '"', 1,
        '#', 18,
        '*', 30,
        '-', 7,
        '.', 10,
        '/', 4,
        ':', 19,
        '<', 9,
        '[', 20,
        ']', 21,
        '{', 16,
        '}', 17,
      );
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(27);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(29);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(25);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(26);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 3:
      if (lookahead == '*') ADVANCE(30);
      if (lookahead == '/') ADVANCE(4);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(28);
      END_STATE();
    case 4:
      if (lookahead == '*') ADVANCE(6);
      if (lookahead == '/') ADVANCE(15);
      END_STATE();
    case 5:
      if (lookahead == '*') ADVANCE(5);
      if (lookahead == '/') ADVANCE(14);
      if (lookahead != 0) ADVANCE(6);
      END_STATE();
    case 6:
      if (lookahead == '*') ADVANCE(5);
      if (lookahead != 0) ADVANCE(6);
      END_STATE();
    case 7:
      if (lookahead == '-') ADVANCE(11);
      END_STATE();
    case 8:
      if (lookahead == '-') ADVANCE(22);
      END_STATE();
    case 9:
      if (lookahead == '-') ADVANCE(8);
      END_STATE();
    case 10:
      if (lookahead == '.') ADVANCE(24);
      END_STATE();
    case 11:
      if (lookahead == '>') ADVANCE(23);
      END_STATE();
    case 12:
      if (eof) ADVANCE(13);
      if (lookahead == '#') ADVANCE(18);
      if (lookahead == '/') ADVANCE(4);
      if (lookahead == '{') ADVANCE(16);
      if (lookahead == '}') ADVANCE(17);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(12);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(29);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) ADVANCE(15);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_LT_DASH_DASH);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_DASH_DASH_GT);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_DOT_DOT);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym_string);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym_string);
      if (lookahead == '"') ADVANCE(25);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym_integer);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(27);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(29);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_integer);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(28);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_identity);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(29);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_star);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (lookahead == 'a') ADVANCE(1);
      if (lookahead == 'c') ADVANCE(2);
      if (lookahead == 'i') ADVANCE(3);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == 's') ADVANCE(4);
      END_STATE();
    case 2:
      if (lookahead == 'a') ADVANCE(5);
      END_STATE();
    case 3:
      if (lookahead == 'n') ADVANCE(6);
      END_STATE();
    case 4:
      if (lookahead == 's') ADVANCE(7);
      END_STATE();
    case 5:
      if (lookahead == 't') ADVANCE(8);
      END_STATE();
    case 6:
      if (lookahead == 'c') ADVANCE(9);
      if (lookahead == 'f') ADVANCE(10);
      END_STATE();
    case 7:
      if (lookahead == 'o') ADVANCE(11);
      END_STATE();
    case 8:
      if (lookahead == 'e') ADVANCE(12);
      END_STATE();
    case 9:
      if (lookahead == 'l') ADVANCE(13);
      END_STATE();
    case 10:
      if (lookahead == 'o') ADVANCE(14);
      END_STATE();
    case 11:
      if (lookahead == 'c') ADVANCE(15);
      END_STATE();
    case 12:
      if (lookahead == 'g') ADVANCE(16);
      END_STATE();
    case 13:
      if (lookahead == 'u') ADVANCE(17);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_info);
      END_STATE();
    case 15:
      if (lookahead == 'i') ADVANCE(18);
      END_STATE();
    case 16:
      if (lookahead == 'o') ADVANCE(19);
      END_STATE();
    case 17:
      if (lookahead == 'd') ADVANCE(20);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(21);
      END_STATE();
    case 19:
      if (lookahead == 'r') ADVANCE(22);
      END_STATE();
    case 20:
      if (lookahead == 'e') ADVANCE(23);
      END_STATE();
    case 21:
      if (lookahead == 't') ADVANCE(24);
      END_STATE();
    case 22:
      if (lookahead == 'y') ADVANCE(25);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_include);
      END_STATE();
    case 24:
      if (lookahead == 'i') ADVANCE(26);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_category);
      END_STATE();
    case 26:
      if (lookahead == 'o') ADVANCE(27);
      END_STATE();
    case 27:
      if (lookahead == 'n') ADVANCE(28);
      END_STATE();
    case 28:
      if (lookahead == 's') ADVANCE(29);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_associations);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 12},
  [2] = {.lex_state = 12},
  [3] = {.lex_state = 12},
  [4] = {.lex_state = 12},
  [5] = {.lex_state = 12},
  [6] = {.lex_state = 12},
  [7] = {.lex_state = 12},
  [8] = {.lex_state = 12},
  [9] = {.lex_state = 12},
  [10] = {.lex_state = 12},
  [11] = {.lex_state = 3},
  [12] = {.lex_state = 12},
  [13] = {.lex_state = 3},
  [14] = {.lex_state = 12},
  [15] = {.lex_state = 12},
  [16] = {.lex_state = 12},
  [17] = {.lex_state = 12},
  [18] = {.lex_state = 12},
  [19] = {.lex_state = 12},
  [20] = {.lex_state = 12},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 3},
  [23] = {.lex_state = 12},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 12},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 12},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 12},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 12},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 12},
  [46] = {.lex_state = 12},
  [47] = {.lex_state = 12},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identity] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
    [anon_sym_include] = ACTIONS(1),
    [anon_sym_category] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_POUND] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_associations] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_LT_DASH_DASH] = ACTIONS(1),
    [anon_sym_DASH_DASH_GT] = ACTIONS(1),
    [anon_sym_DOT_DOT] = ACTIONS(1),
    [anon_sym_info] = ACTIONS(1),
    [sym_string] = ACTIONS(1),
    [sym_integer] = ACTIONS(1),
    [sym_star] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(26),
    [sym_declaration] = STATE(2),
    [sym_include_declaration] = STATE(6),
    [sym_category_declaration] = STATE(6),
    [sym_define_declaration] = STATE(6),
    [sym_associations_declaration] = STATE(6),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_comment] = ACTIONS(3),
    [anon_sym_include] = ACTIONS(7),
    [anon_sym_category] = ACTIONS(9),
    [anon_sym_POUND] = ACTIONS(11),
    [anon_sym_associations] = ACTIONS(13),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_include,
    ACTIONS(9), 1,
      anon_sym_category,
    ACTIONS(11), 1,
      anon_sym_POUND,
    ACTIONS(13), 1,
      anon_sym_associations,
    ACTIONS(15), 1,
      ts_builtin_sym_end,
    STATE(3), 2,
      sym_declaration,
      aux_sym_source_file_repeat1,
    STATE(6), 4,
      sym_include_declaration,
      sym_category_declaration,
      sym_define_declaration,
      sym_associations_declaration,
  [29] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(17), 1,
      ts_builtin_sym_end,
    ACTIONS(19), 1,
      anon_sym_include,
    ACTIONS(22), 1,
      anon_sym_category,
    ACTIONS(25), 1,
      anon_sym_POUND,
    ACTIONS(28), 1,
      anon_sym_associations,
    STATE(3), 2,
      sym_declaration,
      aux_sym_source_file_repeat1,
    STATE(6), 4,
      sym_include_declaration,
      sym_category_declaration,
      sym_define_declaration,
      sym_associations_declaration,
  [58] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      sym_identity,
    ACTIONS(34), 2,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
    STATE(4), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [73] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(36), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [84] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(38), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [95] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(40), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [106] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(42), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [117] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(44), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [128] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(46), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [139] = 5,
    ACTIONS(3), 1,
      sym_comment,
    STATE(21), 1,
      sym__multiplicity_atom,
    STATE(25), 1,
      sym_multiplicity_range,
    STATE(35), 1,
      sym_multiplicity,
    ACTIONS(48), 2,
      sym_integer,
      sym_star,
  [156] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(50), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [167] = 5,
    ACTIONS(3), 1,
      sym_comment,
    STATE(21), 1,
      sym__multiplicity_atom,
    STATE(25), 1,
      sym_multiplicity_range,
    STATE(42), 1,
      sym_multiplicity,
    ACTIONS(48), 2,
      sym_integer,
      sym_star,
  [184] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(52), 1,
      sym_identity,
    ACTIONS(55), 1,
      anon_sym_RBRACE,
    STATE(4), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [198] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(57), 1,
      sym_identity,
    ACTIONS(59), 1,
      anon_sym_LBRACE,
    STATE(16), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [212] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(57), 1,
      sym_identity,
    ACTIONS(61), 1,
      anon_sym_LBRACE,
    STATE(4), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [226] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(63), 1,
      sym_identity,
    ACTIONS(65), 1,
      anon_sym_RBRACE,
    STATE(19), 2,
      sym_association,
      aux_sym_associations_declaration_repeat1,
  [240] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(63), 1,
      sym_identity,
    ACTIONS(67), 1,
      anon_sym_RBRACE,
    STATE(17), 2,
      sym_association,
      aux_sym_associations_declaration_repeat1,
  [254] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(69), 1,
      sym_identity,
    ACTIONS(72), 1,
      anon_sym_RBRACE,
    STATE(19), 2,
      sym_association,
      aux_sym_associations_declaration_repeat1,
  [268] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(74), 1,
      sym_identity,
    ACTIONS(77), 1,
      anon_sym_RBRACE,
    STATE(14), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [282] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(81), 1,
      anon_sym_DOT_DOT,
    ACTIONS(79), 2,
      anon_sym_LBRACK,
      anon_sym_LT_DASH_DASH,
  [293] = 3,
    ACTIONS(3), 1,
      sym_comment,
    STATE(24), 1,
      sym__multiplicity_atom,
    ACTIONS(83), 2,
      sym_integer,
      sym_star,
  [304] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(85), 3,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_identity,
  [313] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(87), 2,
      anon_sym_LBRACK,
      anon_sym_LT_DASH_DASH,
  [321] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(79), 2,
      anon_sym_LBRACK,
      anon_sym_LT_DASH_DASH,
  [329] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(89), 1,
      ts_builtin_sym_end,
  [336] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(91), 1,
      sym_identity,
  [343] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(93), 1,
      anon_sym_COLON,
  [350] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(95), 1,
      sym_string,
  [357] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(97), 1,
      sym_string,
  [364] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(99), 1,
      sym_string,
  [371] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(101), 1,
      anon_sym_RBRACK,
  [378] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(103), 1,
      anon_sym_LBRACK,
  [385] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(105), 1,
      sym_identity,
  [392] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(107), 1,
      anon_sym_LT_DASH_DASH,
  [399] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(109), 1,
      anon_sym_RBRACE,
  [406] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(111), 1,
      sym_identity,
  [413] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(113), 1,
      anon_sym_COLON,
  [420] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(115), 1,
      anon_sym_DASH_DASH_GT,
  [427] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(117), 1,
      anon_sym_LBRACE,
  [434] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(119), 1,
      anon_sym_RBRACE,
  [441] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(121), 1,
      anon_sym_LBRACK,
  [448] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(123), 1,
      sym_identity,
  [455] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(125), 1,
      anon_sym_RBRACK,
  [462] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(127), 1,
      sym_identity,
  [469] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(129), 1,
      sym_identity,
  [476] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(131), 1,
      anon_sym_info,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 29,
  [SMALL_STATE(4)] = 58,
  [SMALL_STATE(5)] = 73,
  [SMALL_STATE(6)] = 84,
  [SMALL_STATE(7)] = 95,
  [SMALL_STATE(8)] = 106,
  [SMALL_STATE(9)] = 117,
  [SMALL_STATE(10)] = 128,
  [SMALL_STATE(11)] = 139,
  [SMALL_STATE(12)] = 156,
  [SMALL_STATE(13)] = 167,
  [SMALL_STATE(14)] = 184,
  [SMALL_STATE(15)] = 198,
  [SMALL_STATE(16)] = 212,
  [SMALL_STATE(17)] = 226,
  [SMALL_STATE(18)] = 240,
  [SMALL_STATE(19)] = 254,
  [SMALL_STATE(20)] = 268,
  [SMALL_STATE(21)] = 282,
  [SMALL_STATE(22)] = 293,
  [SMALL_STATE(23)] = 304,
  [SMALL_STATE(24)] = 313,
  [SMALL_STATE(25)] = 321,
  [SMALL_STATE(26)] = 329,
  [SMALL_STATE(27)] = 336,
  [SMALL_STATE(28)] = 343,
  [SMALL_STATE(29)] = 350,
  [SMALL_STATE(30)] = 357,
  [SMALL_STATE(31)] = 364,
  [SMALL_STATE(32)] = 371,
  [SMALL_STATE(33)] = 378,
  [SMALL_STATE(34)] = 385,
  [SMALL_STATE(35)] = 392,
  [SMALL_STATE(36)] = 399,
  [SMALL_STATE(37)] = 406,
  [SMALL_STATE(38)] = 413,
  [SMALL_STATE(39)] = 420,
  [SMALL_STATE(40)] = 427,
  [SMALL_STATE(41)] = 434,
  [SMALL_STATE(42)] = 441,
  [SMALL_STATE(43)] = 448,
  [SMALL_STATE(44)] = 455,
  [SMALL_STATE(45)] = 462,
  [SMALL_STATE(46)] = 469,
  [SMALL_STATE(47)] = 476,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [19] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(31),
  [22] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(34),
  [25] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(46),
  [28] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(40),
  [31] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_category_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(47),
  [34] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_category_declaration_repeat1, 2, 0, 0),
  [36] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_declaration, 2, 0, 1),
  [38] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_declaration, 1, 0, 0),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_category_declaration, 4, 0, 2),
  [42] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_associations_declaration, 3, 0, 0),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_define_declaration, 4, 0, 3),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_associations_declaration, 4, 0, 0),
  [48] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_category_declaration, 5, 0, 4),
  [52] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_association, 14, 0, 8), SHIFT(47),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_association, 14, 0, 8),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [69] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_associations_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(33),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_associations_declaration_repeat1, 2, 0, 0),
  [74] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_association, 13, 0, 7), SHIFT(47),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_association, 13, 0, 7),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multiplicity, 1, 0, 0),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_meta, 4, 0, 5),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multiplicity_range, 3, 0, 6),
  [89] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [131] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_mal(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_identity,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
