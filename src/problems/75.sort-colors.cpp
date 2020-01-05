//
// Created by liyingmin on 2020/1/5.
//
/*!
 * @brief https://leetcode-cn.com/problems/sort-colors/
 * Time: O(n)
 * Space: O(1)
 */

#include "leetcode/leetcode.h"
void sortColors(vector<int>& nums) {
  int lt = -1;
  int eq = 0;
  int gt = nums.size();
  int i = 0;
  // nums[0...lt] < 1, nums[lt + 1, i) = 1, nums[gt, size-1] > 1
  while (i < gt) {
    if (nums[i] > 1) {
      std::swap(nums[--gt], nums[i]);
    } else if (nums[i] < 1) {
      std::swap(nums[++lt], nums[i++]);
    } else {
      ++i;
    }
  }
}
