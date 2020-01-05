//
// Created by liyingmin on 2020/1/5.
//
#include "leetcode/leetcode.h"
namespace horizon {
namespace leetcode {

int removeDuplicatesII(vector<int>& nums) {
  if (nums.empty()) {
    return 0;
  }
  size_t target = 0;
  size_t counter = 1;
  for (size_t j = 1; j < nums.size(); ++j) {
    if (nums[j] != nums[target]) {
      counter = 1;
      nums[++target] = nums[j];
    } else {
      ++counter;
      if (counter <= 2) {
        nums[++target] = nums[j];
      }
    }
  }
  return ++target;
}
}  // namespace leetcode
}  // namespace horizon