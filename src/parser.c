#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 8
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 7
#define ALIAS_COUNT 0
#define TOKEN_COUNT 3
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 1
#define MAX_ALIAS_SEQUENCE_LENGTH 2
#define PRODUCTION_ID_COUNT 2

enum ts_symbol_identifiers {
  anon_sym_include = 1,
  sym_string = 2,
  sym_source_file = 3,
  sym_declaration = 4,
  sym_include_declaration = 5,
  aux_sym_source_file_repeat1 = 6,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_include] = "include",
  [sym_string] = "string",
  [sym_source_file] = "source_file",
  [sym_declaration] = "declaration",
  [sym_include_declaration] = "include_declaration",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_include] = anon_sym_include,
  [sym_string] = sym_string,
  [sym_source_file] = sym_source_file,
  [sym_declaration] = sym_declaration,
  [sym_include_declaration] = sym_include_declaration,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(154);
      if (lookahead == '"') ADVANCE(25);
      if (lookahead == '/') SKIP(137);
      if (lookahead == 'i') ADVANCE(129);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(25);
      if (lookahead == '/') SKIP(79);
      if (lookahead == 'i') ADVANCE(129);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(25);
      if (lookahead == '/') SKIP(116);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(164);
      if (lookahead == '*') ADVANCE(12);
      if (lookahead == '/') ADVANCE(44);
      if (lookahead == '\\') ADVANCE(28);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(164);
      if (lookahead == '*') ADVANCE(4);
      if (lookahead == '/') ADVANCE(26);
      if (lookahead == '\\') ADVANCE(56);
      if (lookahead != 0) ADVANCE(12);
      END_STATE();
    case 5:
      if (lookahead == '"') ADVANCE(164);
      if (lookahead == '*') ADVANCE(4);
      if (lookahead == '/') ADVANCE(55);
      if (lookahead == '\\') ADVANCE(56);
      if (lookahead != 0) ADVANCE(12);
      END_STATE();
    case 6:
      if (lookahead == '"') ADVANCE(164);
      if (lookahead == '*') ADVANCE(4);
      if (lookahead == '\\') ADVANCE(56);
      if (lookahead == 'c') ADVANCE(9);
      if (lookahead != 0) ADVANCE(12);
      END_STATE();
    case 7:
      if (lookahead == '"') ADVANCE(164);
      if (lookahead == '*') ADVANCE(4);
      if (lookahead == '\\') ADVANCE(56);
      if (lookahead == 'd') ADVANCE(8);
      if (lookahead != 0) ADVANCE(12);
      END_STATE();
    case 8:
      if (lookahead == '"') ADVANCE(164);
      if (lookahead == '*') ADVANCE(4);
      if (lookahead == '\\') ADVANCE(56);
      if (lookahead == 'e') ADVANCE(156);
      if (lookahead != 0) ADVANCE(12);
      END_STATE();
    case 9:
      if (lookahead == '"') ADVANCE(164);
      if (lookahead == '*') ADVANCE(4);
      if (lookahead == '\\') ADVANCE(56);
      if (lookahead == 'l') ADVANCE(11);
      if (lookahead != 0) ADVANCE(12);
      END_STATE();
    case 10:
      if (lookahead == '"') ADVANCE(164);
      if (lookahead == '*') ADVANCE(4);
      if (lookahead == '\\') ADVANCE(56);
      if (lookahead == 'n') ADVANCE(6);
      if (lookahead != 0) ADVANCE(12);
      END_STATE();
    case 11:
      if (lookahead == '"') ADVANCE(164);
      if (lookahead == '*') ADVANCE(4);
      if (lookahead == '\\') ADVANCE(56);
      if (lookahead == 'u') ADVANCE(7);
      if (lookahead != 0) ADVANCE(12);
      END_STATE();
    case 12:
      if (lookahead == '"') ADVANCE(164);
      if (lookahead == '*') ADVANCE(4);
      if (lookahead == '\\') ADVANCE(56);
      if (lookahead != 0) ADVANCE(12);
      END_STATE();
    case 13:
      if (lookahead == '"') ADVANCE(164);
      if (lookahead == '*') ADVANCE(5);
      if (lookahead == '/') ADVANCE(53);
      if (lookahead == '\\') ADVANCE(56);
      if (lookahead != 0) ADVANCE(12);
      END_STATE();
    case 14:
      if (lookahead == '"') ADVANCE(164);
      if (lookahead == '*') ADVANCE(14);
      if (lookahead == '/') ADVANCE(27);
      if (lookahead == '\\') ADVANCE(78);
      if (lookahead != 0) ADVANCE(16);
      END_STATE();
    case 15:
      if (lookahead == '"') ADVANCE(164);
      if (lookahead == '*') ADVANCE(14);
      if (lookahead == '/') ADVANCE(77);
      if (lookahead == '\\') ADVANCE(78);
      if (lookahead != 0) ADVANCE(16);
      END_STATE();
    case 16:
      if (lookahead == '"') ADVANCE(164);
      if (lookahead == '*') ADVANCE(14);
      if (lookahead == '\\') ADVANCE(78);
      if (lookahead != 0) ADVANCE(16);
      END_STATE();
    case 17:
      if (lookahead == '"') ADVANCE(164);
      if (lookahead == '*') ADVANCE(15);
      if (lookahead == '/') ADVANCE(63);
      if (lookahead == '\\') ADVANCE(78);
      if (lookahead != 0) ADVANCE(16);
      END_STATE();
    case 18:
      if (lookahead == '"') ADVANCE(164);
      if (lookahead == '*') ADVANCE(16);
      if (lookahead == '/') ADVANCE(60);
      if (lookahead == '\\') ADVANCE(28);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 19:
      if (lookahead == '"') ADVANCE(164);
      if (lookahead == '\\') ADVANCE(28);
      if (lookahead == 'c') ADVANCE(22);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 20:
      if (lookahead == '"') ADVANCE(164);
      if (lookahead == '\\') ADVANCE(28);
      if (lookahead == 'd') ADVANCE(21);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 21:
      if (lookahead == '"') ADVANCE(164);
      if (lookahead == '\\') ADVANCE(28);
      if (lookahead == 'e') ADVANCE(157);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 22:
      if (lookahead == '"') ADVANCE(164);
      if (lookahead == '\\') ADVANCE(28);
      if (lookahead == 'l') ADVANCE(24);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 23:
      if (lookahead == '"') ADVANCE(164);
      if (lookahead == '\\') ADVANCE(28);
      if (lookahead == 'n') ADVANCE(19);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 24:
      if (lookahead == '"') ADVANCE(164);
      if (lookahead == '\\') ADVANCE(28);
      if (lookahead == 'u') ADVANCE(20);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 25:
      if (lookahead == '"') ADVANCE(164);
      if (lookahead == '\\') ADVANCE(28);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 26:
      if (lookahead == '"') ADVANCE(167);
      if (lookahead == '/') ADVANCE(3);
      if (lookahead == '\\') ADVANCE(28);
      if (lookahead == 'i') ADVANCE(23);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(26);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 27:
      if (lookahead == '"') ADVANCE(167);
      if (lookahead == '/') ADVANCE(18);
      if (lookahead == '\\') ADVANCE(28);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(27);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 28:
      if (lookahead == '"') ADVANCE(167);
      if (lookahead == '\\') ADVANCE(28);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 29:
      if (lookahead == '"') ADVANCE(44);
      if (lookahead == '*') SKIP(72);
      if (lookahead == '/') SKIP(29);
      if (lookahead == 'i') ADVANCE(34);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(36);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(1);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(36);
      END_STATE();
    case 30:
      if (lookahead == '"') ADVANCE(44);
      if (lookahead == '/') SKIP(29);
      if (lookahead == 'c') ADVANCE(33);
      if (lookahead == 'i') ADVANCE(34);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(36);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(1);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(36);
      END_STATE();
    case 31:
      if (lookahead == '"') ADVANCE(44);
      if (lookahead == '/') SKIP(29);
      if (lookahead == 'd') ADVANCE(32);
      if (lookahead == 'i') ADVANCE(34);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(36);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(1);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(36);
      END_STATE();
    case 32:
      if (lookahead == '"') ADVANCE(44);
      if (lookahead == '/') SKIP(29);
      if (lookahead == 'e') ADVANCE(158);
      if (lookahead == 'i') ADVANCE(34);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(36);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(1);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(36);
      END_STATE();
    case 33:
      if (lookahead == '"') ADVANCE(44);
      if (lookahead == '/') SKIP(29);
      if (lookahead == 'i') ADVANCE(34);
      if (lookahead == 'l') ADVANCE(35);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(36);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(1);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(36);
      END_STATE();
    case 34:
      if (lookahead == '"') ADVANCE(44);
      if (lookahead == '/') SKIP(29);
      if (lookahead == 'i') ADVANCE(34);
      if (lookahead == 'n') ADVANCE(30);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(36);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(1);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(36);
      END_STATE();
    case 35:
      if (lookahead == '"') ADVANCE(44);
      if (lookahead == '/') SKIP(29);
      if (lookahead == 'i') ADVANCE(34);
      if (lookahead == 'u') ADVANCE(31);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(36);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(1);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(36);
      END_STATE();
    case 36:
      if (lookahead == '"') ADVANCE(44);
      if (lookahead == '/') SKIP(29);
      if (lookahead == 'i') ADVANCE(34);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(36);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(1);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(36);
      END_STATE();
    case 37:
      ADVANCE_MAP(
        '"', 168,
        '*', 53,
        '/', 37,
        '\\', 44,
        'i', 42,
        '\t', 44,
        ' ', 44,
        '\n', 26,
        '\r', 26,
        0x2028, 25,
        0x2029, 25,
      );
      if (lookahead != 0) ADVANCE(44);
      END_STATE();
    case 38:
      ADVANCE_MAP(
        '"', 168,
        '/', 37,
        '\\', 44,
        'c', 41,
        'i', 42,
        '\t', 44,
        ' ', 44,
        '\n', 26,
        '\r', 26,
        0x2028, 25,
        0x2029, 25,
      );
      if (lookahead != 0) ADVANCE(44);
      END_STATE();
    case 39:
      ADVANCE_MAP(
        '"', 168,
        '/', 37,
        '\\', 44,
        'd', 40,
        'i', 42,
        '\t', 44,
        ' ', 44,
        '\n', 26,
        '\r', 26,
        0x2028, 25,
        0x2029, 25,
      );
      if (lookahead != 0) ADVANCE(44);
      END_STATE();
    case 40:
      ADVANCE_MAP(
        '"', 168,
        '/', 37,
        '\\', 44,
        'e', 159,
        'i', 42,
        '\t', 44,
        ' ', 44,
        '\n', 26,
        '\r', 26,
        0x2028, 25,
        0x2029, 25,
      );
      if (lookahead != 0) ADVANCE(44);
      END_STATE();
    case 41:
      ADVANCE_MAP(
        '"', 168,
        '/', 37,
        '\\', 44,
        'i', 42,
        'l', 43,
        '\t', 44,
        ' ', 44,
        '\n', 26,
        '\r', 26,
        0x2028, 25,
        0x2029, 25,
      );
      if (lookahead != 0) ADVANCE(44);
      END_STATE();
    case 42:
      ADVANCE_MAP(
        '"', 168,
        '/', 37,
        '\\', 44,
        'i', 42,
        'n', 38,
        '\t', 44,
        ' ', 44,
        '\n', 26,
        '\r', 26,
        0x2028, 25,
        0x2029, 25,
      );
      if (lookahead != 0) ADVANCE(44);
      END_STATE();
    case 43:
      ADVANCE_MAP(
        '"', 168,
        '/', 37,
        '\\', 44,
        'i', 42,
        'u', 39,
        '\t', 44,
        ' ', 44,
        '\n', 26,
        '\r', 26,
        0x2028, 25,
        0x2029, 25,
      );
      if (lookahead != 0) ADVANCE(44);
      END_STATE();
    case 44:
      ADVANCE_MAP(
        '"', 168,
        '/', 37,
        '\\', 44,
        'i', 42,
        '\t', 44,
        ' ', 44,
        '\n', 26,
        '\r', 26,
        0x2028, 25,
        0x2029, 25,
      );
      if (lookahead != 0) ADVANCE(44);
      END_STATE();
    case 45:
      ADVANCE_MAP(
        '"', 169,
        '*', 53,
        '/', 45,
        '\\', 53,
        'i', 51,
        '\t', 53,
        ' ', 53,
        '\n', 55,
        '\r', 55,
        0x2028, 12,
        0x2029, 12,
      );
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 46:
      ADVANCE_MAP(
        '"', 169,
        '*', 46,
        '/', 37,
        '\\', 53,
        'i', 51,
        '\t', 53,
        ' ', 53,
        '\n', 55,
        '\r', 55,
        0x2028, 12,
        0x2029, 12,
      );
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 47:
      ADVANCE_MAP(
        '"', 169,
        '*', 46,
        '/', 45,
        '\\', 53,
        'c', 50,
        'i', 51,
        '\t', 53,
        ' ', 53,
        '\n', 55,
        '\r', 55,
        0x2028, 12,
        0x2029, 12,
      );
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 48:
      ADVANCE_MAP(
        '"', 169,
        '*', 46,
        '/', 45,
        '\\', 53,
        'd', 49,
        'i', 51,
        '\t', 53,
        ' ', 53,
        '\n', 55,
        '\r', 55,
        0x2028, 12,
        0x2029, 12,
      );
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 49:
      ADVANCE_MAP(
        '"', 169,
        '*', 46,
        '/', 45,
        '\\', 53,
        'e', 160,
        'i', 51,
        '\t', 53,
        ' ', 53,
        '\n', 55,
        '\r', 55,
        0x2028, 12,
        0x2029, 12,
      );
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 50:
      ADVANCE_MAP(
        '"', 169,
        '*', 46,
        '/', 45,
        '\\', 53,
        'i', 51,
        'l', 52,
        '\t', 53,
        ' ', 53,
        '\n', 55,
        '\r', 55,
        0x2028, 12,
        0x2029, 12,
      );
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 51:
      ADVANCE_MAP(
        '"', 169,
        '*', 46,
        '/', 45,
        '\\', 53,
        'i', 51,
        'n', 47,
        '\t', 53,
        ' ', 53,
        '\n', 55,
        '\r', 55,
        0x2028, 12,
        0x2029, 12,
      );
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 52:
      ADVANCE_MAP(
        '"', 169,
        '*', 46,
        '/', 45,
        '\\', 53,
        'i', 51,
        'u', 48,
        '\t', 53,
        ' ', 53,
        '\n', 55,
        '\r', 55,
        0x2028, 12,
        0x2029, 12,
      );
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 53:
      ADVANCE_MAP(
        '"', 169,
        '*', 46,
        '/', 45,
        '\\', 53,
        'i', 51,
        '\t', 53,
        ' ', 53,
        '\n', 55,
        '\r', 55,
        0x2028, 12,
        0x2029, 12,
      );
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 54:
      if (lookahead == '"') ADVANCE(12);
      if (lookahead == '*') SKIP(80);
      if (lookahead == '/') SKIP(99);
      if (lookahead == 'i') ADVANCE(86);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(54);
      if (lookahead != 0) SKIP(88);
      END_STATE();
    case 55:
      ADVANCE_MAP(
        '"', 165,
        '*', 4,
        '/', 13,
        '\\', 56,
        'i', 10,
        '\t', 55,
        '\n', 55,
        '\r', 55,
        ' ', 55,
      );
      if (lookahead != 0) ADVANCE(12);
      END_STATE();
    case 56:
      if (lookahead == '"') ADVANCE(165);
      if (lookahead == '*') ADVANCE(4);
      if (lookahead == '\\') ADVANCE(56);
      if (lookahead != 0) ADVANCE(12);
      END_STATE();
    case 57:
      if (lookahead == '"') ADVANCE(60);
      if (lookahead == '*') SKIP(75);
      if (lookahead == '/') SKIP(57);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(58);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(2);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(58);
      END_STATE();
    case 58:
      if (lookahead == '"') ADVANCE(60);
      if (lookahead == '/') SKIP(57);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(58);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(2);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(58);
      END_STATE();
    case 59:
      ADVANCE_MAP(
        '"', 170,
        '*', 63,
        '/', 59,
        '\\', 60,
        '\t', 60,
        ' ', 60,
        '\n', 27,
        '\r', 27,
        0x2028, 25,
        0x2029, 25,
      );
      if (lookahead != 0) ADVANCE(60);
      END_STATE();
    case 60:
      ADVANCE_MAP(
        '"', 170,
        '/', 59,
        '\\', 60,
        '\t', 60,
        ' ', 60,
        '\n', 27,
        '\r', 27,
        0x2028, 25,
        0x2029, 25,
      );
      if (lookahead != 0) ADVANCE(60);
      END_STATE();
    case 61:
      ADVANCE_MAP(
        '"', 171,
        '*', 63,
        '/', 61,
        '\\', 63,
        '\t', 63,
        ' ', 63,
        '\n', 77,
        '\r', 77,
        0x2028, 16,
        0x2029, 16,
      );
      if (lookahead != 0) ADVANCE(63);
      END_STATE();
    case 62:
      ADVANCE_MAP(
        '"', 171,
        '*', 62,
        '/', 59,
        '\\', 63,
        '\t', 63,
        ' ', 63,
        '\n', 77,
        '\r', 77,
        0x2028, 16,
        0x2029, 16,
      );
      if (lookahead != 0) ADVANCE(63);
      END_STATE();
    case 63:
      ADVANCE_MAP(
        '"', 171,
        '*', 62,
        '/', 61,
        '\\', 63,
        '\t', 63,
        ' ', 63,
        '\n', 77,
        '\r', 77,
        0x2028, 16,
        0x2029, 16,
      );
      if (lookahead != 0) ADVANCE(63);
      END_STATE();
    case 64:
      if (lookahead == '"') ADVANCE(53);
      if (lookahead == '*') SKIP(72);
      if (lookahead == '/') SKIP(64);
      if (lookahead == 'i') ADVANCE(70);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(72);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(54);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(88);
      if (lookahead != 0) SKIP(72);
      END_STATE();
    case 65:
      if (lookahead == '"') ADVANCE(53);
      if (lookahead == '*') SKIP(65);
      if (lookahead == '/') SKIP(29);
      if (lookahead == 'i') ADVANCE(70);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(72);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(54);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(88);
      if (lookahead != 0) SKIP(72);
      END_STATE();
    case 66:
      if (lookahead == '"') ADVANCE(53);
      if (lookahead == '*') SKIP(65);
      if (lookahead == '/') SKIP(64);
      if (lookahead == 'c') ADVANCE(69);
      if (lookahead == 'i') ADVANCE(70);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(72);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(54);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(88);
      if (lookahead != 0) SKIP(72);
      END_STATE();
    case 67:
      if (lookahead == '"') ADVANCE(53);
      if (lookahead == '*') SKIP(65);
      if (lookahead == '/') SKIP(64);
      if (lookahead == 'd') ADVANCE(68);
      if (lookahead == 'i') ADVANCE(70);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(72);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(54);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(88);
      if (lookahead != 0) SKIP(72);
      END_STATE();
    case 68:
      if (lookahead == '"') ADVANCE(53);
      if (lookahead == '*') SKIP(65);
      if (lookahead == '/') SKIP(64);
      if (lookahead == 'e') ADVANCE(161);
      if (lookahead == 'i') ADVANCE(70);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(72);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(54);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(88);
      if (lookahead != 0) SKIP(72);
      END_STATE();
    case 69:
      if (lookahead == '"') ADVANCE(53);
      if (lookahead == '*') SKIP(65);
      if (lookahead == '/') SKIP(64);
      if (lookahead == 'i') ADVANCE(70);
      if (lookahead == 'l') ADVANCE(71);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(72);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(54);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(88);
      if (lookahead != 0) SKIP(72);
      END_STATE();
    case 70:
      if (lookahead == '"') ADVANCE(53);
      if (lookahead == '*') SKIP(65);
      if (lookahead == '/') SKIP(64);
      if (lookahead == 'i') ADVANCE(70);
      if (lookahead == 'n') ADVANCE(66);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(72);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(54);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(88);
      if (lookahead != 0) SKIP(72);
      END_STATE();
    case 71:
      if (lookahead == '"') ADVANCE(53);
      if (lookahead == '*') SKIP(65);
      if (lookahead == '/') SKIP(64);
      if (lookahead == 'i') ADVANCE(70);
      if (lookahead == 'u') ADVANCE(67);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(72);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(54);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(88);
      if (lookahead != 0) SKIP(72);
      END_STATE();
    case 72:
      if (lookahead == '"') ADVANCE(53);
      if (lookahead == '*') SKIP(65);
      if (lookahead == '/') SKIP(64);
      if (lookahead == 'i') ADVANCE(70);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(72);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(54);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(88);
      if (lookahead != 0) SKIP(72);
      END_STATE();
    case 73:
      if (lookahead == '"') ADVANCE(63);
      if (lookahead == '*') SKIP(75);
      if (lookahead == '/') SKIP(73);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(75);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(76);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(113);
      if (lookahead != 0) SKIP(75);
      END_STATE();
    case 74:
      if (lookahead == '"') ADVANCE(63);
      if (lookahead == '*') SKIP(74);
      if (lookahead == '/') SKIP(57);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(75);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(76);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(113);
      if (lookahead != 0) SKIP(75);
      END_STATE();
    case 75:
      if (lookahead == '"') ADVANCE(63);
      if (lookahead == '*') SKIP(74);
      if (lookahead == '/') SKIP(73);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(75);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(76);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(113);
      if (lookahead != 0) SKIP(75);
      END_STATE();
    case 76:
      if (lookahead == '"') ADVANCE(16);
      if (lookahead == '*') SKIP(111);
      if (lookahead == '/') SKIP(114);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(76);
      if (lookahead != 0) SKIP(113);
      END_STATE();
    case 77:
      if (lookahead == '"') ADVANCE(166);
      if (lookahead == '*') ADVANCE(14);
      if (lookahead == '/') ADVANCE(17);
      if (lookahead == '\\') ADVANCE(78);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(77);
      if (lookahead != 0) ADVANCE(16);
      END_STATE();
    case 78:
      if (lookahead == '"') ADVANCE(166);
      if (lookahead == '*') ADVANCE(14);
      if (lookahead == '\\') ADVANCE(78);
      if (lookahead != 0) ADVANCE(16);
      END_STATE();
    case 79:
      if (lookahead == '*') SKIP(88);
      if (lookahead == '/') SKIP(36);
      END_STATE();
    case 80:
      if (lookahead == '*') SKIP(80);
      if (lookahead == '/') SKIP(1);
      if (lookahead != 0) SKIP(88);
      END_STATE();
    case 81:
      if (lookahead == '*') SKIP(80);
      if (lookahead == '/') SKIP(54);
      if (lookahead != 0) SKIP(88);
      END_STATE();
    case 82:
      if (lookahead == '*') SKIP(80);
      if (lookahead == 'c') ADVANCE(85);
      if (lookahead != 0) SKIP(88);
      END_STATE();
    case 83:
      if (lookahead == '*') SKIP(80);
      if (lookahead == 'd') ADVANCE(84);
      if (lookahead != 0) SKIP(88);
      END_STATE();
    case 84:
      if (lookahead == '*') SKIP(80);
      if (lookahead == 'e') ADVANCE(155);
      if (lookahead != 0) SKIP(88);
      END_STATE();
    case 85:
      if (lookahead == '*') SKIP(80);
      if (lookahead == 'l') ADVANCE(87);
      if (lookahead != 0) SKIP(88);
      END_STATE();
    case 86:
      if (lookahead == '*') SKIP(80);
      if (lookahead == 'n') ADVANCE(82);
      if (lookahead != 0) SKIP(88);
      END_STATE();
    case 87:
      if (lookahead == '*') SKIP(80);
      if (lookahead == 'u') ADVANCE(83);
      if (lookahead != 0) SKIP(88);
      END_STATE();
    case 88:
      if (lookahead == '*') SKIP(80);
      if (lookahead != 0) SKIP(88);
      END_STATE();
    case 89:
      if (lookahead == '*') SKIP(98);
      if (lookahead == '/') SKIP(89);
      if (lookahead == 'i') ADVANCE(121);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(123);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(124);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(123);
      END_STATE();
    case 90:
      if (lookahead == '*') SKIP(98);
      if (lookahead == '/') SKIP(90);
      if (lookahead == 'i') ADVANCE(96);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(98);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(102);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(109);
      if (lookahead != 0) SKIP(98);
      END_STATE();
    case 91:
      if (lookahead == '*') SKIP(91);
      if (lookahead == '/') SKIP(89);
      if (lookahead == 'i') ADVANCE(96);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(98);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(102);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(109);
      if (lookahead != 0) SKIP(98);
      END_STATE();
    case 92:
      if (lookahead == '*') SKIP(91);
      if (lookahead == '/') SKIP(90);
      if (lookahead == 'c') ADVANCE(95);
      if (lookahead == 'i') ADVANCE(96);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(98);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(102);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(109);
      if (lookahead != 0) SKIP(98);
      END_STATE();
    case 93:
      if (lookahead == '*') SKIP(91);
      if (lookahead == '/') SKIP(90);
      if (lookahead == 'd') ADVANCE(94);
      if (lookahead == 'i') ADVANCE(96);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(98);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(102);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(109);
      if (lookahead != 0) SKIP(98);
      END_STATE();
    case 94:
      if (lookahead == '*') SKIP(91);
      if (lookahead == '/') SKIP(90);
      if (lookahead == 'e') ADVANCE(163);
      if (lookahead == 'i') ADVANCE(96);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(98);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(102);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(109);
      if (lookahead != 0) SKIP(98);
      END_STATE();
    case 95:
      if (lookahead == '*') SKIP(91);
      if (lookahead == '/') SKIP(90);
      if (lookahead == 'i') ADVANCE(96);
      if (lookahead == 'l') ADVANCE(97);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(98);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(102);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(109);
      if (lookahead != 0) SKIP(98);
      END_STATE();
    case 96:
      if (lookahead == '*') SKIP(91);
      if (lookahead == '/') SKIP(90);
      if (lookahead == 'i') ADVANCE(96);
      if (lookahead == 'n') ADVANCE(92);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(98);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(102);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(109);
      if (lookahead != 0) SKIP(98);
      END_STATE();
    case 97:
      if (lookahead == '*') SKIP(91);
      if (lookahead == '/') SKIP(90);
      if (lookahead == 'i') ADVANCE(96);
      if (lookahead == 'u') ADVANCE(93);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(98);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(102);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(109);
      if (lookahead != 0) SKIP(98);
      END_STATE();
    case 98:
      if (lookahead == '*') SKIP(91);
      if (lookahead == '/') SKIP(90);
      if (lookahead == 'i') ADVANCE(96);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(98);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(102);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(109);
      if (lookahead != 0) SKIP(98);
      END_STATE();
    case 99:
      if (lookahead == '*') SKIP(81);
      if (lookahead == '/') SKIP(72);
      if (lookahead != 0) SKIP(88);
      END_STATE();
    case 100:
      if (lookahead == '*') SKIP(100);
      if (lookahead == '/') SKIP(124);
      if (lookahead != 0) SKIP(109);
      END_STATE();
    case 101:
      if (lookahead == '*') SKIP(100);
      if (lookahead == '/') SKIP(102);
      if (lookahead != 0) SKIP(109);
      END_STATE();
    case 102:
      if (lookahead == '*') SKIP(100);
      if (lookahead == '/') SKIP(110);
      if (lookahead == 'i') ADVANCE(107);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(102);
      if (lookahead != 0) SKIP(109);
      END_STATE();
    case 103:
      if (lookahead == '*') SKIP(100);
      if (lookahead == 'c') ADVANCE(106);
      if (lookahead != 0) SKIP(109);
      END_STATE();
    case 104:
      if (lookahead == '*') SKIP(100);
      if (lookahead == 'd') ADVANCE(105);
      if (lookahead != 0) SKIP(109);
      END_STATE();
    case 105:
      if (lookahead == '*') SKIP(100);
      if (lookahead == 'e') ADVANCE(155);
      if (lookahead != 0) SKIP(109);
      END_STATE();
    case 106:
      if (lookahead == '*') SKIP(100);
      if (lookahead == 'l') ADVANCE(108);
      if (lookahead != 0) SKIP(109);
      END_STATE();
    case 107:
      if (lookahead == '*') SKIP(100);
      if (lookahead == 'n') ADVANCE(103);
      if (lookahead != 0) SKIP(109);
      END_STATE();
    case 108:
      if (lookahead == '*') SKIP(100);
      if (lookahead == 'u') ADVANCE(104);
      if (lookahead != 0) SKIP(109);
      END_STATE();
    case 109:
      if (lookahead == '*') SKIP(100);
      if (lookahead != 0) SKIP(109);
      END_STATE();
    case 110:
      if (lookahead == '*') SKIP(101);
      if (lookahead == '/') SKIP(98);
      if (lookahead != 0) SKIP(109);
      END_STATE();
    case 111:
      if (lookahead == '*') SKIP(111);
      if (lookahead == '/') SKIP(2);
      if (lookahead != 0) SKIP(113);
      END_STATE();
    case 112:
      if (lookahead == '*') SKIP(111);
      if (lookahead == '/') SKIP(76);
      if (lookahead != 0) SKIP(113);
      END_STATE();
    case 113:
      if (lookahead == '*') SKIP(111);
      if (lookahead != 0) SKIP(113);
      END_STATE();
    case 114:
      if (lookahead == '*') SKIP(112);
      if (lookahead == '/') SKIP(75);
      if (lookahead != 0) SKIP(113);
      END_STATE();
    case 115:
      if (lookahead == '*') SKIP(109);
      if (lookahead == '/') SKIP(123);
      END_STATE();
    case 116:
      if (lookahead == '*') SKIP(113);
      if (lookahead == '/') SKIP(58);
      END_STATE();
    case 117:
      if (lookahead == '/') SKIP(89);
      if (lookahead == 'c') ADVANCE(120);
      if (lookahead == 'i') ADVANCE(121);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(123);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(124);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(123);
      END_STATE();
    case 118:
      if (lookahead == '/') SKIP(89);
      if (lookahead == 'd') ADVANCE(119);
      if (lookahead == 'i') ADVANCE(121);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(123);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(124);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(123);
      END_STATE();
    case 119:
      if (lookahead == '/') SKIP(89);
      if (lookahead == 'e') ADVANCE(162);
      if (lookahead == 'i') ADVANCE(121);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(123);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(124);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(123);
      END_STATE();
    case 120:
      if (lookahead == '/') SKIP(89);
      if (lookahead == 'i') ADVANCE(121);
      if (lookahead == 'l') ADVANCE(122);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(123);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(124);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(123);
      END_STATE();
    case 121:
      if (lookahead == '/') SKIP(89);
      if (lookahead == 'i') ADVANCE(121);
      if (lookahead == 'n') ADVANCE(117);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(123);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(124);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(123);
      END_STATE();
    case 122:
      if (lookahead == '/') SKIP(89);
      if (lookahead == 'i') ADVANCE(121);
      if (lookahead == 'u') ADVANCE(118);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(123);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(124);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(123);
      END_STATE();
    case 123:
      if (lookahead == '/') SKIP(89);
      if (lookahead == 'i') ADVANCE(121);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(123);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(124);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(123);
      END_STATE();
    case 124:
      if (lookahead == '/') SKIP(115);
      if (lookahead == 'i') ADVANCE(129);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(124);
      END_STATE();
    case 125:
      if (lookahead == 'c') ADVANCE(128);
      END_STATE();
    case 126:
      if (lookahead == 'd') ADVANCE(127);
      END_STATE();
    case 127:
      if (lookahead == 'e') ADVANCE(155);
      END_STATE();
    case 128:
      if (lookahead == 'l') ADVANCE(130);
      END_STATE();
    case 129:
      if (lookahead == 'n') ADVANCE(125);
      END_STATE();
    case 130:
      if (lookahead == 'u') ADVANCE(126);
      END_STATE();
    case 131:
      if (eof) ADVANCE(154);
      if (lookahead == '"') ADVANCE(44);
      if (lookahead == '*') SKIP(136);
      if (lookahead == '/') SKIP(131);
      if (lookahead == 'i') ADVANCE(34);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(132);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(0);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(132);
      END_STATE();
    case 132:
      if (eof) ADVANCE(154);
      if (lookahead == '"') ADVANCE(44);
      if (lookahead == '/') SKIP(131);
      if (lookahead == 'i') ADVANCE(34);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(132);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(0);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(132);
      END_STATE();
    case 133:
      if (eof) ADVANCE(154);
      if (lookahead == '"') ADVANCE(12);
      if (lookahead == '*') SKIP(138);
      if (lookahead == '/') SKIP(145);
      if (lookahead == 'i') ADVANCE(86);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(133);
      if (lookahead != 0) SKIP(140);
      END_STATE();
    case 134:
      if (eof) ADVANCE(154);
      if (lookahead == '"') ADVANCE(53);
      if (lookahead == '*') SKIP(136);
      if (lookahead == '/') SKIP(134);
      if (lookahead == 'i') ADVANCE(70);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(136);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(133);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(140);
      if (lookahead != 0) SKIP(136);
      END_STATE();
    case 135:
      if (eof) ADVANCE(154);
      if (lookahead == '"') ADVANCE(53);
      if (lookahead == '*') SKIP(135);
      if (lookahead == '/') SKIP(131);
      if (lookahead == 'i') ADVANCE(70);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(136);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(133);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(140);
      if (lookahead != 0) SKIP(136);
      END_STATE();
    case 136:
      if (eof) ADVANCE(154);
      if (lookahead == '"') ADVANCE(53);
      if (lookahead == '*') SKIP(135);
      if (lookahead == '/') SKIP(134);
      if (lookahead == 'i') ADVANCE(70);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(136);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(133);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(140);
      if (lookahead != 0) SKIP(136);
      END_STATE();
    case 137:
      if (eof) ADVANCE(154);
      if (lookahead == '*') SKIP(140);
      if (lookahead == '/') SKIP(132);
      END_STATE();
    case 138:
      if (eof) ADVANCE(154);
      if (lookahead == '*') SKIP(138);
      if (lookahead == '/') SKIP(0);
      if (lookahead != 0) SKIP(140);
      END_STATE();
    case 139:
      if (eof) ADVANCE(154);
      if (lookahead == '*') SKIP(138);
      if (lookahead == '/') SKIP(133);
      if (lookahead != 0) SKIP(140);
      END_STATE();
    case 140:
      if (eof) ADVANCE(154);
      if (lookahead == '*') SKIP(138);
      if (lookahead != 0) SKIP(140);
      END_STATE();
    case 141:
      if (eof) ADVANCE(154);
      if (lookahead == '*') SKIP(144);
      if (lookahead == '/') SKIP(141);
      if (lookahead == 'i') ADVANCE(121);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(152);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(153);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(152);
      END_STATE();
    case 142:
      if (eof) ADVANCE(154);
      if (lookahead == '*') SKIP(144);
      if (lookahead == '/') SKIP(142);
      if (lookahead == 'i') ADVANCE(96);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(144);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(148);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(149);
      if (lookahead != 0) SKIP(144);
      END_STATE();
    case 143:
      if (eof) ADVANCE(154);
      if (lookahead == '*') SKIP(143);
      if (lookahead == '/') SKIP(141);
      if (lookahead == 'i') ADVANCE(96);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(144);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(148);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(149);
      if (lookahead != 0) SKIP(144);
      END_STATE();
    case 144:
      if (eof) ADVANCE(154);
      if (lookahead == '*') SKIP(143);
      if (lookahead == '/') SKIP(142);
      if (lookahead == 'i') ADVANCE(96);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(144);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(148);
      if (lookahead == 0x2028 ||
          lookahead == 0x2029) SKIP(149);
      if (lookahead != 0) SKIP(144);
      END_STATE();
    case 145:
      if (eof) ADVANCE(154);
      if (lookahead == '*') SKIP(139);
      if (lookahead == '/') SKIP(136);
      if (lookahead != 0) SKIP(140);
      END_STATE();
    case 146:
      if (eof) ADVANCE(154);
      if (lookahead == '*') SKIP(146);
      if (lookahead == '/') SKIP(153);
      if (lookahead != 0) SKIP(149);
      END_STATE();
    case 147:
      if (eof) ADVANCE(154);
      if (lookahead == '*') SKIP(146);
      if (lookahead == '/') SKIP(148);
      if (lookahead != 0) SKIP(149);
      END_STATE();
    case 148:
      if (eof) ADVANCE(154);
      if (lookahead == '*') SKIP(146);
      if (lookahead == '/') SKIP(150);
      if (lookahead == 'i') ADVANCE(107);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(148);
      if (lookahead != 0) SKIP(149);
      END_STATE();
    case 149:
      if (eof) ADVANCE(154);
      if (lookahead == '*') SKIP(146);
      if (lookahead != 0) SKIP(149);
      END_STATE();
    case 150:
      if (eof) ADVANCE(154);
      if (lookahead == '*') SKIP(147);
      if (lookahead == '/') SKIP(144);
      if (lookahead != 0) SKIP(149);
      END_STATE();
    case 151:
      if (eof) ADVANCE(154);
      if (lookahead == '*') SKIP(149);
      if (lookahead == '/') SKIP(152);
      END_STATE();
    case 152:
      if (eof) ADVANCE(154);
      if (lookahead == '/') SKIP(141);
      if (lookahead == 'i') ADVANCE(121);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(152);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(153);
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) SKIP(152);
      END_STATE();
    case 153:
      if (eof) ADVANCE(154);
      if (lookahead == '/') SKIP(151);
      if (lookahead == 'i') ADVANCE(129);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(153);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(anon_sym_include);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(anon_sym_include);
      if (lookahead == '"') ADVANCE(164);
      if (lookahead == '*') ADVANCE(4);
      if (lookahead == '\\') ADVANCE(56);
      if (lookahead != 0) ADVANCE(12);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(anon_sym_include);
      if (lookahead == '"') ADVANCE(164);
      if (lookahead == '\\') ADVANCE(28);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(anon_sym_include);
      if (lookahead == '"') ADVANCE(44);
      if (lookahead == 'i') ADVANCE(34);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(anon_sym_include);
      ADVANCE_MAP(
        '"', 168,
        '/', 37,
        '\\', 44,
        'i', 42,
        '\t', 44,
        ' ', 44,
        '\n', 26,
        '\r', 26,
      );
      if (lookahead != 0 &&
          lookahead != 0x2028 &&
          lookahead != 0x2029) ADVANCE(44);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(anon_sym_include);
      ADVANCE_MAP(
        '"', 169,
        '*', 46,
        '/', 45,
        '\\', 53,
        'i', 51,
        '\t', 53,
        ' ', 53,
        '\n', 55,
        '\r', 55,
        0x2028, 12,
        0x2029, 12,
      );
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(anon_sym_include);
      if (lookahead == '"') ADVANCE(53);
      if (lookahead == 'i') ADVANCE(70);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(anon_sym_include);
      if (lookahead == 'i') ADVANCE(121);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(anon_sym_include);
      if (lookahead == 'i') ADVANCE(96);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(sym_string);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(sym_string);
      if (lookahead == '"') ADVANCE(164);
      if (lookahead == '*') ADVANCE(4);
      if (lookahead == '\\') ADVANCE(56);
      if (lookahead != 0) ADVANCE(12);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(sym_string);
      if (lookahead == '"') ADVANCE(164);
      if (lookahead == '*') ADVANCE(14);
      if (lookahead == '\\') ADVANCE(78);
      if (lookahead != 0) ADVANCE(16);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(sym_string);
      if (lookahead == '"') ADVANCE(164);
      if (lookahead == '\\') ADVANCE(28);
      if (lookahead != 0) ADVANCE(25);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(sym_string);
      ADVANCE_MAP(
        '"', 168,
        '/', 37,
        '\\', 44,
        'i', 42,
        '\t', 44,
        ' ', 44,
        '\n', 26,
        '\r', 26,
        0x2028, 25,
        0x2029, 25,
      );
      if (lookahead != 0) ADVANCE(44);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(sym_string);
      ADVANCE_MAP(
        '"', 169,
        '*', 46,
        '/', 45,
        '\\', 53,
        'i', 51,
        '\t', 53,
        ' ', 53,
        '\n', 55,
        '\r', 55,
        0x2028, 12,
        0x2029, 12,
      );
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(sym_string);
      ADVANCE_MAP(
        '"', 170,
        '/', 59,
        '\\', 60,
        '\t', 60,
        ' ', 60,
        '\n', 27,
        '\r', 27,
        0x2028, 25,
        0x2029, 25,
      );
      if (lookahead != 0) ADVANCE(60);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(sym_string);
      ADVANCE_MAP(
        '"', 171,
        '*', 62,
        '/', 61,
        '\\', 63,
        '\t', 63,
        ' ', 63,
        '\n', 77,
        '\r', 77,
        0x2028, 16,
        0x2029, 16,
      );
      if (lookahead != 0) ADVANCE(63);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 153},
  [2] = {.lex_state = 153},
  [3] = {.lex_state = 153},
  [4] = {.lex_state = 153},
  [5] = {.lex_state = 153},
  [6] = {.lex_state = 2},
  [7] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_include] = ACTIONS(1),
    [sym_string] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(7),
    [sym_declaration] = STATE(2),
    [sym_include_declaration] = STATE(4),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_include] = ACTIONS(5),
  },
  [2] = {
    [sym_declaration] = STATE(3),
    [sym_include_declaration] = STATE(4),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(7),
    [anon_sym_include] = ACTIONS(5),
  },
  [3] = {
    [sym_declaration] = STATE(3),
    [sym_include_declaration] = STATE(4),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(9),
    [anon_sym_include] = ACTIONS(11),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 1,
    ACTIONS(14), 2,
      ts_builtin_sym_end,
      anon_sym_include,
  [5] = 1,
    ACTIONS(16), 2,
      ts_builtin_sym_end,
      anon_sym_include,
  [10] = 1,
    ACTIONS(18), 1,
      sym_string,
  [14] = 1,
    ACTIONS(20), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 5,
  [SMALL_STATE(6)] = 10,
  [SMALL_STATE(7)] = 14,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [11] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(6),
  [14] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_declaration, 1, 0, 0),
  [16] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_declaration, 2, 0, 1),
  [18] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [20] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
