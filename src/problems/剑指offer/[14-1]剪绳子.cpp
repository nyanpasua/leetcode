// 输入: 10
// 输出: 36
// 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36

// 数学推导
// 1将绳子 以相等的长度等分为多段 ，得到的乘积最大
// 2尽可能将绳子以长度 3 等分为多段时，乘积最大。
//最优：3。把绳子尽可能切为多个长度为3的片段，留下的最后一段绳子的长度可能为0,1,2三种情况。
//次优：2。若最后一段绳子长度为 2 ；则保留，不再拆为 1+1。
//最差：1。若最后一段绳子长度为 1；则应把一份 3 + 1替换为 2 + 2，因为 2*2 > 3*1
//
#include <cmath>
class Solution {
 public:
  int cuttingRope(int n) {
    if (n == 2) return 1;
    if (n == 3) return 2;
    int a = n / 3, b = n % 3;
    if (b == 0) return std::pow(3, a);
    if (b == 1) return std::pow(3, a - 1) * 4;
    return std::pow(3, a) * b;
  }
};

class Solution1 {
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
