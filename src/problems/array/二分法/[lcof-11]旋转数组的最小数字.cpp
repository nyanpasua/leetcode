// 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组[3,4,5,1,2]
// 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。

//
// 输入：[3,4,5,1,2]
// 输出：1
// [1,0,1,1,1] ：旋转点 x = 1，因此 m = 2 在 右排序数组
// [1,1,1,0,1] ：旋转点 x = 3，因此 m = 2 在 左排序数组
#include <vector>
using std::vector;

/// 此题优先考虑二分，由于数组被划分为两个有序端，左端所有元素应该 >= 右端最大值
/// num[r] 二分思路：记左侧为 l， 右侧位 r，二分中点为 mid，[l...r]
/// 1. 如果 nums[mid] > nums[r], 则 mid 一定属于左端序列，因此 l = mid + 1
/// 2. 如果 nums[mid] < nums[r], 则 mid 一定属于右端序列，因此 r = mid, [l...r]
/// 3. 困难的是 nums[mid] == nums[r], 这个时候无法判断 mid 属于哪个端
/// 实际上，当出现 nums[m] = nums[j] 时，一定有区间 [i, m]
/// 内所有元素相等 或 区间 [m, j]
/// 内所有元素相等（或两者皆满足）。
/// 对于寻找此类数组的最小值问题，可直接放弃二分查找，而使用线性查找替代。
class Solution {
 public:
  int minArray(vector<int>& numbers) {
    int l = 0;
    int r = numbers.size() - 1;  // [l...r]
    while (l < r) {
      // 循环结束后，l 指向最小值
      int mid = l + (r - l) / 2;
      if (numbers[mid] > numbers[r]) {
        l = mid + 1;
      } else if (numbers[mid] < numbers[r]) {
        r = mid;
      } else {
        // 直接从 [l...r] 遍历找最小值
        int min = numbers[l];
        for (int i = l + 1; i <= r; ++i) {
          if (numbers[i] < min) min = numbers[i];
        }
        return min;
      }
    }
    return numbers[l];
  }
};