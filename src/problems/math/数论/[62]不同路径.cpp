//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
//
// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为
// “Finish” ）。
//
// 问总共有多少条不同的路径？
//
//
//
// 示例 1：
//
//
//输入：m = 3, n = 7
//输出：28
//
// 示例 2：
//
//
//输入：m = 3, n = 2
//输出：3
//解释：
//从左上角开始，总共有 3 条路径可以到达右下角。
// 1. 向右 -> 向下 -> 向下
// 2. 向下 -> 向下 -> 向右
// 3. 向下 -> 向右 -> 向下
//
//
// 示例 3：
//
//
//输入：m = 7, n = 3
//输出：28
//
//
// 示例 4：
//
//
//输入：m = 3, n = 3
//输出：6
//
//
//
// 提示：
//
//
// 1 <= m, n <= 100
// 题目数据保证答案小于等于 2 * 109
//
// Related Topics 数组 动态规划
// 👍 1027 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
using std::vector;

/// 数学方法
// 需要向下 m-1, 向右 n-1
// 组合问题，从 m+n-2 里面选 m-1 出来（或者从 m+n-2 里面选 n-1 出来）
class Solution {
 public:
  int uniquePaths(int m, int n) {
    if (m < n) {
      std::swap(m, n);
    }
    return combination(m + n - 2, n - 1) / combination(n - 1, n - 1);
  }

 private:
  uint64_t combination(uint64_t a, uint64_t times) {
    if (a == 0 || a == 1) return 1;
    if (times == 0) return 1;
    return a * combination(a - 1, times - 1);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
