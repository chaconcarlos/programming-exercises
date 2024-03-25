/**
 * @file FloydCycleDetectionTest.cpp
 *
 * @brief Implementation of Floyd's algorithm for cycle detection on linked lists.
 *
 * @author   Carlos Chacon <chacon.carlosj@gmail.com>
 * @date     Mar 21, 2018
 */

/* INCLUDES ******************************************************************/

#include <gmock/gmock.h>

#include <cstdint>
#include <string>
#include <vector>



#include <iostream>

/* USINGS ********************************************************************/

using namespace testing;

/* DECLARATIONS **************************************************************/

/**
 * @brief Structure that represents a node in a linked list.
 */
struct ListNode
{
public:

  /**
   * @brief Initializes an instance of the ListNode struct.
   *
   * @param x The value of the node.
   */
  ListNode(int x)
  : val(x)
  , next(nullptr)
  {
  }

public:

  int val;
  ListNode *next;
};


/* STATIC FUNCTIONS **********************************************************/

/**
 * @brief Pushes a new value to a linked list.
 *
 * @param [out] head The head node.
 * @param [in]  x    The value.
 */
void push(ListNode** head, int x)
{
  ListNode* new_node = new ListNode(x);

  new_node->next = *head;

  *head = new_node;
}

/**
 * @brief Detects a cycle in a linked list, and returns the node where the cycle begins.
 *
 * @param head The head of the linked list.
 *
 * @return If a cycle exists, returns the node where the cycle begins. If there are no cycles, returns NULL.
 *
 * @remarks https://cs.stackexchange.com/questions/10360/floyds-cycle-detection-algorithm-determining-the-starting-point-of-cycle
 */
static ListNode*
getCycleNode(ListNode* const head)
{
  ListNode* slow      = head;
  ListNode* fast      = head;
  ListNode* cycleNode = nullptr;

  while (slow != nullptr && fast != nullptr && fast->next != nullptr)
  {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
    {
      cycleNode = fast;
      break;
    }
  }

  fast = head;

  while (cycleNode != nullptr && fast != slow)
  {
    fast = fast->next;
    slow = slow->next;

    if (fast == slow)
      cycleNode = fast;
  }

  return cycleNode;
}

/* IMPLEMENTATION ************************************************************/

TEST(DetectCycle, floyd_cycle_exists_detected)
{
  ListNode* head = new ListNode(1);

  push(&head, 20);
  push(&head, 4);
  push(&head, 15);
  push(&head, 10);

  head->next->next->next->next = head;

  const ListNode* const cycleNode = getCycleNode(head);

  ASSERT_THAT(cycleNode, Eq(head));
}

TEST(DetectCycle, floyd_no_cycle_exists_null)
{
  ListNode* head = new ListNode(1);

  push(&head, 20);
  push(&head, 4);
  push(&head, 15);
  push(&head, 10);

  const ListNode* const cycleNode = getCycleNode(head);

  ASSERT_THAT(cycleNode, Eq(nullptr));
}
