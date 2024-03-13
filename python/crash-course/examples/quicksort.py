"""
Module that implements the quicksort algorithm.
"""

def partition(array, left_pointer, right_pointer):
    """
    Partitions an array based on a pivot. Based on Lomuto's partition.
    """
    if len(array) <= 1:
        return array

    pivot_index = right_pointer
    pivot = array[pivot_index]
    right_pointer -= 1

    while left_pointer <= right_pointer:
        while array[left_pointer] < pivot and left_pointer <= right_pointer:
            left_pointer += 1

        while array[right_pointer] > pivot and right_pointer >= left_pointer:
            right_pointer -= 1

        if left_pointer >= right_pointer:
            array[pivot_index], array[left_pointer] = array[left_pointer], array[pivot_index]
            break

        array[right_pointer], array[left_pointer] = array[left_pointer], array[right_pointer]

    return left_pointer

def hoarers_partition(array, left_pointer, right_pointer):
    """
    Partitions an array based on a pivot. Based on Hoare's partition.
    """
    pivot = array[left_pointer]
    low = left_pointer - 1
    high = right_pointer + 1

    while True:
        low += 1

        while array[low] < pivot:
            low += 1

        high -= 1

        while array[high] > pivot:
            high -= 1

        if low >= high:
            return high

        array[low], array[high] = array[high], array[low]

def quicksort(array, left_index = None, right_index = None):
    """
    Implements the quicksort algorithm.
    """
    left_index = left_index if left_index is not None else 0
    right_index = right_index if right_index  is not None else len(array) - 1

    if left_index >= right_index:
        return

    #pivot_index = partition(array, left_index, right_index)
    pivot_index = hoarers_partition(array, left_index, right_index)

    #if using Lomuto's:
    #quicksort(array, left_index, pivot_index - 1)
    quicksort(array, left_index, pivot_index)
    quicksort(array, pivot_index + 1, right_index)

def quickselect(kth_lowest_value, array, left_index = None, right_index = None):
    """
    Implements the quickselect algorithm.
    """
    left_index = left_index if left_index is not None else 0
    right_index = right_index if right_index  is not None else len(array) - 1

    pivot_index = partition(array, left_index, right_index)

    if kth_lowest_value > pivot_index:
        return quickselect(kth_lowest_value, array, pivot_index + 1, right_index)
    elif kth_lowest_value < pivot_index:
        return quickselect(kth_lowest_value, array, left_index, pivot_index - 1)
    else:
        return array[pivot_index]
