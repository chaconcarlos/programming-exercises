/**
 * @file VerifyUniqueString.cpp
 *
 * @brief Verifies if a given string has only unique characters.
 *
 * @author Carlos Chacon <chacon.carlosj@gmail.com>
 * @date   Jan 24, 2019
 */

/* INCLUDES ******************************************************************/

#include <algorithm>
#include <iostream>
#include <string>

/* DEFINITIONS ***************************************************************/

static const uint8_t OFFSET_VALID_CHARS = 33;

/* STATIC FUNCTIONS **********************************************************/

/**
 * @brief Verifies if a string has duplicated characters.
 *
 * @param sequence The string to verify.
 *
 * @return <tt>true</tt> if string has duplicated characters; otherwise, <tt>false</tt>.
 */
static bool
hasDuplicatedCharacters(const std::string& sequence)
{
  bool     hasDuplicates = false;
  uint32_t registry      = 0;

  for (size_t i = 0; i < sequence.size(); ++i)
  {
    const uint8_t shift = sequence[i] - OFFSET_VALID_CHARS;

    if ((registry >> shift) & 1)
    {
      hasDuplicates = true;
      break;
    }
    else
    {
      registry |= (1 << shift);
    }
  }

  return hasDuplicates;
}

/* IMPLEMENTATION ************************************************************/

int main()
{
  std::string testString = "bzcrthd!";

  if (!hasDuplicatedCharacters(testString))
    std::cout << "The string '" << testString << "' has no duplicated characters." << std::endl;
  else
    std::cout << "The string '" << testString << "' has duplicated characters." << std::endl;

  return 0;
}