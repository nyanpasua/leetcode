// 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出
// 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

#include <unordered_map>
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    // 保存从 nums[i] 到 i 的表
    std::unordered_map<int, int> hashtable;
    for (int i = 0; i < nums.size(); ++i) {
      auto it = hashtable.find(target - nums[i]);
      if (it != hashtable.end()) {
        return {it->second, i};
      } else
        hashtable[nums[i]] = i;
    }
    return {};
  }
};
/// 暴力枚举,不借助 hash 表
class Solution1 {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < nums.size(); ++j) {
        if (j != i && nums[j] == target - nums[i]) return {i, j};
      }
    }
    return {};
  }
};
