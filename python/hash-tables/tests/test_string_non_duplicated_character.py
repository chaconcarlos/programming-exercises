"""
Unit tests for the function that gets the missing letter from the 
alphabet in a string using hash tables.
"""

from examples import string_non_duplicated_character

def test_nonduplicatedcharacter_stringwithonenonduplicatedcharacter_returnthecharacter():
    """
    Unit tests for the base case of getting the intersection between two valid arrays.
    """
    input_string = 'minimum'

    assert string_non_duplicated_character.get(input_string) == 'n'
