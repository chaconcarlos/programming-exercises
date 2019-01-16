/**
 * @file CountingBitsTest.cpp
 *
 * @brief Implementation of the algorithm that swaps two integers without a temporal variable.
 *
 * @author Carlos Chacon <chacon.carlosj@gmail.com>
 * @date   Jan 16, 2019
 */

/* INCLUDES ******************************************************************/

#include <gmock/gmock.h>
#include <cstdint>
#include <string>

/* USINGS ********************************************************************/

using namespace testing;

/* STATIC FUNCTIONS **********************************************************/

/**
 * @brief Swaps two integers.
 *
 * @param a First integer to be swapped.
 * @param b Second integer to be swapped.
 */
static void
swapIntegers(int& a, int& b)
{
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}

/* IMPLEMENTATION ************************************************************/

TEST(swap, swap_276_664_complete)
{
  // Arrange
  int a = 276;
  int b = 664;

  // Act
  swapIntegers(a, b);

  ASSERT_THAT(a, Eq(664));
  ASSERT_THAT(b, Eq(276));
}

TEST(swap, swap_0_1675_complete)
{
  // Arrange
  int a = 0;
  int b = 1675;

  // Act
  swapIntegers(a, b);

  ASSERT_THAT(a, Eq(1675));
  ASSERT_THAT(b, Eq(0));
}