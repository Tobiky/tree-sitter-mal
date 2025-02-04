#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 5
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 4
#define ALIAS_COUNT 0
#define TOKEN_COUNT 2
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 2
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  anon_sym_hello = 1,
  sym_source_file = 2,
  aux_sym_source_file_repeat1 = 3,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_hello] = "hello",
  [sym_source_file] = "source_file",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_hello] = anon_sym_hello,
  [sym_source_file] = sym_source_file,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_hello] = {
    .visible = true,
    .named = false,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(40);
      if (lookahead == '/') SKIP(29);
      if (lookahead == 'h') ADVANCE(25);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == '*') SKIP(17);
      if (lookahead == '/') SKIP(1);
      if (lookahead == 'h') ADVANCE(19);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(23);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(24);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(23);
      END_STATE();
    case 2:
      if (lookahead == '*') SKIP(17);
      if (lookahead == '/') SKIP(2);
      if (lookahead == 'h') ADVANCE(13);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(17);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(6);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(11);
      if (lookahead != 0) SKIP(17);
      END_STATE();
    case 3:
      if (lookahead == '*') SKIP(11);
      if (lookahead == '/') SKIP(23);
      END_STATE();
    case 4:
      if (lookahead == '*') SKIP(4);
      if (lookahead == '/') SKIP(24);
      if (lookahead != 0) SKIP(11);
      END_STATE();
    case 5:
      if (lookahead == '*') SKIP(4);
      if (lookahead == '/') SKIP(6);
      if (lookahead != 0) SKIP(11);
      END_STATE();
    case 6:
      if (lookahead == '*') SKIP(4);
      if (lookahead == '/') SKIP(18);
      if (lookahead == 'h') ADVANCE(7);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(6);
      if (lookahead != 0) SKIP(11);
      END_STATE();
    case 7:
      if (lookahead == '*') SKIP(4);
      if (lookahead == 'e') ADVANCE(9);
      if (lookahead != 0) SKIP(11);
      END_STATE();
    case 8:
      if (lookahead == '*') SKIP(4);
      if (lookahead == 'l') ADVANCE(10);
      if (lookahead != 0) SKIP(11);
      END_STATE();
    case 9:
      if (lookahead == '*') SKIP(4);
      if (lookahead == 'l') ADVANCE(8);
      if (lookahead != 0) SKIP(11);
      END_STATE();
    case 10:
      if (lookahead == '*') SKIP(4);
      if (lookahead == 'o') ADVANCE(41);
      if (lookahead != 0) SKIP(11);
      END_STATE();
    case 11:
      if (lookahead == '*') SKIP(4);
      if (lookahead != 0) SKIP(11);
      END_STATE();
    case 12:
      if (lookahead == '*') SKIP(12);
      if (lookahead == '/') SKIP(1);
      if (lookahead == 'h') ADVANCE(13);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(17);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(6);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(11);
      if (lookahead != 0) SKIP(17);
      END_STATE();
    case 13:
      if (lookahead == '*') SKIP(12);
      if (lookahead == '/') SKIP(2);
      if (lookahead == 'e') ADVANCE(15);
      if (lookahead == 'h') ADVANCE(13);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(17);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(6);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(11);
      if (lookahead != 0) SKIP(17);
      END_STATE();
    case 14:
      if (lookahead == '*') SKIP(12);
      if (lookahead == '/') SKIP(2);
      if (lookahead == 'h') ADVANCE(13);
      if (lookahead == 'l') ADVANCE(16);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(17);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(6);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(11);
      if (lookahead != 0) SKIP(17);
      END_STATE();
    case 15:
      if (lookahead == '*') SKIP(12);
      if (lookahead == '/') SKIP(2);
      if (lookahead == 'h') ADVANCE(13);
      if (lookahead == 'l') ADVANCE(14);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(17);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(6);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(11);
      if (lookahead != 0) SKIP(17);
      END_STATE();
    case 16:
      if (lookahead == '*') SKIP(12);
      if (lookahead == '/') SKIP(2);
      if (lookahead == 'h') ADVANCE(13);
      if (lookahead == 'o') ADVANCE(43);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(17);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(6);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(11);
      if (lookahead != 0) SKIP(17);
      END_STATE();
    case 17:
      if (lookahead == '*') SKIP(12);
      if (lookahead == '/') SKIP(2);
      if (lookahead == 'h') ADVANCE(13);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(17);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(6);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(11);
      if (lookahead != 0) SKIP(17);
      END_STATE();
    case 18:
      if (lookahead == '*') SKIP(5);
      if (lookahead == '/') SKIP(17);
      if (lookahead != 0) SKIP(11);
      END_STATE();
    case 19:
      if (lookahead == '/') SKIP(1);
      if (lookahead == 'e') ADVANCE(21);
      if (lookahead == 'h') ADVANCE(19);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(23);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(24);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(23);
      END_STATE();
    case 20:
      if (lookahead == '/') SKIP(1);
      if (lookahead == 'h') ADVANCE(19);
      if (lookahead == 'l') ADVANCE(22);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(23);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(24);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(23);
      END_STATE();
    case 21:
      if (lookahead == '/') SKIP(1);
      if (lookahead == 'h') ADVANCE(19);
      if (lookahead == 'l') ADVANCE(20);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(23);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(24);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(23);
      END_STATE();
    case 22:
      if (lookahead == '/') SKIP(1);
      if (lookahead == 'h') ADVANCE(19);
      if (lookahead == 'o') ADVANCE(42);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(23);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(24);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(23);
      END_STATE();
    case 23:
      if (lookahead == '/') SKIP(1);
      if (lookahead == 'h') ADVANCE(19);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(23);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(24);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(23);
      END_STATE();
    case 24:
      if (lookahead == '/') SKIP(3);
      if (lookahead == 'h') ADVANCE(25);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(24);
      END_STATE();
    case 25:
      if (lookahead == 'e') ADVANCE(27);
      END_STATE();
    case 26:
      if (lookahead == 'l') ADVANCE(28);
      END_STATE();
    case 27:
      if (lookahead == 'l') ADVANCE(26);
      END_STATE();
    case 28:
      if (lookahead == 'o') ADVANCE(41);
      END_STATE();
    case 29:
      if (eof) ADVANCE(40);
      if (lookahead == '*') SKIP(33);
      if (lookahead == '/') SKIP(39);
      END_STATE();
    case 30:
      if (eof) ADVANCE(40);
      if (lookahead == '*') SKIP(30);
      if (lookahead == '/') SKIP(0);
      if (lookahead != 0) SKIP(33);
      END_STATE();
    case 31:
      if (eof) ADVANCE(40);
      if (lookahead == '*') SKIP(30);
      if (lookahead == '/') SKIP(32);
      if (lookahead != 0) SKIP(33);
      END_STATE();
    case 32:
      if (eof) ADVANCE(40);
      if (lookahead == '*') SKIP(30);
      if (lookahead == '/') SKIP(38);
      if (lookahead == 'h') ADVANCE(7);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(32);
      if (lookahead != 0) SKIP(33);
      END_STATE();
    case 33:
      if (eof) ADVANCE(40);
      if (lookahead == '*') SKIP(30);
      if (lookahead != 0) SKIP(33);
      END_STATE();
    case 34:
      if (eof) ADVANCE(40);
      if (lookahead == '*') SKIP(37);
      if (lookahead == '/') SKIP(34);
      if (lookahead == 'h') ADVANCE(19);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(39);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(0);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(39);
      END_STATE();
    case 35:
      if (eof) ADVANCE(40);
      if (lookahead == '*') SKIP(37);
      if (lookahead == '/') SKIP(35);
      if (lookahead == 'h') ADVANCE(13);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(37);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(32);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(33);
      if (lookahead != 0) SKIP(37);
      END_STATE();
    case 36:
      if (eof) ADVANCE(40);
      if (lookahead == '*') SKIP(36);
      if (lookahead == '/') SKIP(34);
      if (lookahead == 'h') ADVANCE(13);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(37);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(32);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(33);
      if (lookahead != 0) SKIP(37);
      END_STATE();
    case 37:
      if (eof) ADVANCE(40);
      if (lookahead == '*') SKIP(36);
      if (lookahead == '/') SKIP(35);
      if (lookahead == 'h') ADVANCE(13);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(37);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(32);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(33);
      if (lookahead != 0) SKIP(37);
      END_STATE();
    case 38:
      if (eof) ADVANCE(40);
      if (lookahead == '*') SKIP(31);
      if (lookahead == '/') SKIP(37);
      if (lookahead != 0) SKIP(33);
      END_STATE();
    case 39:
      if (eof) ADVANCE(40);
      if (lookahead == '/') SKIP(34);
      if (lookahead == 'h') ADVANCE(19);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(39);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(0);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(39);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_hello);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_hello);
      if (lookahead == 'h') ADVANCE(19);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_hello);
      if (lookahead == 'h') ADVANCE(13);
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
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_hello] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(4),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_hello] = ACTIONS(5),
  },
  [2] = {
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(7),
    [anon_sym_hello] = ACTIONS(9),
  },
  [3] = {
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(11),
    [anon_sym_hello] = ACTIONS(13),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 1,
    ACTIONS(16), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [13] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [16] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
