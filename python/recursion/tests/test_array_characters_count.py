"""
Unit tests for the function that gets the anagrams of a given string.
"""

from examples import array_characters_count

def test_getcharacterscount_withnonemptystringarray_returntotalcharacters(): 
    """
    Unit test for the case of getting the total number of characters in a non-empty string array.
    """
    assert array_characters_count.get_character_count([ "ab", "c", "def", "ghij" ]) == 10
