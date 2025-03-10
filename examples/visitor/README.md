# Visitor Pattern Example
This example showcases how a visitor pattern can be built to use the MAL parser.

# Running
1. Install [tree-sitter-cli](https://github.com/tree-sitter/tree-sitter/tree/master/cli)
2. Build the language in the project root folder using `tree-sitter build`
4. Navigate to `./examples/visitor/`
  1. Create a virtual environment `python -m venv venv`
  2. Activate the environment (e.g. `source ./venv/bin/activate`)
  3. Install dependencies `pip install -r requirements.txt`
5. Navigate back to project root
6. Build the python dependency using `pip install -e .`
7. (Optional) swap between fast or simple visitor patterns by editing `main.py` imports
8. Execute the main file `python main.py`
