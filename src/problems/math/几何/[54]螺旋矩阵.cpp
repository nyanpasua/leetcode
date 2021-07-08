//给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序
//，返回矩阵中的所有元素。
//
//
//
// 示例 1：
//
//
//输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
//输出：[1,2,3,6,9,8,7,4,5]
//
//
// 示例 2：
//
//
//输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
//输出：[1,2,3,4,8,12,11,10,9,5,6,7]
//
//
//
//
// 提示：
//
//
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100
//
// Related Topics 数组 矩阵 模拟
// 👍 812 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
using std::vector;

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int height = matrix.size();
    int width = matrix[0].size();
    int t = 0, b = height - 1, l = 0, r = width - 1;
    vector<int> res;
    while (true) {
      for (int idx = l; idx <= r; ++idx) {
        res.push_back(matrix[t][idx]);  // l --> r
      }
      if (++t > b) break;
      for (int idx = t; idx <= b; ++idx) {
        res.push_back(matrix[idx][r]);  // t --> b
      }
      if (--r < l) break;
      for (int idx = r; idx >= l; --idx) {
        res.push_back(matrix[b][idx]);  // r --> l
      }
      if (--b < t) break;
      for (int idx = b; idx >= t; --idx) {
        res.push_back(matrix[idx][l]);  // b --> t
      }
      if (++l > r) break;
    }
    return res;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
