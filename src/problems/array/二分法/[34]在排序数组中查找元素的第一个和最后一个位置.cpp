//给定一个按照升序排列的整数数组 nums，和一个目标值
// target。找出给定目标值在数组中的开始位置和结束位置。
//
// 如果数组中不存在目标值 target，返回 [-1, -1]。
//
// 进阶：
//
//
// 你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
//
//
//
//
// 示例 1：
//
//
//输入：nums = [5,7,7,8,8,10], target = 8
//输出：[3,4]
//
// 示例 2：
//
//
//输入：nums = [5,7,7,8,8,10], target = 6
//输出：[-1,-1]
//
// 示例 3：
//
//
//输入：nums = [], target = 0
//输出：[-1,-1]
//
//
//
// 提示：
//
//
// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
// nums 是一个非递减数组
// -109 <= target <= 109
//
// Related Topics 数组 二分查找
// 👍 1068 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    auto right = SearchRight(nums, target, 0, nums.size());
    auto left = SearchRight(nums, target - 1, 0, right);
    if (right <= left) return {-1, -1};
    return {left, right - 1};
  }

 private:
  int SearchRight(const vector<int>& nums, int target, size_t l, size_t r) {
    // 找右侧边界，开区间
    while (l < r) {
      auto mid = l + (r - l) / 2;
      if (nums[mid] <= target) {
        // 向右侧找
        l = mid + 1;
      } else {
        // 向左侧找
        r = mid;
      }
    }
    return static_cast<int>(r);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
