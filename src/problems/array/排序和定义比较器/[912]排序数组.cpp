//给你一个整数数组 nums，请你将该数组升序排列。
//
//
//
//
//
//
// 示例 1：
//
// 输入：nums = [5,2,3,1]
//输出：[1,2,3,5]
//
//
// 示例 2：
//
// 输入：nums = [5,1,1,2,0,0]
//输出：[0,0,1,1,2,5]
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 50000
// -50000 <= nums[i] <= 50000
//
// Related Topics 数组 分治 桶排序 计数排序 基数排序 排序 堆（优先队列）
// 归并排序 👍 315 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    vector<int> sorted(nums);
    std::sort(sorted.begin(), sorted.end());
    return sorted;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
