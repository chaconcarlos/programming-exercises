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

    def has_children(self):
        """
        Indicates whether a node has child nodes.
        """
        return self.left_child is not None and self.right_child is not None

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

    def __search(self, value, current_node):
        """
        Gets the node with the given value in the tree.
        Returns None if the value is not in the tree.
        """
        if current_node is None:
            return None

        if value > current_node.value:
            return self.__search(value, current_node.right_child)

        if value < current_node.value:
            return self.__search(value, current_node.left_child)

        return current_node

    def __delete(self, value, current_node):
        """
        Deletes the value from the tree starting on the given node.
        """
        if current_node is None:
            return None

        if value > current_node.value:
            current_node.right_child = self.__delete(value, current_node.right_child)
            return current_node
        elif value < current_node.value:
            current_node.left_child = self.__delete(value, current_node.left_child)
            return current_node
        else:
            if current_node.left_child is None:
                return current_node.right_child

            if current_node.right_child is None:
                return current_node.left_child

            current_node.right_child = self.__lift(current_node.right_child, current_node)

            return current_node

    def __lift(self, node, node_to_delete):
        """
        Changes the value of the node to delete for the one of its succesor node.
        """
        if node.left_child is not None:
            node.left_child = self.__lift(node.left_child, node_to_delete)
            return node

        node_to_delete.value = node.value

        return node.right_child

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

    def search(self, value):
        """
        Gets the node with the given value in the tree.
        Returns None if the value is not in the tree.
        """
        return self.__search(value, self.initial_node)

    def contains(self, value):
        """
        Indicates whether a value is in the tree.
        """
        return self.search(value) is not None

    def delete(self, value):
        """
        Deletes a value from the tree.
        """
        if self.initial_node is None:
            return

        self.__delete(value, self.initial_node)

def get_highest_value(node):
    """
    Gets the highest value of the binary tree.
    """
    if node is None:
        return None

    if node.right_child is None:
        return node

    return get_highest_value(node.right_child)

def get_lowest_value(node):
    """
    Gets the lowest value of the binary tree.
    """
    if node is None:
        return None

    if node.left_child is None:
        return node

    return get_lowest_value(node.left_child)

def traverse_and_print(node):
    """
    Traverses and prints the value of a tree.
    """
    if node is None:
        return

    traverse_and_print(node.left_child)
    print(node.value)
    traverse_and_print(node.right_child)

def post_order_traverse_and_print(node):
    """
    Traverses and prints the value of a tree.
    """
    if node is None:
        return

    traverse_and_print(node.left_child)
    traverse_and_print(node.right_child)
    print(node.value)
