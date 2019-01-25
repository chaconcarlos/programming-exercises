/**
 * @file ReverseCharArray.cpp
 *
 * @brief Reverses a given char array.
 *
 * @author Carlos Chacon <chacon.carlosj@gmail.com>
 * @date   Jan 24, 2019
 */

/* INCLUDES ******************************************************************/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

/* DEFINITIONS ***************************************************************/

/* STATIC FUNCTIONS **********************************************************/

/**
 * @brief Calculates the sum of the values of the characters of the given string.
 *
 * @param input The string.
 *
 * @return The sum of the values of the characters of the given string.
 */
static size_t
calculateStringSum(const std::string& input)
{
  size_t result = 0;

  for (size_t i = 0; i < input.size(); ++i)
  {
    result += input[i];
  }

  return result;
}

/**
 * @brief Verifies if a string is a permutation of another one.
 *
 * @param string1 The first string.
 * @param string2 The second string.
 *
 * @return <tt>true</tt> if string1 is a permutation of string2; otherwise, <tt>false</tt>.
 */
static bool
existsPermutation(const std::string& string1, const std::string& string2)
{
  bool result = false;

  if (string1.size() == string2.size())
    result = calculateStringSum(string1) == calculateStringSum(string2);

  return result;
}

/* IMPLEMENTATION ************************************************************/

int main()
{
  const std::string string1       = "asdsfgghjkl";
  const std::string string2       = "lakssfjdhfg";
  const bool        isPermutation = existsPermutation(string1, string2);

  if (isPermutation)
    std::cout << string1 << " is a permutation of " << string2 << std::endl;
  else
    std::cout << string1 << " is not a permutation of " << string2 << std::endl;
}