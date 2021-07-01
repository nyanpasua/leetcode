//给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1
//的最大矩形，并返回其面积。
//
//
//
// 示例 1：
//
//
//输入：matrix =
//[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"]
//,["1","0","0","1","0"]]
//输出：6
//解释：最大矩形如上图所示。
//
//
// 示例 2：
//
//
//输入：matrix = []
//输出：0
//
//
// 示例 3：
//
//
//输入：matrix = [["0"]]
//输出：0
//
//
// 示例 4：
//
//
//输入：matrix = [["1"]]
//输出：1
//
//
// 示例 5：
//
//
//输入：matrix = [["0","0"]]
//输出：0
//
//
//
//
// 提示：
//
//
// rows == matrix.length
// cols == matrix[0].length
// 0 <= row, cols <= 200
// matrix[i][j] 为 '0' 或 '1'
//
// Related Topics 栈 数组 哈希表 动态规划
// 👍 949 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <algorithm>
#include <stack>
#include <vector>
using std::stack;
using std::vector;
/// 单调栈 + 柱状图
// 对每一行生成柱状图，以 O(N) 计算最大矩形面积
// Time: O(MN)
class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int max = 0;
    vector<int> heights(matrix[0].size(), 0);
    for (int i = 0; i < matrix.size(); ++i) {
      // 生成柱状图
      for (int j = 0; j < heights.size(); ++j) {
        heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
      }
      // 计算最大面积
      max = std::max(largestRectangleArea(heights), max);
    }
    return max;
  }

 private:
  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n), right(n, n);

    stack<int> mono_stack;
    for (int i = 0; i < n; ++i) {
      while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
        right[mono_stack.top()] = i;
        mono_stack.pop();
      }
      left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
      mono_stack.push(i);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = std::max(ans, (right[i] - left[i] - 1) * heights[i]);
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
