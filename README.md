# tree-sitter-mal

MAL grammar for [tree-sitter](https://github.com/tree-sitter/tree-sitter).

References
- [MAL Wiki](https://github.com/mal-lang/mal-documentation/wiki)
  - [MAL Syntax](https://github.com/mal-lang/mal-documentation/wiki/MAL-Syntax)
- [MAL Compiler Wiki](https://github.com/mal-lang/malcompiler/wiki/)
  - [MAL Language Specification](https://github.com/mal-lang/malcompiler/wiki/MAL-language-specification)
- [MAL Grammar Implementation](https://github.com/mal-lang/mal-toolbox/blob/main/maltoolbox/language/compiler/mal.g4)
- [MAL Vim Syntax Highlighting](https://github.com/nkakouros-original/mal.vim)

## Usage
[Install tree sitter CLI](https://github.com/tree-sitter/tree-sitter/blob/master/cli/README.md) to be able to use this grammar. Then, run `tree-sitter generate` to generate the parser from the grammar and `tree-sitter test` to test the parser, as well as the syntax highlighting and code navigation queries.

To see the parse tree the parser generates, use the command [`tree-sitter parse`](https://tree-sitter.github.io/tree-sitter/cli/parse.html).

To use the highlight through the command line, make sure you have a [config file initialized](https://tree-sitter.github.io/tree-sitter/cli/init-config.html). Then, you can use your own highlighting colors or copy the ones in the repository, specialized for MAL. Lastly, use `tree-sitter highlight` to generate an output, see the [docs](https://tree-sitter.github.io/tree-sitter/cli/highlight.html) for more information.

For more commands see [tree sitter CLI docs](https://tree-sitter.github.io/tree-sitter/cli/index.html).

### NeoVim Manual Installation
> [!NOTE]
> Tested for NeoVim v0.10.4.
