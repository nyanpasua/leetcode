/*!
 * Copyright (c) 2016-present, Horizon Robotics, Inc.
 * All rights reserved.
 * \File     leetcode.h
 * \Author   Yingmin Li
 * \Mail     yingmin.li-horizon.ai
 * \Version  1.0.0.0
 * \Date     2019/1/10
 * \Brief    implement of api header
 */
#ifndef INCLUDE_LEETCODE_LEETCODE_H_
#define INCLUDE_LEETCODE_LEETCODE_H_
#include <string>
#include <vector>
namespace horizon {
namespace leetcode {
using std::string;
using std::vector;

class HelloWorldLEETCODE {
 public:
  HelloWorldLEETCODE();
};
/// \brief 3 滑动窗口
int lengthOfLongestSubstring(const std::string& s);
/// \brief 438 滑动窗口
vector<int> findAnagrams(string s, string p);
/// \brief 76 滑动窗口
string minWindow(string s, string t);
/// \brief 283 滑动窗口
void moveZeroes(vector<int>& nums);
/// \brief 26 快慢指针
int removeDuplicates(vector<int>& nums);
/// \brief 27 快慢指针
int removeElement(vector<int>& nums, int val);
namespace II {
/// \brief 80 快慢指针
int removeDuplicates(vector<int>& nums);
}
/// \brief 75 partition
void sortColors(vector<int>& nums);
/// \brief 88 merge
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
/// \brief 215 heap
int findKthLargest(vector<int>& nums, int k);
/// \brief 11 对撞指针
int maxArea(vector<int>& height);
/// \brief 209 滑动窗口
int minSubArrayLen(int s, vector<int>& nums);
/// \brief 451 查找表
string frequencySort(string s);
/// \brief 454 查找表
namespace II {
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D);
}
}  // namespace leetcode
}  // namespace horizon

#endif  // INCLUDE_LEETCODE_LEETCODE_H_
