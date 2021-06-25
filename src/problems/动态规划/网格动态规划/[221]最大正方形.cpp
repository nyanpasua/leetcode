//在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1'
//的最大正方形，并返回其面积。
//
//
//
// 示例 1：
//
//
//输入：matrix =
//[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"]
//,["1","0","0","1","0"]]
//输出：4
//
//
// 示例 2：
//
//
//输入：matrix = [["0","1"],["1","0"]]
//输出：1
//
//
// 示例 3：
//
//
//输入：matrix = [["0"]]
//输出：0
//
//
//
//
// 提示：
//
//
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 300
// matrix[i][j] 为 '0' 或 '1'
//
// Related Topics 数组 动态规划 Matrix
// 👍 792 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
using std::vector;

/// 动态规划
// 定义 dp[i][j] 为 以 <i,j> 为右下角的正方形的 最大边长
// m[i][j] == 0 则 dp[i][j] = 0
// m[i][j] == 1，dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]) + 1
class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int height = matrix.size();
    int width = matrix[0].size();
    // 定义 dp 为 以 <i,j> 为右下角的 最大正方形的边长
    vector<vector<int>> dp(height, vector<int>(width, 0));
    int max = 0;
    // base case
    for (int i = 0; i < height; ++i) {
      dp[i][0] = (matrix[i][0] == '0' ? 0 : 1);
      max = std::max(max, dp[i][0]);
    }
    for (int j = 0; j < width; ++j) {
      dp[0][j] = (matrix[0][j] == '0' ? 0 : 1);
      max = std::max(max, dp[0][j]);
    }
    for (int i = 1; i < height; ++i) {
      for (int j = 1; j < width; ++j) {
        if (matrix[i][j] == '1') {
          dp[i][j] =
              std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
          max = std::max(max, dp[i][j]);
        } else {
          dp[i][j] = 0;
        }
      }
    }
    return max * max;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
