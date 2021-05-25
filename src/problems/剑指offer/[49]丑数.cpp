// 我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly
// Number）。求按从小到大的顺序的第 n 个丑数。

// 输入: n = 10
// 输出: 12
// 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
// 1 是丑数。
// n 不超过1690。
class Solution {
 public:
  int nthUglyNumber(int n) {
    std::vector<int> memo(n, 0);
    memo[0] = 1;
    int a = 0, b = 0, c = 0;
    for (int i = 1; i < n; ++i) {
      memo[i] = std::min({memo[a] * 2, memo[b] * 3, memo[c] * 5});
      if (memo[i] >= memo[a] * 2) ++a;
      if (memo[i] >= memo[b] * 3) ++b;
      if (memo[i] >= memo[c] * 5) ++c;
    }
    return memo[n - 1];
  }
};
