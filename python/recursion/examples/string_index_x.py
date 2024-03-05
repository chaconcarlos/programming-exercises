"""
Module that provides the function that gets the first index of the character 'x' in a string.
"""

def get_index_of_x(input_string):
    """
    Gets the first index of the character 'x' in a string.
    """
    if input_string[0] == 'x':
        return 0

    return get_index_of_x(input_string[1:]) + 1
