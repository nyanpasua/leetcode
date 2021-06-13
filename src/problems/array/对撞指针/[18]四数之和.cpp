/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

//给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums
//中是否存在四个元素 a，b，c 和 d ，使得 a + b + c +
// d 的值与 target 相等？找出所有满足条件且不重复的四元组。
//
// 注意：答案中不可以包含重复的四元组。
//
//
//
// 示例 1：
//
//
//输入：nums = [1,0,-1,0,-2,2], target = 0
//输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
//
//
// 示例 2：
//
//
//输入：nums = [], target = 0
//输出：[]
//
//
//
//
// 提示：
//
//
// 0 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109
//
// Related Topics 数组 哈希表 双指针
// 👍 873 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <algorithm>
#include <vector>
using std::vector;

/// 排序 + 双指针
// Time: O(N^3)
// Space: O(1) 也有一说为排序需要 O(logN) 的空间复杂度
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    if (nums.empty()) return {};
    int len = nums.size();
    if (len < 4) return {};
    // 从小到大排序
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < len - 3; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      for (int j = i + 1; j < len - 2; ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }
        int t = target - nums[i] - nums[j];
        int l = j + 1;
        int r = len - 1;
        while (l < r) {
          if (nums[l] + nums[r] == t) {
            res.push_back({nums[i], nums[j], nums[l], nums[r]});
            while (l < r && nums[l] == nums[l + 1]) ++l;  // 去重
            while (l < r && nums[r] == nums[r - 1]) --r;
            ++l;
            --r;
          } else if (nums[l] + nums[r] < t)
            ++l;
          else
            --r;
        }
      }
    }
    return res;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
