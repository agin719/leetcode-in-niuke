/*
 * 题目：
 * triangle
 *
 * 题目描述
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
 *
 * For example, given the following triangle
 *
 * [
 *      [2],
 *     [3,4],
 *    [6,5,7],
 *   [4,1,8,3]
 * ]
 *The minimum path sum from top to bottom is11(i.e., 2 + 3 + 5 + 1 = 11).
 *Note: 
 *Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
 *
 * 题意：
 * 从顶向下走，使路径最小。
 * f[i][j] += min(f[i-1][j],f[i-1][j-1]) 
 */

class Solution {
  public:
    int minimumTotal(vector<vector<int> > &triangle) {
      if (triangle.size() == 0) return 0;
      int size = triangle.size();
      for (int i = 1; i < size; i++) {
        triangle[i][0] += triangle[i-1][0];
        for (int j = 1; j < triangle[i].size(); j++) {
          if (triangle[i-1].size() >= j+1) 
            triangle[i][j] = std::min(triangle[i-1][j]+triangle[i][j], triangle[i-1][j-1]+triangle[i][j]);
          else 
            triangle[i][j] = triangle[i-1][j-1]+triangle[i][j];
        }
      }
      int min_val = triangle[size-1][0];
      for (int i = 1; i < triangle[size-1].size(); i++)
        min_val = std::min(min_val, triangle[size-1][i]);
      return min_val;

    }
};
