//给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
//
// 子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7]
// 是数组 [0,3,1,6,2,2,7] 的子序
//列。
//
//
// 示例 1：
//
//
//输入：nums = [10,9,2,5,3,7,101,18]
//输出：4
//解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
//
//
// 示例 2：
//
//
//输入：nums = [0,1,0,3,2,3]
//输出：4
//
//
// 示例 3：
//
//
//输入：nums = [7,7,7,7,7,7,7]
//输出：1
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 2500
// -104 <= nums[i] <= 104
//
//
//
//
// 进阶：
//
//
// 你可以设计时间复杂度为 O(n2) 的解决方案吗？
// 你能将算法的时间复杂度降低到 O(n log(n)) 吗?
//
// Related Topics 二分查找 动态规划
// 👍 1646 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
using std::vector;
/// 二分查找+贪心
// O(NlogN)
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int len = 1, n = (int)nums.size();
    if (n == 0) {
      return 0;
    }
    // d 数组用于记录 最长严格递增子序列长度 对应的 最小结尾数字 num[i]
    // d 数组一定是一个递增数组
    vector<int> d(n + 1, 0);
    d[len] = nums[0];
    for (int i = 1; i < n; ++i) {
      if (nums[i] > d[len]) {
        d[++len] = nums[i];
      } else {
        // 当 nums[i] <= d[len]，即 <= 当前最长递增子序列结尾的数字
        // 在范围 d[l...r] 二分查找 nums[i]
        // 将 d 数组中 比 nums[i] 小 并且 最接近 nums[i] 的位置 pos 找到
        // 如果找不到说明所有的数都 不小于 nums[i]，此时要更新 d[1]，所以这里将
        // pos 设为 0
        int l = 1, r = len, pos = 0;
        while (l <= r) {
          int mid = l + (r - l) / 2;
          if (d[mid] < nums[i]) {
            pos = mid;
            l = mid + 1;
          } else {
            r = mid - 1;
          }
        }
        // 原 d[pos+1] >= nums[i]
        // 更新 pos + 1 的 最长递增子序列 对应的 最小结尾数字 为 nums[i]
        // 因为 pos 位置的 最长递增子序列 对应的 最小结尾数字 严格 < nums[i]
        // 因此 d[pos+1] = nums[i] 满足贪心条件，使得 d[pos+1] 更小
        d[pos + 1] = nums[i];
      }
    }
    return len;
  }
};

/// 动态规划
// Time: O(N^2)
class Solution1 {
 public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.size() <= 1) {
      return nums.size();
    }
    // memo[i]表示nums[0...i]这个子序列中，最长上升子序列的元素个数
    vector<int> memo(nums.size(), 1);
    // base case, 无
    // 状态转移 memo[i](j < i) = 1 + max(memo[0...j]) if (nums[i] > nums[0...j])
    for (size_t i = 1; i < nums.size(); ++i) {
      for (size_t j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
          memo[i] = std::max(memo[i], memo[j] + 1);
        }
      }
    }
    return *(std::max_element(memo.begin(), memo.end()));
  }
};
// leetcode submit region end(Prohibit modification and deletion)
