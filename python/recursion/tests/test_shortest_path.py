"""
Unit tests for the function gets the shortest path between a 2-dimensional array.
"""

from examples import shortest_path

def test_shortestpath_withvalidarray_returnnumberofpaths():
    """
    Unit test for calculating the shortest path for a 3 x 2 2-dimensional array.
    """
    assert shortest_path.get_shortest_paths_count(3, 2) == 3
