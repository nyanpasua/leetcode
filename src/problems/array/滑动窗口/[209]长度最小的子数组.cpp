/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

//给定一个含有 n 个正整数的数组和一个正整数 target 。
//
// 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ...,
// numsr-1, numsr] ，并返回其长
//度。如果不存在符合条件的子数组，返回 0 。
//
//
//
// 示例 1：
//
//
//输入：target = 7, nums = [2,3,1,2,4,3]
//输出：2
//解释：子数组 [4,3] 是该条件下的长度最小的子数组。
//
//
// 示例 2：
//
//
//输入：target = 4, nums = [1,4,4]
//输出：1
//
//
// 示例 3：
//
//
//输入：target = 11, nums = [1,1,1,1,1,1,1,1]
//输出：0
//
//
//
//
// 提示：
//
//
// 1 <= target <= 109
// 1 <= nums.length <= 105
// 1 <= nums[i] <= 105
//
//
//
//
// 进阶：
//
//
// 如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n))
// 时间复杂度的解法。
//
// Related Topics 数组 双指针 二分查找
// 👍 656 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <algorithm>
#include <limits>
#include <vector>
using std::vector;

/// 滑动窗
// 此题与动态规划里 连续子数组问题 很相似，但是实际上只需要滑动窗即可解决
class Solution {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int i = 0, j = 0;
    int sum = 0;
    int minlen = std::numeric_limits<int>::max();
    // [i,j]为滑动窗, i,j为当前考察的元素
    while (j <= nums.size() && i < nums.size()) {
      if (sum < s) {
        if (j < nums.size()) {
          sum += nums[j++];
        } else {
          break;
        }
      } else {
        minlen = std::min((j - i), minlen);
        sum -= nums[i++];
      }
    }
    return minlen == std::numeric_limits<int>::max() ? 0 : minlen;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
