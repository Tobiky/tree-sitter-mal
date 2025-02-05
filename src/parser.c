#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 24
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 19
#define ALIAS_COUNT 0
#define TOKEN_COUNT 11
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 5
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 6

enum ts_symbol_identifiers {
  sym_comment = 1,
  anon_sym_include = 2,
  anon_sym_category = 3,
  anon_sym_LBRACE = 4,
  anon_sym_RBRACE = 5,
  anon_sym_POUND = 6,
  anon_sym_COLON = 7,
  anon_sym_info = 8,
  sym_string = 9,
  sym_identity = 10,
  sym_source_file = 11,
  sym_declaration = 12,
  sym_include_declaration = 13,
  sym_category_declaration = 14,
  sym_define_declaration = 15,
  sym_meta = 16,
  aux_sym_source_file_repeat1 = 17,
  aux_sym_category_declaration_repeat1 = 18,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_comment] = "comment",
  [anon_sym_include] = "include",
  [anon_sym_category] = "category",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_POUND] = "#",
  [anon_sym_COLON] = ":",
  [anon_sym_info] = "info",
  [sym_string] = "string",
  [sym_identity] = "identity",
  [sym_source_file] = "source_file",
  [sym_declaration] = "declaration",
  [sym_include_declaration] = "include_declaration",
  [sym_category_declaration] = "category_declaration",
  [sym_define_declaration] = "define_declaration",
  [sym_meta] = "meta",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_category_declaration_repeat1] = "category_declaration_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_comment] = sym_comment,
  [anon_sym_include] = anon_sym_include,
  [anon_sym_category] = anon_sym_category,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_POUND] = anon_sym_POUND,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_info] = anon_sym_info,
  [sym_string] = sym_string,
  [sym_identity] = sym_identity,
  [sym_source_file] = sym_source_file,
  [sym_declaration] = sym_declaration,
  [sym_include_declaration] = sym_include_declaration,
  [sym_category_declaration] = sym_category_declaration,
  [sym_define_declaration] = sym_define_declaration,
  [sym_meta] = sym_meta,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_category_declaration_repeat1] = aux_sym_category_declaration_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
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
  [anon_sym_info] = {
    .visible = true,
    .named = false,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_identity] = {
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
};

