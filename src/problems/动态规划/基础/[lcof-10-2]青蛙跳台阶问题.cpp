// n 级台阶，共有多少种跳发，实际上这和
// 斐波拉契数字是一样的
// 递推关系： f(n) = f(n - 1) + f(n - 2)
#include <vector>
class Solution {
 public:
  int numWays(int n) {
    if (n == 0) {
      return 1;
    }

    std::vector<int> memo(n + 1, 0);
    // base
    memo[0] = 1;
    memo[1] = 1;
    // 递推
    for (int i = 2; i <= n; ++i) {
      memo[i] = (memo[i - 1] + memo[i - 2]) % 1000000007;
    }
    return memo[n];
  }
};
