"""
Module that provides the function that calculates the nth number in a triangular numeric pattern.
"""

def get_triangular(n):
    """
    Calculates the nth number in a triangular numeric pattern.
    """
    if n == 1:
        return 1

    return n + get_triangular(n - 1)
