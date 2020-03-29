//
// Created by liyingmin on 2020/3/29.
//
//
class Solution {
 public:
  bool isMatch(string s, string p) {
    // 在s和p前面加了一个空格(其他符号也行)，解决了s为空时的特殊情况，避免了繁琐的初始化
    s = " " + s;
    p = " " + p;
    size_t height = s.size() + 1;
    size_t width = p.size() + 1;
    vector<vector<bool>> memo(height, std::move(vector<bool>(width, false)));
    // base case
    memo[0][0] = true;
    // 状态转移迭代
    for (size_t i = 1; i < height; ++i) {
      for (size_t j = 1; j < width; ++j) {
        if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
          memo[i][j] = memo[i - 1][j - 1];
        } else if (p[j - 1] == '*') {
          if (s[i - 1] != p[j - 2] && p[j - 2] != '.')
            memo[i][j] = memo[i][j - 2];
          else {
            memo[i][j] = memo[i][j - 1] || memo[i][j - 2] || memo[i - 1][j];
          }
        }
      }
    }
    return memo[height - 1][width - 1];
  }
};