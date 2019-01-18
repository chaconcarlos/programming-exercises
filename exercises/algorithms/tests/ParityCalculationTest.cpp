/**
 * @file ParityCaculationTest.cpp
 *
 * @brief Implementation of the parity calculation method test.
 *
 * @author   Carlos Chacon <chacon.carlosj@gmail.com>
 * @date     Mar 21, 2018
 */

/* INCLUDES ******************************************************************/

#include <gmock/gmock.h>
#include <cstdint>
#include <limits>
#include <string>


#include <iostream>

/* USINGS ********************************************************************/

using namespace testing;

/* STATIC DECLARATIONS *******************************************************/

static std::vector<uint8_t> g_precomputedParities;

/* STATIC FUNCTIONS **********************************************************/

/*
 * @brief Precomputes the parities for 8 bit values.
 */
static void
precomputeParities()
{
  if (g_precomputedParities.empty())
  {
    for (size_t i = 0; i <= std::numeric_limits<uint8_t>::max(); ++i)
    {
      const uint8_t parity = (((i * 0x0101010101010101ULL) & 0x8040201008040201ULL) % 0x1FF) & 1;;

      g_precomputedParities.push_back(parity);
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
getParityInt(T x)
{
  const uint8_t bitCount = countSetBits(x);
  const uint8_t parity   = bitCount % 2 == 0 ? 0 : 1;
  return parity;
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
getParityInt(uint8_t x)
{
  return g_precomputedParities[x];
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
getParityInt(uint16_t x)
{
  return getParityInt<uint8_t>(x >> 8) ^ getParityInt<uint8_t>(x & 0xFFFF);
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
getParityInt(uint32_t x)
{
  return getParityInt<uint16_t>(x >> 16) ^ getParityInt<uint16_t>(x & 0xFFFF);
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
getParityInt(uint64_t x)
{
  return getParityInt<uint32_t>(x >> 32) ^ getParityInt<uint32_t>(x & 0xFFFFFFFF);
}

/* IMPLEMENTATION ************************************************************/

TEST(ParityCalculation, parity_test8bit0_return0)
{
  // Arrange
  const uint8_t testNumber = 0;

  // Act
  precomputeParities();

  // Assert
  ASSERT_THAT(getParityInt(testNumber), Eq(0));
}

TEST(ParityCalculation, parity_test8bit1_return1)
{
  // Arrange
  const uint8_t testNumber = 1;

  // Act
  precomputeParities();

  // Assert
  ASSERT_THAT(getParityInt(testNumber), Eq(1));
}

TEST(ParityCalculation, parity_test8bit255_return0)
{
  // Arrange
  const uint8_t testNumber = 255;

  // Act
  precomputeParities();

  // Assert
  ASSERT_THAT(getParityInt(testNumber), Eq(0));
}

TEST(ParityCalculation, parity_test16bit256_return1)
{
  // Arrange
  const uint16_t testNumber = 256;

  // Act
  precomputeParities();

  // Assert
  ASSERT_THAT(getParityInt(testNumber), Eq(1));
}

TEST(ParityCalculation, parity_test16bit4352_return1)
{
  // Arrange
  const uint16_t testNumber = 4352;

  // Act
  precomputeParities();

  // Assert
  ASSERT_THAT(getParityInt(testNumber), Eq(0));
}

TEST(ParityCalculation, parity_test16bit32768_return1)
{
  // Arrange
  const uint16_t testNumber = 32768;

  // Act
  precomputeParities();

  // Assert
  ASSERT_THAT(getParityInt(testNumber), Eq(1));
}

TEST(ParityCalculation, parity_test32bit65536_return1)
{
  // Arrange
  const uint32_t testNumber = 65536;

  // Act
  precomputeParities();

  // Assert
  ASSERT_THAT(getParityInt(testNumber), Eq(1));
}

TEST(ParityCalculation, parity_test32bit65540_return0)
{
  // Arrange
  const uint32_t testNumber = 65540;

  // Act
  precomputeParities();

  // Assert
  ASSERT_THAT(getParityInt(testNumber), Eq(0));
}

TEST(ParityCalculation, parity_test32bit589892_return0)
{
  // Arrange
  const uint32_t testNumber = 65540;

  // Act
  precomputeParities();

  // Assert
  ASSERT_THAT(getParityInt(testNumber), Eq(0));
}

TEST(ParityCalculation, parity_test32bit2148073540_return0)
{
  // Arrange
  const uint32_t testNumber = 2148073540;

  // Act
  precomputeParities();

  // Assert
  ASSERT_THAT(getParityInt(testNumber), Eq(1));
}

TEST(ParityCalculation, parity_test64bit17394676524_return0)
{
  // Arrange
  const uint64_t testNumber = 17394676524;

  // Act
  precomputeParities();

  // Assert
  ASSERT_THAT(getParityInt(testNumber), Eq(0));
}

TEST(ParityCalculation, parity_test64bit86114153260_return1)
{
  // Arrange
  const uint64_t testNumber = 86114153260;

  // Act
  precomputeParities();

  // Assert
  ASSERT_THAT(getParityInt(testNumber), Eq(1));
}