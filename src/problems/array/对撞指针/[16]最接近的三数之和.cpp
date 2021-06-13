/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

//给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums
//中的三个整数，使得它们的和与 target 最接近。返回这三个数的和
//。假定每组输入只存在唯一答案。
//
//
//
// 示例：
//
// 输入：nums = [-1,2,1,-4], target = 1
//输出：2
//解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
//
//
//
//
// 提示：
//
//
// 3 <= nums.length <= 10^3
// -10^3 <= nums[i] <= 10^3
// -10^4 <= target <= 10^4
//
// Related Topics 数组 双指针
// 👍 797 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <algorithm>
#include <limits>
#include <vector>
using std::vector;
/// 排序 + 双指针
// 由于此题的暴力解法需要 3 重循环，因此排序一次似乎完全可以接受
// 排序后，外层循环 O(N)，内两层循环可以用双指针 O(N)
// Time: O(N^2)
// Space: O(1)，也有一说为排序需要 O(logN) 的空间复杂度
class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    // 此题保证 len >= 3
    int len = nums.size();
    // 从小到大排序
    std::sort(nums.begin(), nums.end());
    int res = std::numeric_limits<int>::max() - std::abs(target);
    auto update = [&res, target](int cur) {
      if (std::abs(cur - target) < std::abs(res - target)) {
        res = cur;
      }
    };
    for (int i = 0; i < nums.size(); ++i) {
      // 外层循环
      // 去重，保证不会找到重复的 nums[i]
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      // 使用双指针找 最接近 target 的组合
      // 目标是找到离 target - nums[i] 最接近的两个数
      int l = i + 1;
      int r = len - 1;
      // 在范围 [l...r] 内找两个数 2sum
      while (l < r) {
        int cur_sum = nums[i] + nums[l] + nums[r];
        if (cur_sum == target) return target;
        update(cur_sum);
        if (cur_sum > target) {
          // 去重
          while (l < r && nums[r] == nums[r - 1]) --r;
          --r;
        } else {
          // cur_sum < target
          while (l < r && nums[l] == nums[l + 1]) ++l;
          ++l;
        }
      }
    }
    return res;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
