//给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。
// 假设每一种面额的硬币有无限个。
//
//
//
//
//
//
// 示例 1:
//
// 输入: amount = 5, coins = [1, 2, 5]
//输出: 4
//解释: 有四种方式可以凑成总金额:
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1
//
//
// 示例 2:
//
// 输入: amount = 3, coins = [2]
//输出: 0
//解释: 只用面额2的硬币不能凑成总金额3。
//
//
// 示例 3:
//
// 输入: amount = 10, coins = [10]
//输出: 1
//
//
//
//
// 注意:
//
// 你可以假设：
//
//
// 0 <= amount (总金额) <= 5000
// 1 <= coin (硬币面额) <= 5000
// 硬币种类不超过 500 种
// 结果符合 32 位符号整数
//
// 👍 410 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
using std::vector;

/// 完全背包

class Solution {
 public:
  int change(int amount, vector<int>& coins) {
    // 使用 coins 拼凑 j 可行的方案数量
    std::vector<int> memo(amount + 1, 0);
    // 使用 coins 拼凑 0 的方案个数为 1，即一个都不用
    memo[0] = 1;
    // 这里外层要用 coins，内层用 amount，统计组合数量
    // 如果外层使用 amount，
    // 从4到8可以先放1再放3也可以先放3再放1，这样组合变多了，
    // 这是由于内层多次重复循环coins种类导致的，所以会比实际结果大
    // 完全背包，组合问题方案数，容量正序，可以复用
    for (int i = 0; i < coins.size(); ++i) {
      // 使用 coin
      auto coin = coins[i];
      for (int j = coin; j <= amount; ++j) {
        // 使用不同的 coin 来拼凑 j 面值的方案数量
        // 从较小的 j 更新，在同一个 i 循环，后面较大的 j 都会受到 前置 j
        // 的影响， 比如 用 coin 2 拼 5，memo[3] = memo[3] + memo[1]，{1+2,
        // 1+1+1} memo[5] = memo[5] + memo[3]，这里 memo[3] 前面其实用过 2
        // 了。{1+2+2,1+1+1+2}
        memo[j] = memo[j] + memo[j - coin];
      }
    }
    return memo[amount];
  }
};

class Solution1 {
 public:
  int change(int amount, vector<int>& coins) {
    // 使用 coins 拼凑 j 可行的方案数量
    std::vector<vector<int>> memo(coins.size() + 1, vector<int>(amount + 1, 0));
    // 使用 空集合 拼凑 0 的方案个数为 1，即一个都不用
    memo[0][0] = 1;
    // 这里外层要用 coins，内层用 amount，统计组合数量
    // 如果外层使用 amount，
    // 从4到8可以先放1再放3也可以先放3再放1，这样组合变多了，
    // 这是由于内层多次重复循环coins种类导致的，所以会比实际结果大
    // 完全背包，组合问题方案数，容量正序，可以复用
    for (int i = 1; i <= coins.size(); ++i) {
      // 使用 coin
      auto coin = coins[i - 1];
      for (int j = 0; j <= amount; ++j) {
        // 不使用 coin
        memo[i][j] = memo[i - 1][j];
        // 使用 coin
        if (j >= coin) {
          // 注意这里用的是 memo[i][j-coin]，而不是 01 背包的 memo[i-1][j-coin]
          memo[i][j] = memo[i][j - coin] + memo[i][j];
        }
      }
    }
    return memo[coins.size()][amount];
  }
};

// leetcode submit region end(Prohibit modification and deletion)
