// 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标[0,0]
// 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），
// 也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格
// [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35,
// 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
//
#include <string>
#include <vector>
using std::vector;
/// 思路，dfs
class Solution2 {
 private:
  // 宽高
  int height_{};
  int width_{};
  int k_{};
  // 4个方向，右下左上，x 为纵轴，y 为横轴，<x, y>
  vector<vector<int>> offset_{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  // <x, y> 是否合法
  bool is_area(int x, int y) {
    return x >= 0 && x < height_ && y >= 0 && y < width_;
  }

 public:
  int movingCount(int m, int n, int k) {
    if (m <= 0 || n <= 0) return 0;
    visited_ = std::move(vector<vector<bool>>(m, vector<bool>(n, false)));
    height_ = m;
    width_ = n;
    k_ = k;
    if (condition(0, 0)) dfs(0, 0);
    return count_;
  }

 private:
  vector<vector<bool>> visited_{};
  int count_{0};
  void dfs(int x, int y) {
    // 进入即合法范围，在上层保证
    visited_[x][y] = true;
    ++count_;
    // 4个方向 dfs
    for (int i = 0; i < 4; ++i) {
      // x += offset_[i][0];  // new_x
      // y += offset_[i][1];  // new_y
      //  这里有个易错点，不能上述方式给值，因为这样会产生叠加
      auto new_x = x + offset_[i][0];
      auto new_y = y + offset_[i][1];
      if (is_area(new_x, new_y) && condition(new_x, new_y) &&
          !visited_[new_x][new_y])
        dfs(new_x, new_y);
    }
    return;
  }
  bool condition(int x, int y) {
    auto s = std::to_string(x) + std::to_string(y);
    int sum = 0;
    for (const auto &i : s) {
      sum += i - '0';
    }
    return sum <= k_;
  }
};

/// 优化空间
/// 1. sum 求和可以按位取余
/// 2. 向下或者向右即可完成
class Solution {
 private:
  // 宽高
  int height_{};
  int width_{};
  int k_{};
  // 4个方向，右下左上，x 为纵轴，y 为横轴，<x, y>
  vector<vector<int>> offset_{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  // <x, y> 是否合法
  bool is_area(int x, int y) {
    return x >= 0 && x < height_ && y >= 0 && y < width_;
  }

 public:
  int movingCount(int m, int n, int k) {
    if (m <= 0 || n <= 0) return 0;
    visited_ = std::move(vector<vector<bool>>(m, vector<bool>(n, false)));
    height_ = m;
    width_ = n;
    k_ = k;
    if (condition(0, 0)) dfs(0, 0);
    return count_;
  }

 private:
  vector<vector<bool>> visited_{};
  int count_{0};
  void dfs(int x, int y) {
    // 进入即合法范围，在上层保证
    visited_[x][y] = true;
    ++count_;
    // 4个方向 dfs
    for (int i = 0; i < 2; ++i) {
      // x += offset_[i][0];  // new_x
      // y += offset_[i][1];  // new_y
      //  这里有个易错点，不能上述方式给值，因为这样会产生叠加
      auto new_x = x + offset_[i][0];
      auto new_y = y + offset_[i][1];
      if (is_area(new_x, new_y) && condition(new_x, new_y) &&
          !visited_[new_x][new_y])
        dfs(new_x, new_y);
    }
    return;
  }
  bool condition(int x, int y) {
    int sum = 0;
    while (x != 0) {
      sum += x % 10;
      x /= 10;
    }
    while (y != 0) {
      sum += y % 10;
      y /= 10;
    }
    return sum <= k_;
  }
};
