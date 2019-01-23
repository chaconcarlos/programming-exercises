/**
 * @file StringToIntTest.cpp
 *
 * @brief Implementation of the tests of the method that converts a string to int.
 *
 * @author Carlos Chacon <chacon.carlosj@gmail.com>
 * @date   Mar 21, 2018
 */

/* INCLUDES ******************************************************************/

#include <gmock/gmock.h>

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <stdexcept>
#include <string>

/* USINGS ********************************************************************/

using namespace testing;

/* DEFINITIONS ***************************************************************/

static const char        NEGATIVE_SIGN       = '-';
static const uint8_t     TENS_MULTIPLIER     = 10;
static const uint8_t     ASCII_DIGITS_OFFSET = 48;
static const std::string ZERO_STRING         = "0";

/* STATIC FUNCTIONS **********************************************************/

/**
 * @brief Returns the int representation of a string.
 *
 * @param input The string.
 *
 * @return The int representation of the given string.
 *
 * @throw invalid_argument if the input is empty, or not a valid integer.
 */
static int64_t
convertStringToInt(const std::string& input)
{
  const bool isNegative = !input.empty() && (input[0] == NEGATIVE_SIGN);
  int64_t    result     = 0;

  if (input.empty())
  {
    throw std::invalid_argument("The input can't be empty.");
  }
  else if (input == ZERO_STRING)
  {
    result = 0;
  }
  else
  {
    size_t i = isNegative ? 1 : 0;

    for (; i < input.size(); ++i)
    {
      const char digit = input[i];

      result = result * TENS_MULTIPLIER;

      if (isdigit(digit))
        result += (digit - ASCII_DIGITS_OFFSET);
      else
        throw std::invalid_argument("The input is not a valid integer.");
    }
  }

  return isNegative ? result * -1 : result;
}

/* IMPLEMENTATION ************************************************************/

TEST(StringToInt, convert_String0_returnValidInt)
{
  // Arrange
  const std::string input = "0";

  // Act
  const int64_t result = convertStringToInt(input);

  // Assert
  ASSERT_THAT(result, Eq(0));
}

TEST(StringToInt, convert_String1_returnValidInt)
{
  // Arrange
  const std::string input = "1";

  // Act
  const int64_t result = convertStringToInt(input);

  // Assert
  ASSERT_THAT(result, Eq(1));
}

TEST(StringToInt, convert_String691489734656_returnValidInt)
{
  // Arrange
  const std::string input = "691489734656";

  // Act
  const int64_t result = convertStringToInt(input);

  // Assert
  ASSERT_THAT(result, Eq(691489734656));
}

TEST(StringToInt, convert_StringNegative691489734656_returnValidInt)
{
  // Arrange
  const std::string input = "-691489734656";

  // Act
  const int64_t result = convertStringToInt(input);

  // Assert
  ASSERT_THAT(result, Eq(-691489734656));
}

TEST(StringToInt, convert_EmptyString_InvalidArgumentException)
{
  // Arrange
  const std::string input = "";

  // Assert
  EXPECT_THROW(convertStringToInt(input), std::invalid_argument);
}

TEST(StringToInt, convert_AlphanumericString_InvalidArgumentException)
{
  // Arrange
  const std::string input = "A234´84";

  // Assert
  EXPECT_THROW(convertStringToInt(input), std::invalid_argument);
}

TEST(StringToInt, convert_HyphenEndedNumericString_InvalidArgumentException)
{
  // Arrange
  const std::string input = "342423423-";

  // Assert
  EXPECT_THROW(convertStringToInt(input), std::invalid_argument);
}

