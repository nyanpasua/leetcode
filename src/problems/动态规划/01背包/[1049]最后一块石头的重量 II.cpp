//有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。
//
// 每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和
// y，且 x <= y。那么粉碎的可能结果如下：
//
//
// 如果 x == y，那么两块石头都会被完全粉碎；
// 如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
//
//
// 最后，最多只会剩下一块 石头。返回此石头 最小的可能重量
// 。如果没有石头剩下，就返回 0。
//
//
//
// 示例 1：
//
//
//输入：stones = [2,7,4,1,8,1]
//输出：1
//解释：
//组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
//组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
//组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
//组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。
//
//
// 示例 2：
//
//
//输入：stones = [31,26,33,21,40]
//输出：5
//
//
// 示例 3：
//
//
//输入：stones = [1,2]
//输出：1
//
//
//
//
// 提示：
//
//
// 1 <= stones.length <= 30
// 1 <= stones[i] <= 100
//
// Related Topics 动态规划
// 👍 258 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <numeric>
#include <vector>
using std::vector;

class Solution {
 public:
  int lastStoneWeightII(vector<int> &stones) {
    int sum = accumulate(stones.begin(), stones.end(), 0);
    int m = sum / 2;
    vector<int> dp(m + 1);
    dp[0] = true;
    // 组合问题可行性
    // 注意倒序，01背包，不可复用
    for (int weight : stones) {
      for (int j = m; j >= weight; --j) {
        dp[j] = dp[j] || dp[j - weight];
      }
    }
    for (int j = m;; --j) {
      if (dp[j]) {
        return sum - 2 * j;
      }
    }
  }
};


/// 01背包
// sum−2*neg = 0 --> neg = sum/2;
// 问题转换为 neg 需要在不超过 ⌊sum/2⌋ 的前提下尽可能地大。
// 因此本问题可以看作是背包容量为 ⌊sum/2⌋，物品重量和价值均为 stones 的 0-1
// 背包问题。
//
class Solution1 {
 public:
  int lastStoneWeightII(vector<int>& stones) {
    int sum = std::accumulate(stones.begin(), stones.end(), 0);
    int n = stones.size(), m = sum / 2;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    dp[0][0] = true;
    // 组合问题可行性
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= m; ++j) {
        if (j < stones[i]) {
          dp[i + 1][j] = dp[i][j];
        } else {
          dp[i + 1][j] = dp[i][j] || dp[i][j - stones[i]];
        }
      }
    }
    for (int j = m;; --j) {
      // 找到最大为 true 的 j
      if (dp[n][j]) {
        return sum - 2 * j;
      }
    }
  }
};
// leetcode submit region end(Prohibit modification and deletion)
