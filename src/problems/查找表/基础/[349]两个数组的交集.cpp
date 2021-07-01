/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

//给定两个数组，编写一个函数来计算它们的交集。
//
//
//
// 示例 1：
//
// 输入：nums1 = [1,2,2,1], nums2 = [2,2]
//输出：[2]
//
//
// 示例 2：
//
// 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//输出：[9,4]
//
//
//
// 说明：
//
//
// 输出结果中的每个元素一定是唯一的。
// 我们可以不考虑输出结果的顺序。
//
// Related Topics 数组 哈希表 双指针 二分查找 排序
// 👍 383 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1, set2;
    for (auto& num : nums1) {
      set1.insert(num);
    }
    for (auto& num : nums2) {
      set2.insert(num);
    }
    return getIntersection(set1, set2);
  }

  vector<int> getIntersection(unordered_set<int>& set1,
                              unordered_set<int>& set2) {
    if (set1.size() > set2.size()) {
      return getIntersection(set2, set1);
    }
    vector<int> intersection;
    for (auto& num : set1) {
      if (set2.count(num)) {
        intersection.push_back(num);
      }
    }
    return intersection;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
