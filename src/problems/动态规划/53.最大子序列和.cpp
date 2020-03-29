//
// Created by liyingmin on 2020/3/29.
//
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    if (nums.size() == 1) {
      return nums[0];
    }
    vector<int> memo(nums.size(), 0);
    // base case:
    memo[0] = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
      if (memo[i - 1] > 0) {
        memo[i] = memo[i - 1] + nums[i];
      } else {
        memo[i] = nums[i];
      }
    }
    return *(std::max_element(memo.begin(), memo.end()));
  }
};