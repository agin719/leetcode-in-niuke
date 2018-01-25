/**
 * 题目：
 * A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 * Return a deep copy of the list.
 *
 * 题解：
 * 实现对链表的深拷贝，其中链表有一个随机指针，指向某个节点或者为NULL。
 * 先将原列表每个元素拷贝，跟在源节点后面，如：
 * 1->3->4->NULL
 * 变为：
 * 1->1->3->3->4->4->NULL
 * 若i为源节点，则i+1即为复制节点，他们的随机指针指向同一个元素
 * 假设复制节点x的随机指针指向了节点k，则k+1为节点k的复制节点，只要将x的随机指针向后一位即可。
 *
 * 最后将两个链表分开即可。
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
  public:
    RandomListNode *copyRandomList(RandomListNode *head) {
      //每个节点后面插入一个复制节点
      for (RandomListNode *cur = head; cur; ) {
        RandomListNode *p = new RandomListNode(cur->label);
        p->random = cur->random;
        p->next = cur->next;
        cur->next = p;
        cur = p->next;
      }
      
      //如果该节点为复制节点，将其random指针向后指一位。
      bool is_copy = false;
      for (RandomListNode *cur = head; cur; cur = cur->next) {
        if (is_copy && cur->random) {
          cur->random = cur->random->next;
        }
        is_copy != is_copy;
      }

      //分开两个链表
      RandomListNode *chead = new RandomListNode(0);
      RandomListNode *p = chead;
      for (RandomListNode *cur = head; cur; cur = cur->next){
        p->next = cur->next;
        cur->next = cur->next->next;
        p = p->next;
        p->next = NULL;
      }
      p = chead->next;
      delete chead;
      return p;
    }
};
