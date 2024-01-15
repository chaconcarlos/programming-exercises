/**
 * @file PowersetCalculationTest.cpp
 *
 * @brief Implementation of the tests of the method that calculates the powerset of a string.
 *
 * @author   Carlos Chacon <chacon.carlosj@gmail.com>
 * @date     Mar 21, 2018
 */

/* INCLUDES ******************************************************************/

#include <gmock/gmock.h>

#include <cstdint>
#include <limits>
#include <string>

/* USINGS ********************************************************************/

using namespace testing;

/* STATIC FUNCTIONS **********************************************************/

/*
 * @brief Gets the powerset of a string.
 *
 * @param set The string that represents the main set.
 *
 * @return The powerset of the given string.
 */
static std::vector<std::string>
getPowerset(const std::string& set)
{
  const size_t             subsetsTotal = pow(2, set.size());
  const size_t             setSize      = set.size();
  std::vector<std::string> result;

  for (size_t i = 0; i < subsetsTotal; ++i)
  {
    std::string subset;

    for (size_t j = 0; j < setSize; ++j)
    {
      const uint8_t bitValue = (i >> j) & 1;

      if (bitValue)
        subset.append(1, set[j]);
    }

    result.push_back(subset);
  }

  return result;
}

/* IMPLEMENTATION ************************************************************/

TEST(PowersetCalculation, powerset_empty_returnEmptySubset)
{
  // Arrange
  const std::string        set = "";
  std::vector<std::string> subsets;

  // Act
  subsets = getPowerset(set);

  // Assert
  ASSERT_THAT(subsets.size(), Eq(1));
  ASSERT_THAT(subsets[0],     Eq(""));
}

TEST(PowersetCalculation, powerset_abc_return8subsets)
{
  // Arrange
  const std::string        set = "abc";
  std::vector<std::string> subsets;

  // Act
  subsets = getPowerset(set);

  // Assert
  ASSERT_THAT(subsets.size(), Eq(8));
}

TEST(PowersetCalculation, powerset_abcdefgh_return8subsets)
{
  // Arrange
  const std::string        set = "abcdefgh";
  std::vector<std::string> subsets;

  // Act
  subsets = getPowerset(set);

  // Assert
  ASSERT_THAT(subsets.size(), Eq(256));
}

TEST(PowersetCalculation, powerset_abcdefghijklmnopq_return131072subsets)
{
  // Arrange
  const std::string        set = "abcdefghijklmnopq";
  std::vector<std::string> subsets;

  // Act
  subsets = getPowerset(set);

  // Assert
  ASSERT_THAT(subsets.size(), Eq(131072));
}