from .mal_analyzer_test_wrapper import AnalyzerTestWrapper

from pathlib import Path
import pytest

'''
A file to test existance operators (E and !E) in MAL
'''

@pytest.mark.usefixtures("setup_test_environment")
@pytest.mark.parametrize("setup_test_environment", [Path(__file__).parent / "fixtures/exists_test_files"], indirect=True)

def test_exists_1() -> None:
    '''
    Correctly define defenses
    '''
    AnalyzerTestWrapper(
        test_file="test_exists_1.mal"
    ).test(
        defines=['id', 'version'],
        categories=['System'],
        assets=['Asset1','Asset2','Asset3'],
    )

def test_exists_2() -> None:
    '''
    Test existance with a reach with a non-existing attack step
    '''
    AnalyzerTestWrapper(
        test_file="test_exists_2.mal",
        error_msg="Attack step 'wrongStep' not defined for asset 'Asset1'"
    )

def test_exists_3() -> None:
    '''
    Test existence with non-existing asset
    '''
    AnalyzerTestWrapper(
        test_file="test_exists_3.mal",
        error_msg="Field 'a2' not defined for asset 'Asset1'\n" + \
                  "Line 5: All expressions in requires ('<-') must point to a valid asset"
    )
    
def test_exists_4() -> None:
    '''
    Test existence with a requires which points to a step
    '''
    AnalyzerTestWrapper(
        test_file="test_exists_4.mal",
        error_msg="Field 'attack' not defined for asset 'Asset2'\n" + \
                  "Line 5: All expressions in requires ('<-') must point to a valid asset"
    )
    
def test_exists_5() -> None:
    '''
    Test existence with a TTC expression
    '''
    AnalyzerTestWrapper(
        test_file="test_exists_5.mal",
        error_msg="Attack step of type 'exist' must not have TTC"
    )

def test_exists_6() -> None:
    '''
    Test non-existence with a TTC expression
    '''
    AnalyzerTestWrapper(
        test_file="test_exists_6.mal",
        error_msg = "Attack step of type 'notExist' must not have TTC"
    )

def test_exists_7() -> None:
    '''
    Test existence without a requires
    '''
    AnalyzerTestWrapper(
        test_file="test_exists_7.mal",
        error_msg="Attack step of type 'exist' must have require '<-'"
    )

def test_exists_8() -> None:
    '''
    Test normal step with a requires
    '''
    AnalyzerTestWrapper(
        test_file="test_exists_8.mal",
        error_msg="Require '<-' may only be defined for attack step type exist 'E' or not-exist '!E'"
    )
