
#include <vector>
using std::vector;

/// 由于 matrix 与二叉搜索树很像，因此可以从左下角开始
/// 定义 [i, j]，i 表示行 index，初始化为 n - 1
/// j 表示列，初始化为 0
/// 当 target > matrix[i][j], ++j，即删除第 j 列
/// 当 target < matrix[i][j], --i，即删除第 i 行
/// Time: O(M + N)
/// Space: O(1)
class Solution {
 public:
  bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    // i 表示行，从矩阵最下面的行开始搜索
    int i = matrix.size() - 1;
    // j 表示列，从第一列开始搜索
    int j = 0;
    while (i >= 0 && j <= matrix[0].size() - 1) {
      // matrix[i][j] 是 第 j 列 最大的元素
      // 是 第 i 行 最小的元素
      if (matrix[i][j] < target) {
        // 删除第 j 列
        ++j;
      } else if (matrix[i][j] > target) {
        // 删除第 i 行
        --i;
      } else {
        return true;
      }
    }
    return false;
  }
};
