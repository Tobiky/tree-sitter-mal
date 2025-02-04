#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 14
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 13
#define ALIAS_COUNT 0
#define TOKEN_COUNT 8
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 1
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 2

enum ts_symbol_identifiers {
  anon_sym_SLASH_SLASH = 1,
  aux_sym_comment_token1 = 2,
  anon_sym_SLASH_STAR = 3,
  aux_sym_comment_token2 = 4,
  anon_sym_SLASH = 5,
  anon_sym_include = 6,
  sym_string = 7,
  sym_source_file = 8,
  sym_comment = 9,
  sym_declaration = 10,
  sym_include_declaration = 11,
  aux_sym_source_file_repeat1 = 12,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_SLASH_SLASH] = "//",
  [aux_sym_comment_token1] = "comment_token1",
  [anon_sym_SLASH_STAR] = "/*",
  [aux_sym_comment_token2] = "comment_token2",
  [anon_sym_SLASH] = "/",
  [anon_sym_include] = "include",
  [sym_string] = "string",
  [sym_source_file] = "source_file",
  [sym_comment] = "comment",
  [sym_declaration] = "declaration",
  [sym_include_declaration] = "include_declaration",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_SLASH_SLASH] = anon_sym_SLASH_SLASH,
  [aux_sym_comment_token1] = aux_sym_comment_token1,
  [anon_sym_SLASH_STAR] = anon_sym_SLASH_STAR,
  [aux_sym_comment_token2] = aux_sym_comment_token2,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_include] = anon_sym_include,
  [sym_string] = sym_string,
  [sym_source_file] = sym_source_file,
  [sym_comment] = sym_comment,
  [sym_declaration] = sym_declaration,
  [sym_include_declaration] = sym_include_declaration,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_SLASH_SLASH] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_comment_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SLASH_STAR] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_comment_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_include] = {
    .visible = true,
    .named = false,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
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
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_file = 1,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_file] = "file",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_file, 1},
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(12);
      if (lookahead == '"') ADVANCE(1);
      if (lookahead == '/') ADVANCE(23);
      if (lookahead == 'i') ADVANCE(10);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0);
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
      if (lookahead == '*') ADVANCE(22);
      if (lookahead == '/') ADVANCE(5);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(3);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 4:
      if (lookahead == '*') ADVANCE(22);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 5:
      if (lookahead == '*') ADVANCE(20);
      if (lookahead == '/') ADVANCE(14);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 6:
      if (lookahead == 'c') ADVANCE(9);
      END_STATE();
    case 7:
      if (lookahead == 'd') ADVANCE(8);
      END_STATE();
    case 8:
      if (lookahead == 'e') ADVANCE(24);
      END_STATE();
    case 9:
      if (lookahead == 'l') ADVANCE(11);
      END_STATE();
    case 10:
      if (lookahead == 'n') ADVANCE(6);
      END_STATE();
    case 11:
      if (lookahead == 'u') ADVANCE(7);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_SLASH_SLASH);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_SLASH_SLASH);
      if (lookahead == '*') ADVANCE(22);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_SLASH_SLASH);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) ADVANCE(18);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '*') ADVANCE(21);
      if (lookahead == '/') ADVANCE(15);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) ADVANCE(18);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '/') ADVANCE(16);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(17);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) ADVANCE(18);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) ADVANCE(18);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_SLASH_STAR);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_SLASH_STAR);
      if (lookahead == '*') ADVANCE(22);
      if (lookahead != 0 &&
          lookahead != '/') ADVANCE(4);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_SLASH_STAR);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) ADVANCE(18);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(aux_sym_comment_token2);
      if (lookahead == '*') ADVANCE(22);
      if (lookahead != 0 &&
          lookahead != '/') ADVANCE(4);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '*') ADVANCE(19);
      if (lookahead == '/') ADVANCE(13);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_include);
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
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 17},
  [8] = {.lex_state = 3},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {(TSStateId)(-1)},
  [13] = {(TSStateId)(-1)},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [sym_comment] = STATE(0),
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_SLASH_SLASH] = ACTIONS(3),
    [anon_sym_SLASH_STAR] = ACTIONS(5),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_include] = ACTIONS(1),
    [sym_string] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(10),
    [sym_comment] = STATE(1),
    [sym_declaration] = STATE(4),
    [sym_include_declaration] = STATE(5),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(7),
    [anon_sym_SLASH_SLASH] = ACTIONS(3),
    [anon_sym_SLASH_STAR] = ACTIONS(5),
    [anon_sym_include] = ACTIONS(9),
  },
  [2] = {
    [sym_comment] = STATE(2),
    [sym_declaration] = STATE(4),
    [sym_include_declaration] = STATE(5),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(11),
    [anon_sym_SLASH_SLASH] = ACTIONS(3),
    [anon_sym_SLASH_STAR] = ACTIONS(5),
    [anon_sym_include] = ACTIONS(9),
  },
  [3] = {
    [sym_comment] = STATE(3),
    [sym_declaration] = STATE(4),
    [sym_include_declaration] = STATE(5),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(13),
    [anon_sym_SLASH_SLASH] = ACTIONS(3),
    [anon_sym_SLASH_STAR] = ACTIONS(5),
    [anon_sym_include] = ACTIONS(15),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(4), 1,
      sym_comment,
    ACTIONS(18), 2,
      ts_builtin_sym_end,
      anon_sym_include,
  [14] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(5), 1,
      sym_comment,
    ACTIONS(20), 2,
      ts_builtin_sym_end,
      anon_sym_include,
  [28] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    STATE(6), 1,
      sym_comment,
    ACTIONS(22), 2,
      ts_builtin_sym_end,
      anon_sym_include,
  [42] = 4,
    ACTIONS(24), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(26), 1,
      aux_sym_comment_token1,
    ACTIONS(28), 1,
      anon_sym_SLASH_STAR,
    STATE(7), 1,
      sym_comment,
  [55] = 4,
    ACTIONS(24), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(28), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(30), 1,
      aux_sym_comment_token2,
    STATE(8), 1,
      sym_comment,
  [68] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(32), 1,
      sym_string,
    STATE(9), 1,
      sym_comment,
  [81] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(34), 1,
      ts_builtin_sym_end,
    STATE(10), 1,
      sym_comment,
  [94] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(36), 1,
      anon_sym_SLASH,
    STATE(11), 1,
      sym_comment,
  [107] = 1,
    ACTIONS(38), 1,
      ts_builtin_sym_end,
  [111] = 1,
    ACTIONS(40), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 14,
  [SMALL_STATE(6)] = 28,
  [SMALL_STATE(7)] = 42,
  [SMALL_STATE(8)] = 55,
  [SMALL_STATE(9)] = 68,
  [SMALL_STATE(10)] = 81,
  [SMALL_STATE(11)] = 94,
  [SMALL_STATE(12)] = 107,
  [SMALL_STATE(13)] = 111,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [15] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(9),
  [18] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 1, 0, 0),
  [20] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_declaration, 1, 0, 0),
  [22] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_declaration, 2, 0, 1),
  [24] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [26] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [28] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [30] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [32] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [34] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [36] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [38] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 2, 0, 0),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 3, 0, 0),
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
