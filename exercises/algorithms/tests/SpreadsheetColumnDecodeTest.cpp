/**
 * @file SpreadsheetColumnDecode.cpp
 *
 * @brief Implementation of the tests of the method that decodes the id of the column of a spreedsheet.
 *
 * @author   Carlos Chacon <chacon.carlosj@gmail.com>
 * @date     Mar 21, 2018
 */

/* INCLUDES ******************************************************************/

#include <gmock/gmock.h>

#include <cstdint>
#include <sstream>
#include <string>

/* USINGS ********************************************************************/

using namespace testing;

/* DECLARATIONS **************************************************************/

static const uint8_t BASE_SPREADSHEET                   = 26;
static const uint8_t ASCII_CAPITAL_LETTERS_OFFSET       = 65;
static const uint8_t ASCII_ALLOWED_CAPITAL_DIGITS_LIMIT = 90;

/* STATIC FUNCTIONS **********************************************************/

/**
 * @brief Verifies if a char is in a given range.
 *
 * @param digit      The char.
 * @param lowerLimit The lower limit.
 * @param upperLimit The upper limit.
 *
 * @return <tt>true</tt> if char is in the given range; otherwise, <tt>false</tt>.
 */
static bool
isCharInRange(const char digit, const uint8_t lowerLimit, const uint8_t upperLimit)
{
  return digit >= lowerLimit && digit <= upperLimit;
}

/**
 * @brief Converts a digit to an int.
 *
 * @param digit The digit.
 *
 * @return The int representation of the char digit.
 */
static uint8_t
convertDigitToInt(const char digit)
{
  const bool isInCapitalsRange = isCharInRange(digit, ASCII_CAPITAL_LETTERS_OFFSET, ASCII_ALLOWED_CAPITAL_DIGITS_LIMIT);

  if (!isInCapitalsRange)
  {
    const std::string message = "An invalid character has been found.";
    throw std::invalid_argument(message);
  }

  return digit - ASCII_CAPITAL_LETTERS_OFFSET + 1;
}

/**
 * @brief Decodes the ID of a spreadsheet column as an integer.
 *
 * @param input The input string.
 *
 * @return The decoded ID.
 */
static int64_t
decode(const std::string& input)
{
  const size_t inputSize = input.size();
  int64_t      result    = 0;

  if (input.empty())
    throw std::invalid_argument("The input should not be empty.");

  for (size_t i = 0; i < inputSize; ++i)
    result += convertDigitToInt(input[i]) * pow(BASE_SPREADSHEET, inputSize - 1 - i);

  return result;
}

/* IMPLEMENTATION ************************************************************/

TEST(SpreadsheetColumnDecode, decode_A_return1)
{
   // Arrange
  const std::string input = "A";

   // Assert
  ASSERT_THAT(decode(input), Eq(1));
}

TEST(SpreadsheetColumnDecode, decode_Z_return26)
{
   // Arrange
  const std::string input = "Z";

   // Assert
  ASSERT_THAT(decode(input), Eq(26));
}

TEST(SpreadsheetColumnDecode, decode_YY_return675)
{
   // Arrange
  const std::string input = "YY";

   // Assert
  ASSERT_THAT(decode(input), Eq(675));
}

TEST(SpreadsheetColumnDecode, decode_ZZZ_return18278)
{
   // Arrange
  const std::string input = "ZZZ";

   // Assert
  ASSERT_THAT(decode(input), Eq(18278));
}