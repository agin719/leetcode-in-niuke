class Solution {
  public:
    bool isInterleave(string s1, string s2, string s3) {
      int size1 = s1.size();
      int size2 = s2.size();
      if (size1+size2 != s3.size()) return false;
      bool f[size1+1][size2+1];
      memset(f, false, sizeof(f));
      f[0][0] = true;
      for (int i = 1; i <= size2; i++) {
        if (s3[i-1] != s2[i-1])
          break;
        f[0][i] = true;
      }
      for (int i = 1; i <= size1; i++) {
        if (s3[i-1] != s1[i-1])
          break;
        f[i][0] = true;
      }
      for (int i = 1; i <= size1; i++) {
        for (int j = 1; j <= size2; j++) {
          if (s1[i-1] == s3[i+j-2] && s2[j-1] == s2[i+j-2])
            f[i][j] = f[i-1][j] || f[i][j-1];
          if (s1[i-1] == s3[i+j-2])
            f[i][j] = f[i-1][j];
          else if (s2[j-1] == s3[i+j-2])
            f[i][j] = f[i][j-1];
        }
      }
      return f[size1][size2];
    }
};
