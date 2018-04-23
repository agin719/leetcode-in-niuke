/*
 * 题目：
 * Given numRows, generate the first numRows of Pascal's triangle.
 * For example, given numRows = 5,
 * Return
 *
 * [
 *    [1],
 *   [1,1],
 *  [1,2,1],
 * [1,3,3,1],
 *[1,4,6,4,1]
 *]
 *题解：
 *就是一个杨辉三角形：
 *if (j = 0)
 *  a[i][j] = 1;
 *else 
 *  a[i][j] = a[i-1][j-1]+a[i-1][j]; 
 **/
class Solution {
  public:
    vector<vector<int> > generate(int numRows) {
      vector<vector<int>> ans;
      if (!numRows) return ans;
      ans.emplace_back(1, 1);
      for (int i = 1; i < numRows; i++) {
        vector<int> aRows(1, 1);
        int size = ans[i-1].size();
        for (int j = 1; j < size; j++) {
          int val = ans[i-1][j-1]+ans[i-1][j];
          aRows.push_back(val);
        }
        aRows.push_back(ans[i-1][size-1]);
        ans.push_back(aRows);
      }
      return ans;
    }
};
