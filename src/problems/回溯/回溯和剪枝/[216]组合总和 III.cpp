//找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9
//的正整数，并且每种组合中不存在重复的数字。
//
// 说明：
//
//
// 所有数字都是正整数。
// 解集不能包含重复的组合。
//
//
// 示例 1:
//
// 输入: k = 3, n = 7
//输出: [[1,2,4]]
//
//
// 示例 2:
//
// 输入: k = 3, n = 9
//输出: [[1,2,6], [1,3,5], [2,3,4]]
//
// Related Topics 数组 回溯
// 👍 324 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
using std::vector;
class Solution {
 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> c;
    recursion(k, 1, n, c);
    return res_;
  }
  void recursion(int k, int start, int sum, vector<int>& c) {
    if (sum == 0 && c.size() == k) {
      res_.push_back(c);
      return;
    }
    if (sum < 0 || c.size() > k) return;
    for (int i = start; i <= 9; ++i) {
      c.push_back(i);
      recursion(k, i + 1, sum - i, c);
      c.pop_back();
    }
  }

 private:
  vector<vector<int>> res_;
};
// leetcode submit region end(Prohibit modification and deletion)
