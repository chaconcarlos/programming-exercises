Coding Interview Patterns Study Guide
=====================================

About namespaces
----------------
### `using namespace std` is a bad practice.
  While using namespace std; might seem convenient, it's generally considered bad practice due to the potential for naming conflicts and reduced code readability. Embracing explicit namespace usage is a better approach, ensuring your code remains clean, maintainable, and free of unexpected issues. [[Source]](https://dev.to/iamcymentho/using-namespace-std-in-c-why-its-considered-bad-practice-2adf)

### Important headers to remember
| Header Name      | Description                                      |
| -----------      | -----------                                      |
| \<stdexcept>     | Exceptions                                       |
| \<string>        | std::string                                      |
| \<unordered_set> | std::unordered_set                               |
| \<vector>        | std::vector                                      |
| \<iomanip>       | Stream manipulators (like set_precision)         |
| \<cctype>        | Character type utility functions, like isalpha() |

Code Snippets
-------------
### Iterating a container
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

Other advice
------------
* Use a stringstream from sstream for situations that we have to format a string. std::string is mutable and can be used when there's a lot of concatenations.
* Integer division returns the lowest next integer (floor).

Coding Problems
---------------
### 1. Contains duplicate: Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
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

      if (last > first) {
        ++first;
        --last;
      }
    }

    return true;
  }
};
```

#### 4.4 Lessons learned
* Be careful with size_t and subtracting. If it gets to zero, there will be an overflow.
* If you are going to go step by step, DO ALL THE STEPS. Think about side-effects, how variables are affected.
* Test cases comes in all forms. Size 1, "a"; Size 2, "a.". Important to test weird cases.
* Test cases can be a discussion point. That's why maybe they should presented first. For example, here there's a valid discussion if empty is a palindrome (it is) or what's the expectation with a single character.
* `isalnum` was very helpful.

