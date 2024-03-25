/**
 * @file RemoveDuplicatesLinkedList.cpp
 *
 * @brief Write code to remove duplicates from an unsorted linked list.
 *
 * @author Carlos Chacon <chacon.carlosj@gmail.com>
 * @date   Jan 24, 2019
 */

/* INCLUDES ******************************************************************/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

/* STATIC DECLARATIONS *******************************************************/

/**
 * @brief Represents a node in a linked list.
 */
struct Node
{
  uint8_t value;
  Node*   next;
};

/* STATIC FUNCTIONS **********************************************************/

/**
 * @brief Builds a linked list from a vector.
 *
 * @param values The vector with the values.
 *
 * @return The pointer to the linked list.
 */
static Node*
buildLinkedList(const std::vector<uint8_t>& values)
{
  Node* list        = NULL;
  Node* currentNode = NULL;

  for (size_t i = 0; i < values.size(); ++i)
  {
    uint8_t value = values[i];

    Node* newNode  = new Node();
    newNode->value = value;
    newNode->next  = NULL;

    if (list == NULL)
      list = newNode;
    else
      currentNode->next = newNode;

    currentNode = newNode;
  }

  return list;
}

/**
 * @brief Removes duplicates from a linked list.
 *
 * @param list The pointer to the linked list.
 */
static void
removeDuplicates(Node* list)
{
  if (list != NULL)
  {
    Node* currentNode   = list;
    Node* iterationNode = currentNode;

    while (currentNode)
    {
      while (iterationNode)
      {
        const Node* nextNode = iterationNode->next;

        if (nextNode && nextNode->value == currentNode->value)
        {
          iterationNode->next = nextNode->next;
          delete(nextNode);
        }

        iterationNode = iterationNode->next;
      }

      currentNode   = currentNode->next;
      iterationNode = currentNode;
    }
  }
}

/**
 * @brief Removes Prints a linked list.
 *
 * @param list The pointer to the linked list.
 */
static void
print(const Node* const list)
{
  const Node* currentNode = list;

  while (currentNode)
  {
    std::cout << (double)currentNode->value << " ";
    currentNode = currentNode->next;
  }

  std::cout << std::endl;
}

/* IMPLEMENTATION ************************************************************/

int main()
{
  const std::vector<uint8_t> values = { 0, 5, 6, 7, 4, 2, 2, 6, 0, 1, 3, 5 };
  Node* list = buildLinkedList(values);

  std::cout << "ORIGINAL" << std::endl;
  std::cout << "========" << std::endl;
  print(list);
  std::cout << std::endl;

  std::cout << "OUTPUT" << std::endl;
  std::cout << "======" << std::endl;
  removeDuplicates(list);
  print(list);
  std::cout << std::endl;
}