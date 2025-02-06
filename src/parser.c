#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 82
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 38
#define ALIAS_COUNT 0
#define TOKEN_COUNT 22
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 15
#define MAX_ALIAS_SEQUENCE_LENGTH 14
#define PRODUCTION_ID_COUNT 17

enum ts_symbol_identifiers {
  sym_identity = 1,
  sym_comment = 2,
  anon_sym_include = 3,
  anon_sym_category = 4,
  anon_sym_LBRACE = 5,
  anon_sym_RBRACE = 6,
  anon_sym_abstract = 7,
  anon_sym_asset = 8,
  anon_sym_extends = 9,
  anon_sym_POUND = 10,
  anon_sym_COLON = 11,
  anon_sym_associations = 12,
  anon_sym_LBRACK = 13,
  anon_sym_RBRACK = 14,
  anon_sym_LT_DASH_DASH = 15,
  anon_sym_DASH_DASH_GT = 16,
  anon_sym_DOT_DOT = 17,
  anon_sym_info = 18,
  sym_string = 19,
  sym_integer = 20,
  sym_star = 21,
  sym_source_file = 22,
  sym_declaration = 23,
  sym_include_declaration = 24,
  sym_category_declaration = 25,
  sym_asset = 26,
  sym_define_declaration = 27,
  sym_associations_declaration = 28,
  sym_association = 29,
  sym_multiplicity = 30,
  sym__multiplicity_atom = 31,
  sym_multiplicity_range = 32,
  sym_meta = 33,
  aux_sym_source_file_repeat1 = 34,
  aux_sym_category_declaration_repeat1 = 35,
  aux_sym_category_declaration_repeat2 = 36,
  aux_sym_associations_declaration_repeat1 = 37,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identity] = "identity",
  [sym_comment] = "comment",
  [anon_sym_include] = "include",
  [anon_sym_category] = "category",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_abstract] = "abstract",
  [anon_sym_asset] = "asset",
  [anon_sym_extends] = "extends",
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
  [sym_asset] = "asset",
  [sym_define_declaration] = "define_declaration",
  [sym_associations_declaration] = "associations_declaration",
  [sym_association] = "association",
  [sym_multiplicity] = "multiplicity",
  [sym__multiplicity_atom] = "_multiplicity_atom",
  [sym_multiplicity_range] = "multiplicity_range",
  [sym_meta] = "meta",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_category_declaration_repeat1] = "category_declaration_repeat1",
  [aux_sym_category_declaration_repeat2] = "category_declaration_repeat2",
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
  [anon_sym_abstract] = anon_sym_abstract,
  [anon_sym_asset] = anon_sym_asset,
  [anon_sym_extends] = anon_sym_extends,
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
  [sym_asset] = sym_asset,
  [sym_define_declaration] = sym_define_declaration,
  [sym_associations_declaration] = sym_associations_declaration,
  [sym_association] = sym_association,
  [sym_multiplicity] = sym_multiplicity,
  [sym__multiplicity_atom] = sym__multiplicity_atom,
  [sym_multiplicity_range] = sym_multiplicity_range,
  [sym_meta] = sym_meta,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_category_declaration_repeat1] = aux_sym_category_declaration_repeat1,
  [aux_sym_category_declaration_repeat2] = aux_sym_category_declaration_repeat2,
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
  [anon_sym_abstract] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_asset] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_extends] = {
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
  [sym_asset] = {
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
  [aux_sym_category_declaration_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_associations_declaration_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_assets = 1,
  field_end = 2,
  field_extends = 3,
  field_file = 4,
  field_id = 5,
  field_info = 6,
  field_left_field_id = 7,
  field_left_id = 8,
  field_left_mult = 9,
  field_meta = 10,
  field_right_field_id = 11,
  field_right_id = 12,
  field_right_mult = 13,
  field_start = 14,
  field_value = 15,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_assets] = "assets",
  [field_end] = "end",
  [field_extends] = "extends",
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
  [7] = {.index = 10, .length = 3},
  [8] = {.index = 13, .length = 1},
  [9] = {.index = 14, .length = 2},
  [10] = {.index = 16, .length = 3},
  [11] = {.index = 19, .length = 2},
  [12] = {.index = 21, .length = 3},
  [13] = {.index = 24, .length = 4},
  [14] = {.index = 28, .length = 4},
  [15] = {.index = 32, .length = 7},
  [16] = {.index = 39, .length = 8},
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
    {field_assets, 3},
    {field_id, 1},
  [6] =
    {field_id, 1},
    {field_meta, 2},
  [8] =
    {field_id, 0},
    {field_info, 3},
  [10] =
    {field_assets, 4},
    {field_id, 1},
    {field_meta, 2},
  [13] =
    {field_id, 2},
  [14] =
    {field_id, 2},
    {field_meta, 3},
  [16] =
    {field_extends, 2},
    {field_extends, 3},
    {field_id, 1},
  [19] =
    {field_end, 2},
    {field_start, 0},
  [21] =
    {field_extends, 3},
    {field_extends, 4},
    {field_id, 2},
  [24] =
    {field_extends, 2},
    {field_extends, 3},
    {field_id, 1},
    {field_meta, 4},
  [28] =
    {field_extends, 3},
    {field_extends, 4},
    {field_id, 2},
    {field_meta, 5},
  [32] =
    {field_id, 6},
    {field_left_field_id, 2},
    {field_left_id, 0},
    {field_left_mult, 4},
    {field_right_field_id, 10},
    {field_right_id, 12},
    {field_right_mult, 8},
  [39] =
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
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
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
      if (lookahead == 'e') ADVANCE(3);
      if (lookahead == 'i') ADVANCE(4);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == 'b') ADVANCE(5);
      if (lookahead == 's') ADVANCE(6);
      END_STATE();
    case 2:
      if (lookahead == 'a') ADVANCE(7);
      END_STATE();
    case 3:
      if (lookahead == 'x') ADVANCE(8);
      END_STATE();
    case 4:
      if (lookahead == 'n') ADVANCE(9);
      END_STATE();
    case 5:
      if (lookahead == 's') ADVANCE(10);
      END_STATE();
    case 6:
      if (lookahead == 's') ADVANCE(11);
      END_STATE();
    case 7:
      if (lookahead == 't') ADVANCE(12);
      END_STATE();
    case 8:
      if (lookahead == 't') ADVANCE(13);
      END_STATE();
    case 9:
      if (lookahead == 'c') ADVANCE(14);
      if (lookahead == 'f') ADVANCE(15);
      END_STATE();
    case 10:
      if (lookahead == 't') ADVANCE(16);
      END_STATE();
    case 11:
      if (lookahead == 'e') ADVANCE(17);
      if (lookahead == 'o') ADVANCE(18);
      END_STATE();
    case 12:
      if (lookahead == 'e') ADVANCE(19);
      END_STATE();
    case 13:
      if (lookahead == 'e') ADVANCE(20);
      END_STATE();
    case 14:
      if (lookahead == 'l') ADVANCE(21);
      END_STATE();
    case 15:
      if (lookahead == 'o') ADVANCE(22);
      END_STATE();
    case 16:
      if (lookahead == 'r') ADVANCE(23);
      END_STATE();
    case 17:
      if (lookahead == 't') ADVANCE(24);
      END_STATE();
    case 18:
      if (lookahead == 'c') ADVANCE(25);
      END_STATE();
    case 19:
      if (lookahead == 'g') ADVANCE(26);
      END_STATE();
    case 20:
      if (lookahead == 'n') ADVANCE(27);
      END_STATE();
    case 21:
      if (lookahead == 'u') ADVANCE(28);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_info);
      END_STATE();
    case 23:
      if (lookahead == 'a') ADVANCE(29);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_asset);
      END_STATE();
    case 25:
      if (lookahead == 'i') ADVANCE(30);
      END_STATE();
    case 26:
      if (lookahead == 'o') ADVANCE(31);
      END_STATE();
    case 27:
      if (lookahead == 'd') ADVANCE(32);
      END_STATE();
    case 28:
      if (lookahead == 'd') ADVANCE(33);
      END_STATE();
    case 29:
      if (lookahead == 'c') ADVANCE(34);
      END_STATE();
    case 30:
      if (lookahead == 'a') ADVANCE(35);
      END_STATE();
    case 31:
      if (lookahead == 'r') ADVANCE(36);
      END_STATE();
    case 32:
      if (lookahead == 's') ADVANCE(37);
      END_STATE();
    case 33:
      if (lookahead == 'e') ADVANCE(38);
      END_STATE();
    case 34:
      if (lookahead == 't') ADVANCE(39);
      END_STATE();
    case 35:
      if (lookahead == 't') ADVANCE(40);
      END_STATE();
    case 36:
      if (lookahead == 'y') ADVANCE(41);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_extends);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_include);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_abstract);
      END_STATE();
    case 40:
      if (lookahead == 'i') ADVANCE(42);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_category);
      END_STATE();
    case 42:
      if (lookahead == 'o') ADVANCE(43);
      END_STATE();
    case 43:
      if (lookahead == 'n') ADVANCE(44);
      END_STATE();
    case 44:
      if (lookahead == 's') ADVANCE(45);
      END_STATE();
    case 45:
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
  [11] = {.lex_state = 12},
  [12] = {.lex_state = 12},
  [13] = {.lex_state = 12},
  [14] = {.lex_state = 12},
  [15] = {.lex_state = 12},
  [16] = {.lex_state = 12},
  [17] = {.lex_state = 12},
  [18] = {.lex_state = 12},
  [19] = {.lex_state = 12},
  [20] = {.lex_state = 12},
  [21] = {.lex_state = 3},
  [22] = {.lex_state = 3},
  [23] = {.lex_state = 12},
  [24] = {.lex_state = 12},
  [25] = {.lex_state = 12},
  [26] = {.lex_state = 12},
  [27] = {.lex_state = 12},
  [28] = {.lex_state = 12},
  [29] = {.lex_state = 12},
  [30] = {.lex_state = 12},
  [31] = {.lex_state = 12},
  [32] = {.lex_state = 12},
  [33] = {.lex_state = 12},
  [34] = {.lex_state = 12},
  [35] = {.lex_state = 12},
  [36] = {.lex_state = 12},
  [37] = {.lex_state = 12},
  [38] = {.lex_state = 12},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 12},
  [41] = {.lex_state = 12},
  [42] = {.lex_state = 12},
  [43] = {.lex_state = 3},
  [44] = {.lex_state = 12},
  [45] = {.lex_state = 12},
  [46] = {.lex_state = 12},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 12},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 12},
  [57] = {.lex_state = 12},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 12},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 12},
  [63] = {.lex_state = 12},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 12},
  [67] = {.lex_state = 12},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 12},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 12},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 12},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 12},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 0},
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
    [anon_sym_abstract] = ACTIONS(1),
    [anon_sym_asset] = ACTIONS(1),
    [anon_sym_extends] = ACTIONS(1),
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
    [sym_source_file] = STATE(80),
    [sym_declaration] = STATE(2),
    [sym_include_declaration] = STATE(5),
    [sym_category_declaration] = STATE(5),
    [sym_define_declaration] = STATE(5),
    [sym_associations_declaration] = STATE(5),
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
    STATE(5), 4,
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
    STATE(5), 4,
      sym_include_declaration,
      sym_category_declaration,
      sym_define_declaration,
      sym_associations_declaration,
  [58] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [69] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(33), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [80] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(35), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [91] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(37), 1,
      anon_sym_RBRACE,
    ACTIONS(39), 1,
      anon_sym_abstract,
    ACTIONS(41), 1,
      anon_sym_asset,
    STATE(8), 2,
      sym_asset,
      aux_sym_category_declaration_repeat2,
  [108] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(39), 1,
      anon_sym_abstract,
    ACTIONS(41), 1,
      anon_sym_asset,
    ACTIONS(43), 1,
      anon_sym_RBRACE,
    STATE(16), 2,
      sym_asset,
      aux_sym_category_declaration_repeat2,
  [125] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(45), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [136] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(47), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [147] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(49), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [158] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      sym_identity,
    ACTIONS(54), 2,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
    STATE(12), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [173] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(39), 1,
      anon_sym_abstract,
    ACTIONS(41), 1,
      anon_sym_asset,
    ACTIONS(56), 1,
      anon_sym_RBRACE,
    STATE(18), 2,
      sym_asset,
      aux_sym_category_declaration_repeat2,
  [190] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(58), 1,
      sym_identity,
    ACTIONS(60), 1,
      anon_sym_LBRACE,
    ACTIONS(62), 1,
      anon_sym_extends,
    STATE(27), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [207] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(64), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [218] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(66), 1,
      anon_sym_RBRACE,
    ACTIONS(68), 1,
      anon_sym_abstract,
    ACTIONS(71), 1,
      anon_sym_asset,
    STATE(16), 2,
      sym_asset,
      aux_sym_category_declaration_repeat2,
  [235] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(74), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [246] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(39), 1,
      anon_sym_abstract,
    ACTIONS(41), 1,
      anon_sym_asset,
    ACTIONS(76), 1,
      anon_sym_RBRACE,
    STATE(16), 2,
      sym_asset,
      aux_sym_category_declaration_repeat2,
  [263] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(58), 1,
      sym_identity,
    ACTIONS(78), 1,
      anon_sym_LBRACE,
    ACTIONS(80), 1,
      anon_sym_extends,
    STATE(29), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [280] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(82), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [291] = 5,
    ACTIONS(3), 1,
      sym_comment,
    STATE(39), 1,
      sym__multiplicity_atom,
    STATE(47), 1,
      sym_multiplicity_range,
    STATE(53), 1,
      sym_multiplicity,
    ACTIONS(84), 2,
      sym_integer,
      sym_star,
  [308] = 5,
    ACTIONS(3), 1,
      sym_comment,
    STATE(39), 1,
      sym__multiplicity_atom,
    STATE(47), 1,
      sym_multiplicity_range,
    STATE(76), 1,
      sym_multiplicity,
    ACTIONS(84), 2,
      sym_integer,
      sym_star,
  [325] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(86), 1,
      sym_identity,
    ACTIONS(88), 1,
      anon_sym_RBRACE,
    STATE(26), 2,
      sym_association,
      aux_sym_associations_declaration_repeat1,
  [339] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(90), 1,
      sym_identity,
    ACTIONS(92), 1,
      anon_sym_LBRACE,
    STATE(12), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [353] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(90), 1,
      sym_identity,
    ACTIONS(94), 1,
      anon_sym_LBRACE,
    STATE(24), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [367] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(96), 1,
      sym_identity,
    ACTIONS(99), 1,
      anon_sym_RBRACE,
    STATE(26), 2,
      sym_association,
      aux_sym_associations_declaration_repeat1,
  [381] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(90), 1,
      sym_identity,
    ACTIONS(101), 1,
      anon_sym_LBRACE,
    STATE(12), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [395] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(86), 1,
      sym_identity,
    ACTIONS(103), 1,
      anon_sym_RBRACE,
    STATE(23), 2,
      sym_association,
      aux_sym_associations_declaration_repeat1,
  [409] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(90), 1,
      sym_identity,
    ACTIONS(105), 1,
      anon_sym_LBRACE,
    STATE(12), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [423] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(90), 1,
      sym_identity,
    ACTIONS(107), 1,
      anon_sym_LBRACE,
    STATE(32), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [437] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(90), 1,
      sym_identity,
    ACTIONS(109), 1,
      anon_sym_LBRACE,
    STATE(33), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [451] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(90), 1,
      sym_identity,
    ACTIONS(111), 1,
      anon_sym_LBRACE,
    STATE(12), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [465] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(90), 1,
      sym_identity,
    ACTIONS(113), 1,
      anon_sym_LBRACE,
    STATE(12), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [479] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(115), 1,
      sym_identity,
    ACTIONS(118), 1,
      anon_sym_RBRACE,
    STATE(35), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [493] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(120), 1,
      sym_identity,
    ACTIONS(123), 1,
      anon_sym_RBRACE,
    STATE(12), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [507] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(125), 3,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_identity,
  [516] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(127), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [525] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(129), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [534] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(133), 1,
      anon_sym_DOT_DOT,
    ACTIONS(131), 2,
      anon_sym_LBRACK,
      anon_sym_LT_DASH_DASH,
  [545] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(135), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [554] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(137), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [563] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(139), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [572] = 3,
    ACTIONS(3), 1,
      sym_comment,
    STATE(48), 1,
      sym__multiplicity_atom,
    ACTIONS(141), 2,
      sym_integer,
      sym_star,
  [583] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(143), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [592] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(145), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [601] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(147), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [610] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(131), 2,
      anon_sym_LBRACK,
      anon_sym_LT_DASH_DASH,
  [618] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(149), 2,
      anon_sym_LBRACK,
      anon_sym_LT_DASH_DASH,
  [626] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(151), 1,
      anon_sym_LBRACE,
  [633] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(153), 1,
      sym_identity,
  [640] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(155), 1,
      sym_string,
  [647] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(157), 1,
      anon_sym_RBRACE,
  [654] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(159), 1,
      anon_sym_LT_DASH_DASH,
  [661] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(161), 1,
      sym_string,
  [668] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(163), 1,
      anon_sym_RBRACE,
  [675] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(165), 1,
      sym_identity,
  [682] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(167), 1,
      anon_sym_asset,
  [689] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(169), 1,
      anon_sym_RBRACE,
  [696] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(171), 1,
      anon_sym_RBRACE,
  [703] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(173), 1,
      sym_identity,
  [710] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(175), 1,
      anon_sym_COLON,
  [717] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(177), 1,
      sym_identity,
  [724] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(179), 1,
      sym_identity,
  [731] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(181), 1,
      anon_sym_RBRACE,
  [738] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(183), 1,
      anon_sym_LBRACK,
  [745] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(185), 1,
      anon_sym_info,
  [752] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(187), 1,
      sym_identity,
  [759] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(189), 1,
      anon_sym_RBRACE,
  [766] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(191), 1,
      anon_sym_DASH_DASH_GT,
  [773] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(193), 1,
      anon_sym_RBRACE,
  [780] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(195), 1,
      sym_identity,
  [787] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(197), 1,
      anon_sym_RBRACE,
  [794] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(199), 1,
      sym_identity,
  [801] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(201), 1,
      anon_sym_COLON,
  [808] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(203), 1,
      anon_sym_RBRACK,
  [815] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(205), 1,
      anon_sym_LBRACK,
  [822] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(207), 1,
      sym_identity,
  [829] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(209), 1,
      anon_sym_RBRACK,
  [836] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(211), 1,
      sym_identity,
  [843] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(213), 1,
      ts_builtin_sym_end,
  [850] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(215), 1,
      sym_string,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 29,
  [SMALL_STATE(4)] = 58,
  [SMALL_STATE(5)] = 69,
  [SMALL_STATE(6)] = 80,
  [SMALL_STATE(7)] = 91,
  [SMALL_STATE(8)] = 108,
  [SMALL_STATE(9)] = 125,
  [SMALL_STATE(10)] = 136,
  [SMALL_STATE(11)] = 147,
  [SMALL_STATE(12)] = 158,
  [SMALL_STATE(13)] = 173,
  [SMALL_STATE(14)] = 190,
  [SMALL_STATE(15)] = 207,
  [SMALL_STATE(16)] = 218,
  [SMALL_STATE(17)] = 235,
  [SMALL_STATE(18)] = 246,
  [SMALL_STATE(19)] = 263,
  [SMALL_STATE(20)] = 280,
  [SMALL_STATE(21)] = 291,
  [SMALL_STATE(22)] = 308,
  [SMALL_STATE(23)] = 325,
  [SMALL_STATE(24)] = 339,
  [SMALL_STATE(25)] = 353,
  [SMALL_STATE(26)] = 367,
  [SMALL_STATE(27)] = 381,
  [SMALL_STATE(28)] = 395,
  [SMALL_STATE(29)] = 409,
  [SMALL_STATE(30)] = 423,
  [SMALL_STATE(31)] = 437,
  [SMALL_STATE(32)] = 451,
  [SMALL_STATE(33)] = 465,
  [SMALL_STATE(34)] = 479,
  [SMALL_STATE(35)] = 493,
  [SMALL_STATE(36)] = 507,
  [SMALL_STATE(37)] = 516,
  [SMALL_STATE(38)] = 525,
  [SMALL_STATE(39)] = 534,
  [SMALL_STATE(40)] = 545,
  [SMALL_STATE(41)] = 554,
  [SMALL_STATE(42)] = 563,
  [SMALL_STATE(43)] = 572,
  [SMALL_STATE(44)] = 583,
  [SMALL_STATE(45)] = 592,
  [SMALL_STATE(46)] = 601,
  [SMALL_STATE(47)] = 610,
  [SMALL_STATE(48)] = 618,
  [SMALL_STATE(49)] = 626,
  [SMALL_STATE(50)] = 633,
  [SMALL_STATE(51)] = 640,
  [SMALL_STATE(52)] = 647,
  [SMALL_STATE(53)] = 654,
  [SMALL_STATE(54)] = 661,
  [SMALL_STATE(55)] = 668,
  [SMALL_STATE(56)] = 675,
  [SMALL_STATE(57)] = 682,
  [SMALL_STATE(58)] = 689,
  [SMALL_STATE(59)] = 696,
  [SMALL_STATE(60)] = 703,
  [SMALL_STATE(61)] = 710,
  [SMALL_STATE(62)] = 717,
  [SMALL_STATE(63)] = 724,
  [SMALL_STATE(64)] = 731,
  [SMALL_STATE(65)] = 738,
  [SMALL_STATE(66)] = 745,
  [SMALL_STATE(67)] = 752,
  [SMALL_STATE(68)] = 759,
  [SMALL_STATE(69)] = 766,
  [SMALL_STATE(70)] = 773,
  [SMALL_STATE(71)] = 780,
  [SMALL_STATE(72)] = 787,
  [SMALL_STATE(73)] = 794,
  [SMALL_STATE(74)] = 801,
  [SMALL_STATE(75)] = 808,
  [SMALL_STATE(76)] = 815,
  [SMALL_STATE(77)] = 822,
  [SMALL_STATE(78)] = 829,
  [SMALL_STATE(79)] = 836,
  [SMALL_STATE(80)] = 843,
  [SMALL_STATE(81)] = 850,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [19] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(54),
  [22] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(63),
  [25] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(67),
  [28] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(49),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_associations_declaration, 4, 0, 0),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_declaration, 1, 0, 0),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_declaration, 2, 0, 1),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_associations_declaration, 3, 0, 0),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_define_declaration, 4, 0, 3),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_category_declaration, 4, 0, 2),
  [51] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_category_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(66),
  [54] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_category_declaration_repeat1, 2, 0, 0),
  [56] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [58] = {.entry = {.count = 1, .reusable = false}}, SHIFT(66),
  [60] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [62] = {.entry = {.count = 1, .reusable = false}}, SHIFT(56),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_category_declaration, 5, 0, 4),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_category_declaration_repeat2, 2, 0, 0),
  [68] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_category_declaration_repeat2, 2, 0, 0), SHIFT_REPEAT(57),
  [71] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_category_declaration_repeat2, 2, 0, 0), SHIFT_REPEAT(50),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_category_declaration, 5, 0, 5),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [78] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [80] = {.entry = {.count = 1, .reusable = false}}, SHIFT(71),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_category_declaration, 6, 0, 7),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [86] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [88] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [90] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [92] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [94] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [96] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_associations_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(65),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_associations_declaration_repeat1, 2, 0, 0),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [115] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_association, 13, 0, 15), SHIFT(66),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_association, 13, 0, 15),
  [120] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_association, 14, 0, 16), SHIFT(66),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_association, 14, 0, 16),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_meta, 4, 0, 6),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 8, 0, 14),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 4, 0, 2),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multiplicity, 1, 0, 0),
  [133] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 6, 0, 10),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 5, 0, 8),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 5, 0, 5),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 6, 0, 9),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 7, 0, 12),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 7, 0, 13),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multiplicity_range, 3, 0, 11),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [197] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [213] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
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
