//编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target
//。该矩阵具有以下特性：
//
//
// 每行的元素从左到右升序排列。
// 每列的元素从上到下升序排列。
//
//
//
//
// 示例 1：
//
//
//输入：matrix =
//[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21
//,23,26,30]], target = 5
//输出：true
//
//
// 示例 2：
//
//
//输入：matrix =
//[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21
//,23,26,30]], target = 20
//输出：false
//
//
//
//
// 提示：
//
//
// m == matrix.length
// n == matrix[i].length
// 1 <= n, m <= 300
// -109 <= matix[i][j] <= 109
// 每行的所有元素从左到右升序排列
// 每列的所有元素从上到下升序排列
// -109 <= target <= 109

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
