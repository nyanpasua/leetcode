//
// Created by liyingmin on 2020/3/30.
//

#ifndef LEETCODE_INCLUDE_LEETCODE_DATA_STRUCTURE_BINARYSEARCH_H_
#define LEETCODE_INCLUDE_LEETCODE_DATA_STRUCTURE_BINARYSEARCH_H_

int binarySearch(const vector<int>& nums, int target) {
  size_t l = 0;
  sizt_t r = nums.size() - 1;
  // [l...r]里找target
  while (l <= r) {
    size_t mid = l + (r - l) / 2;
    if (nums[mid] == target) {
      return mid;
    }
    if (nums[mid] > target) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return -1;
}

#endif  // LEETCODE_INCLUDE_LEETCODE_DATA_STRUCTURE_BINARYSEARCH_H_
