//
// Created by liyingmin on 2020/3/27.
//
//给你一个由'1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
//
//岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
//
//此外，你可以假设该网格的四条边均被水包围。
//输入：grid = [
//  ["1","1","1","1","0"],
//  ["1","1","0","1","0"],
//  ["1","1","0","0","0"],
//  ["0","0","0","0","0"]
//]
//输出：1
//
#include <vector>
using std::vector;
class Solution {
 private:
  size_t height_;
  size_t width_;
  vector<vector<bool>> is_visited_;
  // 判断(x, y)是否在矩形范围内
  bool isArea(size_t x, size_t y) {
    return x >= 0 && x < height_ && y >= 0 && y < width_;
  }
  // 上右下左顺序的位置偏移量，顺时针方向
  vector<vector<int>> pos_offset{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  void dfs(const vector<vector<char>>& grid, size_t x, size_t y) {
    // 保证进入合法
    is_visited_[x][y] = true;
    for (size_t i = 0; i < 4; ++i) {
      auto new_x = x + pos_offset[i][0];
      auto new_y = y + pos_offset[i][1];
      if (isArea(new_x, new_y) && !is_visited_[new_x][new_y] &&
          grid[new_x][new_y] == '1') {
        dfs(grid, new_x, new_y);
      }
    }
  }

 public:
  int numIslands(vector<vector<char>>& grid) {
    height_ = grid.size();
    if (height_ == 0) {
      return 0;
    }
    width_ = grid[0].size();
    is_visited_ =
        std::move(vector<vector<bool>>(height_, vector<bool>(width_, false)));
    int count{0};
    for (size_t i = 0; i < height_; ++i) {
      for (size_t j = 0; j < width_; ++j) {
        if (!is_visited_[i][j] && grid[i][j] == '1') {
          ++count;
          dfs(grid, i, j);
        }
      }
    }
    return count;
  }
};