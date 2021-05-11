//
// Created by liyingmin on 2020/3/29.
//
// 动态规划，贪心是不行的
class Solution {
 public:
  int numSquares(int n) {
    vector<int> memo(n + 1, 0);
    // 初始化&base case
    for (size_t i = 0; i <= n; ++i) {
      memo[i] = i;
    }
    // 状态转移迭代
    for (size_t i = 1; i <= n; ++i) {
      for (size_t j = 1; j * j <= i; ++j) {
        memo[i] = std::min(memo[i], memo[i - j * j] + 1);
      }
    }
    return memo[n];
  }
};