/// 由于 f(n) = f(n - 1) + f(n - 2)
/// 因此可以使用动态规划
#include <vector>
class Solution {
 public:
  int fib(int n) {
    if (n == 0) return 0;
    std::vector<int> memo(n + 1, 0);
    // base case
    memo[0] = 0;
    memo[1] = 1;
    for (int i = 2; i <= n; ++i) {
      memo[i] = (memo[i - 1] + memo[i - 2]) % 1000000007;
    }
    return memo[n];
  }
};
