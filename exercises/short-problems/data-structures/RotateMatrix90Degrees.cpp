/**
 * @file ReverseCharArray.cpp
 *
 * @brief Reverses a given char array.
 *
 * @author Carlos Chacon <chacon.carlosj@gmail.com>
 * @date   Jan 24, 2019
 */

/* INCLUDES ******************************************************************/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

/* DEFINITIONS ***************************************************************/

/* STATIC FUNCTIONS **********************************************************/

/**
 * @brief Prints the given matrix.
 *
 * @param input     The input matrix.
 * @param width     The width of the matrix.
 * @param pixelSize The size of each element of the matrix.
 */
static void
printMatrix(const std::vector<unsigned char>& input, const size_t width, const size_t pixelSize)
{
  for (size_t i = 0; i < width; ++i)
  {
    for (size_t j = 0; j < width; ++j)
    {
      for (size_t p = 0; p < pixelSize; ++p)
        std::cout << (double)input[i * width * pixelSize + j * pixelSize + p] << "  ";
    }

    std::cout << std::endl;
  }
}

/**
 * @brief Gets the rotated input by 90 degress clockwise.
 *
 * @param input     The input matrix.
 * @param width     The width of the matrix.
 * @param pixelSize The size of each element of the matrix.
 *
 * @return The rotated input by 90 degress clockwise.
 */
static std::vector<unsigned char>
rotateMatrixClockwise(const std::vector<uint8_t>& input, const size_t width, const size_t pixelSize)
{
  const size_t               lineSize      = width * pixelSize;
  size_t                     currentColumn = width - 1;
  std::vector<uint8_t> output(width * width * pixelSize);

  for (size_t i = 0; i < width; ++i)
  {
    const size_t inputRowOffset     = i * lineSize;
    const size_t outputColumnOffset = currentColumn * pixelSize;

    for (size_t j = 0; j < width; ++j)
    {
      const size_t outputItemOffset = j * lineSize + outputColumnOffset;
      const size_t inputItemOffset  = inputRowOffset + j * pixelSize;

      for (size_t p = 0; p < pixelSize; ++ p)
        output[outputItemOffset + p] = input[inputItemOffset + p];
    }

    currentColumn--;
  }

  return output;
}

/**
 * @brief Rotates the input by 90 degress clockwise.
 *
 * @param input     The input matrix.
 * @param width     The width of the matrix.
 * @param pixelSize The size of each element of the matrix.
 */
static void
rotateMatrixClockwiseInPlace(std::vector<uint8_t>& input, const size_t width, const size_t pixelSize)
{
  const size_t lineWidth   = width * pixelSize;
  const size_t totalCycles = std::floor(width / 2);

  for (size_t layer = 0; layer < totalCycles; ++layer)
  {
    const size_t last  = width - 1 - layer;

    for (size_t i = layer; i < width - 1 - layer; ++i)
    {
      const size_t offset           = layer - i;
      const size_t topLeftIndex     = layer                   * lineWidth + i               * pixelSize;
      const size_t topRightIndex    = i                       * lineWidth + last            * pixelSize;
      const size_t bottomLeftIndex  = (width - 1 - i)         * lineWidth + layer           * pixelSize;
      const size_t bottomRightIndex = (width - 1 - layer)     * lineWidth + (last + offset) * pixelSize;
      uint8_t      temp             = input[topLeftIndex];

      for (size_t pixel = 0; pixel < pixelSize; ++pixel)
      {
        std::swap(temp, input[topRightIndex    + pixel]);
        std::swap(temp, input[bottomRightIndex + pixel]);
        std::swap(temp, input[bottomLeftIndex  + pixel]);
        std::swap(temp, input[topLeftIndex     + pixel]);
      }
    }
  }
}

/* IMPLEMENTATION ************************************************************/

int main()
{
  const size_t         width     = 5;
  const uint8_t        pixelSize = 4;
  std::vector<uint8_t> input     = { 0,  0,  0,  0,  1,  1,  1,  1,  2,  2,  2,  2,  3,  3,  3,  3,  4,  4,  4,  4,
                                     5,  5,  5,  5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  8,  9,  9,  9,  9,
                                    10, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 13, 14, 14, 14, 14,
                                    15, 15, 15, 15, 16, 16, 16, 16, 17, 17, 17, 17, 18, 18, 18, 18, 19, 19, 19, 19,
                                    20, 20, 20, 20, 21, 21, 21, 21, 22, 22, 22, 22, 23, 23, 23, 23, 24, 24, 24, 24};

  std::cout << "ROTATE 90 DEGREES CLOCKWISE" << std::endl;
  std::cout << "===========================" << std::endl;
  std::cout << "INPUT: "                     << std::endl;
  std::cout << std::endl;
  printMatrix(input, width, pixelSize);
  std::cout << std::endl;
  std::cout << "OUTPUT BY COPY: "              << std::endl;
  std::cout << std::endl;
  printMatrix(rotateMatrixClockwise(input, width, pixelSize), width, pixelSize);
  std::cout << std::endl;
  rotateMatrixClockwiseInPlace(input, width, pixelSize);
  std::cout << "OUTPUT BY DOING IT IN PLACE: " << std::endl;
  std::cout << std::endl;
  printMatrix(input, width, pixelSize);
  std::cout << std::endl;
}