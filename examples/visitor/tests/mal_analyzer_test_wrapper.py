from fast import MalCompiler
from mal_analyzer import malAnalyzer, malAnalyzerException

import os
import pytest
import re
from pathlib import Path

class AnalyzerTestWrapper(malAnalyzer):
    def __init__(self, input_string: str = None, test_file: str = None, error_msg: str = None) -> None:
        super().__init__()

        self.compiler = MalCompiler()
        try:
            if error_msg:
                with pytest.raises(malAnalyzerException, match=re.escape(error_msg)):
                    self._result = self.compiler.compile(test_file)
            else:
                self._result = self.compiler.compile(test_file)
        except SyntaxError:
            self._error = True
        except RuntimeError:
            self._error = True
    
    def test(self, 
        error:bool=False, 
        warn:bool=False,
        defines:list=[], 
        categories:list=[], 
        assets:list=[], 
        lets:list=[], 
        associations:list=[],
        steps: list=[]):
        assert(self.compiler.analyzer.has_error() == error)
        if (warn):
            assert(self.compiler.analyzer.has_warning() == warn)
        if (defines):
            assert(set(defines) == set(self.compiler.analyzer._defines.keys()))
        if (categories):
            assert(set(categories) == set(self.compiler.analyzer._category.keys()))
        if (assets):
            assert(set(assets) == set(self.compiler.analyzer._assets.keys()))
        if (lets):
            assert(set(self.compiler.analyzer._vars.keys())==set([asset for asset, _ in lets]))
            for asset, variables in lets:
                assert(set(variables)==set(self.compiler.analyzer._vars[asset].keys()))
        if (associations):
            assert(set(self.compiler.analyzer._associations.keys())==set([asset for asset, _ in associations]))
            for asset, association_list in associations:
                assert(set(association_list)==set(self.compiler.analyzer._associations[asset].keys()))
        if (steps):
            assert(set(self.compiler.analyzer._steps.keys())==set([asset for asset, _ in steps]))
            for asset, step_list in steps:
                assert(set(step_list)==set(self.compiler.analyzer._steps[asset].keys()))
