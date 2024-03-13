"""
Unit tests for the quicksort function implementation.
"""

import random
from examples.quicksort import quicksort

def test_quicksort_withnonemptyrandomarray_shouldsortcorrectly():
    """
    Unit tests for the case of sorting a non-empy random array.
    """
    input_array = list(range(0, 100))
    expected = list(range(0, 100))

    random.shuffle(input_array)

    quicksort(input_array)

    assert input_array == expected