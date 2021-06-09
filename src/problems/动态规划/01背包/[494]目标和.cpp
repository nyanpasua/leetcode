//给你一个整数数组 nums 和一个整数 target 。
//
// 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式
// ：
//
//
// 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-'
// ，然后串联起来得到表达式 "+2-1" 。
//
//
// 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
//
//
//
// 示例 1：
//
//
//输入：nums = [1,1,1,1,1], target = 3
//输出：5
//解释：一共有 5 种方法让最终目标和为 3 。
//-1 + 1 + 1 + 1 + 1 = 3
//+1 - 1 + 1 + 1 + 1 = 3
//+1 + 1 - 1 + 1 + 1 = 3
//+1 + 1 + 1 - 1 + 1 = 3
//+1 + 1 + 1 + 1 - 1 = 3
//
//
// 示例 2：
//
//
//输入：nums = [1], target = 1
//输出：1
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 20
// 0 <= nums[i] <= 1000
// 0 <= sum(nums[i]) <= 1000
// -1000 <= target <= 100
//
// Related Topics 深度优先搜索 动态规划
// 👍 769 👎 0

// leetcode submit region begin(Prohibit modification and deletion)

#include <algorithm>
#include <numeric>
#include <vector>
using std::vector;

class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    for (int& num : nums) {
      sum += num;
    }
    int diff = sum - target;
    if (diff < 0 || diff % 2 != 0) {
      return 0;
    }
    int neg = diff / 2;
    vector<int> dp(neg + 1);
    dp[0] = 1;
    // 01背包，组合问题方案数，容量倒序，不能复用
    for (int& num : nums) {
      for (int j = neg; j >= num; j--) {
        dp[j] += dp[j - num];
      }
    }
    return dp[neg];
  }
};

/// 01背包
// 该问题可以转换为01背包问题，由于题目中给出 nums 为非负数，
// 相当于 给一批数字 加上 - 号，使得 sum(nums) = target，
// 也就是 sum - neg - neg = target，因此，
// neg = (sum - target)/2，且 neg 必须为整数，因此 sum-target 必须为偶数
// 因此问题转换为从 nums 里找到一组子集，使得其和为 neg，求满足条件的子集的数量
class Solution1 {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if ((sum - target) % 2 || sum - target < 0) return 0;
    int neg = (sum - target) / 2;
    // dp 数组定义
    // 表示使用 空集合 和 nums[0....i] 能满足 sum 为 [0...j...neg]
    // 空集合 dp[0][j]
    vector<vector<int>> dp(nums.size() + 1, vector<int>(neg + 1, 0));
    // base case
    // 使用 空集合 只能 满足 dp[0][0] = 1，dp[0][1...neg] = 0
    dp[0][0] = 1;

    // 状态转移
    // 组合问题方案数
    for (int i = 1; i <= nums.size(); ++i) {
      auto num = nums[i - 1];
      for (int j = 0; j <= neg; ++j) {
        // if num > j，则不能选 num，dp[i -1][j]
        // if num <= j，1.使用 num，dp[i-1][j - nums[i]]
        //              2.不使用 num，dp[i - 1][j]
        if (num > j)
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = dp[i - 1][j - num] + dp[i - 1][j];
      }
    }
    return dp[nums.size()][neg];
  }
};
// leetcode submit region end(Prohibit modification and deletion)
