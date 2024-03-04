"""
Module that provides the function that calculates the intersection between 2 arrays
using hash tables.
"""

def find(array_1, array_2):
    """
    Gets the intersection between 2 arrays by using hash tables.
    """
    lookup_table = {}
    intersection = []

    for item in array_1:
        lookup_table[item] = True

    for item in array_2:
        if item in lookup_table:
            intersection.append(item)

    return intersection
