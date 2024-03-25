/**
 * @file FindKthElementToLastLinkedList.cpp
 *
 * @brief Implement an algorithm to find the kth to last element of a singly linked list.
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
 * @brief Finds the element with a given index of a linked list.
 *
 * @param list  The pointer to the linked list.
 * @param index The index of the element to find.
 */
static Node*
findElement(Node* list, const size_t index)
{
  Node* element = NULL;

  if (list != NULL)
  {
    element = list;

    for (size_t i = 1; i < index && element; ++i)
      element = element->next;
  }

  return element;
}

/**
 * @brief Finds the kth element to the last of a linked list.
 *
 * @param list The pointer to the linked list.
 */
static Node*
findKElementToLast(Node* list, const size_t distanceToLast)
{
  Node* kElement = list;
  Node* last     = findElement(list, distanceToLast);

  if (last != NULL)
  {
    while (last->next != NULL)
    {
      kElement = kElement->next;
      last     = last->next;
    }
  }

  return kElement;
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
  const std::vector<uint8_t> values   = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
  const size_t               k        = 4;
  Node*                      list     = buildLinkedList(values);
  Node*                      kElement = findKElementToLast(list, k);

  std::cout << "ORIGINAL" << std::endl;
  std::cout << "========" << std::endl;
  print(list);
  std::cout << std::endl;

  std::cout << "OUTPUT" << std::endl;
  std::cout << "======" << std::endl;
  std::cout << "The " << k << "th element to last is: " << (double)kElement->value << std::endl;
  std::cout << std::endl;
}