//给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。 
//
// 给你一个整数 n ，返回和为 n 的完全平方数的 最少数量 。 
//
// 完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。
// 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 12
//输出：3 
//解释：12 = 4 + 4 + 4 
//
// 示例 2： 
//
// 
//输入：n = 13
//输出：2
//解释：13 = 4 + 9 
// 
//
// 提示： 
//
// 
// 1 <= n <= 104 
// 
// Related Topics 广度优先搜索 数学 动态规划 
// 👍 892 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
using std::vector;

/// 动态规划，贪心是不行的
/// 完全背包最小值问题
// 物品是完全平方数 1,4,9,16...，来拼凑一个数字 n
class Solution {
 public:
  int numSquares(int n) {
    vector<int> memo(n + 1, 0);
    // 初始化&base case，全部由 1 来构成
    for (int i = 0; i <= n; ++i) {
      memo[i] = i;
    }
    // 状态转移迭代
    // 采用排列找最小值
    for (size_t i = 1; i <= n; ++i) {
      for (size_t j = 1; j * j <= i; ++j) {
        memo[i] = std::min(memo[i], memo[i - j * j] + 1);
      }
    }
    return memo[n];
  }
};
//leetcode submit region end(Prohibit modification and deletion)
