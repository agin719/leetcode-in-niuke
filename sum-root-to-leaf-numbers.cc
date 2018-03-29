/*
 * 题目：sum-root-to-leaf-numbers
 *
 * 题目描述
 * Given a binary tree containing digits from0-9only, each root-to-leaf path could represent a number.
 * An example is the root-to-leaf path1->2->3which represents the number123.
 * Find the total sum of all root-to-leaf numbers.
 * For example,
 *
 *     1
 *    / \
 *   2   3
 *
 *The root-to-leaf path1->2represents the number12.
 *The root-to-leaf path1->3represents the number13.
 *Return the sum = 12 + 13 =25.
 *
 * 题解：
 * 深搜
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
    void dfs(TreeNode *node, int value, int &sum) {
      if (node->left == NULL && node->right == NULL) {
        sum += 10*value + node->val;
        return;
      }
      if (node->left) 
        dfs(node->left, value*10+node->val, sum);
      if (node->right) 
        dfs(node->right, value*10+node->val, sum);
    }
    int sumNumbers(TreeNode *root) {
      int sum = 0;
      if (root)
        dfs(root, 0, sum);
      return sum;
    }
};
