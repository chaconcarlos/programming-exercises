/**
 * @file PrimeCalculationTest.cpp
 *
 * @brief Implementation of the tests of the method that calculates prime numbers until a given limit.
 *
 * @author   Carlos Chacon <chacon.carlosj@gmail.com>
 * @date     Mar 21, 2018
 */

/* INCLUDES ******************************************************************/

#include <gmock/gmock.h>

#include <cmath>
#include <cstdint>
#include <limits>
#include <string>

/* USINGS ********************************************************************/

using namespace testing;

/* STATIC FUNCTIONS **********************************************************/

/*
 * @brief Gets the prime numbers from 2 to the given limit.
 *
 * @param limit The limit.
 *
 * @return The list of prime numbers from 2 to the limit.
 */
static std::vector<uint64_t>
getPrimes(uint64_t limit)
{
  std::vector<uint64_t> primes;

  for (size_t i = 2; i <= limit; ++i)
  {
    bool isPrime = true;

    for (size_t j = sqrt(i); j > 1; --j)
    {
      if (i % j == 0)
      {
        isPrime = false;
        break;
      }
    }

    if (isPrime)
      primes.push_back(i);
  }

  return primes;
}

/* IMPLEMENTATION ************************************************************/

TEST(PrimeCalculation, primes_slow_until10_return4primes)
{
  // Arrange
  const uint64_t limit = 10;

  // Act
  const std::vector<uint64_t> primes = getPrimes(limit);

  // Assert
  ASSERT_THAT(primes.size(), Eq(4));
}