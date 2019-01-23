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

#include <algorithm>
#include <cstdint>
#include <limits>
#include <string>

/* USINGS ********************************************************************/

using namespace testing;

/* STATIC FUNCTIONS **********************************************************/

/*
 * @brief Performs a dutch flag partition sorting on the given list.
 *
 * @param list       The list of elements to sort.
 * @param pivotIndex The index of the pivot value.
 */
template<typename T>
static void
sort(std::vector<T>& list, const size_t pivotIndex)
{
  const T pivot   = list[pivotIndex];
  size_t  smaller = 0;
  size_t  equals  = 0;
  size_t  larger  = list.size() - 1;

  while (equals <= larger)
  {
    std::cout << std::endl;

    if (list[equals] < pivot)
    {
      std::swap(list[equals], list[smaller]);
      ++smaller;
      ++equals;
    }
    else if (list[equals] == pivot)
    {
      ++equals;
    }
    else if (list[equals] > pivot)
    {
      std::swap(list[equals], list[larger]);
      --larger;
    }
  }
}

/* IMPLEMENTATION ************************************************************/

TEST(DuthFlagPartitionSort, sort_vector_pivot_index_0_sort_correctly)
{
  // Arrange
  const size_t          pivot = 0;
  std::vector<uint64_t> list  = { 12, 2, 20, 10, 4, 7, 5, 19, 16 };

  // Act
  sort(list, pivot);

  // Assert
  ASSERT_THAT(list, ElementsAre(2, 5, 10, 4, 7, 12, 19, 16, 20));
}