//
// Created by liyingmin on 2020/3/29.
//
// 给定一个整数数组 nums
// ，找到一个具有最大和的连续子数组（子数组最少包含一个元素）， 返回其最大和。
// 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
//输出：6
//解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
#include <vector>
using std::vector;
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    if (nums.size() == 1) {
      return nums[0];
    }
    // 定义 memo[i] 为包含 nums[i] 的最大子序列和
    vector<int> memo(nums.size(), 0);
    // base case:
    memo[0] = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
      //      if (memo[i - 1] > 0) {
      //        // 如果上一个记忆和 > 0，则说明对 nums[i] 有正贡献
      //        memo[i] = memo[i - 1] + nums[i];
      //      } else {
      //        memo[i] = nums[i];
      //      }
      // 上述代码可以简化为
      memo[i] = std::max(memo[i - 1] + nums[i], nums[i]);
    }
    return *(std::max_element(memo.begin(), memo.end()));
  }
};