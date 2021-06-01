//
// Created by liyingmin on 2020/3/27.
// 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

#include <vector>
using std::vector;
// 动态规划
class Solution {
 public:
  int climbStairs(int n) {
    if (n == 1) {return 1;}
    std::vector<int> memo(n + 1, -1);
    memo[1] = 1;
    memo[2] = 2;
    for (int i = 3; i <= n; ++i) {
      memo[i] = memo[i - 1] + memo[i - 2];
    }
    return memo[n];
  }
};

// 暴力递归
class Solution2 {
 public:
  int climbStairs(int n) {
    if (n == 1) {
      return 1;
    }
    if (n == 2) {
      return 2;
    }
    return climbStairs(n - 1) + climbStairs(n - 2);
  }
};

// 记忆化递归
class Solution1 {
 private:
  std::vector<int> memo;
  int searchWays(int n) {
    if (n == 1) {
      return 1;
    }
    if (n == 2) {
      return 2;
    }
    if (memo[n] == -1) {
      memo[n] = searchWays(n - 1) + searchWays(n - 2);
    }
    return memo[n];
  }

 public:
  int climbStairs(int n) {
    memo = std::move(vector<int>(n + 1, -1));
    return searchWays(n);
  }
};
