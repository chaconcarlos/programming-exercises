"""
Module that provides the function that gets the missing character from the alphabet
in a string using hash tables.
"""

import string

def get(input_string):
    """
    Gets the missing character from the alphabet in a string using hash tables.
    """
    lookup_table = {}

    for item in input_string:
        lookup_table[item.lower()] = True

    for character in list(string.ascii_lowercase):
        if character not in lookup_table:
            return character

    return ''
