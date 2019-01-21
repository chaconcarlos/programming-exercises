/**
 * @file BaseConversionTest.cpp
 *
 * @brief Implementation of the tests of the method that changes the base of a number string.
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

static const char    NEGATIVE_SIGN                      = '-';
static const uint8_t BASE_BINARY                        = 2;
static const uint8_t BASE_DECIMAL                       = 10;
static const uint8_t BASE_HEXADECIMAL                   = 16;
static const uint8_t ASCII_DIGITS_OFFSET                = 48;
static const uint8_t ASCII_CAPITAL_LETTERS_OFFSET       = 65;
static const uint8_t ASCII_ALLOWED_CAPITAL_DIGITS_LIMIT = 70;

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
  const bool isValidDigit      = isdigit(digit);
  uint8_t    offset            = ASCII_DIGITS_OFFSET;

  if (!isValidDigit && !isInCapitalsRange)
  {
    const std::string message = "An invalid character has been found.";
    throw std::invalid_argument(message);
  }

  if (isInCapitalsRange)
    offset = ASCII_CAPITAL_LETTERS_OFFSET - BASE_DECIMAL;

  return digit - offset;
}

/**
 * @brief Converts a int digit to its char representation.
 *
 * @param digit The digit.
 *
 * @return The char representation of the int digit.
 */
static char
convertIntToDigit(const uint8_t digit)
{
  char result;

  if (digit >= BASE_DECIMAL)
    result = ASCII_CAPITAL_LETTERS_OFFSET + digit - BASE_DECIMAL;
  else
    result = ASCII_DIGITS_OFFSET + digit;

  return result;
}

/**
 * @brief Converts a integer to string.
 *
 * @param targetBase The target base.
 * @param input      The input integer.
 *
 * @return The string representation of the given integer in the target base.
 */
static std::string
convertIntToString(const uint8_t targetBase, const int64_t input)
{
  int64_t     step = std::abs(input);
  std::string result;

  while (step)
  {
    const int  unit  = step % targetBase;
    const char digit = convertIntToDigit(unit);

    result.append(1, digit);

    step = step / targetBase;
  }

  if (input < 0)
    result.append(1, NEGATIVE_SIGN);

  std::reverse(result.begin(), result.end());

  return result;
}

/**
 * @brief Converts a string representation of a number to a different base.
 *
 * @param inputBase  The base of the input string.
 * @param targetBase The target base for conversion.
 * @param input      The input string.
 *
 * @return The string representation of the input converted to the target base.
 */
static std::string
convertBase(const uint8_t inputBase, const uint8_t targetBase, const std::string& input)
{
  const bool   isNegative = !input.empty() && (input[0] == NEGATIVE_SIGN);
  const size_t inputSize  = input.size();
  int64_t      result     = 0;
  std::string  answer;

  if (input.empty())
    throw std::invalid_argument("The input should not be empty.");

  size_t i = isNegative ? 1 : 0;

  for (; i < inputSize; ++i)
  {
    const uint8_t digit = convertDigitToInt(input[i]);

    if (digit >= inputBase)
      throw std::invalid_argument("The input is not the correct base.");

    result += digit * pow(inputBase, inputSize - 1 - i);
  }

  result = isNegative ? result * -1 : result;
  answer = convertIntToString(targetBase, result);

  return answer;
}

/* IMPLEMENTATION ************************************************************/

TEST(BaseConversion, convert_EmptyString_InvalidArgumentException)
{
   // Arrange
  const std::string input = "";

   // Assert
  EXPECT_THROW(convertBase(2, 3, input), std::invalid_argument);
}

TEST(BaseConversion, convert_2Base2_To_Base10_InvalidArgumentException)
{
   // Arrange
  const std::string input = "2";

   // Assert
  EXPECT_THROW(convertBase(BASE_BINARY, BASE_DECIMAL, input), std::invalid_argument);
}

TEST(BaseConversion, convert_10Base2_To_Base2_ReturnString01)
{
  // Arrange
  const std::string input = "10";

  // Act
  const std::string result = convertBase(BASE_BINARY, BASE_BINARY, input);

  // Assert
  ASSERT_THAT(result, Eq("10"));
}

TEST(BaseConversion, convert_10Base2_To_Base10_ReturnString2)
{
  // Arrange
  const std::string input = "10";

  // Act
  const std::string result = convertBase(BASE_BINARY, BASE_DECIMAL, input);

  // Assert
  ASSERT_THAT(result, Eq("2"));
}

TEST(BaseConversion, convert_01011010Base2_To_Base10_ReturnString90)
{
  // Arrange
  const std::string input = "01011010";

  // Act
  const std::string result = convertBase(BASE_BINARY, BASE_DECIMAL, input);

  // Assert
  ASSERT_THAT(result, Eq("90"));
}

TEST(BaseConversion, convert_101010101Base2_To_Base10_ReturnString341)
{
  // Arrange
  const std::string input = "101010101";

  // Act
  const std::string result = convertBase(BASE_BINARY, BASE_DECIMAL, input);

  // Assert
  ASSERT_THAT(result, Eq("341"));
}

TEST(BaseConversion, convert_693545Base10_To_Base2_ReturnString10101001010100101001)
{
  // Arrange
  const std::string input = "693545";

  // Act
  const std::string result = convertBase(BASE_DECIMAL, BASE_BINARY, input);

  // Assert
  ASSERT_THAT(result, Eq("10101001010100101001"));
}

TEST(BaseConversion, convert_FFFFFFFFBase16_To_Base10_ReturnString4294967295)
{
  // Arrange
  const std::string input = "FFFFFFFF";

  // Act
  const std::string result = convertBase(BASE_HEXADECIMAL, BASE_DECIMAL, input);

  // Assert
  ASSERT_THAT(result, Eq("4294967295"));
}

TEST(BaseConversion, convert_5628734827Base10_To_Base16_ReturnString14F7FAD6B)
{
  // Arrange
  const std::string input = "5628734827";

  // Act
  const std::string result = convertBase(BASE_DECIMAL, BASE_HEXADECIMAL, input);

  // Assert
  ASSERT_THAT(result, Eq("14F7FAD6B"));
}

TEST(BaseConversion, convert_Negative5628734827Base10_To_Base16_ReturnStringNegative4F7FAD6B)
{
  // Arrange
  const std::string input = "-5628734827";

  // Act
  const std::string result = convertBase(BASE_DECIMAL, BASE_HEXADECIMAL, input);

  // Assert
  ASSERT_THAT(result, Eq("-14F7FAD6B"));
}