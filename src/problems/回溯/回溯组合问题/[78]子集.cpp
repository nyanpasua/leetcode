//给你一个整数数组 nums ，数组中的元素 互不相同
//。返回该数组所有可能的子集（幂集）。
//
// 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
//
//
//
// 示例 1：
//
//
//输入：nums = [1,2,3]
//输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
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
// nums 中的所有元素 互不相同
//
// Related Topics 位运算 数组 回溯算法
// 👍 1225 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
using std::vector;

class Solution {
 public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<int> c;
    for (int i = 0; i <= nums.size(); ++i) {
      dfs(nums, i, 0, c);
    }
    return res_;
  }

 private:
  // 从给定集合里 找组合，组合长度为 k，从 nums[start...] 开始
  void dfs(vector<int> &nums, int k, int start, vector<int> &c) {
    if (c.size() == k) {
      res_.push_back(c);
      return;
    }
    for (int i = start; i < nums.size(); ++i) {
      c.push_back(nums[i]);
      dfs(nums, k, i + 1, c);
      c.pop_back();
    }
  }
  vector<vector<int>> res_;
};
// leetcode submit region end(Prohibit modification and deletion)
