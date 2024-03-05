"""
Unit tests for the function that calculates the nth number in a triangular numeric pattern.
"""

from examples import triangular_numbers

def test_triangularnumbers_withvaliddigit_returntriangularnumber():
    """
    Unit test for the case of a valid digit number in the triangular pattern.
    """
    assert triangular_numbers.get_triangular(7) == 28
