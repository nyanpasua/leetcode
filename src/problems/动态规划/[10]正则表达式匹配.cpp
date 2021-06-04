//给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*'
//的正则表达式匹配。
//
//
// '.' 匹配任意单个字符
// '*' 匹配零个或多个前面的那一个元素
//
//
// 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
//
//
// 示例 1：
//
//
//输入：s = "aa" p = "a"
//输出：false
//解释："a" 无法匹配 "aa" 整个字符串。
//
//
// 示例 2:
//
//
//输入：s = "aa" p = "a*"
//输出：true
//解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是
//'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
//
//
// 示例 3：
//
//
//输入：s = "ab" p = ".*"
//输出：true
//解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
//
//
// 示例 4：
//
//
//输入：s = "aab" p = "c*a*b"
//输出：true
//解释：因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a'
//被重复一次。因此可以匹配字符串 "aab"。
//
//
// 示例 5：
//
//
//输入：s = "mississippi" p = "mis*is*p*."
//输出：false
//
//
//
// 提示：
//
//
// 0 <= s.length <= 20
// 0 <= p.length <= 30
// s 可能为空，且只包含从 a-z 的小写字母。
// p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
// 保证每次出现字符 * 时，前面都匹配到有效的字符
//
// Related Topics 字符串 动态规划 回溯算法
// 👍 2156 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution {
 public:
  bool isMatch(string s, string p) {
    int height = s.size() + 1;
    int width = p.size() + 1;
    // 创建 dp
    auto dp =
        std::move(vector<vector<bool>>(height, vector<bool>(width, false)));
    // base case, s 和 p 均为空串
    dp[0][0] = true;
    // base case, s 为空串, p 应该满足偶数位 为 *
    for (int j = 2; j < width; j += 2) {
      dp[0][j] = dp[0][j - 2] && p[j - 1] == '*';
    }
    // 状态转移
    for (int i = 1; i < height; ++i) {
      for (int j = 1; j < width; ++j) {
        if (p[j - 1] == '*') {
          // 看 i - 1 和 j - 2
          if (dp[i][j - 2])
            dp[i][j] = true;  // p[j - 2] 重复0次
          else if (dp[i - 1][j] && s[i - 1] == p[j - 2])
            dp[i][j] = true;  // p[j - 2] 多重复一次
          else if (dp[i - 1][j] && p[j - 2] == '.')
            dp[i][j] = true;  // p[j - 2] 可以为任何值，可与 s[i - 1]相同，多重复一次
          else
            continue;
        } else {
          // p[j - 1]不为 *
          // i j 同时增加一位
          if (dp[i - 1][j - 1] && s[i - 1] == p[j - 1])
            dp[i][j] = true;  // 看左斜对角是否满足，并且对比位也相同
          else if (dp[i - 1][j - 1] && p[j - 1] == '.')
            dp[i][j] = true;  // // 看左斜对角是否满足，并且对比位可匹配任何字符
          else
            continue;
        }
      }
    }
    return dp[height - 1][width - 1];
  }
};
// leetcode submit region end(Prohibit modification and deletion)
