//给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。
//
// 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
//
//
// 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
// 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
//
//
// 示例:
//
// 输入: [1,2,3,0,2]
//输出: 3
//解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
// Related Topics 数组 动态规划
// 👍 807 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <algorithm>
#include <vector>
using std::vector;

/// 动态规划
// 可以进行多次交易，利润累加
//
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty()) {
      return 0;
    }

    int n = prices.size();
    // f[i] 表示 第 i 天结束之后的累积最大收益
    // f[i][0]: 手上持有股票的最大收益，即买入未卖出
    // f[i][1]: 手上不持有股票，并且处于冷冻期中的累计最大收益，即当天卖出
    // f[i][2]: 手上不持有股票，并且不在冷冻期中的累计最大收益，即当天之前卖出
    vector<vector<int>> f(n, vector<int>(3));
    f[0][0] = -prices[0];
    for (int i = 1; i < n; ++i) {
      // 持有股票，最大收益为 持有昨天的股票 or 第 i 天买入
      f[i][0] = std::max(f[i - 1][0], f[i - 1][2] - prices[i]);
      // 第 i 天必须卖出股票进入冷冻期，说明 i-1 天必须手头有股票
      f[i][1] = f[i - 1][0] + prices[i];
      // 今天不能出售股票，因为不能让自己处于冷冻期，只能是昨天出售了，或者保留上一天的情况
      f[i][2] = std::max(f[i - 1][1], f[i - 1][2]);
    }
    return std::max(f[n - 1][1], f[n - 1][2]);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
