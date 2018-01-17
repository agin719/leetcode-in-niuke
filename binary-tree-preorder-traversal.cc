/**
 * 题目：
 * Given a binary tree, return the preorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree{1,#,2,3},
 *
 *    1
 *     \
 *      2
 *     /
 *    3
 *
 * return[1,2,3].
 *
 * Note: Recursive solution is trivial, could you do it iteratively?
 * 树的先序遍历
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
    vector<int> preorderTraversal(TreeNode *root) {
      vector<int> result;
      if (root == NULL) return result;
      travel(root, result);
      return result;
    }
    void travel(TreeNode *root, vector<int> &result) {
      result.push_back(root->val);
      if (root->left) 
        travel(root->left, result);
      if (root->right)
        travel(root->right, result);
    }
};
