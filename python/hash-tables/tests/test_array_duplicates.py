"""
Unit tests for the function that finds the first duplicated item in an array.
"""

from examples import array_duplicates

def test_findarrayduplicate_withanarraywithoneduplicateditem_shouldreturnduplicateditem():
    """
    Unit tests for the base case of getting the intersection between two valid arrays.
    """
    input_array = [ 'a', 'b', 'c', 'd', 'c', 'e', 'f' ]

    assert array_duplicates.find(input_array) == 'c'