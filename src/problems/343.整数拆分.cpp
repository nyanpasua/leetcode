//
// Created by liyingmin on 2020/3/29.
//
class Solution {
 public:
  int integerBreak(int n) {
    if (n == 1 || n == 2) {
      return 1;
    }
    if (n == 3) {
      return 2;
    }
    vector<int> memo(n + 1, -1);
    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 3;
    for (int i = 4; i <= n; ++i) {
      for (int j = 1; j <= i / 2; ++j) {
        if (memo[j] * memo[i - j] > memo[i]) {
          memo[i] = memo[j] * memo[i - j];
        }
      }
    }
    return memo[n];
  }
};