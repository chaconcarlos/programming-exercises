"""
Unit tests for the function that gets the anagrams of a given string.
"""

import math

from examples import anagrams

def test_anagrams_withavalidstring_returnvalidanagrams():
    """
    Unit tests for the base case of getting the anagrams of a valid string.
    """
    input_string = "abc"
    expected = [
      "abc",
      "acb",
      "bac",
      "bca",
      "cab",
      "cba"
    ]
    result = sorted(anagrams.get(input_string))

    assert len(result) == math.factorial(len(input_string))
    assert result == expected
