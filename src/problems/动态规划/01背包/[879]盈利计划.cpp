//集团里有 n 名员工，他们可以完成各种各样的工作创造利润。
//
// 第 i 种工作会产生 profit[i] 的利润，它要求 group[i]
// 名成员共同参与。如果成员参与了其中一项工作，就不能参与另一项工作。
//
// 工作的任何至少产生 minProfit 利润的子集称为 盈利计划
// 。并且工作的成员总数最多为 n 。
//
// 有多少种计划可以选择？因为答案很大，所以 返回结果模 10^9 + 7 的值。
//
//
//
//
//
// 示例 1：
//
//
//输入：n = 5, minProfit = 3, group = [2,2], profit = [2,3]
//输出：2
//解释：至少产生 3 的利润，该集团可以完成工作 0 和工作 1 ，或仅完成工作 1 。
//总的来说，有两种计划。
//
// 示例 2：
//
//
//输入：n = 10, minProfit = 5, group = [2,3,5], profit = [6,7,8]
//输出：7
//解释：至少产生 5
//的利润，只要完成其中一种工作就行，所以该集团可以完成任何工作。 有 7
//种可能的计划：(0)，(1)，(2)，(0,1)，(0,2)，(1,2)，以及 (0,1,2) 。
//
//
//
//
//
// 提示：
//
//
// 1 <= n <= 100
// 0 <= minProfit <= 100
// 1 <= group.length <= 100
// 1 <= group[i] <= 100
// profit.length == group.length
// 0 <= profit[i] <= 100
//
// Related Topics 动态规划
// 👍 123 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
using std::vector;

/// 多维01背包，方案数量问题
class Solution {
 public:
  int profitableSchemes(int n, int minProfit, vector<int>& group,
                        vector<int>& profit) {
    // 两维为限制条件，最多使用 n 个人，最少利润为 minProfit
    // 注意，这里定义的是最多 n 个人，而不是 恰好使用 n 个人
    vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1));
    for (int i = 0; i <= n; i++) {
      dp[i][0] = 1;
    }
    int len = group.size(), MOD = 1e9 + 7;
    for (int i = 1; i <= len; i++) {
      int members = group[i - 1], earn = profit[i - 1];
      for (int j = n; j >= members; j--) {
        for (int k = minProfit; k >= 0; k--) {
          dp[j][k] = (dp[j][k] + dp[j - members][max(0, k - earn)]) % MOD;
        }
      }
    }
    // 为什么这里不需要求和
    return dp[n][minProfit];
  }
};

/// 多维01背包，方案数量问题
class Solution2 {
 public:
  int profitableSchemes(int n, int minProfit, vector<int>& group,
                        vector<int>& profit) {
    int len = group.size(), mod = 1e9 + 7;
    // dp 数组，第一维为 len，第二维为 n，第三维为 minProfit
    // 第一维为物品，后面两维为限制条件，使用 n 个人，最少利润为 minProfit
    vector<vector<vector<int>>> dp(
        len + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, 0)));
    // 使用空集合 即可使用 任意 人 都能拿到 0 利润，方案数 为 1
    for (int i = 0; i <= n; i++) dp[0][i][0] = 1;
    for (int i = 1; i <= len; ++i) {
      auto num = group[i - 1];
      auto fit = profit[i - 1];
      for (int j = 0; j <= n; ++j) {
        for (int k = 0; k <= minProfit; ++k) {
          // 不使用 工作 <num fit>
          dp[i][j][k] = dp[i - 1][j][k];
          // 使用工作 <num fit>
          if (j >= num) {
            // 由于我们定义的第三维是工作利润至少为 k 而不是 工作利润恰好为 k，
            // 因此上述状态转移方程中右侧的第三维是 max(0,k−profit[i])
            // 而不是 k−profit[i]。
            // 相当于就是把 “只做第 i 项工作就能达到利润k” 这个情况考虑到了
            dp[i][j][k] =
                (dp[i][j][k] + dp[i - 1][j - num][max(0, k - fit)]) % mod;
          }
        }
      }
    }
    return dp[len][n][minProfit];
  }
};

/// 多维01背包，方案数量问题
class Solution1 {
 public:
  int profitableSchemes(int n, int minProfit, vector<int>& group,
                        vector<int>& profit) {
    int len = group.size(), mod = 1e9 + 7;
    // dp 数组，第一维为 len，第二维为 n，第三维为 minProfit
    // 第一维为物品，后面两维为限制条件，使用 n 个人，最少利润为 minProfit
    vector<vector<vector<int>>> dp(
        len + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, 0)));
    // 使用空集合 即可使用 0 人 拿到 0 利润，方案数 为 1
    dp[0][0][0] = 1;
    for (int i = 1; i <= len; ++i) {
      auto num = group[i - 1];
      auto fit = profit[i - 1];
      for (int j = 0; j <= n; ++j) {
        for (int k = 0; k <= minProfit; ++k) {
          // 不使用 工作 <num fit>
          dp[i][j][k] = dp[i - 1][j][k];
          // 使用工作 <num fit>
          if (j >= num) {
            // 由于我们定义的第三维是工作利润至少为 k 而不是 工作利润恰好为 k，
            // 因此上述状态转移方程中右侧的第三维是 max(0,k−profit[i])
            // 而不是 k−profit[i]。
            // 相当于就是把 “只做第 i 项工作就能达到利润k” 这个情况考虑到了
            dp[i][j][k] =
                (dp[i][j][k] + dp[i - 1][j - num][max(0, k - fit)]) % mod;
          }
        }
      }
    }
    int sum = 0;
    for (int j = 0; j <= n; j++) {
      sum = (sum + dp[len][j][minProfit]) % mod;
    }
    return sum;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
