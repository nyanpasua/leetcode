// 输入:
//[
//  [1,3,1],
//  [1,5,1],
//  [4,2,1]
//]
// 输出: 12
// 解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物
#include <vector>
using std::vector;
/// 暴力回溯，会超时
class Solution1 {
 private:
  std::vector<std::vector<int>> offset_{{1, 0}, {0, 1}};
  int width_;
  int height_;
  bool is_area(int x, int y) {
    return x >= 0 && x < height_ && y >= 0 && y < width_;
  }

 public:
  int maxValue(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) return 0;
    height_ = grid.size();
    width_ = grid[0].size();
    return dfs(grid, 0, 0);
  }

 private:
  int dfs(vector<vector<int>>& grid, int x, int y) {
    if (x == height_ - 1 && y == width_ - 1) {
      return grid[x][y];
    }
    // 向下
    auto new_x = x + offset_[0][0];
    auto new_y = y + offset_[0][1];
    auto path_down = grid[x][y];
    if (is_area(new_x, new_y)) {
      path_down += dfs(grid, new_x, new_y);
    }
    // 向右
    new_x = x + offset_[1][0];
    new_y = y + offset_[1][1];
    auto path_right = grid[x][y];
    if (is_area(new_x, new_y)) path_right += dfs(grid, new_x, new_y);
    return std::max(path_down, path_right);
  }
};

class Solution {
 public:
  int maxValue(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) return 0;
    auto height = grid.size();
    auto width = grid[0].size();

    vector<vector<int>> dp(height, vector<int>(width, 0));
    // base case
    dp[0][0] = grid[0][0];
    for (size_t i = 1; i < height; ++i) {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (size_t j = 1; j < width; ++j) {
      dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    for (size_t i = 1; i < height; ++i) {
      for (size_t j = 1; j < width; ++j) {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
      }
    }
    return dp[height - 1][width - 1];
  }
};
