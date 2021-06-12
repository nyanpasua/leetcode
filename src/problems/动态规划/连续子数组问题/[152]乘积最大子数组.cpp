/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

//给你一个整数数组 nums
//，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
//
//
//
// 示例 1:
//
// 输入: [2,3,-2,4]
//输出: 6
//解释: 子数组 [2,3] 有最大乘积 6。
//
//
// 示例 2:
//
// 输入: [-2,0,-1]
//输出: 0
//解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
// Related Topics 数组 动态规划
// 👍 1138 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <algorithm>
#include <numeric>
#include <vector>
using std::vector;

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    if (nums.size() == 1) return nums.front();
    // 定义 dp_min[i] 为 以 nums[i] 为结尾的连续子数组的最大乘积
    //    vector<int> dp_min(nums.size(), 0);
    //    vector<int> dp_max(nums.size(), 0);
    //    dp_min[0] = nums[0];
    //    dp_max[0] = nums[0];
    // 上述初始化可以简写为
    vector<int> dp_min(nums);
    vector<int> dp_max(nums);
    for (size_t i = 1; i < nums.size(); ++i) {
      auto num = nums[i];
      dp_max[i] = std::max({dp_max[i - 1] * num, dp_min[i - 1] * num, num});
      dp_min[i] = std::min({dp_min[i - 1] * num, dp_max[i - 1] * num, num});
    }
    return *(std::max_element(dp_max.begin(), dp_max.end()));
  }
};
// leetcode submit region end(Prohibit modification and deletion)
