"""
Module Providing the fibonacci function.
"""

def calculate_recursive(digit):
    """
    Gets the fibonacci value for the given digit using a recursive approach.
    """
    if digit == 0 or digit == 1:
        return digit

    # This is highly ineficient O(2^n).
    # This happens because this recursive functions have overlapping subproblems.
    return calculate_recursive(digit - 1) + calculate_recursive(digit - 2)

def calculate_memoization(digit, pre_calculated_values = None):
    """
    Gets the fibonacci value for the given digit using a recursive approach,
    but using memoization to optimize the algorithm.
    """
    # This dictionary can't be initialized by default.
    # Violates https://pylint.readthedocs.io/en/latest/user_guide/messages/warning/dangerous-default-value.html
    if pre_calculated_values is None:
        pre_calculated_values = { 0: 0, 1: 1 }

    if digit not in pre_calculated_values:
        n_1 = calculate_memoization(digit - 1, pre_calculated_values)
        n_2 = calculate_memoization(digit - 2, pre_calculated_values)
        pre_calculated_values[digit] = n_1 + n_2

    return pre_calculated_values[digit]

def calculate_bottom_up(digit):
    """
    Gets the fibonacci value for the given digit using a bottom-up (non-recursive) approach.
    """
    pre_calculated_values = { 0: 0, 1: 1 }

    for i in range(2, digit + 1):
        pre_calculated_values[i] = pre_calculated_values[i - 1] + pre_calculated_values[i - 2]

    return pre_calculated_values[digit]