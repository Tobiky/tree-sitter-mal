#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 101
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 44
#define ALIAS_COUNT 0
#define TOKEN_COUNT 26
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 17
#define MAX_ALIAS_SEQUENCE_LENGTH 14
#define PRODUCTION_ID_COUNT 26

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
  anon_sym_PIPE = 10,
  anon_sym_AMP = 11,
  anon_sym_POUND = 12,
  anon_sym_E = 13,
  anon_sym_BANGE = 14,
  anon_sym_COLON = 15,
  anon_sym_associations = 16,
  anon_sym_LBRACK = 17,
  anon_sym_RBRACK = 18,
  anon_sym_LT_DASH_DASH = 19,
  anon_sym_DASH_DASH_GT = 20,
  anon_sym_DOT_DOT = 21,
  anon_sym_info = 22,
  sym_string = 23,
  sym_integer = 24,
  sym_star = 25,
  sym_source_file = 26,
  sym_declaration = 27,
  sym_include_declaration = 28,
  sym_category_declaration = 29,
  sym_asset = 30,
  sym_attack_step = 31,
  sym_define_declaration = 32,
  sym_associations_declaration = 33,
  sym_association = 34,
  sym_multiplicity = 35,
  sym__multiplicity_atom = 36,
  sym_multiplicity_range = 37,
  sym_meta = 38,
  aux_sym_source_file_repeat1 = 39,
  aux_sym_category_declaration_repeat1 = 40,
  aux_sym_category_declaration_repeat2 = 41,
  aux_sym_asset_repeat1 = 42,
  aux_sym_associations_declaration_repeat1 = 43,
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
  [anon_sym_PIPE] = "|",
  [anon_sym_AMP] = "&",
  [anon_sym_POUND] = "#",
  [anon_sym_E] = "E",
  [anon_sym_BANGE] = "!E",
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
  [sym_attack_step] = "attack_step",
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
  [aux_sym_asset_repeat1] = "asset_repeat1",
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
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_AMP] = anon_sym_AMP,
  [anon_sym_POUND] = anon_sym_POUND,
  [anon_sym_E] = anon_sym_E,
  [anon_sym_BANGE] = anon_sym_BANGE,
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
  [sym_attack_step] = sym_attack_step,
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
  [aux_sym_asset_repeat1] = aux_sym_asset_repeat1,
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
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUND] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_E] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANGE] = {
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
  [sym_attack_step] = {
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
  [aux_sym_asset_repeat1] = {
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
  field_body = 2,
  field_end = 3,
  field_extends = 4,
  field_file = 5,
  field_id = 6,
  field_info = 7,
  field_left_field_id = 8,
  field_left_id = 9,
  field_left_mult = 10,
  field_meta = 11,
  field_right_field_id = 12,
  field_right_id = 13,
  field_right_mult = 14,
  field_start = 15,
  field_step_type = 16,
  field_value = 17,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_assets] = "assets",
  [field_body] = "body",
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
  [field_step_type] = "step_type",
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
  [10] = {.index = 16, .length = 2},
  [11] = {.index = 18, .length = 2},
  [12] = {.index = 20, .length = 2},
  [13] = {.index = 22, .length = 3},
  [14] = {.index = 25, .length = 3},
  [15] = {.index = 28, .length = 2},
  [16] = {.index = 30, .length = 3},
  [17] = {.index = 33, .length = 3},
  [18] = {.index = 36, .length = 4},
  [19] = {.index = 40, .length = 4},
  [20] = {.index = 44, .length = 4},
  [21] = {.index = 48, .length = 4},
  [22] = {.index = 52, .length = 5},
  [23] = {.index = 57, .length = 5},
  [24] = {.index = 62, .length = 7},
  [25] = {.index = 69, .length = 8},
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
    {field_id, 1},
    {field_step_type, 0},
  [16] =
    {field_body, 3},
    {field_id, 1},
  [18] =
    {field_body, 4},
    {field_id, 2},
  [20] =
    {field_id, 2},
    {field_meta, 3},
  [22] =
    {field_extends, 2},
    {field_extends, 3},
    {field_id, 1},
  [25] =
    {field_body, 4},
    {field_id, 1},
    {field_meta, 2},
  [28] =
    {field_end, 2},
    {field_start, 0},
  [30] =
    {field_extends, 3},
    {field_extends, 4},
    {field_id, 2},
  [33] =
    {field_body, 5},
    {field_id, 2},
    {field_meta, 3},
  [36] =
    {field_body, 5},
    {field_extends, 2},
    {field_extends, 3},
    {field_id, 1},
  [40] =
    {field_extends, 2},
    {field_extends, 3},
    {field_id, 1},
    {field_meta, 4},
  [44] =
    {field_body, 6},
    {field_extends, 3},
    {field_extends, 4},
    {field_id, 2},
  [48] =
    {field_extends, 3},
    {field_extends, 4},
    {field_id, 2},
    {field_meta, 5},
  [52] =
    {field_body, 6},
    {field_extends, 2},
    {field_extends, 3},
    {field_id, 1},
    {field_meta, 4},
  [57] =
    {field_body, 7},
    {field_extends, 3},
    {field_extends, 4},
    {field_id, 2},
    {field_meta, 5},
  [62] =
    {field_id, 6},
    {field_left_field_id, 2},
    {field_left_id, 0},
    {field_left_mult, 4},
    {field_right_field_id, 10},
    {field_right_id, 12},
    {field_right_mult, 8},
  [69] =
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
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 100,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(14);
      ADVANCE_MAP(
        '!', 12,
        '"', 1,
        '#', 21,
        '&', 20,
        '*', 34,
        '-', 7,
        '.', 10,
        '/', 4,
        ':', 23,
        '<', 9,
        '[', 24,
        ']', 25,
        '{', 17,
        '|', 19,
        '}', 18,
      );
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(31);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(29);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(30);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 3:
      if (lookahead == '*') ADVANCE(34);
      if (lookahead == '/') ADVANCE(4);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(32);
      END_STATE();
    case 4:
      if (lookahead == '*') ADVANCE(6);
      if (lookahead == '/') ADVANCE(16);
      END_STATE();
    case 5:
      if (lookahead == '*') ADVANCE(5);
      if (lookahead == '/') ADVANCE(15);
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
      if (lookahead == '-') ADVANCE(26);
      END_STATE();
    case 9:
      if (lookahead == '-') ADVANCE(8);
      END_STATE();
    case 10:
      if (lookahead == '.') ADVANCE(28);
      END_STATE();
    case 11:
      if (lookahead == '>') ADVANCE(27);
      END_STATE();
    case 12:
      if (lookahead == 'E') ADVANCE(22);
      END_STATE();
    case 13:
      if (eof) ADVANCE(14);
      if (lookahead == '!') ADVANCE(12);
      if (lookahead == '#') ADVANCE(21);
      if (lookahead == '&') ADVANCE(20);
      if (lookahead == '/') ADVANCE(4);
      if (lookahead == '{') ADVANCE(17);
      if (lookahead == '|') ADVANCE(19);
      if (lookahead == '}') ADVANCE(18);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) ADVANCE(16);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_AMP);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_BANGE);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_LT_DASH_DASH);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_DASH_DASH_GT);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_DOT_DOT);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_string);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_string);
      if (lookahead == '"') ADVANCE(29);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_integer);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(31);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_integer);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(32);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_identity);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 34:
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
      if (lookahead == 'E') ADVANCE(1);
      if (lookahead == 'a') ADVANCE(2);
      if (lookahead == 'c') ADVANCE(3);
      if (lookahead == 'e') ADVANCE(4);
      if (lookahead == 'i') ADVANCE(5);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      ACCEPT_TOKEN(anon_sym_E);
      END_STATE();
    case 2:
      if (lookahead == 'b') ADVANCE(6);
      if (lookahead == 's') ADVANCE(7);
      END_STATE();
    case 3:
      if (lookahead == 'a') ADVANCE(8);
      END_STATE();
    case 4:
      if (lookahead == 'x') ADVANCE(9);
      END_STATE();
    case 5:
      if (lookahead == 'n') ADVANCE(10);
      END_STATE();
    case 6:
      if (lookahead == 's') ADVANCE(11);
      END_STATE();
    case 7:
      if (lookahead == 's') ADVANCE(12);
      END_STATE();
    case 8:
      if (lookahead == 't') ADVANCE(13);
      END_STATE();
    case 9:
      if (lookahead == 't') ADVANCE(14);
      END_STATE();
    case 10:
      if (lookahead == 'c') ADVANCE(15);
      if (lookahead == 'f') ADVANCE(16);
      END_STATE();
    case 11:
      if (lookahead == 't') ADVANCE(17);
      END_STATE();
    case 12:
      if (lookahead == 'e') ADVANCE(18);
      if (lookahead == 'o') ADVANCE(19);
      END_STATE();
    case 13:
      if (lookahead == 'e') ADVANCE(20);
      END_STATE();
    case 14:
      if (lookahead == 'e') ADVANCE(21);
      END_STATE();
    case 15:
      if (lookahead == 'l') ADVANCE(22);
      END_STATE();
    case 16:
      if (lookahead == 'o') ADVANCE(23);
      END_STATE();
    case 17:
      if (lookahead == 'r') ADVANCE(24);
      END_STATE();
    case 18:
      if (lookahead == 't') ADVANCE(25);
      END_STATE();
    case 19:
      if (lookahead == 'c') ADVANCE(26);
      END_STATE();
    case 20:
      if (lookahead == 'g') ADVANCE(27);
      END_STATE();
    case 21:
      if (lookahead == 'n') ADVANCE(28);
      END_STATE();
    case 22:
      if (lookahead == 'u') ADVANCE(29);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_info);
      END_STATE();
    case 24:
      if (lookahead == 'a') ADVANCE(30);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_asset);
      END_STATE();
    case 26:
      if (lookahead == 'i') ADVANCE(31);
      END_STATE();
    case 27:
      if (lookahead == 'o') ADVANCE(32);
      END_STATE();
    case 28:
      if (lookahead == 'd') ADVANCE(33);
      END_STATE();
    case 29:
      if (lookahead == 'd') ADVANCE(34);
      END_STATE();
    case 30:
      if (lookahead == 'c') ADVANCE(35);
      END_STATE();
    case 31:
      if (lookahead == 'a') ADVANCE(36);
      END_STATE();
    case 32:
      if (lookahead == 'r') ADVANCE(37);
      END_STATE();
    case 33:
      if (lookahead == 's') ADVANCE(38);
      END_STATE();
    case 34:
      if (lookahead == 'e') ADVANCE(39);
      END_STATE();
    case 35:
      if (lookahead == 't') ADVANCE(40);
      END_STATE();
    case 36:
      if (lookahead == 't') ADVANCE(41);
      END_STATE();
    case 37:
      if (lookahead == 'y') ADVANCE(42);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_extends);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_include);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_abstract);
      END_STATE();
    case 41:
      if (lookahead == 'i') ADVANCE(43);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_category);
      END_STATE();
    case 43:
      if (lookahead == 'o') ADVANCE(44);
      END_STATE();
    case 44:
      if (lookahead == 'n') ADVANCE(45);
      END_STATE();
    case 45:
      if (lookahead == 's') ADVANCE(46);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_associations);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 13},
  [2] = {.lex_state = 13},
  [3] = {.lex_state = 13},
  [4] = {.lex_state = 13},
  [5] = {.lex_state = 13},
  [6] = {.lex_state = 13},
  [7] = {.lex_state = 13},
  [8] = {.lex_state = 13},
  [9] = {.lex_state = 13},
  [10] = {.lex_state = 13},
  [11] = {.lex_state = 13},
  [12] = {.lex_state = 13},
  [13] = {.lex_state = 13},
  [14] = {.lex_state = 13},
  [15] = {.lex_state = 13},
  [16] = {.lex_state = 13},
  [17] = {.lex_state = 13},
  [18] = {.lex_state = 13},
  [19] = {.lex_state = 13},
  [20] = {.lex_state = 13},
  [21] = {.lex_state = 13},
  [22] = {.lex_state = 13},
  [23] = {.lex_state = 13},
  [24] = {.lex_state = 13},
  [25] = {.lex_state = 13},
  [26] = {.lex_state = 13},
  [27] = {.lex_state = 13},
  [28] = {.lex_state = 13},
  [29] = {.lex_state = 13},
  [30] = {.lex_state = 13},
  [31] = {.lex_state = 13},
  [32] = {.lex_state = 13},
  [33] = {.lex_state = 13},
  [34] = {.lex_state = 13},
  [35] = {.lex_state = 3},
  [36] = {.lex_state = 13},
  [37] = {.lex_state = 13},
  [38] = {.lex_state = 13},
  [39] = {.lex_state = 13},
  [40] = {.lex_state = 3},
  [41] = {.lex_state = 13},
  [42] = {.lex_state = 13},
  [43] = {.lex_state = 13},
  [44] = {.lex_state = 13},
  [45] = {.lex_state = 13},
  [46] = {.lex_state = 13},
  [47] = {.lex_state = 13},
  [48] = {.lex_state = 13},
  [49] = {.lex_state = 13},
  [50] = {.lex_state = 13},
  [51] = {.lex_state = 13},
  [52] = {.lex_state = 13},
  [53] = {.lex_state = 13},
  [54] = {.lex_state = 3},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 13},
  [57] = {.lex_state = 13},
  [58] = {.lex_state = 13},
  [59] = {.lex_state = 13},
  [60] = {.lex_state = 13},
  [61] = {.lex_state = 13},
  [62] = {.lex_state = 13},
  [63] = {.lex_state = 13},
  [64] = {.lex_state = 13},
  [65] = {.lex_state = 13},
  [66] = {.lex_state = 13},
  [67] = {.lex_state = 13},
  [68] = {.lex_state = 13},
  [69] = {.lex_state = 13},
  [70] = {.lex_state = 13},
  [71] = {.lex_state = 13},
  [72] = {.lex_state = 13},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 13},
  [76] = {.lex_state = 13},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 13},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 13},
  [82] = {.lex_state = 13},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 13},
  [86] = {.lex_state = 13},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 13},
  [91] = {.lex_state = 13},
  [92] = {.lex_state = 13},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 13},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 13},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 13},
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
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_AMP] = ACTIONS(1),
    [anon_sym_POUND] = ACTIONS(1),
    [anon_sym_E] = ACTIONS(1),
    [anon_sym_BANGE] = ACTIONS(1),
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
    [sym_source_file] = STATE(93),
    [sym_declaration] = STATE(2),
    [sym_include_declaration] = STATE(22),
    [sym_category_declaration] = STATE(22),
    [sym_define_declaration] = STATE(22),
    [sym_associations_declaration] = STATE(22),
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
    STATE(22), 4,
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
    STATE(22), 4,
      sym_include_declaration,
      sym_category_declaration,
      sym_define_declaration,
      sym_associations_declaration,
  [58] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_RBRACE,
    STATE(6), 2,
      sym_attack_step,
      aux_sym_asset_repeat1,
    ACTIONS(33), 5,
      anon_sym_PIPE,
      anon_sym_AMP,
      anon_sym_POUND,
      anon_sym_E,
      anon_sym_BANGE,
  [76] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(35), 1,
      anon_sym_RBRACE,
    STATE(8), 2,
      sym_attack_step,
      aux_sym_asset_repeat1,
    ACTIONS(33), 5,
      anon_sym_PIPE,
      anon_sym_AMP,
      anon_sym_POUND,
      anon_sym_E,
      anon_sym_BANGE,
  [94] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(37), 1,
      anon_sym_RBRACE,
    STATE(10), 2,
      sym_attack_step,
      aux_sym_asset_repeat1,
    ACTIONS(33), 5,
      anon_sym_PIPE,
      anon_sym_AMP,
      anon_sym_POUND,
      anon_sym_E,
      anon_sym_BANGE,
  [112] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(39), 1,
      anon_sym_RBRACE,
    STATE(12), 2,
      sym_attack_step,
      aux_sym_asset_repeat1,
    ACTIONS(33), 5,
      anon_sym_PIPE,
      anon_sym_AMP,
      anon_sym_POUND,
      anon_sym_E,
      anon_sym_BANGE,
  [130] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(41), 1,
      anon_sym_RBRACE,
    STATE(10), 2,
      sym_attack_step,
      aux_sym_asset_repeat1,
    ACTIONS(33), 5,
      anon_sym_PIPE,
      anon_sym_AMP,
      anon_sym_POUND,
      anon_sym_E,
      anon_sym_BANGE,
  [148] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(43), 1,
      anon_sym_RBRACE,
    STATE(14), 2,
      sym_attack_step,
      aux_sym_asset_repeat1,
    ACTIONS(33), 5,
      anon_sym_PIPE,
      anon_sym_AMP,
      anon_sym_POUND,
      anon_sym_E,
      anon_sym_BANGE,
  [166] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(45), 1,
      anon_sym_RBRACE,
    STATE(10), 2,
      sym_attack_step,
      aux_sym_asset_repeat1,
    ACTIONS(47), 5,
      anon_sym_PIPE,
      anon_sym_AMP,
      anon_sym_POUND,
      anon_sym_E,
      anon_sym_BANGE,
  [184] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(50), 1,
      anon_sym_RBRACE,
    STATE(15), 2,
      sym_attack_step,
      aux_sym_asset_repeat1,
    ACTIONS(33), 5,
      anon_sym_PIPE,
      anon_sym_AMP,
      anon_sym_POUND,
      anon_sym_E,
      anon_sym_BANGE,
  [202] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(52), 1,
      anon_sym_RBRACE,
    STATE(10), 2,
      sym_attack_step,
      aux_sym_asset_repeat1,
    ACTIONS(33), 5,
      anon_sym_PIPE,
      anon_sym_AMP,
      anon_sym_POUND,
      anon_sym_E,
      anon_sym_BANGE,
  [220] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(54), 1,
      anon_sym_RBRACE,
    STATE(17), 2,
      sym_attack_step,
      aux_sym_asset_repeat1,
    ACTIONS(33), 5,
      anon_sym_PIPE,
      anon_sym_AMP,
      anon_sym_POUND,
      anon_sym_E,
      anon_sym_BANGE,
  [238] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(56), 1,
      anon_sym_RBRACE,
    STATE(10), 2,
      sym_attack_step,
      aux_sym_asset_repeat1,
    ACTIONS(33), 5,
      anon_sym_PIPE,
      anon_sym_AMP,
      anon_sym_POUND,
      anon_sym_E,
      anon_sym_BANGE,
  [256] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(58), 1,
      anon_sym_RBRACE,
    STATE(10), 2,
      sym_attack_step,
      aux_sym_asset_repeat1,
    ACTIONS(33), 5,
      anon_sym_PIPE,
      anon_sym_AMP,
      anon_sym_POUND,
      anon_sym_E,
      anon_sym_BANGE,
  [274] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(60), 1,
      anon_sym_RBRACE,
    STATE(19), 2,
      sym_attack_step,
      aux_sym_asset_repeat1,
    ACTIONS(33), 5,
      anon_sym_PIPE,
      anon_sym_AMP,
      anon_sym_POUND,
      anon_sym_E,
      anon_sym_BANGE,
  [292] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(62), 1,
      anon_sym_RBRACE,
    STATE(10), 2,
      sym_attack_step,
      aux_sym_asset_repeat1,
    ACTIONS(33), 5,
      anon_sym_PIPE,
      anon_sym_AMP,
      anon_sym_POUND,
      anon_sym_E,
      anon_sym_BANGE,
  [310] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(64), 1,
      anon_sym_RBRACE,
    STATE(20), 2,
      sym_attack_step,
      aux_sym_asset_repeat1,
    ACTIONS(33), 5,
      anon_sym_PIPE,
      anon_sym_AMP,
      anon_sym_POUND,
      anon_sym_E,
      anon_sym_BANGE,
  [328] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(66), 1,
      anon_sym_RBRACE,
    STATE(10), 2,
      sym_attack_step,
      aux_sym_asset_repeat1,
    ACTIONS(33), 5,
      anon_sym_PIPE,
      anon_sym_AMP,
      anon_sym_POUND,
      anon_sym_E,
      anon_sym_BANGE,
  [346] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(68), 1,
      anon_sym_RBRACE,
    STATE(10), 2,
      sym_attack_step,
      aux_sym_asset_repeat1,
    ACTIONS(33), 5,
      anon_sym_PIPE,
      anon_sym_AMP,
      anon_sym_POUND,
      anon_sym_E,
      anon_sym_BANGE,
  [364] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(70), 6,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      anon_sym_AMP,
      anon_sym_POUND,
      anon_sym_E,
      anon_sym_BANGE,
  [376] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(72), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [387] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(74), 1,
      anon_sym_RBRACE,
    ACTIONS(76), 1,
      anon_sym_abstract,
    ACTIONS(78), 1,
      anon_sym_asset,
    STATE(30), 2,
      sym_asset,
      aux_sym_category_declaration_repeat2,
  [404] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_abstract,
    ACTIONS(78), 1,
      anon_sym_asset,
    ACTIONS(80), 1,
      anon_sym_RBRACE,
    STATE(32), 2,
      sym_asset,
      aux_sym_category_declaration_repeat2,
  [421] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(82), 1,
      sym_identity,
    ACTIONS(85), 2,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
    STATE(25), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [436] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(87), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [447] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(89), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [458] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(91), 1,
      sym_identity,
    ACTIONS(93), 1,
      anon_sym_LBRACE,
    ACTIONS(95), 1,
      anon_sym_extends,
    STATE(42), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [475] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(97), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [486] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(99), 1,
      anon_sym_RBRACE,
    ACTIONS(101), 1,
      anon_sym_abstract,
    ACTIONS(104), 1,
      anon_sym_asset,
    STATE(30), 2,
      sym_asset,
      aux_sym_category_declaration_repeat2,
  [503] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(107), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [514] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_abstract,
    ACTIONS(78), 1,
      anon_sym_asset,
    ACTIONS(109), 1,
      anon_sym_RBRACE,
    STATE(30), 2,
      sym_asset,
      aux_sym_category_declaration_repeat2,
  [531] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(91), 1,
      sym_identity,
    ACTIONS(111), 1,
      anon_sym_LBRACE,
    ACTIONS(113), 1,
      anon_sym_extends,
    STATE(44), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [548] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(115), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [559] = 5,
    ACTIONS(3), 1,
      sym_comment,
    STATE(55), 1,
      sym__multiplicity_atom,
    STATE(73), 1,
      sym_multiplicity_range,
    STATE(95), 1,
      sym_multiplicity,
    ACTIONS(117), 2,
      sym_integer,
      sym_star,
  [576] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(119), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [587] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(76), 1,
      anon_sym_abstract,
    ACTIONS(78), 1,
      anon_sym_asset,
    ACTIONS(121), 1,
      anon_sym_RBRACE,
    STATE(23), 2,
      sym_asset,
      aux_sym_category_declaration_repeat2,
  [604] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(123), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [615] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(125), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [626] = 5,
    ACTIONS(3), 1,
      sym_comment,
    STATE(55), 1,
      sym__multiplicity_atom,
    STATE(73), 1,
      sym_multiplicity_range,
    STATE(94), 1,
      sym_multiplicity,
    ACTIONS(117), 2,
      sym_integer,
      sym_star,
  [643] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(127), 1,
      sym_identity,
    ACTIONS(129), 1,
      anon_sym_LBRACE,
    STATE(25), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [657] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(127), 1,
      sym_identity,
    ACTIONS(131), 1,
      anon_sym_LBRACE,
    STATE(25), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [671] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(133), 1,
      sym_identity,
    ACTIONS(136), 1,
      anon_sym_RBRACE,
    STATE(43), 2,
      sym_association,
      aux_sym_associations_declaration_repeat1,
  [685] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(127), 1,
      sym_identity,
    ACTIONS(138), 1,
      anon_sym_LBRACE,
    STATE(25), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [699] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(127), 1,
      sym_identity,
    ACTIONS(140), 1,
      anon_sym_LBRACE,
    STATE(41), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [713] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(127), 1,
      sym_identity,
    ACTIONS(142), 1,
      anon_sym_LBRACE,
    STATE(49), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [727] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(127), 1,
      sym_identity,
    ACTIONS(144), 1,
      anon_sym_LBRACE,
    STATE(50), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [741] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(146), 1,
      sym_identity,
    ACTIONS(148), 1,
      anon_sym_RBRACE,
    STATE(51), 2,
      sym_association,
      aux_sym_associations_declaration_repeat1,
  [755] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(127), 1,
      sym_identity,
    ACTIONS(150), 1,
      anon_sym_LBRACE,
    STATE(25), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [769] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(127), 1,
      sym_identity,
    ACTIONS(152), 1,
      anon_sym_LBRACE,
    STATE(25), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [783] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(146), 1,
      sym_identity,
    ACTIONS(154), 1,
      anon_sym_RBRACE,
    STATE(43), 2,
      sym_association,
      aux_sym_associations_declaration_repeat1,
  [797] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(156), 1,
      sym_identity,
    ACTIONS(159), 1,
      anon_sym_RBRACE,
    STATE(53), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [811] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(161), 1,
      sym_identity,
    ACTIONS(164), 1,
      anon_sym_RBRACE,
    STATE(25), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [825] = 3,
    ACTIONS(3), 1,
      sym_comment,
    STATE(74), 1,
      sym__multiplicity_atom,
    ACTIONS(166), 2,
      sym_integer,
      sym_star,
  [836] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(170), 1,
      anon_sym_DOT_DOT,
    ACTIONS(168), 2,
      anon_sym_LBRACK,
      anon_sym_LT_DASH_DASH,
  [847] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(172), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [856] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(174), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [865] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(176), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [874] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(178), 3,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_identity,
  [883] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(180), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [892] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(182), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [901] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(184), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [910] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(186), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [919] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(188), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [928] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(190), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [937] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(192), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [946] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(194), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [955] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(196), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [964] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(198), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [973] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(200), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [982] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(202), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [991] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(204), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [1000] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(168), 2,
      anon_sym_LBRACK,
      anon_sym_LT_DASH_DASH,
  [1008] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(206), 2,
      anon_sym_LBRACK,
      anon_sym_LT_DASH_DASH,
  [1016] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(208), 1,
      sym_identity,
  [1023] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(210), 1,
      sym_identity,
  [1030] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(212), 1,
      sym_string,
  [1037] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(214), 1,
      anon_sym_RBRACK,
  [1044] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(216), 1,
      sym_identity,
  [1051] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(218), 1,
      anon_sym_DASH_DASH_GT,
  [1058] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(220), 1,
      sym_identity,
  [1065] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(222), 1,
      sym_identity,
  [1072] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(224), 1,
      anon_sym_LBRACK,
  [1079] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(226), 1,
      sym_string,
  [1086] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(228), 1,
      sym_identity,
  [1093] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(230), 1,
      sym_identity,
  [1100] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(232), 1,
      anon_sym_COLON,
  [1107] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(234), 1,
      anon_sym_COLON,
  [1114] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(236), 1,
      anon_sym_LBRACE,
  [1121] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(238), 1,
      anon_sym_info,
  [1128] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(240), 1,
      sym_identity,
  [1135] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(242), 1,
      anon_sym_asset,
  [1142] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(244), 1,
      ts_builtin_sym_end,
  [1149] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(246), 1,
      anon_sym_LBRACK,
  [1156] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(248), 1,
      anon_sym_LT_DASH_DASH,
  [1163] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(250), 1,
      sym_identity,
  [1170] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(252), 1,
      anon_sym_RBRACK,
  [1177] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(254), 1,
      sym_identity,
  [1184] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(256), 1,
      sym_string,
  [1191] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(258), 1,
      sym_identity,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 29,
  [SMALL_STATE(4)] = 58,
  [SMALL_STATE(5)] = 76,
  [SMALL_STATE(6)] = 94,
  [SMALL_STATE(7)] = 112,
  [SMALL_STATE(8)] = 130,
  [SMALL_STATE(9)] = 148,
  [SMALL_STATE(10)] = 166,
  [SMALL_STATE(11)] = 184,
  [SMALL_STATE(12)] = 202,
  [SMALL_STATE(13)] = 220,
  [SMALL_STATE(14)] = 238,
  [SMALL_STATE(15)] = 256,
  [SMALL_STATE(16)] = 274,
  [SMALL_STATE(17)] = 292,
  [SMALL_STATE(18)] = 310,
  [SMALL_STATE(19)] = 328,
  [SMALL_STATE(20)] = 346,
  [SMALL_STATE(21)] = 364,
  [SMALL_STATE(22)] = 376,
  [SMALL_STATE(23)] = 387,
  [SMALL_STATE(24)] = 404,
  [SMALL_STATE(25)] = 421,
  [SMALL_STATE(26)] = 436,
  [SMALL_STATE(27)] = 447,
  [SMALL_STATE(28)] = 458,
  [SMALL_STATE(29)] = 475,
  [SMALL_STATE(30)] = 486,
  [SMALL_STATE(31)] = 503,
  [SMALL_STATE(32)] = 514,
  [SMALL_STATE(33)] = 531,
  [SMALL_STATE(34)] = 548,
  [SMALL_STATE(35)] = 559,
  [SMALL_STATE(36)] = 576,
  [SMALL_STATE(37)] = 587,
  [SMALL_STATE(38)] = 604,
  [SMALL_STATE(39)] = 615,
  [SMALL_STATE(40)] = 626,
  [SMALL_STATE(41)] = 643,
  [SMALL_STATE(42)] = 657,
  [SMALL_STATE(43)] = 671,
  [SMALL_STATE(44)] = 685,
  [SMALL_STATE(45)] = 699,
  [SMALL_STATE(46)] = 713,
  [SMALL_STATE(47)] = 727,
  [SMALL_STATE(48)] = 741,
  [SMALL_STATE(49)] = 755,
  [SMALL_STATE(50)] = 769,
  [SMALL_STATE(51)] = 783,
  [SMALL_STATE(52)] = 797,
  [SMALL_STATE(53)] = 811,
  [SMALL_STATE(54)] = 825,
  [SMALL_STATE(55)] = 836,
  [SMALL_STATE(56)] = 847,
  [SMALL_STATE(57)] = 856,
  [SMALL_STATE(58)] = 865,
  [SMALL_STATE(59)] = 874,
  [SMALL_STATE(60)] = 883,
  [SMALL_STATE(61)] = 892,
  [SMALL_STATE(62)] = 901,
  [SMALL_STATE(63)] = 910,
  [SMALL_STATE(64)] = 919,
  [SMALL_STATE(65)] = 928,
  [SMALL_STATE(66)] = 937,
  [SMALL_STATE(67)] = 946,
  [SMALL_STATE(68)] = 955,
  [SMALL_STATE(69)] = 964,
  [SMALL_STATE(70)] = 973,
  [SMALL_STATE(71)] = 982,
  [SMALL_STATE(72)] = 991,
  [SMALL_STATE(73)] = 1000,
  [SMALL_STATE(74)] = 1008,
  [SMALL_STATE(75)] = 1016,
  [SMALL_STATE(76)] = 1023,
  [SMALL_STATE(77)] = 1030,
  [SMALL_STATE(78)] = 1037,
  [SMALL_STATE(79)] = 1044,
  [SMALL_STATE(80)] = 1051,
  [SMALL_STATE(81)] = 1058,
  [SMALL_STATE(82)] = 1065,
  [SMALL_STATE(83)] = 1072,
  [SMALL_STATE(84)] = 1079,
  [SMALL_STATE(85)] = 1086,
  [SMALL_STATE(86)] = 1093,
  [SMALL_STATE(87)] = 1100,
  [SMALL_STATE(88)] = 1107,
  [SMALL_STATE(89)] = 1114,
  [SMALL_STATE(90)] = 1121,
  [SMALL_STATE(91)] = 1128,
  [SMALL_STATE(92)] = 1135,
  [SMALL_STATE(93)] = 1142,
  [SMALL_STATE(94)] = 1149,
  [SMALL_STATE(95)] = 1156,
  [SMALL_STATE(96)] = 1163,
  [SMALL_STATE(97)] = 1170,
  [SMALL_STATE(98)] = 1177,
  [SMALL_STATE(99)] = 1184,
  [SMALL_STATE(100)] = 1191,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [19] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(84),
  [22] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(100),
  [25] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(76),
  [28] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(89),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_asset_repeat1, 2, 0, 0),
  [47] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_asset_repeat1, 2, 0, 0), SHIFT_REPEAT(75),
  [50] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [52] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [56] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [60] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [62] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attack_step, 2, 0, 9),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_declaration, 1, 0, 0),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [78] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [82] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_category_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(90),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_category_declaration_repeat1, 2, 0, 0),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_define_declaration, 4, 0, 3),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_associations_declaration, 4, 0, 0),
  [91] = {.entry = {.count = 1, .reusable = false}}, SHIFT(90),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [95] = {.entry = {.count = 1, .reusable = false}}, SHIFT(86),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_category_declaration, 5, 0, 4),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_category_declaration_repeat2, 2, 0, 0),
  [101] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_category_declaration_repeat2, 2, 0, 0), SHIFT_REPEAT(92),
  [104] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_category_declaration_repeat2, 2, 0, 0), SHIFT_REPEAT(79),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_category_declaration, 5, 0, 5),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [113] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_category_declaration, 6, 0, 7),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_declaration, 2, 0, 1),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_associations_declaration, 3, 0, 0),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_category_declaration, 4, 0, 2),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [131] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [133] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_associations_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(83),
  [136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_associations_declaration_repeat1, 2, 0, 0),
  [138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [144] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [146] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [150] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [156] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_association, 13, 0, 24), SHIFT(90),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_association, 13, 0, 24),
  [161] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_association, 14, 0, 25), SHIFT(90),
  [164] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_association, 14, 0, 25),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multiplicity, 1, 0, 0),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 4, 0, 2),
  [174] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 5, 0, 8),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 5, 0, 10),
  [178] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_meta, 4, 0, 6),
  [180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 5, 0, 5),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 6, 0, 11),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 6, 0, 12),
  [186] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 6, 0, 13),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 6, 0, 14),
  [190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 8, 0, 21),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 7, 0, 16),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 7, 0, 17),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 7, 0, 18),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 7, 0, 19),
  [200] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 8, 0, 20),
  [202] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 8, 0, 22),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 9, 0, 23),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multiplicity_range, 3, 0, 15),
  [208] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [210] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [212] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [214] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [216] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [218] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [220] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [224] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [244] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [246] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [248] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
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
