/*
 * 题目：
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 * Valid operators are+,-,*,/. Each operand may be an integer or another expression.
 *
 * Some examples:
 *
 *   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *     ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 *
 * 题解：
 * 后缀表达式，使用栈操作。
 */
class Solution {
  public:
    int evalRPN(vector<string> &tokens) {
      vector<int> stack_cal;
      for (auto it = tokens.begin(); it != tokens.end(); it++) {
        if (*it== "*" || *it == "/" || *it == "+" || *it == "-") {
          int y = stack_cal.back();
          stack_cal.pop_back();
          int x = stack_cal.back();
          stack_cal.pop_back();
          int ret;
          if (*it == "*") ret = x * y;
          if (*it == "/") ret = x / y;
          if (*it == "+") ret = x + y;
          if (*it == "-") ret = x - y;
          stack_cal.push_back(ret);
        } else {
          stack_cal.push_back(::atoi(it->c_str()));
        }
      }
      if (stack_cal.size())
        return stack_cal.back();
      return 0;
    }
};
