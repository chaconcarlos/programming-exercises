"""
Module that provides the function that gets the non-duplicated character in a string using hash tables.
"""

def get(input_string):
    """
    Gets the non-duplicated character in a string using hash tables.
    """
    lookup_table = {}

    for item in input_string:
        if item in lookup_table:
            lookup_table[item] += 1
        else:
            lookup_table[item] = 1

    for character, count in lookup_table.items():
        if count == 1:
            return character

    return ''
