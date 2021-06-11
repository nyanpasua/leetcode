//给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word
//存在于网格中，返回 true ；否则，返回 false 。
//
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
//
//
//
// 示例 1：
//
//
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
//"AB CCED" 输出：true
//
//
// 示例 2：
//
//
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
//"SE E" 输出：true
//
//
// 示例 3：
//
//
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
//"AB CB" 输出：false
//
//
//
//
// 提示：
//
//
// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board 和 word 仅由大小写英文字母组成
//
//
//
//
// 进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board
// 更大的情况下可以更快解决问题？ Related Topics 数组 回溯算法 👍 926 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
 private:
  vector<vector<int>> offset_{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  int height_;
  int width_;
  bool is_area(int x, int y) {
    return x >= 0 && x < height_ && y >= 0 && y < width_;
  }
  vector<vector<int>> visited_;

 public:
  bool exist(vector<vector<char>>& board, string word) {
    if (board.empty() || board[0].empty()) return false;
    height_ = board.size();
    width_ = board[0].size();
    visited_ = std::move(vector<vector<int>>(height_, vector<int>(width_, 0)));
    for (int i = 0; i < height_; ++i) {
      for (int j = 0; j < width_; ++j) {
        if (dfs(board, word, 0, i, j)) return true;
      }
    }
    return false;
  }

 private:
  bool dfs(const vector<vector<char>>& board, const string& word, int idx,
           int x, int y) {
    // 保证进入即合法，这里相当于做了剪枝
    if (board[x][y] != word[idx]) return false;
    if (idx == word.size() - 1 && board[x][y] == word[idx]) return true;
    // <x, y> 还未到 word 边界, 做四方 dfs
    if (board[x][y] == word[idx]) {
      visited_[x][y] = true;  // 标记为已访问
      for (int i = 0; i < 4; ++i) {
        auto new_x = x + offset_[i][0];
        auto new_y = y + offset_[i][1];
        if (is_area(new_x, new_y) && !visited_[new_x][new_y] &&
            dfs(board, word, idx + 1, new_x, new_y))
          return true;
      }
    }
    visited_[x][y] = false;  // <x, y> 不是解,取消标记
    return false;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
