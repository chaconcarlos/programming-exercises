/**
 * @file ReplaceWhiteSpaces.cpp
 *
 * @brief Replaces whitespaces in a given string.
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

static const char WHITESPACE = ' ';

/* STATIC FUNCTIONS **********************************************************/

/**
 * @brief Gets the total number of whitespaces in a string.
 *
 * @param input  The string.
 * @param length The length of the string.
 *
 * @return The total number of whitespaces in the given string.
 */
static size_t
getTotalWhitespaces(char* input, const size_t length)
{
  size_t totalWhitespaces = 0;

  for (size_t i = 0; i < length; ++i)
  {
    if (input[i] == WHITESPACE)
      ++totalWhitespaces;
  }

  return totalWhitespaces;
}

/**
 * @brief Replaces the whitespaces its URL encoded value, '%20'.
 *
 * @param input  The string.
 * @param length The length of the string.
 */
static void
replaceWhitespaces(char* input, const size_t length)
{
  const size_t whitespaceCount  = getTotalWhitespaces(input, length);
  size_t       windowIndex      = length + (whitespaceCount * 2) - 1;
  size_t       smallWindowIndex = length - 1;

  while (windowIndex)
  {
    if (input[smallWindowIndex] == WHITESPACE)
    {
      input[windowIndex--] = '0';
      input[windowIndex--] = '2';
      input[windowIndex]   = '%';
    }
    else
    {
      std::swap(input[smallWindowIndex], input[windowIndex]);
    }

    smallWindowIndex--;
    windowIndex--;
  }
}

/* IMPLEMENTATION ************************************************************/

int main()
{
  char         input[]    = "Mr John Smith    ";
  const size_t trueLength = 13;

  replaceWhitespaces(input, trueLength);

  std::cout << input << std::endl;
}