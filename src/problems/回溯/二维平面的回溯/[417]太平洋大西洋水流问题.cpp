//给定一个 m x n
//的非负整数矩阵来表示一片大陆上各个单元格的高度。“太平洋”处于大陆的左边界和上边界，而“大西洋”处于大陆的右边界和下边界。
//
// 规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。
//
// 请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。
//
//
//
// 提示：
//
//
// 输出坐标的顺序不重要
// m 和 n 都小于150
//
//
//
//
// 示例：
//
//
//
//
//给定下面的 5x5 矩阵:
//
//  太平洋 ~   ~   ~   ~   ~
//       ~  1   2   2   3  (5) *
//       ~  3   2   3  (4) (4) *
//       ~  2   4  (5)  3   1  *
//       ~ (6) (7)  1   4   5  *
//       ~ (5)  1   1   2   4  *
//          *   *   *   *   * 大西洋
//
//返回:
//
//[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (上图中带括号的单元).
//
//
//
// Related Topics 深度优先搜索 广度优先搜索 数组 矩阵
// 👍 270 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
using std::vector;
/// 二维平面回溯
// 此题和被围绕的区域（130）很类似，从内部 dfs
// 显得比较复杂，但是从边界出发，逆流寻找就很简单
class Solution {
 public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int>> ans;
    if (heights.empty() || heights[0].empty()) return ans;
    height_ = heights.size();
    width_ = heights[0].size();
    vector<vector<int>> po(height_, vector<int>(width_, 0));  // 太平洋
    vector<vector<int>> ao(height_, vector<int>(width_, 0));
    for (int i = 0; i < width_; ++i) {
      // 太平洋
      dfs(heights, 0, i, po);
      // 大西洋
      dfs(heights, height_ - 1, i, ao);
    }

    for (int i = 0; i < height_; ++i) {
      dfs(heights, i, 0, po);
      dfs(heights, i, width_ - 1, ao);
    }
    for (int i = 0; i < height_; ++i) {
      for (int j = 0; j < width_; ++j) {
        if (po[i][j] == 1 && ao[i][j] == 1) {
          ans.push_back({i, j});
        }
      }
    }
    return ans;
  }

 private:
  void dfs(const vector<vector<int>>& heights, int x, int y,
           vector<vector<int>>& tmp) {
    // 保证进入合法
    tmp[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
      int new_x = x + pos_offset[i][0];
      int new_y = y + pos_offset[i][1];
      if (is_area(new_x, new_y) && tmp[new_x][new_y] == 0 &&
          heights[new_x][new_y] >= heights[x][y]) {
        dfs(heights, new_x, new_y, tmp);
      }
    }
  }
  bool is_area(int x, int y) {
    return x < height_ && x >= 0 && y < width_ && y >= 0;
  }
  int height_;
  int width_;
  // 上右下左顺序的位置偏移量，顺时针方向
  vector<vector<int>> pos_offset{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
};
// leetcode submit region end(Prohibit modification and deletion)
