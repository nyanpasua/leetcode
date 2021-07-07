 //给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为
// 1 。
//
// 求在该柱状图中，能够勾勒出来的矩形的最大面积。
//
//
//
//
//
// 以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
//
//
//
//
//
// 图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。
//
//
//
// 示例:
//
// 输入: [2,1,5,6,2,3]
//输出: 10
// Related Topics 栈 数组
// 👍 1408 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <stack>
#include <vector>
using std::stack;
using std::vector;

/// 单调栈+空间优化
// 这里有点不好思考，如何一次遍历即确定 left 和 right
// 当位置 i 被弹出栈时，说明此时遍历到的位置 i_0
//  的高度小于等于 height[i]，并且在 i_0
//  与 i 之间没有其他高度小于等于 height[i] 的柱子。这是因为，如果在 i 和 i_0
//  之间还有其它位置的高度小于等于 height[i] 的，那么在遍历到那个位置的时候，ii
//  应该已经被弹出栈了。 所以位置 i_0 就是位置 i 的右边界。
// 我们确实无法求出所有正确的右边界，但对最终的答案没有任何影响。
// 这是因为在答案对应的矩形中，如果有若干个柱子的高度都等于矩形的高度，
// 那么最右侧的那根柱子是可以求出正确的右边界的
//
class Solution {
 public:
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
      ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
    }
    return ans;
  }
};

/// 单调栈
// 在枚举“高”的过程中，我们需要找到左右两侧第一个小于高度 h
// 的柱子，这样就确定的左右边界， 如果左右边界的宽度为 w，那么以 高 hi
// 为高度的柱子，最大面积为 hi * w， 可以使用单调栈，以 O(n) 时间先将 左右边界
// 预存起来。
class Solution1 {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    // 这里初始值很讲究，-1 表示 heights[i] 左侧没有 比它低的 柱子
    vector<int> left(n, -1);
    // n 表示 heights[i] 右侧 没有比它高的柱子
    vector<int> right(n, n);
    stack<int> mono_s;
    // 从左向右遍历，维护严格单调递增栈，保存 left[i]
    for (int i = 0; i < n; ++i) {
      // 找到栈中第一个小于 heights[i] 的 索引
      while (!mono_s.empty() && heights[i] <= heights[mono_s.top()]) {
        mono_s.pop();
      }
      left[i] = mono_s.empty() ? -1 : mono_s.top();
      // i 入栈
      mono_s.push(i);
    }
    mono_s = stack<int>();
    // 从右向左遍历，维护严格单调递增栈，保存 right[i]
    for (int i = n - 1; i >= 0; --i) {
      while (!mono_s.empty() && heights[i] <= heights[mono_s.top()]) {
        mono_s.pop();
      }
      right[i] = mono_s.empty() ? n : mono_s.top();
      mono_s.push(i);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
