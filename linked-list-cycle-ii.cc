/**
 * 题目：
 * Given a linked list, return the node where the cycle begins. If there is no cycle, returnnull.
 *
 * Follow up:
 * Can you solve it without using extra space?
 *
 * 题解：
 * 快慢指针，快指针每次走两步，慢指针每次走一步，如果有环则一定会相遇(可用归纳法证明)
 * 求环的起点：快慢指针相遇后，快指针指回头结点，每次快慢指针都走一步，直到相遇点，该点为环起点。
 * 原理：快慢指针相遇时，快指针走了2*n步，慢指针走了n步，快指针最多重新从头走n步(相遇时小于等于n步)可与慢指针相遇，因为相遇后走的路线是一样的，所以刚开始相遇时即为环的入口.
 *`
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    ListNode *detectCycle(ListNode *head) {
      if (head == NULL || head->next == NULL) 
        return NULL;
      ListNode *fast = head;
      ListNode *slow = head;
      bool has_circle = false;
      while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
          has_circle = true;
          break;
        }
      }
      if (!has_circle) 
        return NULL;
      fast = head;
      while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
      }
      return fast;
    }
};
