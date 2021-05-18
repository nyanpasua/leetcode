#include <vector>
using std::vector;
/// [i...j] max(prices[j] - prices[i]), j >= i
/// 记录 max 和 max_idx
class Solution2 {
 public:
  int maxProfit(vector<int>& prices) {
    int max = 0, max_idx = 0, min_idx = 0;
    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i] < prices[min_idx]) {
        min_idx = i;
        max_idx = i;
      }
      if (prices[i] > prices[max_idx]) {
        max = std::max(max, prices[i] - prices[min_idx]);
        max_idx = i;
      }
    }
    return max;
  }
};

/// 使用动态规划思路
/// 前i日最大利润=max(前(i−1)日最大利润,第i日价格−前i日最低价格)
/// dp[i]=max(dp[i−1],prices[i]−min(prices[0:i]))
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    int min = prices[0], profit = 0;
    for (int i = 1; i < prices.size(); ++i) {
      min = std::min(min, prices[i]);
      profit = std::max(profit, prices[i] - min);
    }
    return profit;
  }
};
