//
// Created by liyingmin on 2020/1/5.
//
/*!
 * @brief Given a sorted array nums, remove the duplicates in-place such that
each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the
input array in-place with O(1) extra memory.
 */

int removeDuplicates(vector<int>& nums) {
  if (nums.empty()){
    return 0;
  }
  size_t target = 0;
  for (size_t j = 1; j < nums.size(); ++j) {
    if (nums[j] != nums[target]) {
      nums[++target] = nums[j];
    }
  }
  return ++target;
}
