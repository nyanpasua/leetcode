//给你一个 只包含正整数 的 非空 数组 nums
//。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
//
//
//
// 示例 1：
//
//
//输入：nums = [1,5,11,5]
//输出：true
//解释：数组可以分割成 [1, 5, 5] 和 [11] 。
//
// 示例 2：
//
//
//输入：nums = [1,2,3,5]
//输出：false
//解释：数组不能分割成两个元素和相等的子集。
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 200
// 1 <= nums[i] <= 100
//
// Related Topics 动态规划
// 👍 815 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
using std::vector;
#include <algorithm>
#include <numeric>

// 进一步优化时间复杂度
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) {
      return false;
    }
    auto capacity = sum / 2;
    // 从nums.size()个元素，能找出一个组合将capacity为sum/2的背包装满，即找到这个子序列
    // memo矩阵
    size_t height = nums.size();
    vector<bool> memo(capacity + 1, false);
    // base case, memo[0], c==0, i == 0
    memo[0] = true;
    // base case, memo[c], c >= 1, i == 0
    for (int c = 1; c <= capacity; ++c) {
      memo[c] = nums[0] == c ? true : false;
    }
    // 状态转移迭代
    for (size_t i = 1; i < height; ++i) {
      // c >= nums[i]的时候才需要更新
      for (size_t c = capacity; c >= nums[i]; --c) {
        memo[c] = memo[c] || memo[c - nums[i]];
      }
    }
    return memo[capacity];
  }
};

// 优化空间复杂度
class Solution2 {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) {
      return false;
    }
    auto capacity = sum / 2;
    // 从nums.size()个元素，能找出一个组合将capacity为sum/2的背包装满，即找到这个子序列
    // memo矩阵
    size_t height = nums.size();
    vector<bool> memo(capacity + 1, false);
    // base case, memo[0], c==0, i == 0
    memo[0] = true;
    // base case, memo[c], c >= 1, i == 0
    for (int c = 1; c <= capacity; ++c) {
      memo[c] = nums[0] == c ? true : false;
    }
    // 状态转移迭代
    for (size_t i = 1; i < height; ++i) {
      // 这里从 capacity-->1，因为需要使用上一轮循环的较小 index 的值
      // memo[c-nums[i]]
      for (size_t c = capacity; c >= 1; --c) {
        memo[c] = memo[c] || (c >= nums[i] ? memo[c - nums[i]] : false);
      }
    }
    return memo[capacity];
  }
};
class Solution1 {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) {
      return false;
    }
    auto capacity = sum / 2;
    // 从nums.size()个元素，能找出一个组合将capacity为sum/2的背包装满，即找到这个子序列
    // memo矩阵
    size_t height = nums.size();
    vector<vector<bool>> memo(height, vector<bool>(capacity + 1, false));
    // base case, memo[i][0]，capacity 为 0，因此都可以装满
    for (size_t i = 0; i < height; ++i) {
      memo[i][0] = true;
    }
    // base case, memo[0][c]，只使用 nums[0] 来装满 capacity
    for (int c = 1; c <= capacity; ++c) {
      memo[0][c] = nums[0] == c ? true : false;
    }
    // 状态转移迭代
    // memo[i - 1][c] 表示不使用第 i 个数 nums[i]
    // memo[i - 1][c - nums[i]] 表示使用第 i 个数 nums[i]
    for (size_t i = 1; i < height; ++i) {
      for (size_t c = 1; c <= capacity; ++c) {
        memo[i][c] =
            memo[i - 1][c] || (c >= nums[i] ? memo[i - 1][c - nums[i]] : false);
      }
    }
    return memo[height - 1][capacity];
  }
};
// leetcode submit region end(Prohibit modification and deletion)
