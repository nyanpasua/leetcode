//给你一个会议时间安排的数组 intervals ，每个会议时间都会包括开始和结束的时间
// intervals[i] = [starti, endi] ，为避免
//会议冲突，同时要考虑充分利用会议室资源，请你计算至少需要多少间会议室，才能满足这些会议安排。
//
//
//
// 示例 1：
//
//
//输入：intervals = [[0,30],[5,10],[15,20]]
//输出：2
//
//
// 示例 2：
//
//
//输入：intervals = [[7,10],[2,4]]
//输出：1
//
//
//
//
// 提示：
//
//
// 1 <= intervals.length <= 104
// 0 <= starti < endi <= 106
//
// Related Topics 贪心算法 数组 双指针 排序 堆（优先队列）
// 👍 282 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <algorithm>
#include <vector>
using std::vector;

/// 排序 + 合并策略
// 无论怎样采取排序策略，都会有各种异常情况，需要考虑其他思路
// Wrong Answer:
// [[2,11],[6,16],[11,16]]
// Wrong Answer:
// [[9,10],[4,9],[4,17]]
// 此题中，无论开始时间还是结束时间，都对会议室的数量产生影响，因此，
// 需要两种排序的信息，开始时间，对于开新房间直接产生影响，而结束时间
// 对于复用会议室产生影响
class Solution {
 public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    std::vector<int> start(intervals.size());
    std::vector<int> end(intervals.size());
    for (size_t i = 0; i < intervals.size(); ++i) {
      start[i] = intervals[i][0];
      end[i] = intervals[i][1];
    }
    std::sort(start.begin(), start.end());
    std::sort(end.begin(), end.end());

    int start_ptr = 0, end_ptr = 0;
    int num = 0;
    while (start_ptr < intervals.size()) {
      if (start[start_ptr] >= end[end_ptr]) {
        // 有会议室释放出来，可以复用
        end_ptr++;
      } else {
        // 没有会议室释放出来，增加房间数量
        ++num;
      }
      ++start_ptr;
    }
    return num;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
