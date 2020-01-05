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

int lengthOfLongestSubstring(const std::string& s);
vector<int> findAnagrams(string s, string p);
string minWindow(string s, string t);
void moveZeroes(vector<int>& nums);
int removeDuplicates(vector<int>& nums);
int removeElement(vector<int>& nums, int val);
int removeDuplicatesII(vector<int>& nums);

}  // namespace leetcode
}  // namespace horizon

#endif  // INCLUDE_LEETCODE_LEETCODE_H_
