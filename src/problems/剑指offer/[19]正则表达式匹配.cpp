// 请实现一个函数用来匹配包含'. '和'*'的正则表达式。
// 模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。
// 在本题中，匹配是指字符串的所有字符匹配整个模式。
// 例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。
// 输入:
// s = "ab"
// p = ".*"
//输出: true
//解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
// 输入:
// s = "mississippi"
// p = "mis*is*p*."
//输出: false
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
            dp[i][j] = true;
          else if (dp[i - 1][j] && p[j - 2] == '.')
            dp[i][j] = true;
          else
            continue;
        } else {
          // i j 同时增加一位
          if (dp[i - 1][j - 1] && s[i - 1] == p[j - 1])
            dp[i][j] = true;
          else if (dp[i - 1][j - 1] && p[j - 1] == '.')
            dp[i][j] = true;
          else
            continue;
        }
      }
    }
    return dp[height - 1][width - 1];
  }
};
