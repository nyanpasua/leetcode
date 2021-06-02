//
// Created by liyingmin on 2020/1/5.
//

#ifndef LEETCODE_INCLUDE_LEETCODE_DATA_STRUCTURE_SORT_H_
#define LEETCODE_INCLUDE_LEETCODE_DATA_STRUCTURE_SORT_H_
#include <vector>
using std::vector;

template <typename T>
// 对已经排序的区间[l, mid], [mid + 1， r]做merge
void _merge(vector<T> nums, int l, int mid, int r) {
  // 创建临时空间，将nums相应的内容拷贝过来
  vector<T> temp;
  temp.resize(r - l + 1);
  for (int i = l; i <= r; ++i) {
    temp[i - l] = nums[i];
  }
  // merge过程，比较temp[0, middle]&[middle+1, r-l+1]区间的数据，放到nums区间[l, r]
  int i = l, j = mid + 1;
  // 遍历temp[0, r-l+1]的数据，依次放入nums[k]
  for (int k = l; k <= r; ++k) {
    // 如果右侧部分还有多余的
    if (i > mid) {
      nums[k] = temp[j - l];
      ++j;
    } else if (j > r) {  // 左侧部分多余
      nums[k] = temp[i - l];
      ++i;
    } else if (temp[i - l] < temp[j - l]) {
      nums[k] = temp[i - l];
      ++i;
    } else {
      nums[k] = temp[j - l];
      ++j;
    }
  }

}


template <typename T>
// 递归使用归并排序，对区间[begin_idx, end_idx]做归并
void _mergeSort(vector<T> nums, int begin_idx, int end_idx) {
  // 递归到底，只有1个或者1个都没有的情况
  if (begin_idx >= end_idx) {
    return;
  }
  //  int mid = (begin_idx + end_idx) / 2;
  //  begin_idx + end_idx可能超出size_t的范围
  int mid = begin_idx + (end_idx - begin_idx) / 2;
  _mergeSort(nums, begin_idx, mid);
  _mergeSort(nums, mid + 1, end_idx);
  // 对左右排序好的[begin_idx, mid]和[mid + 1, end_idx]做merge
  _merge(nums, begin_idx, mid, end_idx);
}


template <typename T>
void MergeSort(vector<T> &nums) {
  // 对index: [0, nums.size() - 1]这个区间做mergeSort
  _mergeSort(nums, 0, nums.size() - 1);
}

#endif  // LEETCODE_INCLUDE_LEETCODE_DATA_STRUCTURE_SORT_H_
