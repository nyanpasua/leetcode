//给定一个数组 candidates 和一个目标数 target ，找出 candidates
//中所有可以使数字和为 target 的组合。
//
// candidates 中的每个数字在每个组合中只能使用一次。
//
// 注意：解集不能包含重复的组合。
//
//
//
// 示例 1:
//
//
//输入: candidates = [10,1,2,7,6,1,5], target = 8,
//输出:
//[
//[1,1,6],
//[1,2,5],
//[1,7],
//[2,6]
//]
//
// 示例 2:
//
//
//输入: candidates = [2,5,2,1,2], target = 5,
//输出:
//[
//[1,2,2],
//[5]
//]
//
//
//
// 提示:
//
//
// 1 <= candidates.length <= 100
// 1 <= candidates[i] <= 50
// 1 <= target <= 30
//
// Related Topics 数组 回溯
// 👍 647 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
using std::vector;

/// 回溯组合问题
// 对结果进行 push 和 pop 操作即可
class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    vector<int> c;
    recursion(candidates, 0, target, c);
    return res_;
  }

  void recursion(const vector<int>& candidates, int start, int target,
                 vector<int>& ans) {
    if (target == 0) {
      // 获得一个可行解
      res_.push_back(ans);
      return;
    }
    if (start >= candidates.size() || target < 0) return;
    for (int i = start; i < candidates.size(); ++i) {
      // 去重
      if (i > start && candidates[i] == candidates[i - 1]) continue;
      // 从 [start...] 选择此次使用的数字
      ans.push_back(candidates[i]);
      // start 使用 i + 1，不可重复使用
      recursion(candidates, i + 1, target - candidates[i], ans);
      ans.pop_back();
    }
  }

 private:
  vector<vector<int>> res_;
};
// leetcode submit region end(Prohibit modification and deletion)
