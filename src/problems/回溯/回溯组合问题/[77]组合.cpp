/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

//给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
//
// 示例:
//
// 输入: n = 4, k = 2
//输出:
//[
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
//]
// Related Topics 回溯算法
// 👍 601 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
using std::vector;
/// 回溯组合问题
class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<int> c{};
    dfs(c, 1, n, k);
    return res_;
  }

 private:
  vector<vector<int>> res_;
  // 从 [start, n] 找一个数字
  void dfs(vector<int> &c, int start, int n, int k) {
    // 递归到底
    if (c.size() == k) {
      // vector 满足组合条件
      res_.push_back(c);
      return;
    }
    for (int i = start; i <= n; ++i) {
      c.push_back(i);
      // 从 [i+1,n] 找一个数
      dfs(c, i + 1, n, k);
      c.pop_back();
    }
  }
};
// leetcode submit region end(Prohibit modification and deletion)
