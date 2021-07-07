//给定一个非负整数数组，你最初位于数组的第一个位置。
//
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。
//
// 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
//
// 假设你总是可以到达数组的最后一个位置。
//
//
//
// 示例 1:
//
//
//输入: [2,3,1,1,4]
//输出: 2
//解释: 跳到最后一个位置的最小跳跃数是 2。
//     从下标为 0 跳到下标为 1
//的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
//
//
// 示例 2:
//
//
//输入: [2,3,0,1,4]
//输出: 2
//
//
//
//
// 提示:
//
//
// 1 <= nums.length <= 1000
// 0 <= nums[i] <= 105
//
// Related Topics 贪心 数组 动态规划
// 👍 1044 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
/// 贪心
// 正向查找最远可达点；
// 由于这道题已经假设你可以到达最终位置，因此，参考 55
// 题的做法，每次都更新最远可达的位置； 贪心分析：[2 3 1 2 4 2 3] 从下标 0
// 出发，最远可以到达下标 2，也就是可选 下标 1和2； 由于 下标1 可以到 下标
// 4，跳的比下标 2 远，因此贪心的选择这个下标进行跳跃；从 [2...4]
// 的几个选择中，仍然是选择可以到达最远下标的进行跳跃；
// 因此，具体到实现，我只有每次到达最远边界的时候，才会增加一次
// step，在遍历的过程中， 不断更新 max_idx，同时当 i == end 的时候，step++
// 即可；

class Solution {
 public:
  int jump(vector<int>& nums) {
    int max_idx = 0, steps = 0, end = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
      max_idx = std::max(max_idx, nums[i] + i);
      if (i == end) {
        end = max_idx;
        ++steps;
      }
    }
    return steps;
  }
};

/// 贪心
// 反向贪心查找最远距离；思路是，因为我们从左至右遍历数组的时候，第一个出现的可以到达
// position 位置的地点，我们认为就是距离 position
// 位置最远的跳跃点，我们贪心的选择这样的跳跃点；并将 position
// 更新为这个跳跃点，继续从左至右遍历数组；直到 position == 0；
// Time: O(N^2)
class Solution1 {
 public:
  int jump(vector<int>& nums) {
    // 开始的 pos 定为 最后一个 idx
    int pos = nums.size() - 1;
    int steps = 0;
    while (pos > 0) {
      for (int i = 0; i < pos; ++i) {
        if (nums[i] + i >= pos) {
          // 可达 pos 位置
          pos = i;
          steps++;
          break;  // 跳出 for 循环
        }
      }
    }
    return steps;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
