//
// Created by yingmin li on 2021/7/1.
// Copyright (c) 2021 Kwai, Inc. All rights reserved.
//

#pragma once

#include <algorithm>
#include <vector>
using std::vector;

namespace alpha {
//	• 插入排序是稳定的排序
//	•
//因为可以提前终止，这个提前终止可以cover掉其比选择排序更多的交换操作的开销，因此一般来说比选择排序快。
//	•
//随机序列的时候，在待排序的元素比较少的时候（比如<100个），也可以使用插入排序。
//		• 为什么<100个，不使用nlogn的排序算法？
//			○ 需要递归的快速排序，消耗O(logn)的堆栈空间
//			○ 自底向上的归并排序(不需要递归)，消耗O(n)的空间复杂度
//			○
//堆排序，比较的几乎都不是相邻元素，对cache极不友好，因此很少被采用
//○ 而且元素较少时，插入排序可能优于nlogn级别的排序算法（由于系数）
//○ 综上考虑，当递归到元素比较少的时候，可以考虑使用插入排序。
//在序列基本正序的时候，插入排序是所有排序里面最快的：O(n)

void insertSort(vector<int>& arr) {
  int n = arr.size();
  if (n <= 0) return;
  for (int i = 1; i < n; ++i) {
    int temp = arr[i];
    // 使 [0...j] 有序，处理 index j 的数字，temp 为待插入的值；
    // 这里 temp < arr[j-1]，循环就终止了，此时 j 的位置就是 temp 该插入的位置
    for (int j = i; j > 0 && temp < arr[j - 1]; --j) {
      arr[j] = arr[j - 1];
    }
    arr[j] = temp;
  }
}

}  // namespace alpha
