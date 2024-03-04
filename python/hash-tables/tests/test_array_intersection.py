"""
Unit tests for the function that finds the intersection between 2 arrays.
"""

from examples import array_intersection

def test_findarrayintersection_withtwovalidarrays_shouldreturnintersection():
    """
    Unit tests for the base case of getting the intersection between two valid arrays.
    """
    array_1 = [ 1, 2, 3, 4, 5 ]
    array_2 = [ 0, 2, 4, 6, 8 ]

    assert array_intersection.find(array_1, array_2) == [ 2, 4 ]