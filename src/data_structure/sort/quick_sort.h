//
// Created by liyingmin on 2020/3/30.
//

#pragma once
#include <algorithm>
#include <vector>
using std::vector;
namespace alpha {

size_t partition(vector<int> &nums, int l, int r) {
  // 对闭区 [l...r] 进行 partition 操作
  size_t i = l + 1;
  size_t j = l;
  // 这里 v 可以随机化处理
  auto v = nums[l];
  // [l+1...j] < v; [j+1...i-1]>=v;
  //                               i
  // [ 2  -1  1  -2  3  2  5  2  7 ]
  //   l          j              r
  while (i <= r) {
    if (nums[i] >= v) {
      ++i;
    } else {
      std::swap(nums[i++], nums[++j]);
    }
  }
  //                               i
  // [-2  -1  1   2  3  2  5  2  7 ]
  //   l          j              r
  std::swap(nums[j], nums[l]);
  // 最终 j 指向 v 的位置，但是可以发现右侧很多重复的 v 大小的元素
  return j;
}

size_t partition2(vector<int> &nums, int l, int r) {
  // 对闭区 [l...r] 进行 partition 操作
  size_t i = l + 1;
  size_t j = l;
  // 这里 v 可以随机化处理
  auto v = nums[l];
  // [l+1...j] <= v; [j+1...i-1]>v;
  //                               i
  // [ 2  -1  1  2  2  -2  3  5  7 ]
  //   l                j        r
  while (i <= r) {
    if (nums[i] > v) {
      ++i;
    } else {
      std::swap(nums[i++], nums[++j]);
    }
  }
  //                               i
  // [-2  -1  2  1  2   2  3  5  7 ]
  //   l                j        r
  std::swap(nums[j], nums[l]);
  // 最终 j 指向 v 的位置，但是可以发现左侧很多重复的 v 大小的元素
  return j;
}

void quick_sort(vector<int> &nums, int l, int r) {
  // 对闭区间 [l...r] 进行快速排序，2 路
  if (l >= r) {
    return;
  }
  auto p = partition(nums, l, r);
  quick_sort(nums, l, p - 1);
  quick_sort(nums, p + 1, r);
}

void sort(vector<int> &nums) { quick_sort(nums, 0, nums.size() - 1); }
}  // namespace alpha
