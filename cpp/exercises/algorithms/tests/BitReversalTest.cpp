/**
 * @file BitReversalTest.cpp
 *
 * @brief Implementation of the tests of the method that does a reversal on the bits of an integer.
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

/* DEFINITIONS ***************************************************************/

static const uint8_t BITS_IN_BYTE = 8;

/* STATIC DECLARATIONS *******************************************************/

static std::vector<uint8_t> g_precomputedReverseBits;

/* STATIC FUNCTIONS **********************************************************/

/*
 * @brief Precomputes the value of the reversed bites for every 8 bit integer.
 */
static void
precomputeReverseBits()
{
  if (g_precomputedReverseBits.empty())
  {
    for (size_t i = 0; i <= std::numeric_limits<uint8_t>::max(); ++i)
    {
      // As seen on https://graphics.stanford.edu/~seander/bithacks.html
      const uint8_t reversedValue = (i * 0x0202020202ULL & 0x010884422010ULL) % 1023;
      g_precomputedReverseBits.push_back(reversedValue);
    }
  }
}

/*
 * @brief Reverse the bits of the given integer and returns the resulting integer.
 *
 * @param input The integer to reverse.
 *
 * @return The result integer of doing a reverse on the bits of the input.
 */
template<typename T>
uint8_t
reverseBits(T input) = delete;

/*
 * @brief Reverse the bits of the given integer and returns the resulting integer.
 *
 * @param input The integer to reverse.
 *
 * @return The result integer of doing a reverse on the bits of the input.
 */
template<>
uint8_t
reverseBits(uint8_t input)
{
  return g_precomputedReverseBits[input];
}

/*
 * @brief Reverse the bits of the given integer and returns the resulting integer.
 *
 * @param input The integer to reverse.
 *
 * @return The result integer of doing a reverse on the bits of the input.
 */
template<>
uint8_t
reverseBits(uint16_t input)
{
  return reverseBits<uint8_t>(input >> 8) ^ reverseBits<uint8_t>(input & 0xFFFF);
}

/*
 * @brief Reverse the bits of the given integer and returns the resulting integer.
 *
 * @param input The integer to reverse.
 *
 * @return The result integer of doing a reverse on the bits of the input.
 */
template<>
uint8_t
reverseBits(uint32_t input)
{
  return reverseBits<uint16_t>(input >> 16) ^ reverseBits<uint16_t>(input & 0xFFFF);
}

/*
 * @brief Reverse the bits of the given integer and returns the resulting integer.
 *
 * @param input The integer to reverse.
 *
 * @return The result integer of doing a reverse on the bits of the input.
 */
template<>
uint8_t
reverseBits(uint64_t input)
{
  return reverseBits<uint32_t>(input >> 32) ^ reverseBits<uint32_t>(input & 0xFFFFFFFF);
}

/*
 * @brief Reverse the bits of the given integer and returns the resulting integer.
 *
 * @param input The integer to reverse.
 *
 * @return The result integer of doing a reverse on the bits of the input.
 */
static uint8_t
reverseBitsSlow(const uint8_t input)
{
  const size_t bitCount    = sizeof(input) * BITS_IN_BYTE;
  const size_t shiftOffset = bitCount - 1;
  uint8_t      result      = 0;

  for (size_t i = bitCount; i > 0; --i)
  {
    const size_t  shift    = i - 1;
    const uint8_t bitValue = (input >> shift) & 1;

    if (bitValue)
      result |= (1 << (shiftOffset - shift));
  }

  return result;
}

/* IMPLEMENTATION ************************************************************/

TEST(BitReversal, reverse_32_return4)
{
  // Arrange
  const uint8_t testNumber = 32;

  // Act
  precomputeReverseBits();

  // Assert
  ASSERT_THAT(reverseBits(testNumber), Eq(4));
}

TEST(BitReversal, reverse_687194767360_return5)
{
  // Arrange
  const uint64_t testNumber = 687194767360;

  // Act
  precomputeReverseBits();

  // Assert
  ASSERT_THAT(reverseBits(testNumber), Eq(5));
}

TEST(BitReversal, reverse_691489734656_return133)
{
  // Arrange
  const uint64_t testNumber = 691489734656;

  // Act
  precomputeReverseBits();

  // Assert
  ASSERT_THAT(reverseBits(testNumber), Eq(133));
}

TEST(BitReversal, reverse_slow_int8c_2_return1073741824)
{
  // Arrange
  const uint8_t testNumber = 32;

  // Assert
  ASSERT_THAT(reverseBitsSlow(testNumber), Eq(4));
}
