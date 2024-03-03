"""
Unit tests for the Fibonacci function implementation.
"""

from examples import fibonacci

def test_calculaterecursive_withinputzero_shouldreturnzero():
    """
    Unit tests for the base case of getting the digit 0 of the Fibonacci sequence.
    """
    assert fibonacci.calculate_recursive(0) == 0

def test_calculaterecursive_withinputone_shouldreturnone():
    """
    Unit tests for the base case of getting the digit 1 of the Fibonacci sequence.
    """
    assert fibonacci.calculate_recursive(1) == 1

def test_calculaterecursive_withinputtwo_shouldreturnone():
    """
    Unit tests for the base case of getting the digit 1 of the Fibonacci sequence.
    """
    assert fibonacci.calculate_recursive(2) == 1

def test_calculaterecursive_withinput10_shouldreturn55():
    """
    Unit tests for the base case of getting the digit 10 of the Fibonacci sequence.
    """
    assert fibonacci.calculate_recursive(2) == 1

def test_calculatememoization_withinputzero_shouldreturnzero():
    """
    Unit tests for the base case of getting the digit 0 of the Fibonacci sequence.
    """
    assert fibonacci.calculate_memoization(0) == 0

def test_calculatememoization_withinputone_shouldreturnone():
    """
    Unit tests for the base case of getting the digit 1 of the Fibonacci sequence.
    """
    assert fibonacci.calculate_memoization(1) == 1

def test_calculatememoization_withinputtwo_shouldreturnone():
    """
    Unit tests for the base case of getting the digit 1 of the Fibonacci sequence.
    """
    assert fibonacci.calculate_memoization(2) == 1

def test_calculatememoization_withinput10_shouldreturn55():
    """
    Unit tests for the base case of getting the digit 10 of the Fibonacci sequence.
    """
    assert fibonacci.calculate_memoization(2) == 1

def test_calculatebottomup_withinputzero_shouldreturnzero():
    """
    Unit tests for the base case of getting the digit 0 of the Fibonacci sequence.
    """
    assert fibonacci.calculate_bottom_up(0) == 0

def test_calculatebottomup_withinputone_shouldreturnone():
    """
    Unit tests for the base case of getting the digit 1 of the Fibonacci sequence.
    """
    assert fibonacci.calculate_bottom_up(1) == 1

def test_calculatebottomup_withinputtwo_shouldreturnone():
    """
    Unit tests for the base case of getting the digit 1 of the Fibonacci sequence.
    """
    assert fibonacci.calculate_bottom_up(2) == 1

def test_calculatebottomup_withinput10_shouldreturn55():
    """
    Unit tests for the base case of getting the digit 10 of the Fibonacci sequence.
    """
    assert fibonacci.calculate_bottom_up(2) == 1
