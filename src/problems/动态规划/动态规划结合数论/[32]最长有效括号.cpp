//给你一个只包含 '(' 和 ')'
//的字符串，找出最长有效（格式正确且连续）括号子串的长度。
//
//
//
//
//
// 示例 1：
//
//
//输入：s = "(()"
//输出：2
//解释：最长有效括号子串是 "()"
//
//
// 示例 2：
//
//
//输入：s = ")()())"
//输出：4
//解释：最长有效括号子串是 "()()"
//
//
// 示例 3：
//
//
//输入：s = ""
//输出：0
//
//
//
//
// 提示：
//
//
// 0 <= s.length <= 3 * 104
// s[i] 为 '(' 或 ')'
//
//
//
// Related Topics 字符串 动态规划
// 👍 1333 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <algorithm>
#include <string>
using std::string;
class Solution {
 public:
  int longestValidParentheses(string s) {
    // 定义 dp 为最长有效括号的长度
    int n = s.size();
    int max_len = 0;

    vector<int> dp(n, 0);
    // dp[0] = 0
    // 以 '(' 结尾的字符串的 dp 必为 0
    for (int i = 1; i < n; ++i) {
      if (s[i] == ')') {
        if (s[i - 1] == '(') {
          // 形如 "()" 的形式,因此直接 + 2
          dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
        } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
          // 形如 "))" 的形式
          // 比如 "()(())" 中 dp[i-1] = 2
          // dp[i-dp[i-1]-2] 是最前面的那个 "()"
          dp[i] = dp[i - 1] +
                  ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
        }
        max_len = std::max(max_len, dp[i]);
      }
    }
    return max_len;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
