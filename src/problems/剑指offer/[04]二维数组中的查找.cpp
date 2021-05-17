
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
    int i = matrix.size() - 1;
    int j = 0;
    while (i >= 0 && j <= matrix[0].size() - 1) {
      if (matrix[i][j] < target) {
        ++j;
      } else if (matrix[i][j] > target) {
        --i;
      } else {
        return true;
      }
    }
    return false;
  }
};
