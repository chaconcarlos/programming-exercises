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

/* STATIC FUNCTIONS **********************************************************/

/**
 * @brief Compresses a string using a [char][count] format.
 *
 * @param input The input string.
 *
 * @return The compressed string.
 */
static std::string
compress(const std::string& input)
{
  std::string result;
  size_t      repeatsCount = 0;

  for (size_t i = 0; i < input.size(); ++i)
  {
    bool isRepetition = false;

    if (i == input.size() - 1)
      isRepetition = false;
    else
      isRepetition = input[i] == input[i + 1];

    ++repeatsCount;

    if (!isRepetition)
    {
      // Append is faster than using std::ostringstream.
      // https://stackoverflow.com/questions/19844858/c-stdostringstream-vs-stdstringappend
      result.append(1, input[i]);
      result.append(std::to_string(repeatsCount));
      repeatsCount = 0;
    }
  }

  return result.size() >= input.size() ? input : result;
}

/* IMPLEMENTATION ************************************************************/

int main()
{
  const std::string input  = "aabcccccaaa";
  const std::string output = compress(input);

  std::cout << output << std::endl;
}