"""
Module that provides the function that gets the anagrams of a given string.
"""

def get(input_string):
    """
    Gets the anagrams of a given string.
    """
    if len(input_string) == 1:
        return [ input_string[0] ]

    previous_anagrams = get(input_string[1:])
    result = []

    for anagram in previous_anagrams:
        for i in range(len(anagram) + 1):
            result.append(anagram[:i] + input_string[0] + anagram[i:])

    return result
