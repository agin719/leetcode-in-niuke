/*
 * 题目
 * palindrome-partitioning-ii
 *
 * 题目描述
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 * Return the minimum cuts needed for a palindrome partitioning of s.
 * For example, given s ="aab",
 * Return1since the palindrome partitioning["aa","b"]could be produced using 1 cut.
 *
 * 题意：
 * 给定一个字符串，将这个字符串进行分割，使每个子串都是回文串，求最小分割的次数
 *
 * 动态规划：
 * f[i]表示子串S(0-i)的最小分割次数
 * 如果子串s[k+1,..,i]是回文串，则尝试从k这个位置分割，f[i] = min(f[k] + 1, f[i]); (0 < k < i-1)
 */

class Solution {
  public:
    //判断回文
    bool is_palindrome(string s) {
      int l = 0, r = s.size()-1;
      while (l < r) {
        if (s[l] != s[r])
          return false;
        l++; r--;
      }
      return true;
    }
    int minCut(string s) {  
      int size = s.size();
      int ans[size];
      for (int i = 0; i < size; i++) 
        ans[i] = -1;
      ans[0] = 0;
      for (int i = 1; i < size; i++) {
        if (is_palindrome(s.substr(0, i+1))) {
          ans[i] = 0;
          continue;
        }
        for (int j = 0; j < i; j++) 
          if (ans[j] >= 0) {
            if (is_palindrome(s.substr(j+1, i-j))) {
              if (ans[i] == -1) 
                ans[i] = ans[j] + 1;
              else 
                ans[i] = std::min(ans[i], ans[j]+1);
            }
          }
      }
      return ans[size-1];
    }

};
