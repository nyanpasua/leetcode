//
// Created by liyingmin on 2020/3/29.
//
// weights.size() == values.size()，
// capacity为背包的最大weight，返回背包可装最大value的值
int knapsack01(const vector<int>& weights, const vector<int>& values,
               int capacity) {
  size_t height = weights.size();
  assert(height == values.size());
  // memo矩阵，height*width
  vector<vector<int>> memo(height,
                           vector<int>(capacity + 1, 0));  // 注意capacity + 1
  // 初始化base case, height方向
  for (size_t i = 0; i < height; ++i) {
    memo[i][0] = 0;
  }
  // capacity（width）方向
  for (size_t c = 1; c <= capacity; ++c) {
    memo[0][c] = weights[0] > c ? 0 : values[0];
  }
  // 状态转移迭代
  // memo[i][c] = max(memo[i - 1][c], value[i] + memo[i - 1][c - weight[i]])
  for (size_t i = 1; i < height; ++i) {
    for (size_t c = 1; c <= capacity; ++c) {
      memo[i][c] =
          max(memo[i - 1][c],
              c - weights[i] >= 0 ? value[i] + memo[i - 1][c - weights[i]] : 0);
    }
  }
  return memo[height - 1][capacity];
}