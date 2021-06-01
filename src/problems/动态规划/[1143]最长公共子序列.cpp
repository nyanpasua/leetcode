//
// Created by liyingmin on 2020/3/29.
// 最长公共子序列
// 输入：text1 = "abcde", text2 = "ace"
//输出：3
//解释：最长公共子序列是 "ace" ，它的长度为 3 。
#include <algorithm>
#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution {
 public:
  int SubString(string text1, string text2) {
    size_t height = text1.size() + 1;
    size_t width = text2.size() + 1;
    // base case:
    vector<vector<int>> memo(height, vector<int>(width, 0));
    // 状态转移迭代
    for (size_t i = 1; i < height; ++i) {
      for (size_t j = 1; j < width; ++j) {
        if (text1[i - 1] == text2[j - 1]) {
          memo[i][j] = memo[i - 1][j - 1] + 1;
        } else {
          memo[i][j] = std::max(memo[i - 1][j], memo[i][j - 1]);
        }
      }
    }
    return memo[height - 1][width - 1];
  }
};
