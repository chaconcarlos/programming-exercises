/**
 * @file CountingBitsTest.cpp
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

/**
 * @brief Counts the number of set bits for an int.
 *
 * @param x The int to count set bits to.
 *
 * @return The number of set bits.
 */
static size_t
countSetBits(uint16_t x)
{
  unsigned int totalSetBits = 0;

  for (; x; ++totalSetBits)
    x = x & (x - 1); // Returns x with the less significant bit cleared.

  return totalSetBits;
}

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
      const uint8_t bitCount = countSetBits(i);
      const uint8_t parity   = bitCount % 2 == 0 ? 0 : 1;

      g_precomputedParities.push_back(parity);
    }
  }
}

static uint8_t
getParityInt8(uint8_t x)
{
  return g_precomputedParities[x];
}

static uint8_t
getParityInt16(uint16_t x)
{
  return getParityInt8(x >> 8) ^ getParityInt8(x & 0xFFFF);
}

static uint8_t
getParityInt32(uint32_t x)
{
  return getParityInt16(x >> 16) ^ getParityInt16(x & 0xFFFF);
}

static uint8_t
getParityInt64(uint64_t x)
{
  return getParityInt32(x >> 32) ^ getParityInt32(x & 0xFFFFFFFF);
}

/* IMPLEMENTATION ************************************************************/

TEST(ParityCalculation, parity_test8bit0_return0)
{
  // Arrange
  const uint8_t testNumber = 0;

  // Act
  precomputeParities();

  // Assert
  ASSERT_THAT(getParityInt8(testNumber), Eq(0));
}

TEST(ParityCalculation, parity_test8bit1_return1)
{
  // Arrange
  const uint8_t testNumber = 1;

  // Act
  precomputeParities();

  // Assert
  ASSERT_THAT(getParityInt8(testNumber), Eq(1));
}

TEST(ParityCalculation, parity_test8bit255_return0)
{
  // Arrange
  const uint8_t testNumber = 255;

  // Act
  precomputeParities();

  // Assert
  ASSERT_THAT(getParityInt8(testNumber), Eq(0));
}

TEST(ParityCalculation, parity_test16bit256_return1)
{
  // Arrange
  const uint16_t testNumber = 256;

  // Act
  precomputeParities();

  // Assert
  ASSERT_THAT(getParityInt16(testNumber), Eq(1));
}

TEST(ParityCalculation, parity_test16bit4352_return1)
{
  // Arrange
  const uint16_t testNumber = 4352;

  // Act
  precomputeParities();

  // Assert
  ASSERT_THAT(getParityInt16(testNumber), Eq(0));
}

TEST(ParityCalculation, parity_test16bit32768_return1)
{
  // Arrange
  const uint16_t testNumber = 32768;

  // Act
  precomputeParities();

  // Assert
  ASSERT_THAT(getParityInt16(testNumber), Eq(1));
}

TEST(ParityCalculation, parity_test32bit65536_return1)
{
  // Arrange
  const uint32_t testNumber = 65536;

  // Act
  precomputeParities();

  // Assert
  ASSERT_THAT(getParityInt32(testNumber), Eq(1));
}

TEST(ParityCalculation, parity_test32bit65540_return0)
{
  // Arrange
  const uint32_t testNumber = 65540;

  // Act
  precomputeParities();

  // Assert
  ASSERT_THAT(getParityInt32(testNumber), Eq(0));
}

TEST(ParityCalculation, parity_test32bit589892_return0)
{
  // Arrange
  const uint32_t testNumber = 65540;

  // Act
  precomputeParities();

  // Assert
  ASSERT_THAT(getParityInt32(testNumber), Eq(0));
}

TEST(ParityCalculation, parity_test32bit2148073540_return0)
{
  // Arrange
  const uint32_t testNumber = 2148073540;

  // Act
  precomputeParities();

  // Assert
  ASSERT_THAT(getParityInt32(testNumber), Eq(1));
}

TEST(ParityCalculation, parity_test64bit17394676524_return0)
{
  // Arrange
  const uint64_t testNumber = 17394676524;

  // Act
  precomputeParities();

  // Assert
  ASSERT_THAT(getParityInt64(testNumber), Eq(0));
}

TEST(ParityCalculation, parity_test64bit86114153260_return1)
{
  // Arrange
  const uint64_t testNumber = 86114153260;

  // Act
  precomputeParities();

  // Assert
  ASSERT_THAT(getParityInt64(testNumber), Eq(1));
}