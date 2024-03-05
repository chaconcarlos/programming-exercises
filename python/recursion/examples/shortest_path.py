"""
Module that provides the function that gets the total number of paths between a 2-dimensional array.
"""

def get_shortest_paths_count(rows, columns):
    """
    Gets the shortest path between a 2-dimensional array.
    """
    if rows == 1 or columns == 1:
        return 1

    step_down_paths = get_shortest_paths_count(rows - 1, columns)
    step_left_paths = get_shortest_paths_count(rows, columns - 1)

    return step_down_paths + step_left_paths
