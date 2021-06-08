//你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
// 如果两间相邻的房屋在同一晚上
//被小偷闯入，系统会自动报警。
//
// 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下
// ，一夜之内能够偷窃到的最高金额。
//
//
//
// 示例 1：
//
//
//输入：[1,2,3,1]
//输出：4
//解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
//     偷窃到的最高金额 = 1 + 3 = 4 。
//
// 示例 2：
//
//
//输入：[2,7,9,3,1]
//输出：12
//解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋
//(金额 = 1)。      偷窃到的最高金额 = 2 + 9 + 1 = 12 。
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 100
// 0 <= nums[i] <= 400
//
// Related Topics 动态规划
// 👍 1493 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
using std::vector;
class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    if (nums.size() == 1) {
      return nums[0];
    }
    if (nums.size() == 2) {
      return std::max(nums[0], nums[1]);
    }
    // 表示空集合 和 nums[0...size] 可以获得的最大值
    vector<int> memo(nums.size() + 1, 0);
    memo[1] = nums[0];
    memo[2] = std::max(nums[0], nums[1]);
    for (size_t i = 3; i <= nums.size(); ++i) {
      auto num = nums[i - 1];
      // [0..倒数第二家] + num 之和 > [0..倒数第一家]
      memo[i] = num + memo[i - 2] > memo[i - 1] ?
                num + memo[i - 2] : memo[i - 1];
    }
    return memo[nums.size()];
  }
};
// leetcode submit region end(Prohibit modification and deletion)
