//给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
//
// 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要
// 使用另一个矩阵来旋转图像。
//
//
//
// 示例 1：
//
//
//输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
//输出：[[7,4,1],[8,5,2],[9,6,3]]
//
//
// 示例 2：
//
//
//输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
//输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
//
//
// 示例 3：
//
//
//输入：matrix = [[1]]
//输出：[[1]]
//
//
// 示例 4：
//
//
//输入：matrix = [[1,2],[3,4]]
//输出：[[3,1],[4,2]]
//
//
//
//
// 提示：
//
//
// matrix.length == n
// matrix[i].length == n
// 1 <= n <= 20
// -1000 <= matrix[i][j] <= 1000
//
// Related Topics 数组
// 👍 901 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
using std::vector;

/// 原地旋转
// temp=matrix[row][col]
// matrix[row][col]=matrix[n−col−1][row]
// matrix[n−col−1][row]=matrix[n−row−1][n−col−1]
// matrix[n−row−1][n−col−1]=matrix[col][n−row−1]
// matrix[col][n−row−1]=temp

// 如果 n == 3，则旋转 2 次
// i = 0, j = 0
// temp = a[0][0];
// a[0][0] = a[2][0];
// a[2][0]=a[2][2];
// a[2][2] = a[0][2];
// a[0][2] = a[0][0];
// i = 0, j = 1
// temp = a[0][1];
// a[0][1] = a[1][0];
// a[1][0] = a[2][1];
// a[2][1] = a[1][2];
// a[1][2] = temp;
class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n / 2; i++) {
      for (int j = 0; j < (n + 1) / 2; j++) {
        int temp = matrix[i][j];
        matrix[i][j] = matrix[n - 1 - j][i];
        matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
        matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
        matrix[j][n - 1 - i] = temp;
      }
    }
  }
};
// leetcode submit region end(Prohibit modification and deletion)
