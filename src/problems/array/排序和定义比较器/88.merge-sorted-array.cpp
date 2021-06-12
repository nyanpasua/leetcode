//
// Created by liyingmin on 2020/1/5.
//
/*!
 * @brief https://leetcode-cn.com/problems/merge-sorted-array/
 * Time: O(n)
 * Space: O(1)
 */
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  int i = m - 1;
  int j = n - 1;
  int target = i + j + 1;
  while (target >= 0) {
    if (i < 0 && j >= 0) {
      nums1[target--] = nums2[j--];
    } else if (j < 0 && i >= 0) {
      break;
    } else if (nums1[i] <= nums2[j]) {
      nums1[target--] = nums2[j--];
    } else {
      nums1[target--] = nums1[i--];
    }
  }
}
