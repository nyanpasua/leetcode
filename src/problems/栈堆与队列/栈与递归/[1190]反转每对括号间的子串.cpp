//给出一个字符串 s（仅含有小写英文字母和括号）。
//
// 请你按照从括号内到外的顺序，逐层反转每对匹配括号中的字符串，并返回最终的结果。
//
// 注意，您的结果中 不应 包含任何括号。
//
//
//
// 示例 1：
//
//
//输入：s = "(abcd)"
//输出："dcba"
//
//
// 示例 2：
//
//
//输入：s = "(u(love)i)"
//输出："iloveu"
//解释：先反转子字符串 "love" ，然后反转整个字符串。
//
// 示例 3：
//
//
//输入：s = "(ed(et(oc))el)"
//输出："leetcode"
//解释：先反转子字符串 "oc" ，接着反转 "etco" ，然后反转整个字符串。
//
// 示例 4：
//
//
//输入：s = "a(bcdefghijkl(mno)p)q"
//输出："apmnolkjihgfedcbq"
//
//
//
//
// 提示：
//
//
// 0 <= s.length <= 2000
// s 中只有小写英文字母和括号
// 题目测试用例确保所有括号都是成对出现的
//
// Related Topics 栈 字符串
// 👍 184 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <stack>
#include <string>
using std::stack;
using std::string;

/// 预处理括号 + 数学
// 第一步我们向右移动到左括号，此时我们跳跃到该左括号对应的右括号（进入了更深一层）；
//第二到第三步我们在括号内部向左移动（完成了更深层的遍历）；
//第四步我们向左移动到左括号，此时我们跳跃到该左括号对应的右括号（返回到上一层）；
//第五步我们在括号外向右移动（继续遍历）。
//假设我们沿着某个方向移动，此时遇到了括号，
// 那么我们只需要首先跳跃到该括号对应的另一个括号所在处，然后改变我们的移动方向即可。
class Solution {
 public:
  string reverseParentheses(string s) {
    int n = s.length();
    vector<int> pair(n);
    stack<int> stk;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        stk.push(i);
      } else if (s[i] == ')') {
        int j = stk.top();
        stk.pop();
        pair[i] = j, pair[j] = i;
      }
    }
    string ret;
    int index = 0, step = 1;
    while (index < n) {
      if (s[index] == '(' || s[index] == ')') {
        index = pair[index];
        step = -step;
      } else {
        ret.push_back(s[index]);
      }
      index += step;
    }
    return ret;
  }
};

/// 栈
// 使用栈来模拟嵌套括号问题
// Time: O(N^2)
class Solution1 {
 public:
  string reverseParentheses(string s) {
    stack<string> stk;
    string str;
    for (auto &ch : s) {
      if (ch == '(') {
        stk.push(str);
        str = "";
      } else if (ch == ')') {
        reverse(str.begin(), str.end());
        str = stk.top() + str;
        stk.pop();
      } else {
        str.push_back(ch);
      }
    }
    return str;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
