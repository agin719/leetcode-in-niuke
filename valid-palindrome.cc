/*
 * 题目：
 * valid-palindrome
 * 题目描述：
 *
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 *
 * For example,
 * "A man, a plan, a canal: Panama"is a palindrome.
 * "race a car"is not a palindrome.
 *
 * Note: 
 * Have you consider that the string might be empty? This is a good question to ask during an interview.
 *
 * For the purpose of this problem, we define empty string as valid palindrome.
 *
 * 题解：
 * 就是给定一个字符串，只考虑数字和字母，判断是否为回文字符串。
 */

class Solution {
  public:
    bool is_same(char x, char y) {
      int duration = 'a' - 'A';
      if (x + duration == y) return true;
      if (y + duration == x) return true;
      return (x == y);
    }
    bool isPalindrome(string s) {
      int head = 0;
      int last = s.size()-1;
      while (head < last) {
        while (head < last && !isalnum(s[head])) 
          head++;
        while (head < last && !isalnum(s[last]))
          last--;
        if (tolower(s[head]) != tolower(s[last]))
          return false;
        head++;
        last--;
      }
      return true;
    }
};

