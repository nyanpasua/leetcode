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
namespace horizon {
namespace leetcode {

class HelloWorldLEETCODE {
 public:
  HelloWorldLEETCODE();
};

class Solution {
 public:
  Solution() = default;
  static int lengthOfLongestSubstring(const std::string& s);
};

}  // namespace leetcode
}  // namespace horizon

#endif  // INCLUDE_LEETCODE_LEETCODE_H_
