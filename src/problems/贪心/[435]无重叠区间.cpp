/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

//给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。
//
// 注意:
//
//
// 可以认为区间的终点总是大于它的起点。
// 区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
//
//
// 示例 1:
//
//
//输入: [ [1,2], [2,3], [3,4], [1,3] ]
//
//输出: 1
//
//解释: 移除 [1,3] 后，剩下的区间没有重叠。
//
//
// 示例 2:
//
//
//输入: [ [1,2], [1,2], [1,2] ]
//
//输出: 2
//
//解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
//
//
// 示例 3:
//
//
//输入: [ [1,2], [2,3] ]
//
//输出: 0
//
//解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
//
// Related Topics 贪心 数组 动态规划 排序
// 👍 440 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
/// 贪心
// Time: O(NlogN)
class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
      return 0;
    }
    // 右端点排序
    sort(intervals.begin(), intervals.end(),
         [](const auto& u, const auto& v) { return u[1] < v[1]; });

    int n = intervals.size();
    // 初始化 right = 第 0 个区间的 右端点
    int right = intervals[0][1];
    int ans = 1;
    for (int i = 1; i < n; ++i) {
      // 如果 第 i 个区间的左端点 >= right，即不重合
      // 1.需要删除的区间 -1
      // 2.贪心的选择这个区间的右端点作为 right
      if (intervals[i][0] >= right) {
        ++ans;
        right = intervals[i][1];
      }
    }
    return n - ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
