//给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s
//是否可以被空格拆分为一个或多个在字典中出现的单词。
//
// 说明：
//
//
// 拆分时可以重复使用字典中的单词。
// 你可以假设字典中没有重复的单词。
//
//
// 示例 1：
//
// 输入: s = "leetcode", wordDict = ["leet", "code"]
//输出: true
//解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
//
//
// 示例 2：
//
// 输入: s = "applepenapple", wordDict = ["apple", "pen"]
//输出: true
//解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
//     注意你可以重复使用字典中的单词。
//
//
// 示例 3：
//
// 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
//输出: false
//
// Related Topics 动态规划
// 👍 1014 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
using std::vector;
#include <string>
using std::string;

/// 完全背包问题，排列
class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    vector<bool> dp(n + 1, false);
    // base，使用任意 word 都可以拼凑 空集合
    dp[0] = true;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < wordDict.size(); ++j) {
        auto word = wordDict[j];
        auto sz = word.size();
        // 如果可以使用 word
        if (i >= sz && s.substr(i - sz, sz) == word) {
          dp[i] = dp[i - sz] || dp[i];
        }
      }
    }

    return dp[n];
  }
};
// leetcode submit region end(Prohibit modification and deletion)
