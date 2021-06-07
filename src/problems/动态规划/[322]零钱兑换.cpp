//给定不同面额的硬币 coins 和一个总金额
// amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回
// -1。
//
// 你可以认为每种硬币的数量是无限的。
//
//
//
// 示例 1：
//
//
//输入：coins = [1, 2, 5], amount = 11
//输出：3
//解释：11 = 5 + 5 + 1
//
// 示例 2：
//
//
//输入：coins = [2], amount = 3
//输出：-1
//
// 示例 3：
//
//
//输入：coins = [1], amount = 0
//输出：0
//
//
// 示例 4：
//
//
//输入：coins = [1], amount = 1
//输出：1
//
//
// 示例 5：
//
//
//输入：coins = [1], amount = 2
//输出：2
//
//
//
//
// 提示：
//
//
// 1 <= coins.length <= 12
// 1 <= coins[i] <= 231 - 1
// 0 <= amount <= 104
//
// Related Topics 动态规划
// 👍 1298 👎 0

// leetcode submit region begin(Prohibit modification and deletion)

#include <vector>
using std::vector;
#include <limits>

/// 动态规划，类似剪绳子，容易搞成背包问题
class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    // 使用 coins 拼凑 j 需要的硬币个数 memo[j]
    std::vector<int> memo(amount + 1, std::numeric_limits<int>::max());
    // base case
    memo[0] = 0;
    // 状态转移，这里我们采用外部循环是 amount，而内部循环是 coins
    // 因为这里 coins 的数量是无限的，不像分割等和子集那里 nums 是固定的
    for (int i = 1; i <= amount; ++i) {
      for (int j = 0; j < coins.size(); ++j) {
        if (coins[j] <= i) {
          // memo[i] 表示 拼凑 i 需要的最少硬币数
          // memo[i - coins[j]] 使用 coins[j] 来拼凑 i，因此增加 1
          if (memo[i - coins[j]] != std::numeric_limits<int>::max()) {
            memo[i] = std::min(memo[i], memo[i - coins[j]] + 1);
          }
        }
      }
    }
    return memo[amount] == std::numeric_limits<int>::max() ? -1 : memo[amount];
  }
};

/// dp，会超时
class Solution1 {
 public:
  int coinChange(vector<int>& coins, int amount) {
    // 使用 coins 拼凑 amount
    // 使用 coins 拼凑 j 需要的硬币个数 memo[j]
    std::vector<int> memo(amount + 1, -1);
    // base case
    memo[0] = 0;
    // 只使用 coins[0] 拼凑 amount
    for (int j = 1; j <= amount; ++j) {
      memo[j] = (j % coins[0] == 0) ? j / coins[0] : -1;
    }

    // 状态转移
    for (int i = 1; i < coins.size(); ++i) {
      for (int j = amount; j >= coins[i]; --j) {
        // 使用 nums[i]，找到最少个数
        auto temp = coins[i];
        int use_i = std::numeric_limits<int>::max();
        while (j >= temp) {
          if (memo[j - temp] != -1) {
            use_i = std::min(memo[j - temp] + temp / coins[i], use_i);
          }
          temp += coins[i];
        }
        // 不使用 nums[i]
        auto not_use_i = memo[j];
        // std::min(use_i, not_use_i);
        if (use_i != std::numeric_limits<int>::max()) {
          memo[j] = use_i;
        }
        if (not_use_i != -1) {
          memo[j] = std::min(memo[j], not_use_i);
        }
      }
    }
    return memo[amount];
  }
};
// leetcode submit region end(Prohibit modification and deletion)
