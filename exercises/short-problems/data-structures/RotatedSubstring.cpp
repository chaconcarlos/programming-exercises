/**
 * @file RotatedSubstring.cpp
 *
 * @brief Verifies if a string s1 and a string s2 (rotated from s1) is a substring of s1.
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
 * @brief Verifies if a string s2 is a substring of s1.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 *
 * @return  </b>true</b> if s2 is a substring of s1; otherwise, <b>false.</b>
 */
static bool
isSubstring(const std::string& s1, const std::string& s2)
{
  return s1.find(s2) != std::string::npos;
}

/**
 * @brief Verifies if a string s2 is a rotated substring of s1.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 *
 * @return  </b>true</b> if s2 is a rotated substring of s1; otherwise, <b>false.</b>
 */
static bool
isRotatedSubstring(const std::string& s1, const std::string& s2)
{
  bool isRotatedSubstring = false;

  if (s1.size() == s2.size())
  {
    const std::string baseComparableString = s1 + s1;
    isRotatedSubstring = isSubstring(baseComparableString, s2);
  }

  return isRotatedSubstring;
}

/* IMPLEMENTATION ************************************************************/

int main()
{
  const std::string s1 = "waterbottle";
  const std::string s2 = "erbottlewat";

  std::cout << "Is '" << s2 << "'' a rotated substring of '" << s1 << "'? " << (isRotatedSubstring(s1, s2) ? "yes!" : "no!") << std::endl;

  return 0;
}