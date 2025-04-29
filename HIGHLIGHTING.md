# Highlighting
To produce highlighting using the CLI tool, a config first needs to be generated. Do so using the CLI:
```
tree-sitter init-config
```

Afterwards, replace the contents of the `theme` with the following snippet. The colors aim to correspond to the default values provided by tree-sitter but include extra highlight names (or tags) as per neovim tree sitter integrations.
```
    "punctuation.delimiter": 239,
    "punctuation.bracket":   239,
    "punctuation.special":   239,

    "variable": null,
    "variable.parameter": {
        "underline": true
    },
    "variable.builtin": {
        "bold": true
    },
    "variable.parameter.builtin": null,
    "variable.member": null,

    "embedded": null,

    "constant": 94,
    "constant.builtin": {
        "color": 94,
        "bold": true
    },
    "constant.macro": 94,

    "function": 26,
    "function.builtin": {
        "bold": true,
        "color": 26
    },
    "function.call": 26,
    "function.macro": 26,
    "function.method": 26,
    "function.method.call": 26,

    "constructor": 136,
    
    "string": 28,
    "string.documentation": 28,
    "string.regexp": 28,
    "string.escape": 28,
    "string.special": 30,
    "string.special.symbol": 30,
    "string.special.url": 30,
    "string.special.path": 30,

    "character": null,
    "character.special": null,

    "tag": 18,
    "tag.builtin": 18,
    "tag.attribute": 18,
    "tag.delimiter": 18,

    "type": 23,
    "type.builtin": {
        "color": 23,
        "bold": true
    },
    "type.definition": 23,

    "operator": {
        "color": 239,
        "bold": true
    },

    "comment": {
        "italic": true,
        "color": 245
    },
    "comment.documentation": 245,
    "comment.error": 245,
    "comment.warning": 245,
    "comment.todo": 245,
    "comment.note": 245,

    "module": 136,
    "module.builtin": 136,

    "label": null,

    "attribute": {
        "color": 124,
        "italic": true
    },
    "attribute.builtin": {
        "color": 124,
        "bold": true
    },

    "property": 124,

    "number": {
        "color": 94,
        "bold": true
    },
    "number.float": {
        "color": 94,
        "bold": true
    },
    "boolean": 94,

    "keyword": 56,
    "keyword.coroutine": 56,
    "keyword.function": 56,
    "keyword.operator": 56,
    "keyword.import": 56,
    "keyword.type": 56,
    "keyword.modifier": 56,
    "keyword.repeat": 56,
    "keyword.return": 56,
    "keyword.debug": 56,
    "keyword.exception": 56,
    "keyword.conditional": 56,
    "keyword.conditional.ternary": 56,
    "keyword.directive": 56,
    "keyword.directive.define": 56,

    "markup.strong": null,
    "markup.italic": null,
    "markup.strikethrough": null,
    "markup.underline": null,
    "markup.heading": null,
    "markup.heading.1": null,
    "markup.heading.2": null,
    "markup.heading.3": null,
    "markup.heading.4": null,
    "markup.heading.5": null,
    "markup.heading.6": null,
    "markup.quote": null,
    "markup.math": null,
    "markup.link": null,
    "markup.link.label": null,
    "markup.link.url": null,
    "markup.raw": null,
    "markup.raw.block": null,
    "markup.list": null,
    "markup.list.checked": null,
    "markup.list.unchecked": null,

    "diff.plus": null,
    "diff.minus": null,
    "diff.delta": null,

    "none": null,
    "conceal": null,

    "spell": null,
    "nospell": null,
```
