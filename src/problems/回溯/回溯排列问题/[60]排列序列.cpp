/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

//给出集合 [1,2,3,...,n]，其所有元素共有 n! 种排列。
//
// 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
//
//
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
//
//
// 给定 n 和 k，返回第 k 个排列。
//
//
//
// 示例 1：
//
//
//输入：n = 3, k = 3
//输出："213"
//
//
// 示例 2：
//
//
//输入：n = 4, k = 9
//输出："2314"
//
//
// 示例 3：
//
//
//输入：n = 3, k = 1
//输出："123"
//
//
//
//
// 提示：
//
//
// 1 <= n <= 9
// 1 <= k <= n!
//
// Related Topics 数学 回溯算法
// 👍 532 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <string>
using std::string;

/// 回溯 + 剪枝
// 统计次数，当递归到第 k 次时返回
// 此题还可以进一步剪枝，比如当递归到某一个分支时，可以通过计算阶乘，来判断是否可以直接跳过
class Solution {
 public:
  string getPermutation(int n, int k) {}
};

/// 回溯
// 统计次数，当递归到第 k 次时返回
class Solution {
 public:
  string getPermutation(int n, int k) {
    int min = 0;
    for (int i = 1; i <= n; ++i) {
      min = min * 10 + i;
    }
    auto s = std::to_string(min);
    k_ = k;
    dfs(s, 0);
    return res_;
  }

 private:
  void dfs(string s, size_t index) {
    // 提前终止
    if (count_ > k_) return;
    // 递归到底，index 为最后一个字母的索引
    if (index == s.size() - 1) {
      count_++;
      // 第 k 次进入
      if (count_ == k_) {
        res_ = s;
      }
      // 前面的字母都已经固定，因此直接返回
      return;
    }
    for (size_t i = index; i < s.size(); ++i) {
      // 这里要特别注意控制 s 交换后有序
      // 1234 2134 !!3214!! !!4231!!
      // 可以发现后面的都无序
      for (int j = i; j > index; --j) {
        std::swap(s[j], s[j - 1]);
      }
      dfs(s, index + 1);
      for (int j = index; j < i; ++j) {
        std::swap(s[j], s[j + 1]);
      }
    }
  }
  string res_;
  int k_{0};
  int count_{0};
};
// leetcode submit region end(Prohibit modification and deletion)
