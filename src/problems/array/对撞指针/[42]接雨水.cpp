//给定 n 个非负整数表示每个宽度为 1
//的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
//
//
//
// 示例 1：
//
//
//
//
//输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
//输出：6
//解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1]
//表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
//
//
// 示例 2：
//
//
//输入：height = [4,2,0,3,2,5]
//输出：9
//
//
//
//
// 提示：
//
//
// n == height.length
// 0 <= n <= 3 * 104
// 0 <= height[i] <= 105
//
// Related Topics 栈 数组 双指针 动态规划
// 👍 2397 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <algorithm>
#include <vector>
using std::vector;

/// 双指针
// 由于动态规划的方法，需要找到 left_max[i] 和 right_max[i]，因此维护了一个数组
// 而使用双指针，可以动态的找到两边的 left_max 和 right_max，无需维护数组
class Solution {
 public:
  int trap(vector<int>& height) {
    int res = 0;
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0;
    while (left < right) {
      leftMax = std::max(leftMax, height[left]);
      rightMax = std::max(rightMax, height[right]);
      if (height[left] < height[right]) {
        // height[left] < height[right], min(left) = leftMax
        res += leftMax - height[left];
        ++left;
      } else {
        // height[left] >= height[right], min(right) = rightMax
        res += rightMax - height[right];
        --right;
      }
    }
    return res;
  }
};

/// 动态规划
// 对于下标 i，下雨后水能到达的最大高度等于下标 i 两边的最大高度的最小值，
// 下标 i 处能接的雨水量等于下标 i 处的水能到达的最大高度减去 height[i]
// 可以使用动态规划，预先存储每一个下标 i 的左右侧最大高度，
// left_max 和 right_max
// left_max[i] = std::max(left_max[i-1], height[i]), 1 <= i <= n - 1
// right_max[i] = std::max(right_max[i+1], height[i]), 0 <= i <= n - 2
// left_max[0] = height[0], right_max[n-1] = height[n-1]
// weights[i] = std::min(left_max[i], right[i]) - height[i]
// Time: O(N)  Space: O(N)
class Solution1 {
 public:
  int trap(vector<int>& height) {
    if (height.empty()) return 0;
    int n = height.size();
    vector<int> left_max(n, 0);
    left_max[0] = height[0];
    for (int i = 1; i < n; ++i) {
      left_max[i] = std::max(left_max[i - 1], height[i]);
    }
    vector<int> right_max(n, 0);
    right_max[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      right_max[i] = std::max(right_max[i + 1], height[i]);
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
      res += (std::min(left_max[i], right_max[i]) - height[i]);
    }
    return res;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
