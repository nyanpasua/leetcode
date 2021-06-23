//给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树
//有多少种？返回满足题意的二叉搜索树的种数。
//
//
//
// 示例 1：
//
//
//输入：n = 3
//输出：5
//
//
// 示例 2：
//
//
//输入：n = 1
//输出：1
//
//
//
//
// 提示：
//
//
// 1 <= n <= 19
//
// Related Topics 树 动态规划
// 👍 1198 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
/// 数学+动态规划
// 卡特兰数公式
// 设 n 个数的节点可以构成的二叉搜索树 为 f(n) 种
// f(0) = 1, f(1) = 1
// 那么 f(2) = 以 1 为根节点的数量 + 以 2 为根节点的数量
// 以 1 为根节点的数量为 左侧只能是 f(0) 种，右侧可以用一个数字 2，也就是 f(1)
// 种 以 2 为根节点的数量为 左侧要用一个数字 1，也就是 f(1) 种，右侧只能是 f(0)
// 种 f(2) = f(0)*f(1) + f(1)*f(0) 同理，f(3) = f(0)*f(2) + f(1)*f(1) +
// f(2)*f(0) f(n) = f(0)*f(n-1) + f(1)*f(n-2) +...+ f(n-1)*f(0)
class Solution {
 public:
  int numTrees(int n) {
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= n; i++)
      for (int j = 1; j <= i; j++) dp[i] += dp[j - 1] * dp[i - j];
    return dp[n];
  }
};
// leetcode submit region end(Prohibit modification and deletion)
