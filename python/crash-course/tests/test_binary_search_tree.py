"""
Unit tests for the quicksort function implementation.
"""

from examples.binary_search_tree import BinarySearchTree

def test_binarysearchtree_withemptytree_shouldreturnheight0():
    """
    Test case for calculating the height when the tree is empty.
    """
    tree = BinarySearchTree()

    assert tree.get_height() == 0

def test_binarysearchtree_with2leveltree_shouldreturnheight2():
    """
    Test case for calculating the height when the tree has 2 levels.
    """
    tree = BinarySearchTree()

    tree.insert(2)
    tree.insert(1)
    tree.insert(3)

    assert tree.get_height() == 2

def test_binarysearchtree_withitemlist_shouldinsertallelements():
    """
    Test case for calculating the height when the tree has 2 levels.
    """
    elements = [5, 3, 8, 1, 6, 2, 4, 7, 9, 0]
    tree = BinarySearchTree()
    tree.insert_list(elements)

    assert tree.get_height() == 4
