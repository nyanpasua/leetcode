// 输入: [7,5,6,4]
//
// 输出: 5

#include <vector>
using std::vector;

/// 使用归并排序的思路，每一次归并的过程，实际上就是找逆序对的过程
/// Time: O(nlogn) Space: O(n)
class Solution {
 public:
  int reversePairs(vector<int>& nums) {
    return MergeSort(nums, 0, nums.size());
  }

 private:
  ///
  /// \param nums
  /// \param left 需要归并的左界，闭区间
  /// \param right 需要归并的右届，开区间
  /// \return 逆序个数
  int MergeSort(std::vector<int>& nums, size_t left, size_t right) {
    // 递归到底，只剩下一个或者一个都没有，直接返回 0
    if (left + 1 >= right) {
      return 0;
    }
    int reverse_num = 0;
    // 二分
    auto mid = left + (right - left) / 2;
    reverse_num += MergeSort(nums, left, mid);
    reverse_num += MergeSort(nums, mid, right);
    // 合并两个已排序的子区间
    reverse_num += merge(nums, left, mid, right);
    return reverse_num;
  }

  int merge(std::vector<int>& nums, size_t left, size_t mid, size_t right) {
    // 创建临时空间，将nums相应的内容拷贝过来
    vector<int> temp;
    temp.resize(right - left);
    for (size_t i = left; i < right; ++i) {
      temp[i - left] = nums[i];
    }
    auto i = left;
    auto j = mid;
    int reverse_num = 0;
    // 循环 right - left 次
    for (size_t k = left; k < right; ++k) {
      if (i >= mid) {
        // 右侧部分还有多余的
        nums[k] = temp[j - left];
        ++j;
      } else if (j >= right) {
        // 左侧部分多余
        nums[k] = temp[i - left];
        ++i;
      } else if (temp[i - left] <= temp[j - left]) {
        nums[k] = temp[i - left];
        ++i;
      } else {
        nums[k] = temp[j - left];
        ++j;
        reverse_num += static_cast<int>(mid - i);
      }
    }
    return reverse_num;
  }
};