// 输入: 10
// 输出: 36
// 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36

class Solution {
 public:
  int cuttingRope(int n) {
    std::vector<int> dp(n + 1, 1);
    // base case
    // 当绳子只有1, dp[1] = 1
    dp[1] = 1;
    // 状态转移
    for (int i = 2; i <= n; ++i) {
      int max = 1;
      for (int j = 1; j < i; ++j) {
        max = std::max(max, std::max(dp[j], j) * (i - j));
      }
      dp[i] = max;
    }
    return dp[n];
  }
};
