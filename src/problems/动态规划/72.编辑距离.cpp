//
// Created by liyingmin on 2020/3/29.
//
class Solution {
 public:
  int minDistance(string word1, string word2) {
    size_t height = word1.size() + 1;
    size_t width = word2.size() + 1;
    vector<vector<int>> memo(height, std::move(vector<int>(width, -1)));
    // base case
    for (size_t i = 0; i < height; ++i) {
      memo[i][0] = i;
    }
    for (size_t j = 0; j < width; ++j) {
      memo[0][j] = j;
    }
    // 状态转移迭代
    for (size_t i = 1; i < height; ++i) {
      for (size_t j = 1; j < width; ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          memo[i][j] = memo[i - 1][j - 1];  // 啥都不做
        } else {
          memo[i][j] =
              std::min({memo[i - 1][j], memo[i][j - 1], memo[i - 1][j - 1]}) +
              1;
        }
      }
    }
    return memo[height - 1][width - 1];
  }
};