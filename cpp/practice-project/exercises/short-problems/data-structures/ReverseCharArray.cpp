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

static const size_t MAX_INPUT_SIZE = 1024;

/* STATIC FUNCTIONS **********************************************************/

/**
 * @brief Verifies if a string has duplicated characters.
 *
 * @param sequence The string to verify.
 *
 * @return <tt>true</tt> if string has duplicated characters; otherwise, <tt>false</tt>.
 */
static void
reverse(char* input)
{
  if (input != NULL)
  {
    char*  end   = input;

    while (*end)
      ++end;

    --end;

    while (input < end)
    {
      char tmp = *input;
      *input++ = *end;
      *end--   = tmp;
    }
  }
  else
  {
    throw std::invalid_argument("The input can't be NULL.");
  }
}

/* IMPLEMENTATION ************************************************************/

int main()
{
  char input[MAX_INPUT_SIZE];

  std::cout << "Enter the text to reverse: ";
  std::cin.get(input, MAX_INPUT_SIZE);

   reverse(input);

  std::cout << "Reversed output = " << input << std::endl;
}