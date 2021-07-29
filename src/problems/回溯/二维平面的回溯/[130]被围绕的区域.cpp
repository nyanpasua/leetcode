//给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X'
//围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充 。
//
//
//
//
// 示例 1：
//
//
//输入：board = [["X","X","X","X"],
//              ["X","O","O","X"],
//              ["X","X","O","X"],
//              ["X","O","X","X"]]
//输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
//解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。
//任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都
//会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
//
//
// 示例 2：
//
//
//输入：board = [["X"]]
//输出：[["X"]]
//
//
//
//
// 提示：
//
//
// m == board.length
// n == board[i].length
// 1 <= m, n <= 200
// board[i][j] 为 'X' 或 'O'
//
//
//
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵
// 👍 574 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
using std::vector;

/// dfs
// 反向思考，所有没有被边界的 'O' 直接或间接相连的 'O' 不应该被修改为
// 'X'，其他都应该修改；
// 因此，只要对所有边界 'O' 进行 dfs，做上标记 'M'，然后遍历，将 'M' 还原为
// 'O'， 'O' 修改 为 'X'
class Solution {
 public:
  void solve(vector<vector<char>>& board) {
    height_ = board.size();
    if (height_ == 0) {
      return;
    }
    width_ = board[0].size();
    visited_ =
        std::move(vector<vector<bool>>(height_, vector<bool>(width_, false)));
    // 四周 'O' dfs
    for (int i = 0; i < height_; i++) {
      if (!visited_[i][0] && board[i][0] == 'O') {
        dfs(board, i, 0);
      }
      if (!visited_[i][width_ - 1] && board[i][width_ - 1] == 'O') {
        dfs(board, i, width_ - 1);
      }
    }
    for (int i = 1; i < width_ - 1; i++) {
      if (!visited_[0][i] && board[0][i] == 'O') {
        dfs(board, 0, i);
      }
      if (!visited_[height_ - 1][i] && board[height_ - 1][i] == 'O') {
        dfs(board, height_ - 1, i);
      }
    }
    for (int i = 0; i < height_; i++) {
      for (int j = 0; j < width_; j++) {
        if (board[i][j] == 'M') {
          board[i][j] = 'O';
        } else if (board[i][j] == 'O') {
          board[i][j] = 'X';
        }
      }
    }
  }

 private:
  void dfs(vector<vector<char>>& board, int x, int y) {
    // 保证进入合法
    board[x][y] = 'M';
    visited_[x][y] = true;
    for (int i = 0; i < 4; ++i) {
      auto new_x = x + pos_offset[i][0];
      auto new_y = y + pos_offset[i][1];
      if (is_area(new_x, new_y) && !visited_[new_x][new_y] &&
          board[new_x][new_y] == 'O') {
        dfs(board, new_x, new_y);
      }
    }
  }

  int height_{};
  int width_{};
  vector<vector<bool>> visited_;
  // 上右下左顺序的位置偏移量，顺时针方向
  vector<vector<int>> pos_offset{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  bool is_area(int x, int y) {
    return x >= 0 && x < height_ && y >= 0 && y < width_;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
