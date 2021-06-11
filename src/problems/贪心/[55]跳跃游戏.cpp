//给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
//
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。
//
// 判断你是否能够到达最后一个下标。
//
//
//
// 示例 1：
//
//
//输入：nums = [2,3,1,1,4]
//输出：true
//解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3
//步到达最后一个下标。
//
//
// 示例 2：
//
//
//输入：nums = [3,2,1,0,4]
//输出：false
//解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ，
//所以永远不可能到达最后一个下标。
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 3 * 104
// 0 <= nums[i] <= 105
//
// Related Topics 贪心算法 数组
// 👍 1226 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
#include <algorithm>
using std::vector;

/// 贪心
// 遍历数组,如果有一个位置满足 i + nums[i] >= n - 1,则该位置满足条件
// 在遍历数组的过程中,更新每个位置最远可以到达的位置 max_idx
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int n = nums.size();
    int max_idx = 0;
    for (int i = 0; i < n; ++i) {
      if (i <= max_idx) {
        // 只有 i <= max_idx 的时候,该位置才可达,才有可能满足条件
        max_idx = std::max(max_idx, nums[i] + i);
        if (max_idx >= n - 1) return true;
      }
    }
    return false;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
