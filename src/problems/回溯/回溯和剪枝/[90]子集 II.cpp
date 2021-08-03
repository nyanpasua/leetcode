//给你一个整数数组 nums
//，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
//
// 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
//
//
//
//
//
// 示例 1：
//
//
//输入：nums = [1,2,2]
//输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
//
//
// 示例 2：
//
//
//输入：nums = [0]
//输出：[[],[0]]
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
//
//
//
// Related Topics 位运算 数组 回溯
// 👍 621 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
using std::vector;

/// 组合问题
class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    vector<int> ans;
    recursion(nums, 0, ans);
    return res_;
  }

 private:
  void recursion(vector<int>& nums, int start, vector<int>& ans) {
    res_.push_back(ans);
    if (start >= nums.size()) return;
    for (int i = start; i < nums.size(); ++i) {
      // 去重
      if (i > start && nums[i] == nums[i - 1]) continue;
      ans.push_back(nums[i]);
      recursion(nums, i + 1, ans);
      ans.pop_back();
    }
  }
  vector<vector<int>> res_;
};
// leetcode submit region end(Prohibit modification and deletion)
