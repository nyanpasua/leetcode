//现有一个按 升序 排列的整数数组 nums ，其中每个数字都 互不相同 。
//
// 给你一个整数 k ，请你找出并返回从数组最左边开始的第 k 个缺失数字。
//
//
//
// 示例 1：
//
//
//输入：nums = [4,7,9,10], k = 1
//输出：5
//解释：第一个缺失数字为 5 。
//
//
// 示例 2：
//
//
//输入：nums = [4,7,9,10], k = 3
//输出：8
//解释：缺失数字有 [5,6,8,...]，因此第三个缺失数字为 8 。
//
//
// 示例 3：
//
//
//输入：nums = [1,2,4], k = 3
//输出：6
//解释：缺失数字有 [3,5,6,7,...]，因此第三个缺失数字为 6 。
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 5 * 104
// 1 <= nums[i] <= 107
// nums 按 升序 排列，其中所有元素 互不相同 。
// 1 <= k <= 108
//
//
//
//
// 进阶：你可以设计一个对数时间复杂度（即，O(log(n))）的解决方案吗？
// Related Topics 数组 二分查找
// 👍 71 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  int missingElement(vector<int>& nums, int k) {
    int n = nums.size();
    int left = 0, right = n - 1;
    // If kth missing number is larger than
    // the last element of the array
    if (k > missing(n - 1, nums)) return nums[n - 1] + k - missing(n - 1, nums);
    // [left...right]
    // nums = [4,7,9,10], k = 3, [5,6,8...]
    // find left = right index such that
    // missing(left - 1) < k <= missing(left)
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (missing(mid, nums) < k) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    // 7 + 3 - (7 - 4 - 1)
    return nums[left - 1] + k - missing(left - 1, nums);
  }

 private:
  // Return how many numbers are missing until nums[idx]
  int missing(int idx, vector<int>& nums) { return nums[idx] - nums[0] - idx; }
};
// leetcode submit region end(Prohibit modification and deletion)
