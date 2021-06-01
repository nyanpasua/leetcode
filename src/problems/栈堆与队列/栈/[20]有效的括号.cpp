// 输入：s = "([)]"
//输出：false

// 输入：s = "()[]{}"
//输出：true
#include <stack>
#include <string>
#include <unordered_map>
using std::string;

class Solution {
 public:
  bool isValid(string s) {
    // 奇数必返回 false
    if (s.size() % 2) return false;
    std::stack<char> stk;
    std::unordered_map<char, char> table{{'[', ']'}, {'{', '}'}, {'(', ')'}};
    for (const auto& ch : s) {
      if (ch == '{' || ch == '(' || ch == '[') {
        stk.push(ch);
      }
      if (ch == ']' || ch == ')' || ch == '}') {
        if (stk.empty() || table.find(stk.top()) == table.end() ||
            table[stk.top()] != ch)
          return false;
        stk.pop();
      }
    }
    return stk.empty();
  }
};