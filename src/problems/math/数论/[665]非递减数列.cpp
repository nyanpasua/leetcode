/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */

//给你一个长度为 n 的整数数组，请你判断在 最多 改变 1
//个元素的情况下，该数组能否变成一个非递减数列。
//
// 我们是这样定义一个非递减数列的： 对于数组中任意的 i (0 <= i <= n-2)，总满足
// nums[i] <= nums[i + 1]。
//
//
//
// 示例 1:
//
//
//输入: nums = [4,2,3]
//输出: true
//解释: 你可以通过把第一个4变成1来使得它成为一个非递减数列。
//
//
// 示例 2:
//
//
//输入: nums = [4,2,1]
//输出: false
//解释: 你不能在只改变一个元素的情况下将其变为非递减数列。
//
//
//
//
// 提示：
//
//
// 1 <= n <= 10 ^ 4
// - 10 ^ 5 <= nums[i] <= 10 ^ 5
//
// Related Topics 数组
// 👍 593 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
using std::vector;
// [3,4,2,7] [2,4,2,3]
// a[i] > a[i+1] 时，可以改动 a[i] 也可以改动 a[i+1]
// 如果 a[i-1] <= a[i+1], 则修改 a[i] = a[i-1]即可 : [2,3,2,4] -> [2,2,2,4]
// 如果 a[i-1] > a[i+1], 则修改 a[i+1] = a[i] : [3,3,2,4] -> [3,3,3,4]
// [3,2,1] 无论怎样修改都无法满足条件，因此 最多 只有一个 a[i] > a[i+1]
// 流程
// 1. x = a[i], y = a[i+1]
// 2. if x > y { count++ if (y < a[i-1]) a[i+1]=x }
// 3. 如果 count > 1，则返回 false
class Solution {
 public:
  bool checkPossibility(vector<int>& nums) {
    int count = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
      int x = nums[i], y = nums[i + 1];
      if (x > y) {
        ++count;
        if (count > 1) return false;
        if (i > 0 && y < nums[i - 1]) {
          // 修改 a[i+1] = a[i]，为了统计下一次的逆序对
          nums[i + 1] = x;
        }
      }
    }
    return true;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
