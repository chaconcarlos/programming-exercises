/**
 * @file BlankRowColumnIfZero.cpp
 *
 * @brief Zerofies a matrix.
 *
 * @author Carlos Chacon <chacon.carlosj@gmail.com>
 * @date   Jan 24, 2019
 */

/* INCLUDES ******************************************************************/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

/* STATIC FUNCTIONS **********************************************************/

/**
 * @brief Zerofies a given matrix. When a zero is encountered in the matrix,
 *        the row and the column are completely zeroed.
 *
 * @param matrix       The matrix.
 * @param totalRows    The total rows of the matrix.
 * @param totalColumns The total columns of the matrix.
 */
static void
zerofy(int* matrix, const size_t totalRows, const size_t totalColumns)
{
  uint8_t rowsToZerofy[totalRows];
  uint8_t columnsToZerofy[totalColumns];

  for (size_t row = 0; row < totalRows; ++row)
  {
    const size_t rowStart = row * totalColumns;

    for (size_t column = 0; column < totalColumns; ++column)
    {
      if(matrix[rowStart + column] == 0)
      {
        rowsToZerofy[row]       = 1;
        columnsToZerofy[column] = 1;
      }
    }
  }

  for (size_t row = 0; row < totalRows; ++row)
  {
    const size_t rowStart = row * totalColumns;

    for (size_t column = 0; column < totalColumns; ++column)
    {
      if (rowsToZerofy[row] == 1 || columnsToZerofy[column] == 1)
        matrix[rowStart + column] = 0;
    }
  }
}

/**
 * @brief Prints a given matrix.
 *
 * @param matrix       The matrix.
 * @param totalRows    The total rows of the matrix.
 * @param totalColumns The total columns of the matrix.
 */
static void
print(int* matrix, const size_t totalRows, const size_t totalColumns)
{
  for (size_t row = 0; row < totalRows; ++row)
  {
    const size_t rowStart = row * totalColumns;

    for (size_t column = 0; column < totalColumns; ++column)
    {
      std::cout << matrix[rowStart + column] << " ";
    }

    std::cout << std::endl;
  }

  std::cout << std::endl;
}

/* IMPLEMENTATION ************************************************************/

int main()
{
  const size_t rows    = 3;
  const size_t columns = 4;

  // int matrix[] =
  //   {
  //      9,  1,  3,  4,
  //      5,  6,  7,  8,
  //      9,  0, 11,  0,
  //     13, 14, 15, 16
  //   };

  int matrix[] =
  {
     9,  1,  3,  4,
     5,  6,  7,  4,
     9,  0, 11,  0
  };

  std::cout << "ORIGINAL MATRIX" << std::endl;
  std::cout << "===============" << std::endl;
  print(matrix, rows, columns);
  zerofy(matrix, rows, columns);
  std::cout << "ZEROFIED MATRIX" << std::endl;
  std::cout << "===============" << std::endl;
  print(matrix, rows, columns);
}