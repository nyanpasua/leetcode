//给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
//
//
// 请你找出并返回 strs 的最大子集的大小，该子集中 最多 有 m 个 0 和 n 个 1 。
//
// 如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。
//
//
//
//
// 示例 1：
//
//
//输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
//输出：4
//解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是
// 4 。 其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"}
//不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。
//
//
// 示例 2：
//
//
//输入：strs = ["10", "0", "1"], m = 1, n = 1
//输出：2
//解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
//
//
//
//
// 提示：
//
//
// 1 <= strs.length <= 600
// 1 <= strs[i].length <= 100
// strs[i] 仅由 '0' 和 '1' 组成
// 1 <= m, n <= 100
//
// Related Topics 动态规划
// 👍 506 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
using std::vector;
#include <string>
using std::string;

/// 01背包
// 从集合中找到一组子集，使得子集满足 最多 m 个 0，n 个
// 1，并且子集的元素个数最多。
// 定义三维数组 dp，其中 dp[i][j][k] 表示在前 i
// 个字符串中，
// 使用 j 个 0 和 k 个 1 的情况下最多可以得到的字符串数量。
// 假设数组 str 的长度为 l，则最终答案为 dp[l][m][n]
// 如果 j<zeros 或 k<ones，则不能选第 i
// 个字符串，此时有dp[i][j][k]=dp[i−1][j][k]；
//
//如果 j≥zeros 且 k≥ones，则 1.如果不选第 i
// 个字符串，有dp[i][j][k]=dp[i-1][j][k]，
// 2.如果选第 i
// 个字符串，有dp[i][j][k]=dp[i-1][j-zeros][k-ones]+1，应取上面两项中的最大值。
//
class Solution {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    // dp[0][j][k] 表示空集合里满足条件的子集，元素个数为 0
    vector<vector<vector<int>>> dp(
        strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
    for (int i = 1; i <= strs.size(); ++i) {
      auto zero_one = get01pair(strs[i - 1]);
      int zeros = zero_one[0], ones = zero_one[1];
      for (int j = 0; j <= m; ++j) {
        for (int k = 0; k <= n; ++k) {
          dp[i][j][k] = dp[i - 1][j][k];
          if (j >= zeros && k >= ones) {
            dp[i][j][k] =
                std::max(dp[i - 1][j - zeros][k - ones] + 1, dp[i][j][k]);
          }
        }
      }
    }
    return dp[strs.size()][m][n];
  }

 private:
  vector<int> get01pair(const string& str) {
    vector<int> zero_one(2, 0);
    int length = str.length();
    for (int i = 0; i < length; i++) {
      zero_one[str[i] - '0']++;
    }
    return zero_one;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
