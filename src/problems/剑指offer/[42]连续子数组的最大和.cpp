// 输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
// 输出: 6
// 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

#include <vector>
using std::vector;

/// 动态规划
/// 设动态规划列表 dp ，dp[i] 代表以元素 nums[i]
/// 为结尾的连续子数组最大和。
//
// 为何定义最大和 dp[i] 中必须包含元素 nums[i] ：保证 dp[i]
// 递推到 dp[i+1] 的正确性；如果不包含 nums[i]
// ，递推时则不满足题目的 连续子数组 要求。
//

/// Time: O(n)
/// Space: O(n), 也可以降为 O(1)，因为 dp[i] 只与前面的 dp[i - 1] 有关
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    std::vector<int> dp(nums.size());
    // base case
    dp[0] = nums[0];
    int max = dp[0];
    // 状态转移方程
    // dp[i] = nums[i], if dp[i - 1] <= 0
    // dp[i] = nums[i] + dp[i - 1], if dp[i - 1] > 0
    for (size_t i = 1; i < nums.size(); ++i) {
      if (dp[i - 1] <= 0) {
        dp[i] = nums[i];
      } else {
        dp[i] = nums[i] + dp[i - 1];
      }
      if (dp[i] > max) {
        max = dp[i];
      }
    }
    return max;
  }
};