"""
Unit tests for the quicksort function implementation.
"""

from examples.trie import Trie

def test_trie_withwordintrie_shouldfindword():
    """
    Tests the case for the search of a word in a trie when the word exists in the trie.
    """
    trie = Trie()

    trie.insert('cat')

    assert trie.contains('cat') is True

def test_trie_withwordnotintrie_shouldnotfindword():
    """
    Tests the case for the search of a word in a trie when the word doesn't exists in the trie.
    """
    trie = Trie()

    trie.insert('cat')

    assert trie.contains('cot') is False

def test_trie_withnestedwords_shouldgetwordslist():
    """
    Tests when getting the list of words given a root.
    """
    trie = Trie()

    trie.insert('cat')
    trie.insert('catnip')
    trie.insert('cab')
    trie.insert('catnap')

    expected = [ 'cat', 'catnip', 'catnap' ]

    assert trie.collect_words('cat') == expected

def test_trie_withemptyroot_shouldgetallwords():
    """
    Tests when getting the list of words given a root.
    """
    trie = Trie()

    trie.insert('ant')
    trie.insert('arm')
    trie.insert('armaggedon')
    trie.insert('cat')
    trie.insert('catnip')
    trie.insert('cab')
    trie.insert('catnap')
    trie.insert('test')
    trie.insert('test-tube')

    expected = [ 'ant', 'arm', 'armaggedon', 'cat', 'catnip', 'cab', 'catnap', 'test', 'test-tube' ]

    assert sorted(trie.collect_words()) == sorted(expected)
