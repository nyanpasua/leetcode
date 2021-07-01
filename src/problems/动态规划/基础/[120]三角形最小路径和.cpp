/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

//给定一个三角形 triangle ，找出自顶向下的最小路径和。
//
// 每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与
// 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，如果
//正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。
//
//
//
// 示例 1：
//
//
//输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
//输出：11
//解释：如下面简图所示：
//   2
//  3 4
// 6 5 7
// 4 1 8 3
//自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
//
//
// 示例 2：
//
//
//输入：triangle = [[-10]]
//输出：-10
//
//
//
//
// 提示：
//
//
// 1 <= triangle.length <= 200
// triangle[0].length == 1
// triangle[i].length == triangle[i - 1].length + 1
// -104 <= triangle[i][j] <= 104
//
//
//
//
// 进阶：
//
//
// 你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题吗？
//
// Related Topics 数组 动态规划
// 👍 784 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    // 从三角形顶部走到位置 (i, j) 的最小路径和。
    // 这里的位置 (i, j) 指的是三角形中第 i 行第 j 列（均从 0开始编号）的位置
    vector<vector<int>> f(n, vector<int>(n));
    // 在三角形的顶部时，最小路径和就等于对应位置的元素值。
    // 这样一来，我们从 1 开始递增地枚举 i，
    // 并在 [0, i] 的范围内递增地枚举 j，就可以完成所有状态的计算。
    f[0][0] = triangle[0][0];
    for (int i = 1; i < n; ++i) {
      // 第 i 行有 i+1 个元素，它们对应的 j 的范围为 [0, i]。
      // 当 j == 0, f[i - 1][j - 1] 无意义
      f[i][0] = f[i - 1][0] + triangle[i][0];
      for (int j = 1; j < i; ++j) {
        // 每一步只能移动到下一行「相邻的节点」上，因此要想走到位置 (i, j)，
        // 上一步就只能在位置 (i - 1, j - 1) 或者位置 (i - 1, j)。
        // 我们在这两个位置中选择一个路径和较小的来进行转移
        f[i][j] = min(f[i - 1][j - 1], f[i - 1][j]) + triangle[i][j];
      }
      // 当 j=i 时，f[i-1][j] 没有意义
      f[i][i] = f[i - 1][i - 1] + triangle[i][i];
    }
    return *min_element(f[n - 1].begin(), f[n - 1].end());
  }
};
// leetcode submit region end(Prohibit modification and deletion)
