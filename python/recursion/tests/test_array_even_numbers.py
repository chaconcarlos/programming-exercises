"""
Unit tests for the function that gets the anagrams of a given string.
"""

from examples import array_even_numbers

def test_getevennumbers_withnonemptynumberarray_returnevennumberlist(): 
    """
    Unit test for the case of getting the total number of characters in a non-empty string array.
    """
    assert array_even_numbers.get_even_numbers(list(range(0, 10))) == [ 0, 2, 4, 6, 8 ]
