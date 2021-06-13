/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

//给定一个包含红色、白色和蓝色，一共 n
//个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
//
// 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
//
//
//
//
//
//
// 示例 1：
//
//
//输入：nums = [2,0,2,1,1,0]
//输出：[0,0,1,1,2,2]
//
//
// 示例 2：
//
//
//输入：nums = [2,0,1]
//输出：[0,1,2]
//
//
// 示例 3：
//
//
//输入：nums = [0]
//输出：[0]
//
//
// 示例 4：
//
//
//输入：nums = [1]
//输出：[1]
//
//
//
//
// 提示：
//
//
// n == nums.length
// 1 <= n <= 300
// nums[i] 为 0、1 或 2
//
//
//
//
// 进阶：
//
//
// 你可以不使用代码库中的排序函数来解决这道题吗？
// 你能想出一个仅使用常数空间的一趟扫描算法吗？
//
// Related Topics 排序 数组 双指针
// 👍 913 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
using std::vector;

/// 快排 partition
class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int lt = -1;
    int eq = 0;
    int gt = nums.size();
    int i = 0;
    // nums[0...lt] < 1, nums[lt + 1, i) = 1, nums[gt, size-1] > 1
    while (i < gt) {
      if (nums[i] > 1) {
        std::swap(nums[--gt], nums[i]);
      } else if (nums[i] < 1) {
        std::swap(nums[++lt], nums[i++]);
      } else {
        ++i;
      }
    }
  }
};
// leetcode submit region end(Prohibit modification and deletion)
