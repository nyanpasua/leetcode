//
// Created by liyingmin on 2020/3/30.
//

#pragma once
#include <algorithm>
#include <vector>
using std::vector;
namespace alpha {

std::pair<int, int> partition(vector<int> &nums, int l, int r) {
  // 对闭区 [l...r] 进行 partition 操作
  size_t lt = l;
  size_t gt = r + 1;  // 左闭右开
  size_t i = l + 1;
  // 这里可以添加随机化
  auto v = nums[l];
  // 下面这一轮循环结束后，lt 指向最后一个 < v 的元素
  // i 和 gt 指向第一个 > v 的元素
  // l 仍指向 == v 的元素
  //                     i
  // [2  1  -1  2  2  2  5  3  6  7  9]
  //  l     lt           gt          r
  while (i < gt) {
    if (nums[i] == v) {
      ++i;
    } else if (nums[i] < v) {
      std::swap(nums[i++], nums[++lt]);
    } else {
      std::swap(nums[i], nums[--gt]);
    }
  }
  //                     i
  // [-1  1  2  2  2  2  5  3  6  7  9]
  //   l     lt          gt          r
  std::swap(nums[lt], nums[l]);
  return std::pair<int, int>{lt, gt};
}

void quick_sort(vector<int> &nums, int l, int r) {
  // 对闭区间 [l...r] 进行三路快排
  if (l >= r) {
    return;
  }
  auto p = partition(nums, l, r);
  quick_sort(nums, l, p.first - 1);
  quick_sort(nums, p.second, r);
}

void sort(vector<int> &nums) { quick_sort(nums, 0, nums.size() - 1); }
}  // namespace alpha
