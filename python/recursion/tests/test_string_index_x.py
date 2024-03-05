"""
Unit tests for the function that gets the first index of the character 'x' in a string.
"""

from examples import string_index_x

def test_getindexofx_withastringwithanx_returnindexofx():
    """
    Unit test for the case when a string with an instance of the character 'x' is given.
    """
    assert string_index_x.get_index_of_x('abcdefghijklmnopqrstuvwxyz') == 23