enum ts_field_identifiers {
  field_file = 1,
  field_id = 2,
  field_info = 3,
  field_meta = 4,
  field_value = 5,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_file] = "file",
  [field_id] = "id",
  [field_info] = "info",
  [field_meta] = "meta",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 2},
  [4] = {.index = 4, .length = 2},
  [5] = {.index = 6, .length = 2},
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(21);
      ADVANCE_MAP(
        '"', 1,
        '#', 28,
        '/', 3,
        ':', 29,
        'c', 7,
        'i', 14,
        '{', 26,
        '}', 27,
      );
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(31);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(32);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 3:
      if (lookahead == '*') ADVANCE(5);
      if (lookahead == '/') ADVANCE(23);
      END_STATE();
    case 4:
      if (lookahead == '*') ADVANCE(4);
      if (lookahead == '/') ADVANCE(22);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 5:
      if (lookahead == '*') ADVANCE(4);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 6:
      if (lookahead == '/') ADVANCE(3);
      if (lookahead == '{') ADVANCE(26);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(6);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 7:
      if (lookahead == 'a') ADVANCE(18);
      END_STATE();
    case 8:
      if (lookahead == 'c') ADVANCE(13);
      if (lookahead == 'f') ADVANCE(15);
      END_STATE();
    case 9:
      if (lookahead == 'd') ADVANCE(11);
      END_STATE();
    case 10:
      if (lookahead == 'e') ADVANCE(12);
      END_STATE();
    case 11:
      if (lookahead == 'e') ADVANCE(24);
      END_STATE();
    case 12:
      if (lookahead == 'g') ADVANCE(16);
      END_STATE();
    case 13:
      if (lookahead == 'l') ADVANCE(19);
      END_STATE();
    case 14:
      if (lookahead == 'n') ADVANCE(8);
      END_STATE();
    case 15:
      if (lookahead == 'o') ADVANCE(30);
      END_STATE();
    case 16:
      if (lookahead == 'o') ADVANCE(17);
      END_STATE();
    case 17:
      if (lookahead == 'r') ADVANCE(20);
      END_STATE();
    case 18:
      if (lookahead == 't') ADVANCE(10);
      END_STATE();
    case 19:
      if (lookahead == 'u') ADVANCE(9);
      END_STATE();
    case 20:
      if (lookahead == 'y') ADVANCE(25);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) ADVANCE(23);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_include);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_category);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_info);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_string);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_string);
      if (lookahead == '"') ADVANCE(31);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_identity);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 6},
  [7] = {.lex_state = 6},
  [8] = {.lex_state = 6},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 6},
  [13] = {.lex_state = 6},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 6},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
    [anon_sym_include] = ACTIONS(1),
    [anon_sym_category] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_POUND] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_info] = ACTIONS(1),
    [sym_string] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(14),
    [sym_declaration] = STATE(2),
    [sym_include_declaration] = STATE(5),
    [sym_category_declaration] = STATE(5),
    [sym_define_declaration] = STATE(5),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_comment] = ACTIONS(3),
    [anon_sym_include] = ACTIONS(7),
    [anon_sym_category] = ACTIONS(9),
    [anon_sym_POUND] = ACTIONS(11),
  },
  [2] = {
    [sym_declaration] = STATE(3),
    [sym_include_declaration] = STATE(5),
    [sym_category_declaration] = STATE(5),
    [sym_define_declaration] = STATE(5),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(13),
    [sym_comment] = ACTIONS(3),
    [anon_sym_include] = ACTIONS(7),
    [anon_sym_category] = ACTIONS(9),
    [anon_sym_POUND] = ACTIONS(11),
  },
  [3] = {
    [sym_declaration] = STATE(3),
    [sym_include_declaration] = STATE(5),
    [sym_category_declaration] = STATE(5),
    [sym_define_declaration] = STATE(5),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(15),
    [sym_comment] = ACTIONS(3),
    [anon_sym_include] = ACTIONS(17),
    [anon_sym_category] = ACTIONS(20),
    [anon_sym_POUND] = ACTIONS(23),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(26), 4,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
  [10] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(28), 4,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
  [20] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(30), 1,
      anon_sym_LBRACE,
    ACTIONS(32), 1,
      sym_identity,
    STATE(7), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [34] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(32), 1,
      sym_identity,
    ACTIONS(34), 1,
      anon_sym_LBRACE,
    STATE(8), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [48] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(36), 1,
      anon_sym_LBRACE,
    ACTIONS(38), 1,
      sym_identity,
    STATE(8), 2,
      sym_meta,
      aux_sym_category_declaration_repeat1,
  [62] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(41), 4,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
  [72] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(43), 4,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
  [82] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(45), 4,
      ts_builtin_sym_end,
      anon_sym_include,
      anon_sym_category,
      anon_sym_POUND,
  [92] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(47), 2,
      anon_sym_LBRACE,
      sym_identity,
  [100] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(49), 1,
      sym_identity,
  [107] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(51), 1,
      ts_builtin_sym_end,
  [114] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(53), 1,
      sym_string,
  [121] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(55), 1,
      sym_identity,
  [128] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(57), 1,
      anon_sym_COLON,
  [135] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(59), 1,
      anon_sym_RBRACE,
  [142] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(61), 1,
      anon_sym_COLON,
  [149] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(63), 1,
      anon_sym_RBRACE,
  [156] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(65), 1,
      anon_sym_info,
  [163] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(67), 1,
      sym_string,
  [170] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(69), 1,
      sym_string,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 10,
  [SMALL_STATE(6)] = 20,
  [SMALL_STATE(7)] = 34,
  [SMALL_STATE(8)] = 48,
  [SMALL_STATE(9)] = 62,
  [SMALL_STATE(10)] = 72,
  [SMALL_STATE(11)] = 82,
  [SMALL_STATE(12)] = 92,
  [SMALL_STATE(13)] = 100,
  [SMALL_STATE(14)] = 107,
  [SMALL_STATE(15)] = 114,
  [SMALL_STATE(16)] = 121,
  [SMALL_STATE(17)] = 128,
  [SMALL_STATE(18)] = 135,
  [SMALL_STATE(19)] = 142,
  [SMALL_STATE(20)] = 149,
  [SMALL_STATE(21)] = 156,
  [SMALL_STATE(22)] = 163,
  [SMALL_STATE(23)] = 170,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [17] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(15),
  [20] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(13),
  [23] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(16),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_declaration, 2, 0, 1),
  [28] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_declaration, 1, 0, 0),
  [30] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [32] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [34] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [36] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_category_declaration_repeat1, 2, 0, 0),
  [38] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_category_declaration_repeat1, 2, 0, 0), SHIFT_REPEAT(21),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_category_declaration, 4, 0, 2),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_define_declaration, 4, 0, 3),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_category_declaration, 5, 0, 4),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_meta, 4, 0, 5),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [51] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
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
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
