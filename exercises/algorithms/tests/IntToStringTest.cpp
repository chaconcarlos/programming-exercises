/**
 * @file IntToStringTest.cpp
 *
 * @brief Implementation of the tests of the method that converts an int to string.
 *
 * @author   Carlos Chacon <chacon.carlosj@gmail.com>
 * @date     Mar 21, 2018
 */

/* INCLUDES ******************************************************************/

#include <gmock/gmock.h>

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <string>

/* USINGS ********************************************************************/

using namespace testing;

/* DEFINITIONS ***************************************************************/

static const int         TENS_DIVISOR        = 10;
static const int         ASCII_DIGITS_OFFSET = 48;
static const char        NEGATIVE_SIGN       = '-';
static const std::string ZERO_STRING         = "0";

/* STATIC FUNCTIONS **********************************************************/

/**
 * @brief Returns the string representation of an integer.
 *
 * @param x The integer.
 *
 * @return The string representation of the given integer.
 */
static std::string
convertIntToString(const int64_t x)
{
  int64_t     nextStep  = std::abs(x); // Using std's abs function. The command abs is only useful for int.
  std::string result;

  if (x == 0)
    result = ZERO_STRING;

  while (nextStep > 0)
  {
    const int64_t nextDigit = nextStep % TENS_DIVISOR;
    const char    nextChar  = ASCII_DIGITS_OFFSET + nextDigit;

    // I use append and not push_back because push_back is not part of the semantics of a string.
    // Append is more readable, and probably has a far better understading of a string vs a
    // standard container.
    result.append(1, nextChar);
    nextStep = nextStep / TENS_DIVISOR;
  }

  if (x < 0)
    result.append(1, NEGATIVE_SIGN);

  std::reverse(result.begin(), result.end());

  return result;
}

/* IMPLEMENTATION ************************************************************/

TEST(IntToString, convert_0_returnValidString)
{
  // Assert
  const int number = 0;

  // Act
  const std::string result = convertIntToString(number);

  // Assert
  ASSERT_THAT(result, Eq("0"));
}

TEST(IntToString, convert_1_returnValidString)
{
  // Assert
  const int number = 1;

  // Act
  const std::string result = convertIntToString(number);

  // Assert
  ASSERT_THAT(result, Eq("1"));
}

TEST(IntToString, convert_135_returnValidString)
{
  // Assert
  const int number = 135;

  // Act
  const std::string result = convertIntToString(number);

  // Assert
  ASSERT_THAT(result, Eq("135"));
}

TEST(IntToString, convert_13456_returnValidString)
{
  // Assert
  const int number = 13456;

  // Act
  const std::string result = convertIntToString(number);

  // Assert
  ASSERT_THAT(result, Eq("13456"));
}

TEST(IntToString, convert_Negative13456_returnValidString)
{
  // Assert
  const int number = -13456;

  // Act
  const std::string result = convertIntToString(number);

  // Assert
  ASSERT_THAT(result, Eq("-13456"));
}

TEST(IntToString, convert_691489734656_returnValidString)
{
  // Assert
  const int64_t number = 691489734656;

  // Act
  const std::string result = convertIntToString(number);

  // Assert
  ASSERT_THAT(result, Eq("691489734656"));
}


TEST(IntToString, convert_Negative691489734656_returnValidString)
{
  // Assert
  const int64_t number = -691489734656;

  // Act
  const std::string result = convertIntToString(number);

  // Assert
  ASSERT_THAT(result, Eq("-691489734656"));
}