from .mal_analyzer_test_wrapper import AnalyzerTestWrapper

from pathlib import Path
import pytest

'''
A file to test different cases of the `define` instruction in MAL.
'''

@pytest.mark.usefixtures("setup_test_environment")
@pytest.mark.parametrize("setup_test_environment", [Path(__file__).parent / "fixtures/define_test_files"], indirect=True)

def test_define_1() -> None:
    '''
    Defines only version.
    '''
    AnalyzerTestWrapper(
        test_file="test_define_1.mal",
        error_msg = 'Missing required define \'#id: ""\''
    )

def test_define_2() -> None:
    '''
    Defines only ID.
    '''
    AnalyzerTestWrapper(
        test_file="test_define_2.mal",
        error_msg='Missing required define \'#version: ""\''
    )

def test_define_3() -> None:
    '''
    Defines correct ID but wrong version.
    '''
    AnalyzerTestWrapper(
        test_file="test_define_3.mal",
        error_msg='Define \'version\' must be valid semantic versioning without pre-release identifier and build metadata'
    )

def test_define_4() -> None:
    '''
    Defines correct version and ID.
    '''
    AnalyzerTestWrapper(
        test_file="test_define_4.mal"
    ).test(
        defines=['id', 'version']
    )

def test_define_5() -> None:
    '''
    Defines correct version and ID, but version twice.
    '''
    AnalyzerTestWrapper(
        test_file="test_define_5.mal"
    ).test(
        defines=['id', 'version']
    )

def test_define_6() -> None:
    '''
    Defines correct version, ID.
    Defines Key with value.
    '''
    AnalyzerTestWrapper(
        test_file="test_define_6.mal"
    ).test(
        defines=['id', 'version', 'key']
    )

def test_define_7() -> None:
    '''
    Defines correct version, ID.
    Defines Key with value twice.
    '''
    AnalyzerTestWrapper(
        test_file="test_define_7.mal",
        error_msg="Define 'key' previously defined at line 2"
    )

def test_define_8() -> None:
    '''
    Defines correct version and ID, but id twice.
    '''
    AnalyzerTestWrapper(
        test_file="test_define_8.mal"
    ).test(
        defines=['id', 'version']
    )