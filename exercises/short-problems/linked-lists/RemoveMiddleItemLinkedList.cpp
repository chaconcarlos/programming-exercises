/**
 * @file RemoveMiddleItemLinkedList.cpp
 *
 * @brief Implement an algorithm to delete a node in the middle of a singly linked list,
 *        given only access to that node.
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
remove(Node* node)
{
  if (node != NULL && node->next != NULL)
  {
    Node* nextNode = node->next;

    node->value = nextNode->value;
    node->next  = nextNode->next;

    delete(nextNode);
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
  const std::vector<uint8_t> values     = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
  Node*                      list       = buildLinkedList(values);
  Node*                      middleNode = list;

  for (size_t i = 0; i < values.size() / 2; ++i)
    middleNode = middleNode->next;

  std::cout << "ORIGINAL" << std::endl;
  std::cout << "========" << std::endl;
  print(list);
  std::cout << std::endl;
  std::cout << "Middle node to remove is: " << (double)middleNode->value << std::endl;
  std::cout << std::endl;
  std::cout << "OUTPUT" << std::endl;
  std::cout << "======" << std::endl;
  remove(middleNode);
  print(list);
  std::cout << std::endl;
}