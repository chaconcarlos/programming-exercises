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
 * @brief Gets the parity of an int.
 *
 * @param x The int to calculate the parity to.
 *
 * @return The parity of the given int.
 */
template<typename T>
uint8_t
reverseBits(T x) = delete;

/*
 * @brief Gets the parity of an int.
 *
 * @param x The int to calculate the parity to.
 *
 * @return The parity of the given int.
 */
template<>
uint8_t
reverseBits(uint8_t x)
{
  return g_precomputedReverseBits[x];
}

/*
 * @brief Gets the parity of an int.
 *
 * @param x The int to calculate the parity to.
 *
 * @return The parity of the given int.
 */
template<>
uint8_t
reverseBits(uint16_t x)
{
  return reverseBits<uint8_t>(x >> 8) ^ reverseBits<uint8_t>(x & 0xFFFF);
}

/*
 * @brief Gets the parity of an int.
 *
 * @param x The int to calculate the parity to.
 *
 * @return The parity of the given int.
 */
template<>
uint8_t
reverseBits(uint32_t x)
{
  return reverseBits<uint16_t>(x >> 16) ^ reverseBits<uint16_t>(x & 0xFFFF);
}

/*
 * @brief Gets the parity of an int.
 *
 * @param x The int to calculate the parity to.
 *
 * @return The parity of the given int.
 */
template<>
uint8_t
reverseBits(uint64_t x)
{
  return reverseBits<uint32_t>(x >> 32) ^ reverseBits<uint32_t>(x & 0xFFFFFFFF);
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