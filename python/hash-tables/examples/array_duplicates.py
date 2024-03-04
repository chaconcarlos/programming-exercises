"""
Module that provides the function that gets the first duplicate in an array
using hash tables.
"""

def find(input_array):
    """
    Gets the first duplicated element in an array.
    """
    lookup_table = {}

    for item in input_array:
        if item in lookup_table:
            return item
        else:
            lookup_table[item] = True

    return ''
