//给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2
//所使用的最少操作数 。
//
// 你可以对一个单词进行如下三种操作：
//
//
// 插入一个字符
// 删除一个字符
// 替换一个字符
//
//
//
//
// 示例 1：
//
//
//输入：word1 = "horse", word2 = "ros"
//输出：3
//解释：
// horse -> rorse (将 'h' 替换为 'r')
// rorse -> rose (删除 'r')
// rose -> ros (删除 'e')
//
//
// 示例 2：
//
//
//输入：word1 = "intention", word2 = "execution"
//输出：5
//解释：
// intention -> inention (删除 't')
// inention -> enention (将 'i' 替换为 'e')
// enention -> exention (将 'n' 替换为 'x')
// exention -> exection (将 'n' 替换为 'c')
// exection -> execution (插入 'u')
//
//
//
//
// 提示：
//
//
// 0 <= word1.length, word2.length <= 500
// word1 和 word2 由小写英文字母组成
//
// Related Topics 字符串 动态规划
// 👍 1640 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution {
 public:
  int minDistance(string word1, string word2) {
    size_t height = word1.size() + 1;
    size_t width = word2.size() + 1;
    vector<vector<int>> memo(height, std::move(vector<int>(width, -1)));
    // base case
    for (size_t i = 0; i < height; ++i) {
      memo[i][0] = i;
    }
    for (size_t j = 0; j < width; ++j) {
      memo[0][j] = j;
    }
    // 状态转移迭代
    for (size_t i = 1; i < height; ++i) {
      for (size_t j = 1; j < width; ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          // i - 1 和 j - 1 的字符相同，左斜对角到这里不需要任何编辑距离
          memo[i][j] = memo[i - 1][j - 1];  // 啥都不做
        } else {
          // 字符不等，左侧和上侧的最小值 + 1
          memo[i][j] =
              std::min({memo[i - 1][j], memo[i][j - 1], memo[i - 1][j - 1]}) +
              1;
        }
      }
    }
    return memo[height - 1][width - 1];
  }
};
// leetcode submit region end(Prohibit modification and deletion)
