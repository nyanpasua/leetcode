/*!
 * Copyright (c) 2016-present, Horizon Robotics, Inc.
 * All rights reserved.
 * \File     test_api.cpp
 * \Author   Yingmin Li
 * \Mail     yingmin.li-horizon.ai
 * \Version  1.0.0.0
 * \Date     2019/1/10
 * \Brief    implement of test_api.cpp
 */
#include "gtest/gtest.h"
#include "hobotlog/hobotlog.hpp"
#include "sys/utsname.h"

namespace horizon {
namespace leetcode {
namespace test {

TEST(leetcode, api) {
  SetLogLevel(INFO);
  struct utsname name {};
  if (uname(&name)) {
    exit(-1);
  }
  LOGI << "Hello! Your remote computer's OS is " << name.sysname << " "
       << name.release;
  LOGI << "Test leetcode api file success";
}

}  // namespace test
}  // namespace leetcode
}  // namespace horizon
