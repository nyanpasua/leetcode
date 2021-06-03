//  某公司生产长钢管，然后一般，会将钢条切断，变成不同长度，然后去售卖。
//  其中有个问题是，不同长度的钢管的售价是不一样的，但是它们并不是完全按照比例来，
//  比如2米的钢管售价要比3米的钢管售价要少，但是并不是2比3的比例。
// 于是问题就来了，比如30米长的钢管，要如何切割，切割成多长的几条，才能让售价最高，收益最高呢？

#include <algorithm>
#include <vector>
using std::vector;
// prices[n] 表示长度为 n 的钢管的售价，prices[0] = 0
// 假设 prices.size() >= n + 1
class Solution {
 public:
  int cut_rod(const vector<int>& prices, int n) {
    // 记录长度为 n 的钢管的最大售价
    vector<int> dp(n + 1, 0);
    // base case
    dp[1] = prices[1];  // 1m 最多卖 prices[1]
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j < i; ++j) {
        dp[i] = std::max(dp[i], dp[i - j] + prices[j]);
      }
    }
    return dp[n];
  }
};