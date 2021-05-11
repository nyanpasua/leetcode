//
// Created by liyingmin on 2020/3/29.
//
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.size() <= 1) {
      return nums.size();
    }
    // memo[j]表示nums[0...j]这个子序列中，最长上升子序列的元素个数
    vector<int> memo(nums.size(), 1);
    // base case, 无
    // 状态转移 memo[i](j < i) = 1 + max(memo[0...j]) if (nums[i] > nums[j])
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