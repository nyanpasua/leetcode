//
// Created by liyingmin on 2020/3/30.
//

#ifndef LEETCODE_INCLUDE_LEETCODE_DATA_STRUCTURE_QUICKSORT_H_
#define LEETCODE_INCLUDE_LEETCODE_DATA_STRUCTURE_QUICKSORT_H_

size_t _partition(vector<int> &nums, size_t l, size_t r) {
  size_t i = l + 1;
  size_t j = l;
  auto v = nums[l];
  // [l+1...j] < v; [j+1...i-1]>=v;
  while (i <= r) {
    if (nums[i] >= v) {
      ++i;
    } else {
      std::swap(nums[i++], nums[++j]);
    }
  }
  std::swap(nums[j], nums[l]);
  return j;
}

void _quickSort(vector<int> &nums, size_t l, size_t r) {
  if (l >= r) {
    return;
  }
  auto p = _partition(nums, l, r);
  _quickSort(nums, l, p - 1);
  _quickSort(nums, p + 1, r);
}

void quickSort(vector<int> &nums) { _quickSort(nums, 0, nums.size() - 1); }
#endif  // LEETCODE_INCLUDE_LEETCODE_DATA_STRUCTURE_QUICKSORT_H_
