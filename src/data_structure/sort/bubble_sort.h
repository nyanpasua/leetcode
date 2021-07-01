//
// Created by yingmin li on 2021/7/1.
// Copyright (c) 2021 Kwai, Inc. All rights reserved.
//

#pragma once

#include <algorithm>
#include <vector>
using std::vector;

namespace alpha {

void bubbleSort(vector<int>& arr) {
  int n = arr.size();
  if (n <= 0) return;
  for (int i = n - 1; i > 0; --i) {
    // [0...j) 找最大值
    for (int j = 0; j < i; ++j) {
      if (arr[j + 1] < arr[j]) {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
}

}  // namespace alpha
