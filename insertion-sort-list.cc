/**
 * 题目：
 * Sort a linked list using insertion sort.
 *
 * 题解：
 * 链表的插入排序, 和数组的差不多，不过插入时，从已排好序的前面开始遍历，找到正确的插入点.
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    ListNode *insertionSortList(ListNode *head) {
      if (head == NULL || head->next == NULL) 
        return head;
      ListNode guard(0);
      guard.next = head;    //门卫
      auto pre_i = head;
      for (auto i = head->next; i != NULL; ) {
        auto pre_j = &guard;
        for (auto j = guard.next; j != i; j = j->next) {
          if (j->val > i->val) {
            pre_j->next = i;
            pre_i->next = i->next;
            i->next = j;
            i = pre_i;
            break;
          }
          pre_j = j;
        }
        pre_i = i;
        i = i->next;
      } 
      return guard.next;
    }
};
