"""
Module that implements the binary search tree data structure.
"""

class TreeNode:
    """
    Represents a binary tree node.
    """
    def __init__(self, value, left_child=None, right_child=None):
        """
        Initializes an instance of the TreeNode class.
        """
        self.value = value
        self.left_child = left_child
        self.right_child = right_child

class BinarySearchTree:
    """
    Represents a binary search tree.
    """
    def __init__(self):
        self.initial_node = None

    def __calculate_height(self, current_node):
        """
        Calculates the height of a tree given it's starting node.
        """
        if current_node is None:
            return 0

        left_height = self.__calculate_height(current_node.left_child)
        right_height = self.__calculate_height(current_node.right_child)

        return 1 + max(left_height, right_height)

    def __insert(self, value, initial_node):
        """
        Inserts a value in the binary search tree.
        """
        if value > initial_node.value:
            if initial_node.right_child is None:
                initial_node.right_child = TreeNode(value)
            else:
                self.__insert(value, initial_node.right_child)
        elif value < initial_node.value:
            if initial_node.left_child is None:
                initial_node.left_child = TreeNode(value)
            else:
                self.__insert(value, initial_node.left_child)

    def get_height(self):
        """
        Gets the height of the tree.
        """
        if self.initial_node is None:
            return 0

        return self.__calculate_height(self.initial_node)

    def insert(self, value):
        """
        Inserts a value in the binary search tree.
        """
        if self.initial_node is None:
            self.initial_node = TreeNode(value)
        else:
            self.__insert(value, self.initial_node)

    def insert_list(self, item_list):
        """
        Inserts a list of items in the tree.
        """
        for item in item_list:
            self.insert(item)
