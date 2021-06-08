//给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。 
//
// 说明：每次只能向下或者向右移动一步。 
//
// 
//
// 示例 1： 
//
// 
//输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
//输出：7
//解释：因为路径 1→3→1→1→1 的总和最小。
// 
//
// 示例 2： 
//
// 
//输入：grid = [[1,2,3],[4,5,6]]
//输出：12
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 200 
// 0 <= grid[i][j] <= 100 
// 
// Related Topics 数组 动态规划 
// 👍 896 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
using std::vector;
/// 动态规划
class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    if (grid.empty()) {
      return 0;
    }
    size_t height = grid.size();
    size_t width = grid[0].size();
    // 初始化memo矩阵
    vector<vector<int>> memo(height, vector<int>(width, -1));
    // base case
    memo[0][0] = grid[0][0];
    // base case, height方向
    for (size_t i = 1; i < height; ++i) {
      memo[i][0] = memo[i - 1][0] + grid[i][0];
    }
    // base case, width方向
    for (size_t j = 1; j < width; ++j) {
      memo[0][j] = memo[0][j - 1] + grid[0][j];
    }
    // 状态转移迭代求解
    for (size_t i = 1; i < height; ++i) {
      for (size_t j = 1; j < width; ++j) {
        memo[i][j] = std::min(memo[i - 1][j], memo[i][j - 1]) + grid[i][j];
      }
    }
    return memo[height - 1][width - 1];
  }
};

// 回溯方式：使用暴力递归
class Solution1 {
 private:
  size_t height_;
  size_t width_;
  // 判断(x, y)是否在矩形范围内
  bool isArea(int x, int y) {
    return x >= 0 && x < height_ && y >= 0 && y < width_;
  }
  // 右下顺序的位置偏移量，顺时针方向
  vector<vector<int>> pos_offset{{0, 1}, {1, 0}};
  int searchPath(const vector<vector<int>>& grid, int x, int y) {
    if (x == height_ - 1 && y == width_ - 1) {
      return grid[height_ - 1][width_ - 1];
    }
    vector<vector<int>> new_xy{{x + pos_offset[0][0], y + pos_offset[0][1]},
                               {x + pos_offset[1][0], y + pos_offset[1][1]}};
    // 向右走
    int sum_right{0};
    if (isArea(new_xy[0][0], new_xy[0][1])) {
      sum_right = searchPath(grid, new_xy[0][0], new_xy[0][1]) + grid[x][y];
    } else {
      sum_right = INT_MAX;
    }
    // 向下走
    int sum_down{0};
    if (isArea(new_xy[1][0], new_xy[1][1])) {
      sum_down = searchPath(grid, new_xy[1][0], new_xy[1][1]) + grid[x][y];
    } else {
      sum_down = INT_MAX;
    }
    return std::min(sum_right, sum_down);
  }

 public:
  int minPathSum(vector<vector<int>>& grid) {
    height_ = grid.size();
    if (height_ == 0) {
      return 0;
    }
    width_ = grid[0].size();
    return searchPath(grid, 0, 0);
  }
};
//leetcode submit region end(Prohibit modification and deletion)
