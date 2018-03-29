/*
 * 题目：distinct-subsequences
 * 题目描述：
 * Given a string S and a string T, count the number of distinct subsequences of T in S.
 * A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie,"ACE"is a subsequence of"ABCDE"while"AEC"is not).
 * Here is an example:
 * S ="rabbbit", T ="rabbit"
 * Return3.
 * 题解：
 * 给定串S和T，求出有多少个子串等于T。其中这里的子串的元素可以只要按照S中的顺序即可，并不是每个元素一定要连续的子串，如：
 * ACE是ABCDE的子串，而AEC就不是了。
 * DP：
 * f[i][j]表示S(0..i-1)与T(0..j-1)相同的子串数量，即f[s.size()][t.size()]为答案。
 * 初始：
 * f[i][0] = 1; 
 * 状态：
 * if (S[i-1] == T[j-1])    
 *     f[i][j] = f[i-1][j-1] + f[i-1][j];//当节点相同时，可以选择这两个节点匹配(f[i-1][j-1])，也可以选择这两个节点不匹配(f[i-1][j]);
 *     else 
 *         f[i][j] = f[i-1][j];    //相当于S[i]这个节点没用到。
 */
class Solution {
  public:
    int numDistinct(string S, string T) {
      int s_size = S.size();
      int t_size = T.size();
      int f[s_size+1][t_size+1];
      memset(f, 0 , sizeof(f));
      for (int i = 0; i <= s_size; i++)
        f[i][0] = 1;
      for (int i = 1; i <= s_size; i++) {
        for (int j = 1; j <= t_size; j++) {
          if (S[i-1] == T[j-1]) {
            f[i][j] = f[i-1][j-1] + f[i-1][j];
          } else {
            f[i][j] = f[i-1][j];
          }
        }
      }
      return f[s_size][t_size];
    }
};
