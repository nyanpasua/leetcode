//
// Created by liyingmin on 2020/3/29.
//
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
    vector<int> memo(nums.size() + 1, -1);
    memo[1] = nums[0];
    memo[2] = std::max(nums[0], nums[1]);
    for (size_t i = 3; i <= nums.size(); ++i) {
      memo[i] = nums[i - 1] + memo[i - 2] > memo[i - 1] ?
                nums[i - 1] + memo[i - 2] : memo[i - 1];
    }
    return memo[nums.size()];
  }
};