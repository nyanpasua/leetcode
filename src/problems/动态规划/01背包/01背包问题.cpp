//
// Created by liyingmin on 2020/3/29.
//
#include <vector>
using std::vector;
#include <algorithm>
// 给你一堆物品，物品的重量是 weights,物品对应的价值是 values，问题是如何使用一个书包，可以
// 载重 capacity，使得书包可以获得最大价值的装包方案
// weights.size() == values.size()，
// capacity为背包的最大weight，返回背包可装最大value的值
int knapsack01(const vector<int>& weights, const vector<int>& values,
               int capacity) {
  size_t height = weights.size();
  assert(height == values.size());
  // memo[i][c] 矩阵，表示使用 [0...i] 物品装包载重 c 的包的最大价值
  // height*width，高度为物品的数量，宽度为 capacity + 1
  vector<vector<int>> memo(height,
                           vector<int>(capacity + 1, 0));  // 注意capacity + 1
  // 初始化base case, height方向，capacity == 0
  for (size_t i = 0; i < height; ++i) {
    memo[i][0] = 0;
  }
  // capacity（width）方向，只使用第一个物品 weights[0] 装包
  for (size_t c = 1; c <= capacity; ++c) {
    memo[0][c] = weights[0] > c ? 0 : values[0];
  }
  // 状态转移迭代
  // memo[i][c] = max(memo[i - 1][c], value[i] + memo[i - 1][c - weight[i]])
  // memo[i - 1][c] 为不装第 i 物品 weights[i] 的最大价值
  // value[i] + memo[i - 1][c - weight[i]] 装第 i 物品的最大价值
  for (size_t i = 1; i < height; ++i) {
    for (size_t c = 1; c <= capacity; ++c) {
      memo[i][c] = std::max(
          memo[i - 1][c],
          c - weights[i] >= 0 ? values[i] + memo[i - 1][c - weights[i]] : 0);
    }
  }
  return memo[height - 1][capacity];
}