//给你一个整数数组 nums ，你需要找出一个 连续子数组
//，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
//
// 请你找出符合题意的 最短 子数组，并输出它的长度。
//
//
//
//
//
// 示例 1：
//
//
//输入：nums = [2,6,4,8,10,9,15]
//输出：5
//解释：你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
//
//
// 示例 2：
//
//
//输入：nums = [1,2,3,4]
//输出：0
//
//
// 示例 3：
//
//
//输入：nums = [1]
//输出：0
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 104
// -105 <= nums[i] <= 105
//
//
//
//
// 进阶：你可以设计一个时间复杂度为 O(n) 的解决方案吗？
//
//
// Related Topics 栈 贪心 数组 双指针 排序 单调栈
// 👍 550 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <algorithm>
#include <limits>
#include <vector>
using std::vector;

/// 选择排序思路
// 实际上，我们需要找到无序序列的最大和最小值，将其放到正确的位置，就是答案
// 而从左到右，只有下降的区间才会出现最小值，从右到左，只有上升的区间才会出现最大值
// Time: O(N)
// Space: O(1)
class Solution {
 public:
  int findUnsortedSubarray(vector<int>& nums) {
    if (nums.size() <= 1) return 0;
    int min = std::numeric_limits<int>::max();
    int max = std::numeric_limits<int>::min();
    // 从左到右遍历，找到 min
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] < nums[i - 1]) {
        min = std::min(min, nums[i]);
      }
    }
    // 从右至左遍历，找到 max
    for (int i = nums.size() - 2; i >= 0; --i) {
      if (nums[i] > nums[i + 1]) {
        max = std::max(max, nums[i]);
      }
    }
    // max 和 min 没有变化，那么返回 0
    if (max == std::numeric_limits<int>::max()) return 0;
    // 找 max 和 min 的正确位置
    int left = nums.size(), right = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > min) {
        left = i;
        break;
      }
    }
    for (int i = nums.size() - 1; i >= 0; --i) {
      if (nums[i] < max) {
        right = i;
        break;
      }
    }
    return right - left > 0 ? right - left + 1 : 0;
  }
};
/// 排序
// 思路很简单，不妨排序之后，判断两侧不同的位置
// Time: O(NlogN)
// Space: O(N)
class Solution1 {
 public:
  int findUnsortedSubarray(vector<int>& nums) {
    if (nums.size() <= 1) return 0;
    auto nums_sorted(nums);
    std::sort(nums_sorted.begin(), nums_sorted.end());
    int left = nums.size(), right = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != nums_sorted[i]) {
        // left 取 min，right 取 max
        left = std::min(i, left);
        right = std::max(i, right);
      }
    }
    return right - left > 0 ? right - left + 1 : 0;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
