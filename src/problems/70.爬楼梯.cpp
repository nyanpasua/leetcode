//
// Created by liyingmin on 2020/3/27.
//
// 暴力递归
class Solution {
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
class Solution {
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

// 暴力回溯（略），模拟走的所有路径，计数求和

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