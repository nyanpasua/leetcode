// 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1
// 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
// 输入：
// [2, 3, 1, 0, 2, 5, 3]
// 输出：2 或 3

#include <vector>
using std::vector;
/// 此题容易想到的思路是使用哈希表，每次都以 O(1) 的复杂度去找哈希；
/// 但是题目中一个条件没有利用到，就是所有数字的取值范围都在 0~n-1
/// 因此，题目中元素的索引和值 是 一对多 的关系；如果不重复，则是 一对一 的关系
/// 如果不重复，由于 index 和 value，排序后是一一对应的，原地交换排序，复杂度 O(n)
/// Time: O(n)，n 为 nums 数组的元素个数
/// Space: O(1)
class Solution {
 public:
  int findRepeatNumber(vector<int>& nums) {
    size_t i = 0;
    while (i < nums.size()) {
      if (nums[i] == i) {
        ++i;
        continue;
      }
      // 原地交换排序过程中，如果发现 nums[value] = value，则该数重复
      if (nums[nums[i]] == nums[i]) return nums[i];
      std::swap(nums[i], nums[nums[i]]);
    }
    return -1;
  }
};