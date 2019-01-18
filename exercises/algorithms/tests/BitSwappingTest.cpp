/**
 * @file BitSwappingTest.cpp
 *
 * @brief Implementation of the tests of the method that swaps two bits in a integer.
 *
 * @author   Carlos Chacon <chacon.carlosj@gmail.com>
 * @date     Mar 21, 2018
 */

/* INCLUDES ******************************************************************/

#include <gmock/gmock.h>
#include <cstdint>
#include <string>



#include <iostream>

/* USINGS ********************************************************************/

using namespace testing;

/* STATIC FUNCTIONS **********************************************************/

/**
 * @brief Swaps the value of two bit positions in a given integer.
 *
 * @param i The first bit position to swap.
 * @param J The second bit position to swap.
 *
 * @return The integer with the swapped bits.
 */
static uint64_t
swapBits(uint64_t x, uint8_t i, uint8_t j)
{
  const uint8_t firstBitValue  = (x >> i) & 1;
  const uint8_t secondBitValue = (x >> j) & 1;
  uint64_t      result         = x;

  if (firstBitValue != secondBitValue)
    x ^= (1L << i) | (1L << j);

  return x;
}

/* IMPLEMENTATION ************************************************************/

TEST(BitSwapping, switch_0_0_0_return0)
{
  ASSERT_THAT(swapBits(0, 0, 0), Eq(0));
}

TEST(BitSwapping, count_1_0_1_return1)
{
  ASSERT_THAT(swapBits(1, 0, 0), Eq(1));
}

TEST(BitSwapping, count_32768_0_15_return1)
{
  ASSERT_THAT(swapBits(32768, 0, 15), Eq(1));
}

TEST(BitSwapping, count_8388608_0_23_return1)
{
  ASSERT_THAT(swapBits(8388608, 0, 23), Eq(1));
}

TEST(BitSwapping, count_1073741824_0_30_return1)
{
  ASSERT_THAT(swapBits(1073741824, 0, 30), Eq(1));
}

TEST(BitSwapping, count_137438953472_0_37_return1)
{
  ASSERT_THAT(swapBits(137438953472, 0, 37), Eq(1));
}

TEST(BitSwapping, count_1_0_1_return2)
{
  ASSERT_THAT(swapBits(1, 0, 1), Eq(2));
}

TEST(BitSwapping, count_32768_15_15_return32768)
{
  ASSERT_THAT(swapBits(32768, 15, 15), Eq(32768));
}

TEST(BitSwapping, count_1073741824_23_30_return8388608)
{
  ASSERT_THAT(swapBits(1073741824, 23, 30), Eq(8388608));
}

TEST(BitSwapping, count_824633720960_23_30_return274886295680)
{
  ASSERT_THAT(swapBits(824633720960, 39, 23), Eq(274886295680));
}