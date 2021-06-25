//编写一个高效的算法来判断 m x n
//矩阵中，是否存在一个目标值。该矩阵具有如下特性：
//
//
// 每行中的整数从左到右按升序排列。
// 每行的第一个整数大于前一行的最后一个整数。
//
//
//
//
// 示例 1：
//
//
//输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
//输出：true
//
//
// 示例 2：
//
//
//输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
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
// 1 <= m, n <= 100
// -104 <= matrix[i][j], target <= 104
//
// Related Topics 数组 二分查找 Matrix
// 👍 446 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
/// 二分
// 可以看出，这就是一个延长为 二维的 线性表
// matrix[i][j] = vec[i*width+j]
// vec[x] = matrix[x/width][x%width]
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int height = matrix.size();
    int width = matrix[0].size();
    int l = 0, r = height * width - 1;
    while (l <= r) {
      auto mid = l + (r - l) / 2;
      if (matrix[mid / width][mid % width] > target) {
        r = mid - 1;
      } else if (matrix[mid / width][mid % width] < target) {
        l = mid + 1;
      } else {
        return true;
      }
    }
    return false;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
