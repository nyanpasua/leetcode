//给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i
//天的价格。
//
// 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子
// 卖出该股票。设计一个算法来计算你所能获取的最大利润。
//
// 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
//
//
//
// 示例 1：
//
//
//输入：[7,1,5,3,6,4]
//输出：5
//解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 =
//6）的时候卖出，最大利润 = 6-1 = 5 。
//     注意利润不能是 7-1 = 6,
//     因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
//
//
// 示例 2：
//
//
//输入：prices = [7,6,4,3,1]
//输出：0
//解释：在这种情况下, 没有交易完成, 所以最大利润为 0。
//
//
//
//
// 提示：
//
//
// 1 <= prices.length <= 105
// 0 <= prices[i] <= 104
//
// Related Topics 数组 动态规划
// 👍 1656 👎 0

// leetcode submit region begin(Prohibit modification and deletion)

#include <vector>
using std::vector;
/// [i...j] max(prices[j] - prices[i]), j >= i
/// 记录 max 和 max_idx
class Solution {
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
// 某天买入，某天卖出，只能进行一次交易
// 前i日最大利润=max(前(i−1)日最大利润,第i日价格−前i日最低价格)
// 第i日价格−前i日最低价格 为 第 i 日完成交易可以获得的最大利润
// dp[i]=max(dp[i−1],prices[i]−min(prices[0:i]))
class Solution1 {
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
// leetcode submit region end(Prohibit modification and deletion)
