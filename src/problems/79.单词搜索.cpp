//
// Created by liyingmin on 2020/3/27.
//
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
  // index表示现在正在匹配word的character索引，x，y表示处在board的(x, y)坐标处
  // 判断当前(x,y)坐标处，是否匹配了word[index]的字母，如果匹配，则以新的位置(x+offset,
  // y+offset)递归，如果不匹配，return false。
  bool searchWord(const vector<vector<char>>& board, const string& word,
                  size_t index, size_t x, size_t y) {
    // 递归到底，index指向word的最后一个字母的时候
    if (index == word.size() - 1) {
      return board[x][y] == word[index];
    }
    if (board[x][y] == word[index]) {
      // 标记(x, y)这个位置成功匹配了word[index]
      is_visited_[x][y] = true;
      for (size_t i = 0; i < 4; ++i) {
        auto new_x = x + pos_offset[i][0];
        auto new_y = y + pos_offset[i][1];
        if (isArea(new_x, new_y) && !is_visited_[new_x][new_y]) {
          if (searchWord(board, word, index + 1, new_x, new_y)) {
            return true;
          }
        }
      }
      // 如果递归返回了false，要把位置取消标记，防止接下来的递归出现问题
      is_visited_[x][y] = false;
    }
    return false;
  }

 public:
  bool exist(vector<vector<char>>& board, string word) {
    height_ = board.size();
    assert(height_);
    width_ = board[0].size();
    is_visited_ =
        std::move(vector<vector<bool>>(height_, vector<bool>(width_, false)));
    for (size_t i = 0; i < board.size(); ++i) {
      for (size_t j = 0; j < board[i].size(); ++j) {
        if (searchWord(board, word, 0, i, j)) {
          return true;
        }
      }
    }
    return false;
  }
};