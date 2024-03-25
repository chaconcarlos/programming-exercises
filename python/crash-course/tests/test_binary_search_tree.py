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

def test_binarysearchtree_withvalueintree_shouldcontainvalue():
    """
    Test case for searching for a value in a tree when the value is in the tree.
    """
    elements = [5, 3, 8, 1, 6, 2, 4, 7, 9, 0]
    tree = BinarySearchTree()
    tree.insert_list(elements)

    assert tree.contains(9) is True
    assert tree.contains(0) is True
    assert tree.contains(4) is True

def test_binarysearchtree_withvaluenotintree_shouldnotcontainvalue():
    """
    Test case for searching for a value in a tree when the value is not in the tree.
    """
    elements = [5, 3, 8, 1, 6, 2, 4, 7, 9, 10]
    tree = BinarySearchTree()
    tree.insert_list(elements)

    assert tree.contains(11) is False
    assert tree.contains(0) is False

def test_binarysearchtree_withvalueintree_shouldfindnodewithvalue():
    """
    Test case for searching for a value in a tree when the value is in the tree.
    """
    elements = [5, 3, 8, 1, 6, 2, 4, 7, 9, 0]

    tree = BinarySearchTree()
    tree.insert_list(elements)

    node = tree.search(9)

    assert node is not None
    assert node.value == 9

def test_binarysearchtree_withvaluenotintree_shouldnotfindnodewithvalue():
    """
    Test case for searching for a value in a tree when the value is not in the tree.
    """
    elements = [5, 3, 8, 1, 6, 2, 4, 7, 9, 0]

    tree = BinarySearchTree()
    tree.insert_list(elements)

    assert tree.search(10) is None

def test_binarysearchtree_withvaluenotintree_deleteshouldnotthrow():
    """
    Test case for deleting a value in a tree when the value is not in the tree.
    """
    elements = [52, 25, 75, 11, 33, 61, 89, 30, 40, 55, 82, 95]

    tree = BinarySearchTree()
    tree.insert_list(elements)

    tree.delete(96)

def test_binarysearchtree_withnodewithnochildren_shoulddelete():
    """
    Test case for deleting a value in a tree when the value is not in the tree.
    """
    elements = [52, 25, 75, 11, 33, 61, 89, 30, 40, 55, 82, 95]

    tree = BinarySearchTree()
    tree.insert_list(elements)

    tree.delete(95)

    parent_node = tree.search(89)

    assert tree.contains(95) is False
    assert parent_node is not None
    assert parent_node.right_child is None
    assert parent_node.left_child.value == 82

def test_binarysearchtree_withnodewithbothchildrens_shoulddeleteandreplacenode():
    """
    Test case for deleting a value in a tree when the value is not in the tree.
    """
    elements = [50, 25, 75, 10, 33, 56, 89, 4, 11, 30, 40, 52, 61, 82, 95]

    tree = BinarySearchTree()
    tree.insert_list(elements)

    tree.delete(50)

    root_node = tree.search(52)

    assert tree.contains(50) is False
    assert root_node is not None
    assert root_node.left_child.value == 25
    assert root_node.right_child.value == 75
