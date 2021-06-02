//
// Created by liyingmin on 2020/3/30.
//

#ifndef LEETCODE_INCLUDE_LEETCODE_DATA_STRUCTURE_QUICKSORT3WAYS_H_
#define LEETCODE_INCLUDE_LEETCODE_DATA_STRUCTURE_QUICKSORT3WAYS_H_

std::pair<int, int> _partition3way(vector<int> &nums, int l,
                                         int r) {
  size_t lt = l;
  size_t gt = r + 1;
  size_t i = l + 1;
  auto v = nums[l];
  while (i < gt) {
    if (nums[i] == v) {
      ++i;
    } else if (nums[i] < v) {
      std::swap(nums[i++], nums[++lt]);
    } else {
      std::swap(nums[i], nums[--gt]);
    }
  }
  std::swap(nums[lt], nums[l]);
  return std::pair<int, int>{lt, gt};
}

void _quickSort3Ways(vector<int> &nums, int l, int r) {
  if (l >= r) {
    return;
  }
  auto p = _partition3way(nums, l, r);
  _quickSort3Ways(nums, l, p.first - 1);
  _quickSort3Ways(nums, p.second, r);
}

void quickSort3Ways(vector<int> &nums) {
  _quickSort3Ways(nums, 0, nums.size() - 1);
}
#endif  // LEETCODE_INCLUDE_LEETCODE_DATA_STRUCTURE_QUICKSORT3WAYS_H_
