"""
Unit tests for the function that gets the missing letter from the 
alphabet in a string using hash tables.
"""

from examples import string_missing_character

def test_missingcharacter_withastringmissingonecharacter_returnthemissingcharacter():
    """
    Unit tests for the base case of getting the intersection between two valid arrays.
    """
    input_string = 'the quick brown box jumps over a lazy dog'

    assert string_missing_character.get(input_string) == 'f'
