"""
Module that provides the function that gets the even numbers from a number array.
"""

def get_even_numbers(input):
    """
    Gets the list of even numbers in a number array.
    """
    if len(input) == 0:
        return []

    if input[0] % 2 == 0:
        return [ input[0] ] + get_even_numbers(input[1:])
    else:
        return get_even_numbers(input[1:])