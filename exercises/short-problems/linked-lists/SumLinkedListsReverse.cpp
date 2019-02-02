/**
 * @file SumLinkedListsReverse.cpp
 *
 * @brief You have two numbers represented by a linked list, where each node contains a
 *        single digit. The digits are stored in reverse order, such that the Ts digit is at the
 *        head of the list. Write a function that adds the two numbers and returns the sum
 *        as a linked list
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

static const uint8_t BASE_DECIMAL = 10;

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

/**
 * @brief Removes duplicates from a linked list.
 *
 * @param list The pointer to the linked list.
 */
static Node*
add(const Node* list1, const Node* list2, const bool hasCarry)
{
  Node* node = NULL;

  if (list1 != NULL || list2 != NULL)
  {
    const Node* next1 = list1 ? list1->next : NULL;
    const Node* next2 = list2 ? list2->next : NULL;
    int         value = hasCarry ? 1 : 0;

    node = new Node();

    if (list1 != NULL)
      value += list1->value;

    if (list2 != NULL)
      value += list2->value;

    node->value = value % BASE_DECIMAL;
    node->next = add(next1, next2, value > BASE_DECIMAL);
  }

  return node;
}

/* IMPLEMENTATION ************************************************************/

int main()
{
  const std::vector<uint8_t> values1 = { 7, 1, 6, 1 };
  const std::vector<uint8_t> values2 = { 5, 9, 2 };
  Node* list1  = buildLinkedList(values1);
  Node* list2  = buildLinkedList(values2);
  Node* result = add(list1, list2, false);

  std::cout << "SUM" << std::endl;
  std::cout << "===" << std::endl;
  print(list1);
  std::cout << " + " << std::endl;
  print(list2);
  std::cout << "=" << std::endl;
  print(result);
  std::cout << std::endl;
}