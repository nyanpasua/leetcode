//
// Created by liyingmin on 2020/3/30.
//

// 给定一个数组，这个数组是有序递增并且不重复的，找出其中值和下标相等的子集
// [-7, -5, 2, 3, 4, 8, 9, 100] --> [2, 3, 4]

#include <vector>
using std::vector;

class Solution {
 public:
  vector<int> findSubset(vector<int> &nums) {
    int left, right;
    find_right(nums, &right);
    find_left(nums, &left);
    return vector<int>(nums.begin() + left, nums.begin() + right);
  }

 private:
  void find_right(const vector<int> &nums, int *right) {
    int l = 0, r = nums.size() - 1;  // [l...r]
    while (l <= r) {
      auto mid = l + (r - l) / 2;
      if (nums[mid] > mid) {
        // 向左找
        r = mid - 1;
      } else if (nums[mid] < mid) {
        // 向右找
        l = mid + 1;
      } else {
        // 找右边界
        // 最终 r 将停留在区间最后一个元素位置，[2,3,4]的4
        // 这里可以和上面 elif 合并
        l = mid + 1;
      }
    }
    *right = r + 1;  // 返回尾后
  }
  void find_left(const vector<int> &nums, int *left) {
    int l = 0, r = nums.size() - 1;  // [l...r]
    while (l <= r) {
      auto mid = l + (r - l) / 2;
      if (nums[mid] > mid) {
        // 向左找
        r = mid - 1;
      } else if (nums[mid] < mid) {
        // 向右找
        l = mid + 1;
      } else {
        // 找左边界
        // 最终 l 将停留在区间第一个元素位置，[2,3,4]的2
        // 这里可以和上面 if 合并
        r = mid - 1;
      }
    }
    *left = l;
  }
};
