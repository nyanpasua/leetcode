/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

//给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得
//nums [i] = nums [j]，并且 i 和 j 的差的 绝对值
// 至多为 k。
//
//
//
// 示例 1:
//
// 输入: nums = [1,2,3,1], k = 3
//输出: true
//
// 示例 2:
//
// 输入: nums = [1,0,1,1], k = 1
//输出: true
//
// 示例 3:
//
// 输入: nums = [1,2,3,1,2,3], k = 2
//输出: false
// Related Topics 数组 哈希表
// 👍 277 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <unordered_map>
#include <vector>
using std::unordered_map;
using std::vector;
/// hash 表
class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    std::unordered_map<int, int> counter;
    for (size_t i = 0; i < nums.size(); ++i) {
      if (counter.find(nums[i]) != counter.end()) {
        if (i - counter[nums[i]] <= k) {
          return true;
        }
        counter[nums[i]] = i;
      } else {
        counter[nums[i]] = i;
      }
    }
    return false;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
