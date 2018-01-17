/*
 * 题目：
 * Given a linked list, determine if it has a cycle in it.
 *
 * Follow up:
 * Can you solve it without using extra space?
 *
 * 题解：
 * 快慢指针，快指针每次走两步，慢指针每次走一步，如果有环则一定会相遇(可用归纳法证明)
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    bool hasCycle(ListNode *head) {
      if (head == NULL || head->next == NULL) 
        return false;
      ListNode *fast = head;
      ListNode *slow = head;
      bool has_circle = false;
      while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
          return true;
        }
      }
      return has_circle;
    }
};
