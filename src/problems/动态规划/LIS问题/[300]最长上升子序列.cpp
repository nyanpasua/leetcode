//
// Created by liyingmin on 2020/3/29.
//
#include <vector>
using std::vector;
/// 二分查找+贪心
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int len = 1, n = (int)nums.size();
    if (n == 0) {
      return 0;
    }
    vector<int> d(n + 1, 0);
    d[len] = nums[0];
    for (int i = 1; i < n; ++i) {
      if (nums[i] > d[len]) {
        d[++len] = nums[i];
      } else {
        int l = 1, r = len,
            pos = 0;  // 如果找不到说明所有的数都比 nums[i] 大，此时要更新
                      // d[1]，所以这里将 pos 设为 0
        while (l <= r) {
          int mid = (l + r) >> 1;
          if (d[mid] < nums[i]) {
            pos = mid;
            l = mid + 1;
          } else {
            r = mid - 1;
          }
        }
        d[pos + 1] = nums[i];
      }
    }
    return len;
  }
};

/// 动态规划
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