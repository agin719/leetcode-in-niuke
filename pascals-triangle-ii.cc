/*
 * 题目：
 * Given an index k, return the k th row of the Pascal's triangle.
 * For example, given k = 3,
 * Return[1,3,3,1].
 * Note: 
 * Could you optimize your algorithm to use only O(k) extra space?
 * 题解：
 * 杨辉三角形，只输出第k行，k从0开始，限制只用O(k)的额外空间
 * 第k行只和第k-1行有关。从后面开始算起。
 * */

class Solution {
  public:
    vector<int> getRow(int rowIndex) {
      vector<int> aRows;
      aRows.push_back(1);
      for (int i = 1; i < rowIndex+1; i++) {
        int tmp = aRows[aRows.size()-1];
        for (int j = aRows.size()-1; j > 0; j--) {
          aRows[j] += aRows[j-1];
        }
        aRows.push_back(tmp);
      }
      return aRows;
    }
};
