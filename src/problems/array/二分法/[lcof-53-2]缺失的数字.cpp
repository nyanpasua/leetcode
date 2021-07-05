// 一个长度为n-1的递增排序数组中的所有数字都是唯一的，
// 并且每个数字都在范围0～n-1之内。
// 在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
// [0 1 2 4 5] 缺失 3

#include <vector>
using std::vector;

/// 思路，二分法，mid 的 index 与数字相等，向右找，反之向左找
class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    size_t l = 0;
    size_t r = nums.size();
    while (l < r) {
      auto mid = l + (r - l) / 2;
      if (nums[mid] == mid) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return static_cast<int>(r);
  }
};