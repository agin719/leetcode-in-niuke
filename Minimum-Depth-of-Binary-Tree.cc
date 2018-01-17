/* 题目：
 * Given a binary tree, find its minimum depth.The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 * 题解：
 * 找到树的最小深度，使用广度遍历的方式。
 */

class Solution {
  public:
    int run(TreeNode *root) {
      if (root == NULL) return 0;
      list<TreeNode*> nodes;
      TreeNode *level_last_node = root;
      nodes.push_back(root);
      int min = 1;
      while (nodes.size()) {
        TreeNode *node = nodes.front();
        nodes.pop_front();
        if (node->left == NULL && node->right == NULL) 
          return min;
        if (node->left != NULL)
          nodes.push_back(node->left);
        if (node->right != NULL)
          nodes.push_back(node->right);
        if (node == level_last_node) {
          level_last_node = nodes.back();
          min++;
        }
      }
      return min;
    }
};
