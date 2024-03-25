"""
Module that implements the trie data structure.
"""

TERMINATOR = '*'

class TrieNode:
    """
    Represents a node of the trie data structure.
    """
    def __init__(self):
        """
        Initializes an instance TrieNode class.
        """
        self.children = {}

    def insert(self, value):
        """
        Inserts a value in the node and its childrens.
        """
        if len(value) == 0:
            self.children[TERMINATOR] = None
            return

        root_char = value[0]

        if root_char not in self.children:
            self.children[root_char] = TrieNode()

        self.children[root_char].insert(value[1:])

    def contains(self, value):
        """
        Indicates whether the value is part of the node and its children.
        """
        if len(value) == 0 and TERMINATOR in self.children:
            return True

        root_char = value[0]

        if root_char not in self.children:
            return False

        return self.children[root_char].contains(value[1:])

    def search(self, value):
        """
        Gets the tree node that has value as root.
        """
        root_char = value[0]

        if root_char not in self.children:
            return None

        if len(value) == 1:
            return self.children[root_char]

        return self.children[root_char].search(value[1:])

    def collect_words(self, root, collected_words=None):
        """
        Collects the words under this node that start with the given root.
        """
        if root is None:
            root = ''

        if collected_words is None:
            collected_words = []

        for key, child_node in self.children.items():
            if key == TERMINATOR:
                collected_words.append(root)
            else:
                child_node.collect_words(root + key, collected_words)

        return collected_words

class Trie:
    """
    Implementation of the trie data structure.
    """
    def __init__(self):
        """
        Initializes an instance of the Trie class.
        """
        self.root = TrieNode()

    def insert(self, value):
        """
        Inserts a value in the trie.
        """
        if value is not None:
            self.root.insert(value)

    def contains(self, value):
        """
        Indicates whether a value is in the trie.
        """
        if value is None:
            return False

        return self.root.contains(value)

    def collect_words(self, root=None):
        """
        Gets the list of words that start with the given root.
        """
        root_node = self.root

        if root is not None and len(root) > 0:
            root_node = self.root.search(root)

        return root_node.collect_words(root)
