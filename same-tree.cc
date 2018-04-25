/**
 * 题目：
 * same-tree
 * 题目描述：
 * Given two binary trees, write a function to check if they are equal or not.
 * Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 *
 * 题解：
 * 深搜，逐个节点比较
 *
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    bool dfs(TreeNode *p, TreeNode *q) {
      if (p != NULL && q != NULL) {
        if (p->val != q->val)
          return false;
        return dfs(p->left, q->left) && dfs(p->right, q->right);
      }
      if (p != NULL || q!= NULL)
        return false;
      return true;
    }
    bool isSameTree(TreeNode *p, TreeNode *q) {
      return dfs(p, q);
    }
};
