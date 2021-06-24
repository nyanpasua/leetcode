//给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。请你找出所有在
//[1, n] 范围内但没有出现在 nums 中的数 字，并以数组的形式返回结果。
//
//
//
// 示例 1：
//
//
//输入：nums = [4,3,2,7,8,2,3,1]
//输出：[5,6]
//
//
// 示例 2：
//
//
//输入：nums = [1,1]
//输出：[2]
//
//
//
//
// 提示：
//
//
// n == nums.length
// 1 <= n <= 105
// 1 <= nums[i] <= n
//
//
// 进阶：你能在不使用额外空间且时间复杂度为 O(n) 的情况下解决这个问题吗?
// 你可以假定返回的数组不算在额外空间内。 Related Topics 数组 👍 760 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <algorithm>
#include <vector>
using std::vector;

/// 原地交换排序
// 由于 1-n 的数字范围，如果都出现，则是 index 和 value 一一对应的
// 原地交换排序，如果出现重复的数字，就置位为 -1，最后统计 -1 位置的 index 即可
class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    size_t i = 0;
    vector<int> res;
    while (i < nums.size()) {
      // 处理 nums[i]
      if (nums[i] - 1 == i || nums[i] == -1) {
        ++i;
        continue;
      }
      if (nums[i] == nums[nums[i] - 1]) {
        // 出现重复数字
        nums[i] = -1;
        ++i;
        continue;
      }
      std::swap(nums[i], nums[nums[i] - 1]);
    }
    // 统计 -1 的 index
    for (int j = 0; j < nums.size(); ++j) {
      if (nums[j] == -1) {
        res.push_back(j + 1);
      }
    }
    return res;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
