//这里有 d 个一样的骰子，每个骰子上都有 f 个面，分别标号为 1, 2, ..., f。
//
// 我们约定：掷骰子的得到总点数为各骰子面朝上的数字的总和。
//
// 如果需要掷出的总点数为
// target，请你计算出有多少种不同的组合情况（所有的组合情况总共有 f^d 种），模
// 10^9 + 7 后返回。
//
//
//
// 示例 1：
//
// 输入：d = 1, f = 6, target = 3
//输出：1
//
//
// 示例 2：
//
// 输入：d = 2, f = 6, target = 7
//输出：6
//
//
// 示例 3：
//
// 输入：d = 2, f = 5, target = 10
//输出：1
//
//
// 示例 4：
//
// 输入：d = 1, f = 2, target = 3
//输出：0
//
//
// 示例 5：
//
// 输入：d = 30, f = 30, target = 500
//输出：222616187
//
//
//
// 提示：
//
//
// 1 <= d, f <= 30
// 1 <= target <= 1000
//
// Related Topics 动态规划
// 👍 90 👎 0

// leetcode submit region begin(Prohibit modification and deletion)

/// 分组背包
// 分组01背包的组合问题
// 如果所有物品被划分成 i 组，每组最多只能拿一个物品，
// 对于这里，每个筛子就是一组，每组可以选不同的点数 f（一个物品）
class Solution {
 public:
  int numRollsToTarget(int d, int f, int target) {
    int mod = 1e9 + 7;
    // 扔 [0...d] 个筛子得到点数 [0...target] 的方案数
    vector<int> dp(target + 1, 0);
    // 0 个筛子 只能得到 点数 0，方案为 1
    dp[0] = 1;
    // i 是 筛子个数循环，也就是组循环
    // j 是 目标 target 点数循环
    // k 是 每组物品数量
    for (int i = 1; i <= d; i++)
      for (int j = target; j >= i; j--) {
        // !! 注意这里需要置位
        dp[j] = 0;
        for (int k = 1; k <= std::min(f, j - i + 1); k++) {
          dp[j] = (dp[j] + dp[j - k]) % mod;
        }
      }
    return dp[target];
  }
};

/// 分组背包
// 分组01背包的组合问题
// 如果所有物品被划分成 i 组，每组最多只能拿一个物品，
// 对于这里，每个筛子就是一组，每组可以选不同的点数 f（一个物品）
class Solution1 {
 public:
  int numRollsToTarget(int d, int f, int target) {
    int mod = 1e9 + 7;
    // 扔 [0...d] 个筛子得到点数 [0...target] 的方案数
    vector<vector<int>> dp(d + 1, vector<int>(target + 1, 0));
    // 0 个筛子 只能得到 点数 0，方案为 1
    dp[0][0] = 1;
    // i 是 筛子个数循环，也就是组循环
    // j 是 目标 target 点数循环
    // k 是 每组物品数量
    for (int i = 1; i <= d; i++)
      for (int j = 1; j <= target; j++)
        for (int k = 1; k <= f; k++) {
          // 循环 k，看可以取出哪个物品（筛子的点数）来满足 target
          // 这里没有 dp[i][j] = dp[i-1][j]
          // 不能使用 点数 k：则 dp[i][j] 无需累加 dp[i-1][j-k]
          // 能使用 点数 k：则累加 dp[i-1][j-k]
          if (j >= k) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
          }
        }
    return dp[d][target];
  }
};
// leetcode submit region end(Prohibit modification and deletion)
