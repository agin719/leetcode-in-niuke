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
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
      vector<string> answer;
      do_work(s, 0, dict, answer, "");
      return answer;
    }
    void do_work(string s, int pos, unordered_set<string> &dict, vector<string> &result, string one_result) {
      if (pos == s.size()) {
        result.push_back(one_result);
        return;
      }
      for (auto it = dict.begin(); it != dict.end(); it++) {
        string tmp = one_result;
        if (s.size()-pos >= it->size() && strncmp(s.c_str()+pos, it->c_str(), it->size()) == 0) {
          tmp += " " + *it;
          do_work(s, pos+s.size(), dict, result, tmp);
        }    
      }
    }
};

int main() {
  Solution sol;
  unordered_set<string> dict;
  dict.insert(string("a"));
  dict.insert(string("b"));
  vector<string> ans = sol.wordBreak("ab", dict);
  for (auto it = ans.begin(); it != ans.end(); it++)
    cout << "ans: " << *it << endl;

  return 0;
}
