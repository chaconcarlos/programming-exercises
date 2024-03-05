"""
Module that provides the function that gets the total number of characters in an array of string.
"""

def get_character_count(strings):
    """
    Gets the 
    """
    if (len(strings) == 0):
        return 0

    return len(strings[0]) + get_character_count(strings[1:len(strings)])
