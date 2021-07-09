//给你一个整数 n ，请你找出并返回第 n 个 丑数 。
//
// 丑数 就是只包含质因数 2、3 和/或 5 的正整数。
//
//
//
// 示例 1：
//
//
//输入：n = 10
//输出：12
//解释：[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。
//
//
// 示例 2：
//
//
//输入：n = 1
//输出：1
//解释：1 通常被视为丑数。
//
//
//
//
// 提示：
//
//
// 1 <= n <= 1690
//
// Related Topics 哈希表 数学 动态规划 堆（优先队列）
// 👍 685 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  int nthUglyNumber(int n) {
    std::vector<int> memo(n, 0);
    memo[0] = 1;
    int a = 0, b = 0, c = 0;
    for (int i = 1; i < n; ++i) {
      memo[i] = std::min({memo[a] * 2, memo[b] * 3, memo[c] * 5});
      if (memo[i] >= memo[a] * 2) ++a;
      if (memo[i] >= memo[b] * 3) ++b;
      if (memo[i] >= memo[c] * 5) ++c;
    }
    return memo[n - 1];
  }
};
// leetcode submit region end(Prohibit modification and deletion)
