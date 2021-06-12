//以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti,
// endi] 。请你合并所有重叠的区间，并返
//回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
//
//
//
// 示例 1：
//
//
//输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
//输出：[[1,6],[8,10],[15,18]]
//解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
//
//
// 示例 2：
//
//
//输入：intervals = [[1,4],[4,5]]
//输出：[[1,5]]
//解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
//
//
//
// 提示：
//
//
// 1 <= intervals.length <= 104
// intervals[i].length == 2
// 0 <= starti <= endi <= 104
//
// Related Topics 排序 数组
// 👍 957 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <algorithm>
#include <limits>
#include <vector>
using std::vector;
class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() == 1) return intervals;
    // 使用默认排序即可，先比较第一个数，如果相等比较第二个
    std::sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    // temp，用于记录每次的合并区间
    vector<int> temp(2, 0);
    temp = intervals[0];
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] <= temp[1]) {
        temp[1] = std::max(intervals[i][1], temp[1]);
      } else {
        res.push_back(temp);
        temp = intervals[i];
      }
    }
    res.push_back(temp);
    return res;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
