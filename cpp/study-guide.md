# Coding Patterns Study Guide

# Coding Patterns Study Guide

<!-- TOC start (generated with https://github.com/derlin/bitdowntoc) -->
- [About namespaces](#code-snippets)
   * [`using namespace std` is a bad practice.](#using-namespace-std-is-a-bad-practice)
   * [Important headers to remember](#important-headers-to-remember)
- [Code Snippets](#code-snippets)
   * [Append a char (not a char*) to a std::string](#append-a-char-not-a-char-to-a-stdstring)
   * [Different ways to get a substring from a std::string](#different-ways-to-get-a-substring-from-a-stdstring)
   * [Replace a char in a std::string](#replace-a-char-in-a-stdstring)
   * [Iterating a list-like container](#iterating-a-list-like-container)
   * [Iterating maps](#iterating-maps)
   * [Reverse a linked list](#reverse-a-linked-list)
   * [Merge 2 linked lists, no order.](#merge-2-linked-lists-no-order)
   * [Merge 2 linked lists, ascending order](#merge-2-linked-lists-ascending-order)
   * [Get the middle node of a linked list](#get-the-middle-node-of-a-linked-list)
   * [Priority queue with custom lambda expression for sorting.](#priority-queue-with-custom-lambda-expression-for-sorting)
   * [Compare 2 binary trees](#compare-2-binary-trees)
   * [Know if a subtree is part of a binary tree](#know-if-a-subtree-is-part-of-a-binary-tree)
   * [Count bits 1 on a number](#count-bits-1-on-a-number)
   * [Using an unordered_set with std::pair<int, int>](#using-an-unordered_set-with-stdpair)
- [Patterns](#patterns)
   * [Two Pointers Pattern](#two-pointers-pattern)
   * [Fast & Slow Pointers Pattern](#fast--slow-pointers-pattern)
   * [Sliding Window Pattern](#sliding-window-pattern)
   * [Modified Binary Search Pattern](#modified-binary-search-pattern)
   * [Tree Breadth First Search Pattern](#tree-breadth-first-search-pattern)
   * [Tree Depth First Search Pattern](#tree-depth-first-search-pattern)
   * [In-place Reversal of a Linked List Pattern](#in-place-reversal-of-a-linked-list-pattern)
   * [Hashing](#hashing)
   * [Sets](#sets)
   * [Stacks](#stacks)
   * [Tries](#tries)
- [Other advice](#other-advice)
- [Coding Problems](#coding-problems)
   * [1. Contains duplicate](#1-contains-duplicate)
      + [1.1 Analysis](#11-analysis)
      + [1.2 Test cases](#12-test-cases)
      + [1.3 Solution](#13-solution)
      + [1.4 Lessons learned](#14-lessons-learned)
   * [2. Pangrams](#2-pangrams)
      + [2.1 Analysis](#21-analysis)
      + [2.2 Test cases](#22-test-cases)
      + [2.3 Solution](#23-solution)
      + [2.4 Lessons learned](#24-lessons-learned)
   * [3. Reverse Vowels](#3-reverse-vowels)
      + [3.1 Analysis](#31-analysis)
      + [3.2 Test cases](#32-test-cases)
      + [3.3 Solution](#33-solution)
      + [3.4 Lessons learned](#34-lessons-learned)
   * [4. Valid Palindrome](#4-valid-palindrome)
      + [4.1 Analysis.](#41-analysis)
      + [4.2 Test cases](#42-test-cases)
      + [4.3 Solution](#43-solution)
      + [4.4 Lessons learned](#44-lessons-learned)
   * [5. Valid Anagram](#5-valid-anagram)
      + [5.1 Analysis](#51-analysis)
      + [5.2 Test cases](#52-test-cases)
      + [5.3 Solution](#53-solution)
      + [5.4 Lessons learned](#54-lessons-learned)
   * [6. Shortest Word Distance](#6-shortest-word-distance)
   * [6.1 Analysis](#61-analysis)
      + [6.2 Test cases](#62-test-cases)
      + [6.3 Solution](#63-solution)
      + [6.4 Lessons learned](#64-lessons-learned)
   * [7. Number of Good Pairs](#7-number-of-good-pairs)
   * [7.1 Analysis](#71-analysis)
   * [7.3 Solution](#73-solution)
   * [7.4 Lessons Learned](#74-lessons-learned)
   * [8. Sqrt (medium)](#8-sqrt-medium)
      + [8.3 Solution](#83-solution)
      + [8.4 Lessons learned](#84-lessons-learned)
   * [9. Pair with Target Sum (easy)](#9-pair-with-target-sum-easy)
      + [9.1 Analysis](#91-analysis)
      + [9.2 Solution](#92-solution)

<!-- TOC end -->

## About namespaces

### `using namespace std` is a bad practice.
  While using namespace std; might seem convenient, it's generally considered bad practice due to the potential for naming conflicts and reduced code readability. Embracing explicit namespace usage is a better approach, ensuring your code remains clean, maintainable, and free of unexpected issues. [[Source]](https://dev.to/iamcymentho/using-namespace-std-in-c-why-its-considered-bad-practice-2adf)

### Important headers to remember
| Header Name       | Description                                      |
| -----------       | -----------                                      |
| `<algorithm>`     | Useful algorithms like std::sort                 |
| `<stdexcept>`     | Exceptions                                       |
| `<string>`        | std::string                                      |
| `<unordered_set>` | std::unordered_set                               |
| `<vector>`        | std::vector                                      |
| `<iomanip>`       | Stream manipulators (like set_precision)         |
| `<cctype>`        | Character type utility functions, like isalpha() |

## Code Snippets

### Append a char (not a char*) to a std::string

Use `std::string::append(size_t n, char c)` -> Appends n consecutive copies of character c.

```cpp
result.append(1, characterStack.top());
```

Or `operator+`.

```cpp
std::string test = "TEST";

test += "1" // Test is not "TEST1"
```

### Different ways to get a substring from a std::string

```cpp
// string::substr
#include <iostream>
#include <string>

int main ()
{
  std::string str="We think in generalities, but we live in details.";
                                           // (quoting Alfred N. Whitehead)

  std::string str2 = str.substr (3,5);     // "think"

  std::size_t pos = str.find("live");      // position of "live" in str

  std::string str3 = str.substr (pos);     // get from "live" to the end

  std::cout << str2 << ' ' << str3 << '\n';

  return 0;
}
```

### Replace a char in a std::string

```cpp
static const std::string ENCODED_WHITESPACE = "%20";

while (i < testString.size()) {
  const char currentChar = testString[i];
  // How to concatenate a char to a string.
  const std::string message = std::string("is '") + currentChar + "' a whitespace? ";
  const bool isWhitespace = currentChar == ' ';
	
  std::cout << message << (isWhitespace ? "YES" : "NO") << std::endl;
	
  if (isWhitespace) {
    testString.replace(i, 1, ENCODED_WHITESPACE);
    i += ENCODED_WHITESPACE.size();
  } else {
    ++i;
  }
}
```

### Iterating a list-like container
* C++98 way (using iterators):

  ```cpp
  const std::vector<int> nums;

  for (auto it = nums.begin(); it != nums.end(); ++it) {
    // Do something.
    // Dereference the value from the iterator by *it
  }
  ```
* C++14, using range-based for loop:

  ```cpp
  const std::vector<int> nums;

  for (const int& i : nums) {
    // Do something with i.
  }
  ```

### Iterating maps
```cpp
for (const auto& [key, value] : map) {
  // Do something.
}

for (const std::pair<const std::string, std::string>& n : map) {
  // Do something.
  // n.first: key
  // n.second: value
}
```

### Reverse a linked list
```cpp
static ListNode* reverse(ListNode* head) {
    ListNode *prev = nullptr;

    while (head != nullptr) {
      ListNode *next = head->next;

      head->next = prev;
      prev = head;
      head = next;
    }

    return prev;
}
```

### Merge 2 linked lists, no order.

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* current1 = list1;
        ListNode* current2 = list2;

        while (current1 != nullptr && current2 != nullptr) {
            ListNode* next1 = current1->next;
            ListNode* next2 = current2->next;

            if (current2 != nullptr)
                current1->next = current2;

            if (next1 != nullptr) {
                current2->next = next1;
            }

            current1 = next1;
            current2 = next2;
        }

        return list1 == nullptr ? list2 : list1;
    }
};

```

### Merge 2 linked lists, ascending order

Remember to use an extra node for the start!

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }

        if (list2 == nullptr) {
            return list1;
        }

        ListNode* start = new ListNode();
        ListNode* current = start;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val > list2->val) {
                current->next = list2;
                list2 = list2->next;
            } else {
                current->next = list1;
                list1 = list1->next;
            }

            current = current->next;
        }

        if (list1 == nullptr) {
            current->next = list2;
        } else {
            current->next = list1;
        }

        return start->next;
    }
};
```


### Get the middle node of a linked list
```cpp
static ListNode* getMiddleNode(ListNode* head) {
  ListNode* slow = head;
  ListNode* fast = head;

  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}
```

### Priority queue with custom lambda expression for sorting.

```cpp
#include <queue>

// Using lambda to compare elements.
auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
std::priority_queue<int, std::vector<int>, decltype(cmp)> q5(cmp);
```

### Compare 2 binary trees

```cpp
static bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr || q == nullptr) 
        return p == q;

    if (p->val != q->val)
        return false;
    
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
```

### Know if a subtree is part of a binary tree

```cpp
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (root == nullptr) {
        return false;
    }

    if (isSameTree(root, subRoot)) {
        return true;
    }

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
```

### Count bits 1 on a number

```cpp
static int getOnesCount(int n) {
    int count = 0;

    while (n > 0) {
        n = n & (n - 1);
        ++count;
    }

    return count;
}
```

### Using an unordered_set with std::pair<int, int>

```cpp
// Hash function  
struct hashFunction 
{ 
  size_t operator()(const pair<int ,  
                    int> &x) const
  { 
    return x.first ^ x.second; 
  } 
}; 

int main() 
{ 
  // Declaring an unordered set of pairs 
  unordered_set<pair<int, int>,  
  hashFunction> myUnorderedSet; 
  
  // Initializing pairs of int type 
  pair<int, int> pair1; 
  pair1 = make_pair(4, 2); 
  
  pair<int, int> pair2; 
  pair2 = make_pair(2, 3); 
  
  pair<int, int> pair3; 
  pair3 = make_pair(2, 3); 
  
  pair<int, int> pair4; 
  pair4 = make_pair(5, 8); 
  
  pair<int, int> pair5; 
  pair5 = make_pair(9, 5); 
  
  
  // Inserting pairs in the unordered set 
  myUnorderedSet.insert(pair1); 
  myUnorderedSet.insert(pair2); 
  myUnorderedSet.insert(pair3); 
  myUnorderedSet.insert(pair4); 
  myUnorderedSet.insert(pair5); 
  
  // Calling print function 
  print(myUnorderedSet); 
  return 0; 
}
```


## Patterns


### Two Pointers Pattern

* In problems where we deal with sorted arrays (or linked-lists) and need to find a set of elements that fulfill certain constraints, the Two Pointers approach becomes quite useful. **The set of elements could be a pair, a triplet or even a subarray.**
* It's important to remember that the 2-pointer pattern can differ in how the pointers go. Sometimes they go in the same direction, sometimes the go opposite sides. Sometimes they move simultaneously, others not.
* **REMEMBER: for sorted arrays. You may need to sort the input first.** Although, not every problem may need it.
* Usually in these problems, the difficulty is knowing when to move the pointers. Sometimes there's tricks, usually related to what to assume because the array is sorted.
* Usually, if there's needed a constraint for n elements, the problem grows like this:
  * Pair: two pointers.
  * Triplets: for fixing up first element + two pointers for the rest. 
  * Quadruplets: 2 for's for fixing up the first 2 elements, etc. O(N^3).
* In these kind of problems, usually programming errors are in boundary checks for cycles.

### Fast & Slow Pointers Pattern

The Fast & Slow pointer approach, also known as the Hare & Tortoise algorithm, is a pointer algorithm that uses two pointers which move through the array (or sequence/LinkedList) at different speeds. This approach is quite useful when dealing with cyclic LinkedLists or arrays.

By moving at different speeds (say, in a cyclic LinkedList), the algorithm proves that the two pointers are bound to meet. The fast pointer should catch the slow pointer once both the pointers are in a cyclic loop.

One of the famous problems solved using this technique was **Finding a cycle in a LinkedList**.

* For finding a cycle, start both slow and fast at head. Remember because of this, when advancing, it's usually a **do while (slow != fast)**.

* Mostly useful when: finding the middle of a linked list, or detecting cycles.

### Sliding Window Pattern
In many problems dealing with an array (or a LinkedList), we are asked to find or calculate something among all the subarrays (or sublists) of a given size. For example, **given an array, find the average of each subarray of ‘K’ contiguous elements in it.**

* Useful when for example there's overlapping elements in an array, and want to avoid repeating calculations. That's the case for:
	* Given an array, find the average of each subarray of ‘K’ contiguous elements in it.
	* Given an array of positive numbers and a positive number 'k,' find the maximum sum of any contiguous subarray of size 'k'.
* This pattern usually has a distinct shape; a `for` loop that moves the window end border, and on each ieration the given constraint is validated to decide if the window start should be moved.
* Usually this pattern gives you a **O(n) time complexity** (for the pattern, the constraint validation could multiply that).


### Modified Binary Search Pattern

Whenever we are given a **sorted** Array or LinkedList or Matrix, and we are asked to find a certain element, the best algorithm we can use is the Binary Search. Time complexity is O(log n).

Implementation:

```cpp
	int low = 0;
	int high = arr.size() - 1;
	
	while (low <= high) {
	  const int middle = low + (high - low) / 2;
	
	  if (arr[middle] == key) {
	    return middle;
	  } else if (key > arr[middle]) {
	    low = middle + 1;
	  } else if (key < arr[middle]) {
	    high = middle - 1;
	  }
	}
```

if at the end the element is not found, low will be the smallest greater value than the key. High will be the greatest element smaller than the key.

An sort-direction agnostic implementation:

```cpp
int search(const vector<int>& arr, int key) {
    int low = 0;
    int high = arr.size() - 1;
    int middle = low + (high - low) / 2;
    const bool isAscending = arr[middle] > arr[low];

    while (low <= high) {
      middle = low + (high - low) / 2;

      if (arr[middle] == key) {
        return middle;
      } 

      if (isAscending) {
        if (key > arr[middle]) {
          low = middle + 1;
        } else {
          high = middle - 1;
        }
      } else {
        if (key > arr[middle]) {
          high = middle - 1;
        } else {
          low = middle + 1;
        }
      }
    }

    return -1;
  }
```

**It's crucial to remember that the input needs to be sorted to use the binary search.**

### Tree Breadth First Search Pattern

This pattern is based on the Breadth First Search (BFS) technique to traverse a tree. It's an iterative algorithm.

Any problem involving the traversal of a tree in a level-by-level order can be efficiently solved using this approach. We will use a Queue to keep track of all the nodes of a level before we jump onto the next level. This also means that the space complexity of the algorithm will be O(W), where ‘W’ is the maximum number of nodes on any level.

**Traversal of a binary tree level by level:**

```cpp
  std::vector<vector<int>> traverse(TreeNode *root) {
    vector<vector<int>> result;
    queue<TreeNode*> queue;

    queue.push(root);

    while (!queue.empty()) {
      const int levelSize = queue.size();
      std::vector<int> currentLevel;

      for (int i = 0; i < levelSize; ++i) {
        TreeNode* node = queue.front();
        currentLevel.push_back(node->val);
        queue.pop();

        if (node->left != nullptr) {
          queue.push(node->left);
        }

        if (node->right != nullptr) {
          queue.push(node->right);
        }
      }

      result.push_back(currentLevel);
    }

    return result;
  }
```

**Reverse traversal of a binary tree:**

```cpp
class Solution {
public:
  vector<vector<int>> traverse(TreeNode *root) {
    deque<vector<int>> result = deque<vector<int>>();
    vector<vector<int>> output = vector<vector<int>>();
    if (root == nullptr) {
      return output;
    }

    queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty()) {
      int levelSize = queue.size();
      vector<int> currentLevel;
      for (int i = 0; i < levelSize; i++) {
        TreeNode *currentNode = queue.front();
        queue.pop();
        // add the node to the current level
        currentLevel.push_back(currentNode->val);
        // insert the children of current node to the queue
        if (currentNode->left != nullptr) {
          queue.push(currentNode->left);
        }
        if (currentNode->right != nullptr) {
          queue.push(currentNode->right);
        }
      }
      // append the current level at the beginning
      result.push_front(currentLevel);
    }

    // convert the result queue to vector for output
    for (auto level : result) {
      output.push_back(level);
    }

    return output;
  }
};
```

**Zigzag traversal**

```
vector<vector<int>> traverse(TreeNode *root) {
    vector<vector<int>> result;
    queue<TreeNode*> queue;
    bool isReverseOrder = false;

    queue.push(root);

    while (!queue.empty()) {
      const int levelSize = queue.size();
      std::vector<int> level(levelSize);

      for (int i = 0; i < levelSize; ++i) {
        TreeNode* node = queue.front();

        if (isReverseOrder)
          level[levelSize - 1 - i] = node->val;
        else
          level[i] = node->val;

        queue.pop();

        if (node->left != nullptr)
          queue.push(node->left);

        if (node->right != nullptr) {
          queue.push(node->right);
        }
      }

      result.push_back(level);

      isReverseOrder = !isReverseOrder;
    }

    return result;
  }
```

### Tree Depth First Search Pattern

This pattern is based on the Depth First Search (DFS) technique to traverse a tree.

We will be using recursion (or we can also use a stack for the iterative approach) to keep track of all the previous (parent) nodes while traversing. This also means that the space complexity of the algorithm will be O(H), where ‘H’ is the maximum height of the tree.


### In-place Reversal of a Linked List Pattern

In a lot of problems, we are asked to reverse the links between a set of nodes of a LinkedList. Often, the constraint is that we need to do this in-place, i.e., using the existing node objects and without using extra memory.

### Hashing

Usually used in combination with other techniques, to count occurrences, maximums, etc. or when quick retrieval of a value is needed (for example, as part of the structure of a trie).

### Sets

Usually used to check for duplicates, or visited nodes.

### Stacks

Usually for balance pairing / checking (for example, **balanced parentheses problem.** ). Also, for dynamic programming and check / save visited nodes (DFS, BFS).

### Tries

A Trie, short for retrieval, is a specialized tree-based data structure primarily used for efficient storing, searching, and retrieval of strings over a given alphabet. It excels in scenarios where a large collection of strings needs to be managed and pattern-matching operations need to be performed with optimal efficiency.

Tries are commonly employed in applications such as spell checking, autocomplete suggestions, and searching within dictionaries or databases. They excel at these tasks because they minimize the search complexity in proportion to the length of the target string, making them significantly more efficient than other data structures like binary search trees.

## Other advice

* When working with palindromes, remember to handle non-alphanumeric characters and casing.
* `<cctype>` has a lot of useful utility functions for chars:
	- `toupper()`
	- `tolower()`
	- `isxdigit(int ch)` ->  checks if ch is a hexadecimal numeric character as classified by the current C locale.
	- `isupper()`
	- `isspace()`
	- `ispunct()`
	- `islower()`
	- `isdigit()`
	- `isblank()`
	- `isalpha()`
	- `isalnum()`
* Use a `stringstream` from `sstream` for situations that we have to format a string. std::string is mutable and can be used when there's a lot of concatenations.
* Integer division returns the lowest next integer (floor).
* `const` vs `constexpr` for defining native type static constants. Given
```cpp
const     double PI1 = 3.141592653589793;
constexpr double PI2 = 3.141592653589793;
```

Both PI1 and PI2 are constant, meaning you can not modify them. However only PI2 is a compile-time constant. It shall be initialized at compile time. PI1 may be initialized at compile time or run time. So for **native type static constants, prefer `constexpr`**. For objects, it's necessary to use `const` still.

* A priority queue is useful to get the k largest o smallest elements of an array. The priority queue can be ordered using a lambda function that compares the occurrences in a `unordered_map`, so the top of the priority queue is the largest, etc. Also, remember that a priority queue can be used for heap sort.


```cpp
vector<int> topKFrequent(vector<int>& nums, int k) {
    std::unordered_map<int, int> occurrences;
    std::vector<int> result;

    for (int i = 0; i < nums.size(); ++i) {
        ++occurrences[nums[i]];
    }
    
     // Compares if element 1 comes before element 2. In a priority queue, elements that come before 
     // are output last. That means, if the comparison is n1 > n2, the top will be n2. 
    auto comparisonFunc = [&occurrences] (int n1, int n2) { return occurrences[n1] > occurrences[n2]; };

    std::priority_queue<int, std::vector<int>, decltype(comparisonFunc)> heap(comparisonFunc); 

    for (const std::pair<int, int>& count: occurrences) {
        heap.push(count.first);
        if (heap.size() > k) heap.pop();
    }

    for (int i = 0; i < k; ++i) {
        result.push_back(heap.top());
        heap.pop();
    }

    return result;
}
```


## Coding Problems

### 1. Contains duplicate

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:

```
Input: nums= [1, 2, 3, 4]
Output: false
Explanation: There are no duplicates in the given array.
```

Example 2:

```
Input: nums= [1, 2, 3, 1]
Output: true
Explanation: '1' is repeating.
```

Constraints:
* 1 <= nums.length <= 10^5
* -10^9 1 <= nums.length <= 10^9

#### 1.1 Analysis

**Possible solutions:**

**1. Brute force scenario.**
Iterate through each element of the list, and then compare with each element of the list. If there's a match, there's a duplicated element. Highly inefficient. Resulting complexity O(N^2) (N to the power of 2). Space complexity is O(1).

**2. Use an unordered map.**
Iterate through each element of the list, and then compare if the element is already in the unordered map. The time complexity is O(N) in the worst case. However, it has a space complexity of O(2N), requiring a key value pair. Maybe not too readable and/or elegant.

**3. Use an unordered set.**
Iterate through each element of the list, and then compare if the element is already in the unordered set. The complexity will be O(N) in the worst case. Better than the map, the set only takes the value in the array to compare. Same space complexity, O(N).

**4. Sorting the list.**
Sort the list first (which will add a time complexity of O(N log N)). Then, iterate through the list to compare each element and the one following it. If they match, there's a duplicated element. Time complexity is O(N + N log N) = O(N log N). Space complexity is constant, O(1), depending on the algorithm used.

**Why use the unordered_map or unordered_set?**

Because the have a lookup complexity of O(1) amortized, O(N) worst case.

**What's the difference with the regular Set and Map?**

The lookup complexity for the regular Set and Map is O(log N). Because they are implemented as a red/black tree (they are required to be ordered).
The unordered containers are hashed data structures, which makes the lookup faster, being in constant time.

#### 1.2 Test cases

1. A list with one duplicate -> should return **true**.
2. A list with no duplicates -> should return **false**.
3. A list with the duplicated value on both ends of the list -> should return **true**.
4. A list with a duplicated negative value. -> should return **true**.
5. A list with negative values with no duplicates -> should return **false**.
6. No need to test empty list. The constraints indicate the list always has values.

#### 1.3 Solution
```cpp
#include <unordered_set>
#include <iostream>
#include <vector>

class Solution
{
public:
  bool containsDuplicate(const std::vector<int>& nums)
  {
    std::unordered_set<int> visited;

    for (const int& i : nums) {
      if (visited.find(i) != visited.end()) {
        return true;
      }

      visited.insert(i);
    }

    return false;
  }
};
```

#### 1.4 Lessons learned
* When solving a problem that involves arrays, it could be a solution to think if sorting would help.
* Always check which data structures could help make the algorithm more efficient, and if the penalty in space is worth it.

### 2. Pangrams

A pangram is a sentence where every letter of the English alphabet appears at least once.

Given a string sentence containing English letters (lower or upper-case), return true if sentence is a pangram, or false otherwise.

Note: The given sentence might contain other characters like digits or spaces, your solution should handle these too.

Example 1:

```
Input: sentence = "TheQuickBrownFoxJumpsOverTheLazyDog"
Output: true
Explanation: The sentence contains at least one occurrence of every letter of the English alphabet either in lower or upper case.
```

Example 2:

```
Input: sentence = "This is not a pangram"
Output: false
Explanation: The sentence doesn't contain at least one occurrence of every letter of the English alphabet.
```

Constraints:

    1 <= sentence.length <= 1000
    Sentence consists of lowercase English letters.

#### 2.1 Analysis
**Possible solutions**

**1. Brute-force scenario.**

Iterate through a vector of all letters in the alphabet, then iterate through all the characters in the string to check if the letter is present. If one of the letters is not present, return **false**; otherwise, return **true**. Highly inefficient, of course. Time complexity of O(N^2). Space complexity O(26) = O(N) being N the letters in the alphabet.

**2. Using an unordered map with the count for each letter of the alphabet.**

Iterate through the characters in the string, and then if it's a letter of the alphabet, increment the value for that letter in the map. After iterating through all the characters, the program should iterate through all the values in the unordered map. If there's at least one value that is 0, return **false**. Otherwise, return **true**. O(N + N) = O(2N) = O(N). Space complexity O(26 * 2) = O(1) because the map can at most have 26 * 2 elements for all strings.

**3. Using an unordered set with alphabet letters.**

Starting with a map with all the letter in the alphabet, we iterate through all the characters in the input string. For each character in the input that is an alphabet letter, remove that letter from the set. After that, if the unordered set is empty, return **true**. Otherwise, the string is not pangram and the program should return **false**. Time complexity will be O(26 + N) = O(N), because the set is constructed and then the string iterated. Space complexity O(26) = O(1) because the set will always be size 26, constant.

**4. Order the string and add only alphabet characters to a set.**

Start by ordering the string, and then, add all the characters that are alphabet letters to a set. If the size of the set at the is 26 (total letters in the alphabet) return **true**; otherwise, return **false**.

**5. Using an unordered set.**

Iterate through all the characters in the string, and if it's an alphabet letter, save in the set. After that, if the unordered set has size 26, return **true**. Otherwise, the string is not pangram and the program should return **false**. Time complexity will be O(N), because the string is only iterated once; inserting and looking up in the set is done in constant time O(1). Space complexity O(26) = O(1) because the most items set can have is 26 for all strings.

#### 2.2 Test cases
1. A valid pangram without special characters.
2. A valid pangram with special characters.
3. A regular string that is not a pangram.
4. No need to try an empty string, it's on the constraints.

#### 2.3 Solution

Implemented solution #5.

```cpp
#include <unordered_set>
#include <iostream>

static const size_t ALPHABET_COUNT = 26;

class Solution {
  public:
    bool checkIfPangram(const std::string& sentence) {
      std::unordered_set<char> alphabet;

      for (const char character : sentence) {
        const char lowercaseChar = tolower(character);

        if (isalpha(lowercaseChar)) {
          alphabet.insert(lowercaseChar);
        }
      }

      return alphabet.size() == ALPHABET_COUNT;
    }
};
```

#### 2.4 Lessons learned

* An unordered_set can be initialized with an initializer list.

```cpp
  std::unordered_set<string>New_set({
    "Ground",
    "Grass",
    "Floor",
    "Table",
    "Wood"
  });
```

* To erase an element from an unordered_set, use `erase(ELEMENT)`.
* Don't forget to put the type on the template for the containers.
* No need to use references when using a range-based for when using native types, because they are trivially-copyable.
* “Objects of trivially-copyable types are the only C++ objects that may be safely copied with std::memcpy”. [[Source]](https://olafurw.com/2019-02-14-trivial-code/)
* `isalpha(char)` returns **true** if a char is an alphabetic character.
* `tolower(char)` returns the lowercase version of the given char.
* `<cctype>` has a lot of useful utility functions for chars:
	- `toupper()`
	- `tolower()`
	- `isxdigit(int ch)` ->  checks if ch is a hexadecimal numeric character as classified by the current C locale.
	- `isupper()`
	- `isspace()`
	- `ispunct()`
	- `islower()`
	- `isdigit()`
	- `isblank()`
	- `isalpha()`
	- `isalnum()`

### 3. Reverse Vowels

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

Example 1:

```
Input: s= "hello"
Output: "holle"
```

Example 2:

```
Input: s= "AEIOU"
Output: "UOIEA"
```

Example 3:

```
Input: s= "DesignGUrus"
Output: "DusUgnGires"
```

Constraints:
* 1 <= s.length <= 3 * 105
* s consist of printable ASCII characters.

#### 3.1 Analysis

**Possible solutions**

**1. Using two pointers.**
We start with one pointer on the right, and one pointer on the left of the string. The left pointer advances forward, and the right pointer advances backwards. They advance until they match a vowel, and if that happens, it swaps the values. Has time complexity O(N) and O(N) space complexity, requiring a copy.

#### 3.2 Test cases

1. A string with pairs of vowels.
2. A string with only one vowel.
3. A string with no vowels.
4. A string with an odd number of vowels.
5. A string made with only vowels.
6. A string with a combination of upper and lowercase vowels.

#### 3.3 Solution
```cpp
#include <iostream>
#include <string>
#include <unordered_set>

static const std::unordered_set<char> VOWELS({
  'a', 'A',
  'e', 'E', 
  'i', 'I',
  'o', 'O',
  'u', 'U'
}); // Lookup: O(1)

class Solution {
  public:
    std::string reverseVowels(const std::string& s) {
      size_t left = 0;
      size_t right = s.size() - 1;
      std::string result = s; // O(N)

      while (right > left) { // O(N/2)
        while(right > left && VOWELS.find(result[left]) == VOWELS.end()) {
          ++left;
        }

        while (right > left && VOWELS.find(result[right]) == VOWELS.end()) {
          --right;
        }

        if (right > left)
          std::swap(result[left++], result[right--]); // O(1)
      }

      return result;
    }
};
```

#### 3.4 Lessons learned
* Be careful with the condition for stopping cycles. Make sure they are always valid.
* Be careful with pre and post increments.
* If I need a set for comparison (for example the vowels), if the set is small enough, just put everything. I tried first putting only lowercase values, but putting uppercase was cheap too.

### 4. Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:

```
Input: sentence = "A man, a plan, a canal, Panama!"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
```

Example 2:

```
Input: sentence = "Was it a car or a cat I saw?"
Output: true
Explanation: Explanation: "wasitacaroracatisaw" is a palindrome.
```

Constraints:

    1 <= s.length <= 2 * 105
    s consists only of printable ASCII characters.

#### 4.1 Analysis.

This is basically solved using the two pointer pattern.

#### 4.2 Test cases

* Empty string.
* A one character string.
* A palindrome with alphabetic letters and numbers.
* A character with a non-alphanumeric characters.
* A character and a non-alphanumeric character.
* A string that is not a palindrome.

#### 4.3 Solution

```cpp
#include <iostream>

class Solution {
public:
  bool isPalindrome(const std::string& s) {
    size_t first = 0;
    size_t last = s.size() - 1;

    if (s.empty()) {
      return true;
    }

    while (last > first) {
      while (last > first && !isalnum(s[first])) {
        ++first;
      }

      while (last > first && !isalnum(s[last])) {
        --last;
      }

      std::cout << first << std::endl;
      std::cout << last << std::endl;

      if (tolower(s[first]) != tolower(s[last])) {
        return false;
      }
		
	  // Avoids overflow on the last pointer.
      if (last > first) {
        ++first;
        --last;
      }
    }

    return true;
  }
};
```

There's no copies, so the algorithm runs in place. The iteration for the while will take at most O(N/2) iterations. There's no use of additional space, so space complexity is constant. This results in 
a time complexity of O(N) and a space complexity of O(1).

#### 4.4 Lessons learned
* Be careful with size_t and subtracting. If it gets to zero, there will be an overflow.
* If you are going to go step by step, DO ALL THE STEPS. Think about side-effects, how variables are affected.
* Test cases comes in all forms. Size 1, "a"; Size 2, "a.". Important to test weird cases.
* Test cases can be a discussion point. That's why maybe they should presented first. For example, here there's a valid discussion if empty is a palindrome (it is) or what's the expectation with a single character.
* `isalnum` was very helpful.

### 5. Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: s = "listen", t = "silent"
Output: true

Example 2:

```
Input: s = "rat", t = "car"
Output: false
```

Example 3:

```
Input: s = "hello", t = "world"
Output: false
```

Constraints:

    1 <= s.length, t.length <= 5 * 104
    s and t consist of lowercase English letters.

#### 5.1 Analysis

**Possible solutions**

**1. Sorting both string, then comparing.** Sorting would have a complexity of O(M log M + N Log N), and comparing O(N). In total, would be O(N log N) for time complexity. For space complexity, given that is required to copy both strings, would be O(N * M) (worst case when they are not anagrams). Definitely the complexity for both time and space can be improved by validating the size of both at the beginning. That would get O(N log N) for time and O(N) for space.

**2. Using unordered maps for counting the occurrences of the characters.** Get the counts for each character in unordered maps for each string, then compare both unordered maps. This would require O(N + N) for building the count maps. Then O(N^2) for map comparison [[Source]](https://en.cppreference.com/w/cpp/container/unordered_map/operator_cmp). Space complexity is O(N).

**3. Unordered maps, but subtracting the counts.**

#### 5.2 Test cases
* A valid anagram.
* Two strings that are not anagrams.
* No need to test the empty string.
* One character anagrams.
* Strings with different sizes.
* Not anagrams with same size.

#### 5.3 Solution

Implemented using solution #2

```cpp
#include <algorithm>
#include <iostream>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
      if (s.size() != t.size()) {
        return false;
      }

      std::sort(s.begin(), s.end());
      std::sort(t.begin(), t.end());

      return s == t;
    }
};
```

Implemented using solution #3.

```cpp
#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
      if (s.size() != t.size()) {
        return false;
      }

      std::unordered_map<char, int> charCount;

      for (size_t i = 0; i < s.size(); ++i) {
        charCount[s[i]]++;
        charCount[t[i]]--;
      }

      for (const auto& [character, count] : charCount) {
        if (count != 0)
          return false;
      }

      return true;
    }
};
```

I don't like this solution that much because it may break portability of the program, and potentially size_t (which is the type C++ uses for collection size) can be bigger than 32 bits. [[Source]](https://en.cppreference.com/w/cpp/types/size_t)

>The primary use of size_t in C++ is for loop counting and array indexing provided by the standard template library in C++. Programs that rely on 32-bit modular arithmetic or use other types, for example - unsigned int and indexing of array, may break on 64-bit platforms whenever the array index exceeds UINT_MAX.

However, the constraints only specify that words can be only in the range of 1 <= s.length, t.length <= 5 * 104, which is fine for using an int.


#### 5.4 Lessons learned
* `unordered_map` comparison (operator==) has a complexity of O(N^2) at worst [[Source]](https://en.cppreference.com/w/cpp/container/unordered_map/operator_cmp).

### 6. Shortest Word Distance
Given an array of strings words and two different strings that already exist in the array word1 and word2, return the shortest distance between these two words in the list.

Example 1:

```
Input: words = ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"], word1 = "fox", word2 = "dog"
Output: 5
Explanation: The distance between "fox" and "dog" is 5 words.
```

Example 2:

```
Input: words = ["a", "c", "d", "b", "a"], word1 = "a", word2 = "b"
Output: 1
Explanation: The shortest distance between "a" and "b" is 1 word. Please note that "a" appeared twice.
```

Example 3:

```
Input: words = ["a", "b", "c", "d", "e"], word1 = "a", word2 = "e"
Output: 4
Explanation: The distance between "a" and "e" is 4 words.
```

Constraints:

* 2 <= words.length <= 3 * 104
* 1 <= words[i].length <= 10
* words[i] consists of lowercase English letters.
* word1 and word2 are in words.
* word1 != word2

### 6.1 Analysis

At first, this could look like a two pointer problem where the pointers move. However, this can be solved with only one loop that checks if the current position is one of the words given, and then update the position.

#### 6.2 Test cases
* A valid word array like the example. ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"], word1 = "fox", word2 = "dog".
* A word array, but word1 is in the last position and word2 at the first one.
* Word1 is duplicated in both the start and the end.
* Word1 and word2 are duplicated in the array.

#### 6.3 Solution

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int shortestDistance(
    const vector<string>& words,
    const string& word1,
    const string& word2) const
  {
    int position1 = -1;
    int position2 = -1;
    int shortestDistance = words.size();

    for (int i = 0; i < words.size(); ++i)
    {
      if (words[i] == word1)
      {
        position1 = i;
      }
      else if (words[i] == word2)
      {
        position2 = i;
      }

      if (position1 >= 0 && position2 >= 0) {
        shortestDistance = std::min(shortestDistance, std::abs(position2 - position1));
      }
    }

    return shortestDistance;
  }
};
```

This solution has a time complexity of O(N), because we only need to iterate through the list of elements once. Space complexity is constant, no copies are done, and always use 3 variables to do its job.

#### 6.4 Lessons learned
* Don't blindly follow a solution. Understand it first.
* When studying and getting stuck, don't stay stuck. Put a timer, and then study the solution.

### 7. Number of Good Pairs
Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.

Example 1:

```
Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs, here are the indices: (0,3), (0,4), (3,4), (2,5).
```

Example 2:

```
Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array is a 'good pair'.
```

Example 3:

```
Input: words = nums = [1,2,3]
Output: 0
Explanation: No number is repeating.
```

Constraints:

* 1 <= nums.length <= 100
* 1 <= nums[i] <= 100

### 7.1 Analysis

**Possible solutions**

**1. Brute-force.**

Iterate through each element and then iterate through the whole list looking for good pairs for that element. Will end up having a time  complexity of O(N-1 + N - 2 + N - 3 + ... + 1) = O(N * (N - 1) / N) = O(N^2)

**2. Using a hash table.**

Calculate the ocurrences of each number and save them to a hash table. Whenever we find a new occurrence of a number, we have found a new pair, if there's at least 2 elements.

Every new occurrence of a number can be paired with every previous occurrence of the same number. This means if a number has already appeared p times, we will have p-1 new pairs. This can be done with 1 iteration.

### 7.3 Solution
```cpp
#include <iostream>
#include <map>
#include <vector>

class Solution {
  public:
    int numGoodPairs(const std::vector<int>& nums) {
      std::unordered_map<int, int> ocurrences;
      int pairCount = 0;

      for (size_t i = 0; i < nums.size(); ++i) {
        ocurrences[nums[i]]++;

        pairCount += ocurrences[nums[i]] - 1;
      }

      return pairCount;
    }
};
```

This solution has time complexity of O(N), because only needs one pass through the whole input vector. Space complexity will be in the worst case O(N), which correspond to the unordered map fill with one ocurrence for each element if there are no equal elements.

### 7.4 Lessons Learned

* There's no factorial function in the C++ standard library.
* Sometimes solutions are simpler than they look.

### 8. Sqrt (medium)

Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

Example 1:

```
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.8284, and since we need to return the floor of the square root (integer), hence we returned 2.
```

Example 2:

```
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2.
```

Example 3:

```
Input: x = 2
Output: 1
Explanation: The square root of 2 is 1.414, and since we need to return the floor of the square root (integer), hence we returned 1.
```

Constraints:

* 0 <= x <= 231 - 1

#### 8.3 Solution

```cpp
class Solution {
public:
  int mySqrt(const int x) const
  {
    if (x < 2) {
      return x;
    }

    int left = 2;
    int right = x / 2;

    while (left <= right) {
      int pivot = left + (right - left) / 2;
      long squaredPivot = static_cast<long>(pivot) * pivot;

      if (squaredPivot > x) {
        right = pivot - 1;
      } else if (squaredPivot < x) {
        left = pivot + 1;
      } else {
        return pivot;
      }
    }

    return right;
  }
};
```

**Time Complexity**

**1. Binary Search Algorithm:** The key part of this algorithm is the binary search, which repeatedly divides the search interval in half. The time complexity of binary search is O(log N), where N is the size of the search space. In this case, the search space is initially from 2 to x/2.

**2. Search Space:** The maximum size of the search space is x/2 (when x >= 4). For smaller values of x, the function immediately returns x, as it's either 0 or 1.

**3. Overall Time Complexity:** Considering the binary search on a range up to x/2, the time complexity is O(log x / 2), which simplifies to O(log x).

**Space Complexity**

**1. Constant Extra Space:** The algorithm uses a fixed number of integer variables (left, right, pivot, num), regardless of the input size.

**2. No Recursive Calls or Dynamic Allocation:** The implementation does not use recursion or allocate additional data structures that grow with the input size.

**3. Overall Space Complexity:** Given the constant amount of extra space, the space complexity is O(1), meaning it's constant.

#### 8.4 Lessons learned

* Be careful with overflowing when doing math operations. For example:

```cpp
int pivot = left + (right - left) / 2;

// This will overflow. Pivot is still an integer multiplication.
long squaredPivot = pivot * pivot;

// This will not overflow. By one of the operands being cast to long,
// the final operation is a long.
long squaredPivot = static_cast<long>(pivot) * pivot;
```

* Use modern cast operations instead of C-type casts. [[More info]](https://stackoverflow.com/questions/332030/when-should-static-cast-dynamic-cast-const-cast-and-reinterpret-cast-be-used)

### 9. Pair with Target Sum (easy)

Given an array of numbers sorted in ascending order and a target sum, find a pair in the array whose sum is equal to the given target.

Write a function to return the indices of the two numbers (i.e. the pair) such that they add up to the given target. If no such pair exists return [-1, -1].

Example 1:

```
Input: [1, 2, 3, 4, 6], target=6
Output: [1, 3]
Explanation: The numbers at index 1 and 3 add up to 6: 2+4=6
```

Example 2:

```
Input: [2, 5, 9, 11], target=11
Output: [0, 2]
Explanation: The numbers at index 0 and 2 add up to 11: 2+9=11
```

Constraints:

* 2 <= arr.length <= 10^4
* -10^9 <= arr[i] <= 10^9
* -10^9 <= target <= 10^9
* Only one valid answer exists.

#### 9.1 Analysis

**1. Brute force.**

Since the given array is sorted, a brute-force solution could be to iterate through the array, taking one number at a time and searching for the second number through Binary Search. The time complexity of this algorithm will be O(N log N).

**2. Using two pointers.**

I chose this solution.

**3. Using a hash table.**

Instead of using a two-pointer or a binary search approach, we can utilize a HashTable to search for the required pair. We can iterate through the array one number at a time. Let’s say during our iteration we are at number ‘X’, so we need to find ‘Y’ such that “X + Y == Target". We will do two things here:

Search for ‘Y’ (which is equivalent to “Target−X”) in the HashTable. If it is there, we have found the required pair. Otherwise, insert “X” in the HashTable, so that we can search it for the later numbers.

Complexity O(N).

#### 9.2 Solution

``` cpp
#include <iostream>
#include <vector>

class Solution {

  public:

  static std::vector<int> search(
    const std::vector<int>& arr,
    int targetSum)
  {
    int first = 0;
    int last  = arr.size() - 1;

    while (first < last)
    {
      const int sum = arr[first] + arr[last];

      if (sum > targetSum)
      {
        --last;
      }
      else if (sum < targetSum)
      {
        ++first;
      }
      else {
        return std::vector<int>({ first, last });
      }
    }

    return std::vector<int>({ -1, -1});
  }
};
```

**Time Complexity**

**Initialization:**

Constant time, O(1), as it involves assigning values to left and right.

**While Loop:**

The while loop runs as long as left is less than right.

In the worst case, this loop iterates over all elements of the array once. This happens when no pair is found, or the pair is found at the extreme ends of the array. 

Each iteration involves a constant amount of work: calculating currentSum, comparing it with targetSum, and then incrementing left or decrementing right.

Therefore, the loop runs in O(N) time, where N is the number of elements in the array.

**Overall:**

The dominant factor in this algorithm is the while loop, making the overall time complexity O(N).

**Space Complexity**

The algorithm uses a fixed amount of extra space: variables left, right, and currentSum. It does not depend on the size of the input array, as no additional data structures are used that grow with the input size. Thus, the space complexity is O(1), constant space.

