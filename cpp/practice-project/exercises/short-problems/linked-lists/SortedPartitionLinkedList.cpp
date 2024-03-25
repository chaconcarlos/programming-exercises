/**
 * @file SortedPartitionLinkedList.cpp
 *
 * @brief Write code to partition a linked list around a value x, such that all nodes less than
 *        x come before all nodes greater than or equal to x.
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
sort(Node* list, const uint8_t pivotValue)
{
  Node* sortedList = NULL;

  if (list != NULL)
  {
    Node* beforeList = NULL;
    Node* afterList  = NULL;

    while (list)
    {
      Node* nextNode = list->next;

      if (list->value >= pivotValue)
      {
        list->next = afterList;
        afterList  = list;
      }
      else
      {
        list->next = beforeList;
        beforeList = list;
      }

      list = nextNode;
    }

    if (beforeList == NULL)
    {
      sortedList = afterList;
    }
    else
    {
      Node* head = beforeList;

      while (beforeList->next)
        beforeList = beforeList->next;

      beforeList->next = afterList;

      sortedList = head;
    }
  }

  return sortedList;
}

/* IMPLEMENTATION ************************************************************/

int main()
{
  const std::vector<uint8_t> values = { 8, 0, 5, 6, 7, 4, 2, 2, 6, 0, 1, 3, 5 };
  Node* list = buildLinkedList(values);

  std::cout << "ORIGINAL" << std::endl;
  std::cout << "========" << std::endl;
  print(list);
  std::cout << std::endl;

  std::cout << "OUTPUT" << std::endl;
  std::cout << "======" << std::endl;
  list = sort(list, 6);
  print(list);
  std::cout << std::endl;
}