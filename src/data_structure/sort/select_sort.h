#pragma once

#include <algorithm>
#include <vector>
using std::vector;

namespace alpha {
// 	• 这种选择的思想，恰恰又是堆排序的思想。堆排序也是一种选择排序。
//	•
//在完全随机的序列中，选择排序是移动次数最少的排序，因此在待排序的元素比较少的时候（比如<100个），也可以使用选择排序。
//	• 为什么<100个，不使用nlogn的排序算法？
//		○ 需要递归的快速排序，消耗O(logn)的堆栈空间
//		○ 自底向上的归并排序(不需要递归)，消耗O(n)的空间复杂度
//		○
//堆排序，比较的几乎都不是相邻元素，对cache极不友好，因此很少被采用 ○
//而且元素较少时，选择排序可能优于nlogn级别的排序算法（由于系数） ○
//综上考虑，当递归到元素比较少的时候，可以考虑使用选择排序。 		○
//你可能还会问，为什么不用插入排序呢？插入排序一定比选择排序快？
//§
//插入排序理论上确实比选择排序快（因为可以提前终止），但是相比选择排序有更多移动操作，如果要比较的元素不是int，而是较大的class，选择排序性能就会相对好一些。
//	• 选择排序是不稳定的排序
//选择排序不能提前终止，因此即便比插入排序移动次数更少，但是一般来说，性能没有插入排序好

void selectSort(vector<int>& arr) {
  int n = arr.size();
  if (n <= 0) return;
  for (int i = 0; i < n - 1; ++i) {
    int min_idx = i;
    // 从 [i,n) 找到最小值
    for (int j = i; j < n; ++j) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    std::swap(arr[i], arr[min_idx]);
  }
}

}  // namespace alpha