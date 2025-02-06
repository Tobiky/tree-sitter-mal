#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 103
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 45
#define ALIAS_COUNT 0
#define TOKEN_COUNT 27
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 18
#define MAX_ALIAS_SEQUENCE_LENGTH 14
#define PRODUCTION_ID_COUNT 27

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
  anon_sym_AT = 15,
  anon_sym_COLON = 16,
  anon_sym_associations = 17,
  anon_sym_LBRACK = 18,
  anon_sym_RBRACK = 19,
  anon_sym_LT_DASH_DASH = 20,
  anon_sym_DASH_DASH_GT = 21,
  anon_sym_DOT_DOT = 22,
  anon_sym_info = 23,
  sym_string = 24,
  sym_integer = 25,
  sym_star = 26,
  sym_source_file = 27,
  sym_declaration = 28,
  sym_include_declaration = 29,
  sym_category_declaration = 30,
  sym_asset = 31,
  sym_attack_step = 32,
  sym_define_declaration = 33,
  sym_associations_declaration = 34,
  sym_association = 35,
  sym_multiplicity = 36,
  sym__multiplicity_atom = 37,
  sym_multiplicity_range = 38,
  sym_meta = 39,
  aux_sym_source_file_repeat1 = 40,
  aux_sym_category_declaration_repeat1 = 41,
  aux_sym_category_declaration_repeat2 = 42,
  aux_sym_asset_repeat1 = 43,
  aux_sym_associations_declaration_repeat1 = 44,
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
  [anon_sym_AT] = "@",
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
  [anon_sym_AT] = anon_sym_AT,
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
  [anon_sym_AT] = {
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
  field_tag = 17,
  field_value = 18,
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
  [field_tag] = "tag",
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
  [22] = {.index = 52, .length = 4},
  [23] = {.index = 56, .length = 5},
  [24] = {.index = 61, .length = 5},
  [25] = {.index = 66, .length = 7},
  [26] = {.index = 73, .length = 8},
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
    {field_id, 1},
    {field_step_type, 0},
    {field_tag, 2},
    {field_tag, 3},
  [40] =
    {field_body, 5},
    {field_extends, 2},
    {field_extends, 3},
    {field_id, 1},
  [44] =
    {field_extends, 2},
    {field_extends, 3},
    {field_id, 1},
    {field_meta, 4},
  [48] =
    {field_body, 6},
    {field_extends, 3},
    {field_extends, 4},
    {field_id, 2},
  [52] =
    {field_extends, 3},
    {field_extends, 4},
    {field_id, 2},
    {field_meta, 5},
  [56] =
    {field_body, 6},
    {field_extends, 2},
    {field_extends, 3},
    {field_id, 1},
    {field_meta, 4},
  [61] =
    {field_body, 7},
    {field_extends, 3},
    {field_extends, 4},
    {field_id, 2},
    {field_meta, 5},
  [66] =
    {field_id, 6},
    {field_left_field_id, 2},
    {field_left_id, 0},
    {field_left_mult, 4},
    {field_right_field_id, 10},
    {field_right_id, 12},
    {field_right_mult, 8},
  [73] =
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
  [101] = 101,
  [102] = 102,
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
        '*', 35,
        '-', 7,
        '.', 10,
        '/', 4,
        ':', 24,
        '<', 9,
        '@', 23,
        '[', 25,
        ']', 26,
        '{', 17,
        '|', 19,
        '}', 18,
      );
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(32);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(34);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(30);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(31);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 3:
      if (lookahead == '*') ADVANCE(35);
      if (lookahead == '/') ADVANCE(4);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(33);
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
      if (lookahead == '-') ADVANCE(27);
      END_STATE();
    case 9:
      if (lookahead == '-') ADVANCE(8);
      END_STATE();
    case 10:
      if (lookahead == '.') ADVANCE(29);
      END_STATE();
    case 11:
      if (lookahead == '>') ADVANCE(28);
      END_STATE();
    case 12:
      if (lookahead == 'E') ADVANCE(22);
      END_STATE();
    case 13:
      if (eof) ADVANCE(14);
      ADVANCE_MAP(
        '!', 12,
        '#', 21,
        '&', 20,
        '/', 4,
        '@', 23,
        '{', 17,
        '|', 19,
        '}', 18,
      );
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(34);
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
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_LT_DASH_DASH);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_DASH_DASH_GT);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_DOT_DOT);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_string);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_string);
      if (lookahead == '"') ADVANCE(30);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_integer);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(32);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(34);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_integer);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(33);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_identity);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(34);
      END_STATE();
    case 35:
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
  [24] = {.lex_state = 3},
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
  [35] = {.lex_state = 13},
  [36] = {.lex_state = 3},
  [37] = {.lex_state = 13},
  [38] = {.lex_state = 13},
  [39] = {.lex_state = 13},
  [40] = {.lex_state = 13},
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
  [54] = {.lex_state = 13},
  [55] = {.lex_state = 13},
  [56] = {.lex_state = 13},
  [57] = {.lex_state = 3},
  [58] = {.lex_state = 13},
  [59] = {.lex_state = 0},
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
  [73] = {.lex_state = 13},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 13},
  [77] = {.lex_state = 13},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 13},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 13},
  [83] = {.lex_state = 13},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 13},
  [89] = {.lex_state = 13},
  [90] = {.lex_state = 13},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 13},
  [93] = {.lex_state = 13},
  [94] = {.lex_state = 13},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 13},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 13},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 13},
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
    [anon_sym_AT] = ACTIONS(1),
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
    [sym_source_file] = STATE(97),
    [sym_declaration] = STATE(2),
    [sym_include_declaration] = STATE(23),
    [sym_category_declaration] = STATE(23),
    [sym_define_declaration] = STATE(23),
    [sym_associations_declaration] = STATE(23),
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
    STATE(23), 4,
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
    STATE(23), 4,
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
  [364] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(72), 1,
      anon_sym_AT,
    ACTIONS(70), 6,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      anon_sym_AMP,
      anon_sym_POUND,
      anon_sym_E,
      anon_sym_BANGE,
  [379] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(74), 6,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      anon_sym_AMP,
      anon_sym_POUND,
      anon_sym_E,
      anon_sym_BANGE,
  [391] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(76), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [402] = 5,
    ACTIONS(3), 1,
      sym_comment,
    STATE(59), 1,
      sym__multiplicity_atom,
    STATE(74), 1,
      sym_multiplicity_range,
    STATE(96), 1,
      sym_multiplicity,
    ACTIONS(78), 2,
      sym_integer,
      sym_star,
  [419] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(80), 1,
      anon_sym_RBRACE,
    ACTIONS(82), 1,
      anon_sym_abstract,
    ACTIONS(84), 1,
      anon_sym_asset,
    STATE(33), 2,
      sym_asset,
      aux_sym_category_declaration_repeat2,
  [436] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(86), 1,
      sym_identity,
    ACTIONS(89), 2,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
    STATE(26), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [451] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(91), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [462] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(93), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [473] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(95), 1,
      sym_identity,
    ACTIONS(97), 1,
      anon_sym_LBRACE,
    ACTIONS(99), 1,
      anon_sym_extends,
    STATE(53), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [490] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(101), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [501] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(103), 1,
      anon_sym_RBRACE,
    ACTIONS(105), 1,
      anon_sym_abstract,
    ACTIONS(108), 1,
      anon_sym_asset,
    STATE(31), 2,
      sym_asset,
      aux_sym_category_declaration_repeat2,
  [518] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(111), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [529] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(82), 1,
      anon_sym_abstract,
    ACTIONS(84), 1,
      anon_sym_asset,
    ACTIONS(113), 1,
      anon_sym_RBRACE,
    STATE(31), 2,
      sym_asset,
      aux_sym_category_declaration_repeat2,
  [546] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(95), 1,
      sym_identity,
    ACTIONS(115), 1,
      anon_sym_LBRACE,
    ACTIONS(117), 1,
      anon_sym_extends,
    STATE(43), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [563] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(119), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [574] = 5,
    ACTIONS(3), 1,
      sym_comment,
    STATE(59), 1,
      sym__multiplicity_atom,
    STATE(74), 1,
      sym_multiplicity_range,
    STATE(80), 1,
      sym_multiplicity,
    ACTIONS(78), 2,
      sym_integer,
      sym_star,
  [591] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(121), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [602] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(82), 1,
      anon_sym_abstract,
    ACTIONS(84), 1,
      anon_sym_asset,
    ACTIONS(123), 1,
      anon_sym_RBRACE,
    STATE(41), 2,
      sym_asset,
      aux_sym_category_declaration_repeat2,
  [619] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(125), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [630] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(127), 5,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
      anon_sym_associations,
  [641] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(82), 1,
      anon_sym_abstract,
    ACTIONS(84), 1,
      anon_sym_asset,
    ACTIONS(129), 1,
      anon_sym_RBRACE,
    STATE(31), 2,
      sym_asset,
      aux_sym_category_declaration_repeat2,
  [658] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(131), 1,
      sym_identity,
    ACTIONS(134), 1,
      anon_sym_RBRACE,
    STATE(26), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [672] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(136), 1,
      sym_identity,
    ACTIONS(138), 1,
      anon_sym_LBRACE,
    STATE(26), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [686] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(136), 1,
      sym_identity,
    ACTIONS(140), 1,
      anon_sym_LBRACE,
    STATE(49), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [700] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(142), 1,
      sym_identity,
    ACTIONS(145), 1,
      anon_sym_RBRACE,
    STATE(45), 2,
      sym_association,
      aux_sym_associations_declaration_repeat1,
  [714] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(136), 1,
      sym_identity,
    ACTIONS(147), 1,
      anon_sym_LBRACE,
    STATE(50), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [728] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(136), 1,
      sym_identity,
    ACTIONS(149), 1,
      anon_sym_LBRACE,
    STATE(51), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [742] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(151), 1,
      sym_identity,
    ACTIONS(153), 1,
      anon_sym_RBRACE,
    STATE(52), 2,
      sym_association,
      aux_sym_associations_declaration_repeat1,
  [756] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(136), 1,
      sym_identity,
    ACTIONS(155), 1,
      anon_sym_LBRACE,
    STATE(26), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [770] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(136), 1,
      sym_identity,
    ACTIONS(157), 1,
      anon_sym_LBRACE,
    STATE(26), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [784] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(136), 1,
      sym_identity,
    ACTIONS(159), 1,
      anon_sym_LBRACE,
    STATE(26), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [798] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(151), 1,
      sym_identity,
    ACTIONS(161), 1,
      anon_sym_RBRACE,
    STATE(45), 2,
      sym_association,
      aux_sym_associations_declaration_repeat1,
  [812] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(136), 1,
      sym_identity,
    ACTIONS(163), 1,
      anon_sym_LBRACE,
    STATE(26), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [826] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(165), 1,
      sym_identity,
    ACTIONS(168), 1,
      anon_sym_RBRACE,
    STATE(42), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [840] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(170), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [849] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(172), 3,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_identity,
  [858] = 3,
    ACTIONS(3), 1,
      sym_comment,
    STATE(75), 1,
      sym__multiplicity_atom,
    ACTIONS(174), 2,
      sym_integer,
      sym_star,
  [869] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(176), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [878] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(180), 1,
      anon_sym_DOT_DOT,
    ACTIONS(178), 2,
      anon_sym_LBRACK,
      anon_sym_LT_DASH_DASH,
  [889] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(182), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [898] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(184), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [907] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(186), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [916] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(188), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [925] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(190), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [934] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(192), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [943] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(194), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [952] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(196), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [961] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(198), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [970] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(200), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [979] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(202), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [988] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(204), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [997] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(206), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [1006] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(208), 3,
      anon_sym_RBRACE,
      anon_sym_abstract,
      anon_sym_asset,
  [1015] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(178), 2,
      anon_sym_LBRACK,
      anon_sym_LT_DASH_DASH,
  [1023] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(210), 2,
      anon_sym_LBRACK,
      anon_sym_LT_DASH_DASH,
  [1031] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(212), 1,
      sym_identity,
  [1038] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(214), 1,
      sym_identity,
  [1045] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(216), 1,
      sym_string,
  [1052] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(218), 1,
      sym_identity,
  [1059] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(220), 1,
      anon_sym_LT_DASH_DASH,
  [1066] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(222), 1,
      anon_sym_DASH_DASH_GT,
  [1073] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(224), 1,
      sym_identity,
  [1080] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(226), 1,
      sym_identity,
  [1087] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(228), 1,
      anon_sym_LBRACK,
  [1094] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(230), 1,
      sym_string,
  [1101] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(232), 1,
      anon_sym_RBRACK,
  [1108] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(234), 1,
      anon_sym_LBRACE,
  [1115] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(236), 1,
      sym_identity,
  [1122] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(238), 1,
      sym_identity,
  [1129] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(240), 1,
      anon_sym_asset,
  [1136] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(242), 1,
      anon_sym_COLON,
  [1143] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(244), 1,
      sym_identity,
  [1150] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(246), 1,
      anon_sym_info,
  [1157] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(248), 1,
      sym_identity,
  [1164] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(250), 1,
      sym_string,
  [1171] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(252), 1,
      anon_sym_LBRACK,
  [1178] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(254), 1,
      ts_builtin_sym_end,
  [1185] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(256), 1,
      sym_identity,
  [1192] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(258), 1,
      anon_sym_RBRACK,
  [1199] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(260), 1,
      sym_identity,
  [1206] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(262), 1,
      anon_sym_COLON,
  [1213] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(264), 1,
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
  [SMALL_STATE(22)] = 379,
  [SMALL_STATE(23)] = 391,
  [SMALL_STATE(24)] = 402,
  [SMALL_STATE(25)] = 419,
  [SMALL_STATE(26)] = 436,
  [SMALL_STATE(27)] = 451,
  [SMALL_STATE(28)] = 462,
  [SMALL_STATE(29)] = 473,
  [SMALL_STATE(30)] = 490,
  [SMALL_STATE(31)] = 501,
  [SMALL_STATE(32)] = 518,
  [SMALL_STATE(33)] = 529,
  [SMALL_STATE(34)] = 546,
  [SMALL_STATE(35)] = 563,
  [SMALL_STATE(36)] = 574,
  [SMALL_STATE(37)] = 591,
  [SMALL_STATE(38)] = 602,
  [SMALL_STATE(39)] = 619,
  [SMALL_STATE(40)] = 630,
  [SMALL_STATE(41)] = 641,
  [SMALL_STATE(42)] = 658,
  [SMALL_STATE(43)] = 672,
  [SMALL_STATE(44)] = 686,
  [SMALL_STATE(45)] = 700,
  [SMALL_STATE(46)] = 714,
  [SMALL_STATE(47)] = 728,
  [SMALL_STATE(48)] = 742,
  [SMALL_STATE(49)] = 756,
  [SMALL_STATE(50)] = 770,
  [SMALL_STATE(51)] = 784,
  [SMALL_STATE(52)] = 798,
  [SMALL_STATE(53)] = 812,
  [SMALL_STATE(54)] = 826,
  [SMALL_STATE(55)] = 840,
  [SMALL_STATE(56)] = 849,
  [SMALL_STATE(57)] = 858,
  [SMALL_STATE(58)] = 869,
  [SMALL_STATE(59)] = 878,
  [SMALL_STATE(60)] = 889,
  [SMALL_STATE(61)] = 898,
  [SMALL_STATE(62)] = 907,
  [SMALL_STATE(63)] = 916,
  [SMALL_STATE(64)] = 925,
  [SMALL_STATE(65)] = 934,
  [SMALL_STATE(66)] = 943,
  [SMALL_STATE(67)] = 952,
  [SMALL_STATE(68)] = 961,
  [SMALL_STATE(69)] = 970,
  [SMALL_STATE(70)] = 979,
  [SMALL_STATE(71)] = 988,
  [SMALL_STATE(72)] = 997,
  [SMALL_STATE(73)] = 1006,
  [SMALL_STATE(74)] = 1015,
  [SMALL_STATE(75)] = 1023,
  [SMALL_STATE(76)] = 1031,
  [SMALL_STATE(77)] = 1038,
  [SMALL_STATE(78)] = 1045,
  [SMALL_STATE(79)] = 1052,
  [SMALL_STATE(80)] = 1059,
  [SMALL_STATE(81)] = 1066,
  [SMALL_STATE(82)] = 1073,
  [SMALL_STATE(83)] = 1080,
  [SMALL_STATE(84)] = 1087,
  [SMALL_STATE(85)] = 1094,
  [SMALL_STATE(86)] = 1101,
  [SMALL_STATE(87)] = 1108,
  [SMALL_STATE(88)] = 1115,
  [SMALL_STATE(89)] = 1122,
  [SMALL_STATE(90)] = 1129,
  [SMALL_STATE(91)] = 1136,
  [SMALL_STATE(92)] = 1143,
  [SMALL_STATE(93)] = 1150,
  [SMALL_STATE(94)] = 1157,
  [SMALL_STATE(95)] = 1164,
  [SMALL_STATE(96)] = 1171,
  [SMALL_STATE(97)] = 1178,
  [SMALL_STATE(98)] = 1185,
  [SMALL_STATE(99)] = 1192,
  [SMALL_STATE(100)] = 1199,
  [SMALL_STATE(101)] = 1206,
  [SMALL_STATE(102)] = 1213,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [19] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(95),
  [22] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(77),
  [25] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(82),
  [28] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(87),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_asset_repeat1, 2, 0, 0),
  [47] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_asset_repeat1, 2, 0, 0), SHIFT_REPEAT(92),
  [50] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [52] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [56] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [60] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [62] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attack_step, 2, 0, 9),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attack_step, 4, 0, 18),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_declaration, 1, 0, 0),
  [78] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [86] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_category_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(93),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_category_declaration_repeat1, 2, 0, 0),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_define_declaration, 4, 0, 3),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_associations_declaration, 4, 0, 0),
  [95] = {.entry = {.count = 1, .reusable = false}}, SHIFT(93),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [99] = {.entry = {.count = 1, .reusable = false}}, SHIFT(76),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_category_declaration, 5, 0, 4),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_category_declaration_repeat2, 2, 0, 0),
  [105] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_category_declaration_repeat2, 2, 0, 0), SHIFT_REPEAT(90),
  [108] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_category_declaration_repeat2, 2, 0, 0), SHIFT_REPEAT(94),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_category_declaration, 5, 0, 5),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [117] = {.entry = {.count = 1, .reusable = false}}, SHIFT(83),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_category_declaration, 6, 0, 7),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_declaration, 2, 0, 1),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_associations_declaration, 3, 0, 0),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_category_declaration, 4, 0, 2),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [131] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_association, 14, 0, 26), SHIFT(93),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_association, 14, 0, 26),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [142] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_associations_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(84),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_associations_declaration_repeat1, 2, 0, 0),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [165] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_association, 13, 0, 25), SHIFT(93),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_association, 13, 0, 25),
  [170] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 8, 0, 21),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_meta, 4, 0, 6),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 6, 0, 11),
  [178] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multiplicity, 1, 0, 0),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 6, 0, 12),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 6, 0, 13),
  [186] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 6, 0, 14),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 7, 0, 16),
  [190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 5, 0, 10),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 7, 0, 17),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 7, 0, 19),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 7, 0, 20),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 5, 0, 8),
  [200] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 8, 0, 22),
  [202] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 8, 0, 23),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 9, 0, 24),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 4, 0, 2),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_asset, 5, 0, 5),
  [210] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multiplicity_range, 3, 0, 15),
  [212] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [214] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [216] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [218] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [220] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [224] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [246] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [248] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [254] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [260] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
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
