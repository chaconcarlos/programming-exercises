/**
 * @file HashTableTest.h
 *
 * @brief Implementation of the count bits method tests.
 *
 * @author   Carlos Chacon <chacon.carlosj@gmail.com>
 * @date     Mar 21, 2018
 * @revision $Revision: 1$.
 */

/* INCLUDES ******************************************************************/

#include <gmock/gmock.h>
#include <cstdint>
#include <string>

/* USINGS ********************************************************************/

using namespace testing;

/* STATIC FUNCTIONS **********************************************************/

/**
 * @brief Counts the number of set bits for an int.
 *
 * @param x The int to count set bits to.
 *
 * @return The number of set bits.
 */
static unsigned int
countSetBits(uint32_t x)
{
  unsigned int totalSetBits = 0;

  for (; x; ++totalSetBits)
    x = x & (x - 1);

  return totalSetBits;
}

/* IMPLEMENTATION ************************************************************/

TEST(CountSetBytesTest, count_0_bit)
{
  ASSERT_THAT(countSetBits(0), Eq(0));
}

TEST(CountSetBytesTest, count_1_bit)
{
  ASSERT_THAT(countSetBits(1), Eq(1));
}

TEST(CountSetBytesTest, count_10_bit)
{
  ASSERT_THAT(countSetBits(1023), Eq(10));
}

TEST(CountSetBytesTest, count_32_bit)
{
  ASSERT_THAT(countSetBits(std::numeric_limits<uint32_t>::max()), Eq(32));
}
