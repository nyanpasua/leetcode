//
// Created by liyingmin on 2020/3/27.
//

// 回溯方式：使用暴力递归
class Solution {
 private:
  size_t height_;
  size_t width_;
  // 判断(x, y)是否在矩形范围内
  bool isArea(size_t x, size_t y) {
    return x >= 0 && x < height_ && y >= 0 && y < width_;
  }
  // 右下顺序的位置偏移量，顺时针方向
  vector<vector<int>> pos_offset{{0, 1}, {1, 0}};
  int searchPath(const vector<vector<int>>& grid, size_t x, size_t y) {
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

// 动态规划
class Solution {
 private:
  size_t height_;
  size_t width_;
  // 判断(x, y)是否在矩形范围内
  bool isArea(size_t x, size_t y) {
    return x >= 0 && x < height_ && y >= 0 && y < width_;
  }
  // 上左顺序的位置偏移量，顺时针方向
  vector<vector<int>> pos_offset{{-1, 0}, {0, -1}};

 public:
  int minPathSum(vector<vector<int>>& grid) {
    height_ = grid.size();
    if (height_ == 0) {
      return 0;
    }
    width_ = grid[0].size();
  }
};