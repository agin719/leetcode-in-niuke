/*
 * 未完成
 */
#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>
#include <string.h>

using namespace std;

class Solution {
  public:
    bool wordBreak(string s, unordered_set<string> &dict) {
      int f[s.size()+1];
      memset(f, 0, sizeof(f));
      f[0] = 1;
      for (int i = 1; i <= s.size(); i++) {
        for (auto it = dict.begin(); it != dict.end(); it++) {
          if (!it->size()) 
            continue;
          if (i >= it->size() && strncmp(s.c_str()+i-it->size(), it->c_str(), it->size()) == 0) {
            f[i] = f[i-it->size()];
          }
        }
      }
      return f[s.size()];
    }
};

int main() {
  Solution sol;
  vector<string> input = {"leet", "code"};//{"cbc","bcda","adb","ddca","bad","bbb","dad","dac","ba","aa","bd","abab","bb","dbda","cb","caccc","d","dd","aadb","cc","b","bcc","bcd","cd","cbca","bbd","ddd","dabb","ab","acd","a","bbcc","cdcbd","cada","dbca","ac","abacd","cba","cdb","dbac","aada","cdcda","cdc","dbc","dbcb","bdb","ddbdd","cadaa","ddbc","babb"};
  unordered_set<string> dict(input.begin(), input.end());
  cout << sol.wordBreak("leetcode", dict) << endl;

  return 0;
}
