/**
 * 题目：
 * Given a binary tree, return the postorder traversal of its nodes' values.
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
 *   return[3,2,1].
 *
 *Note: Recursive solution is trivial, could you do it iteratively?
 *
 * 树的后序遍历
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
    vector<int> postorderTraversal(TreeNode *root) {
      vector<int> result;
      if (root == NULL) return result;
      travel(root, result);
      return result;
    }
    void travel(TreeNode *root, vector<int> &result) {
      if (root->left) 
        travel(root->left, result);
      if (root->right)
        travel(root->right, result);
      result.push_back(root->val);
    }
};
