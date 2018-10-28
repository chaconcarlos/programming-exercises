/**
 * @file FindSingleIntegerTest.cpp
 *
 * @brief Implementation of the find single integer in array method tests.
 *
 * @author   Carlos Chacon <chacon.carlosj@gmail.com>
 * @date     Mar 21, 2018
 */

/* INCLUDES ******************************************************************/

#include <gmock/gmock.h>

#include <cstdint>
#include <string>
#include <vector>

/* USINGS ********************************************************************/

using namespace testing;

/* STATIC FUNCTIONS **********************************************************/

/**
 * @brief Get the integer that is single in an array of integer duplicates.
 *
 * @param input The input array.
 *
 * @return The single integer.
 */
static int
findSingle(const std::vector<int>& input)
{
  int accumulator = 0;

  for (size_t i = 0; i < input.size(); ++i)
    accumulator ^= input[i];

  return accumulator;
}

/* IMPLEMENTATION ************************************************************/

TEST(FindSingleInteger, no_zero_single_is_1)
{
  const std::vector<int> input = { 1, 2, 2, 3, 4, 5, 4, 3, 5 };

  ASSERT_THAT(findSingle(input), Eq(1));
}

TEST(FindSingleInteger, includes_zero_single_is_1)
{
  const std::vector<int> input = { 0, 0, 2, 2, 3, 4, 5, 4, 3, 5, 1 };

  ASSERT_THAT(findSingle(input), Eq(1));
}
