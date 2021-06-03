// 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
// 请你找出并返回这两个正序数组的 中位数 。
// 输入：nums1 = [1,2], nums2 = [3,4]
//输出：2.50000
//解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
//输入：nums1 = [1,3], nums2 = [2]
//输出：2.00000
//解释：合并数组 = [1,2,3] ，中位数 2
//输入：nums1 = [2], nums2 = []
//输出：2.00000

#include <algorithm>
#include <limits>
#include <vector>
using std::vector;

// 还存在一种复杂度更低的算法
// Time: O(logmin(m, n)) Space: O(1)
class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
      return findMedianSortedArrays(nums2, nums1);
    }

    int m = nums1.size();
    int n = nums2.size();
    int left = 0, right = m;
    // median1：前一部分的最大值
    // median2：后一部分的最小值
    int median1 = 0, median2 = 0;

    while (left <= right) {
      // 前一部分包含 nums1[0 .. i-1] 和 nums2[0 .. j-1]
      // 后一部分包含 nums1[i .. m-1] 和 nums2[j .. n-1]
      int i = (left + right) / 2;
      int j = (m + n + 1) / 2 - i;

      // nums_im1, nums_i, nums_jm1, nums_j 分别表示 nums1[i-1], nums1[i],
      // nums2[j-1], nums2[j]
      int nums_im1 = (i == 0 ? std::numeric_limits<int>::min() : nums1[i - 1]);
      int nums_i = (i == m ? std::numeric_limits<int>::max() : nums1[i]);
      int nums_jm1 = (j == 0 ? std::numeric_limits<int>::min() : nums2[j - 1]);
      int nums_j = (j == n ? std::numeric_limits<int>::max() : nums2[j]);

      if (nums_im1 <= nums_j) {
        median1 = std::max(nums_im1, nums_jm1);
        median2 = std::min(nums_i, nums_j);
        left = i + 1;
      } else {
        right = i - 1;
      }
    }

    return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
  }
};

// 二分查找，该问题可以转换为查找两个数组里第 k 大的数：
// k 为偶数：(m+n)/2 和 (m+n)/2+1，k 为奇数：(m+n+1)/2 或者 (m+n)/2+1
// 注意，这里的 k 表示第 k 个，比如
// [3, 4] 和 [2, 5] 得到 (2+2)/2 和 (2+2)/2+1
// [1] 和 [2, 3] 得到 (1+2 +1)/2
// Time: O(log(m+n)) Space: O(1)
class Solution1 {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int total = nums1.size() + nums2.size();
    if (total % 2 == 1) {
      return find_kth(nums1, nums2, (total + 1) / 2);
    } else {
      return (find_kth(nums1, nums2, total / 2) +
              find_kth(nums1, nums2, total / 2 + 1)) /
             2.0;
    }
  }

 private:
  int find_kth(const vector<int>& nums1, const vector<int>& nums2, int k) {
    /* 主要思路：要找到第 k (k>1) 大的元素，那么就取 pivot1 = nums1[k/2-1] 和
     * pivot2 = nums2[k/2-1] 进行比较 这里的 "/" 表示整除 nums1 中小于等于
     * pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个， nums2 中小于等于 pivot2
     * 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
     * 取 pivot = min(pivot1,pivot2)，
     * 两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) = k-2 个，
     * 这样 pivot 本身最大也只能是第 k-1 大的元素， 如果 pivot =
     * pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部
     * "删除"，剩下的作为新的 nums1 数组 如果 pivot = pivot2，那么 nums2[0 ..
     * k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的
     * nums2 数组 由于我们 "删除" 了一些元素（这些元素都比第 k
     * 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
     * 如此更新 k，直到 k == 1，返回 nums1 和 nums2 中第一个数里较小的即可
     */
    int m = nums1.size();
    int n = nums2.size();
    int idx1 = 0, idx2 = 0;
    while (true) {
      // 特殊边界情况
      if (idx1 >= m) {
        // 已经遍历完 nums1 或者 nums1 为空
        return nums2[idx2 + k - 1];
      }
      if (idx2 >= n) {
        return nums1[idx1 + k - 1];
      }
      // 循环到底的情况
      if (k == 1) {
        return std::min(nums1[idx1], nums2[idx2]);
      }
      // 正常情况
      int new_idx1 = std::min(idx1 + k / 2 - 1, m - 1);
      int new_idx2 = std::min(idx2 + k / 2 - 1, n - 1);
      int pivot1 = nums1[new_idx1];
      int pivot2 = nums2[new_idx2];
      if (pivot1 <= pivot2) {
        // 删除 [idx1, new_idx1]
        k -= (new_idx1 - idx1 + 1);
        idx1 = new_idx1 + 1;
      } else {
        k -= (new_idx2 - idx2 + 1);
        idx2 = new_idx2 + 1;
      }
    }
  }
};