
// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[1,2,3,6,9,8,7,4,5]

#include <vector>
using std::vector;
/// 设 i 为行，j 为列
/// i --> 0 0 0 1 2 2 2 1 1
/// j --> 0 1 2 2 2 1 0 0 1

//   ---t---
//   |     |
//   l     r
//   |     |
//   ---b---
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return std::vector<int>{};
    int t = 0;
    int b = matrix.size() - 1;
    int l = 0;
    int r = matrix[0].size() - 1;
    std::vector<int> res((b + 1) * (r + 1), 0);
    int x = 0;
    while (true) {
      for(int i = l; i <= r; i++) res[x++] = matrix[t][i]; // left to right.
      if(++t > b) break;
      for(int i = t; i <= b; i++) res[x++] = matrix[i][r]; // top to bottom.
      if(l > --r) break;
      for(int i = r; i >= l; i--) res[x++] = matrix[b][i]; // right to left.
      if(t > --b) break;
      for(int i = b; i >= t; i--) res[x++] = matrix[i][l]; // bottom to top.
      if(++l > r) break;
    }
    return res;
  }
};