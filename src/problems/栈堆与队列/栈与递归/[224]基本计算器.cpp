//给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
//
//
//
// 示例 1：
//
//
//输入：s = "1 + 1"
//输出：2
//
//
// 示例 2：
//
//
//输入：s = " 2-1 + 2 "
//输出：3
//
//
// 示例 3：
//
//
//输入：s = "(1+(4+5+2)-3)+(6+8)"
//输出：23
//
//
//
//
// 提示：
//
//
// 1 <= s.length <= 3 * 105
// s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
// s 表示一个有效的表达式
//
// Related Topics 栈 递归 数学 字符串
// 👍 596 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
/// 栈 + 括号展开（加法结合交换率）
// 每当遇到一个以 - 号开头的括号，则意味着此后的符号都要被「翻转」
// Time: O(N)
class Solution {
 public:
  int calculate(string s) {
    stack<int> ops;
    ops.push(1);
    int sign = 1;

    int ret = 0;
    int n = s.length();
    int i = 0;
    while (i < n) {
      if (s[i] == ' ') {
        i++;
      } else if (s[i] == '+') {
        sign = ops.top();
        i++;
      } else if (s[i] == '-') {
        sign = -ops.top();
        i++;
      } else if (s[i] == '(') {
        // 遇到 (，入栈一个 sign
        ops.push(sign);
        i++;
      } else if (s[i] == ')') {
        // 遇到 )，出栈一个 sign
        ops.pop();
        i++;
      } else {
        long num = 0;
        // 累加数字
        while (i < n && s[i] >= '0' && s[i] <= '9') {
          num = num * 10 + s[i] - '0';
          i++;
        }
        // 求和
        ret += sign * num;
      }
    }
    return ret;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
