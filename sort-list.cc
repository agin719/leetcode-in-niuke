/*
 * 题目：
 * Sort a linked list in O(n log n) time using constant space complexity.
 *
 * 题解：
 * 链表的归并排序或者快速排序
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *   int val;
 *   ListNode *next;
 *   ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    /* 归并排序
    ListNode *sortList(ListNode *head) {
      if (head == NULL || head->next == NULL) return head;

      ListNode *fast = head;
      ListNode *slow = head;
      //通过快慢指针找中点
      while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
      }
      fast = slow;
      slow = slow->next;
      fast->next = NULL;
      return merge(sortList(head), sortList(slow));
    }
    */
    ListNode *merge(ListNode *head1, ListNode *head2) {
      if (head1 == NULL) return head2;
      if (head2 == NULL) return head1;
      ListNode *head, *p;
      if (head1->val < head2->val) {
        head = head1;
        head1 = head1->next;
      }
      else {
        head = head2;
        head2 = head2->next;
      }
      p = head;
      while (head1 != NULL && head2 != NULL) {
        if (head1->val < head2->val) {
          p->next = head1;
          p = p->next;
          head1 = head1->next;
        } else {
          p->next = head2;
          p = p->next;
          head2 = head2->next;
        }
      }
      if (head1 == NULL) 
        p->next = head2;
      else 
        p->next = head1;
      return head;
    }

    //快速排序
    ListNode *sortList(ListNode *head) {
      quick_sort(head, NULL);
      return head;
    }
    void quick_sort(ListNode *head, ListNode *tail) {
      if (head != tail) {
        ListNode *mid = partion(head, tail);
        quick_sort(head, mid);
        quick_sort(mid->next, tail);
      }
    }
    
    /*
     * partion原理，将low做为枢纽点，用类似冒泡的方式将小的放在前面，大的放到后面，然后交换最后比枢纽小的点
     * 枢纽点，小的1，小的2, 小的3，大的1， 大的2， 大的3
     * 交换枢纽和小的3
     * 小的3，小的1，小的2， 枢纽点，大的1， 大的2， 大的3
     */
    ListNode *partion(ListNode *low, ListNode *high) {
      int key = low->val;
      ListNode *loc = low; 
      for (auto it = low->next; it != high; it = it->next){
        if (key > it->val) {
          loc = loc->next;
          std::swap(loc->val, it->val);
        }
      }
      std::swap(low->val, loc->val);
      return loc;
    }
};
