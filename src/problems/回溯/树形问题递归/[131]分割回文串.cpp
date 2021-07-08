//给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s
//所有可能的分割方案。
//
// 回文串 是正着读和反着读都一样的字符串。
//
//
//
// 示例 1：
//
//
//输入：s = "aab"
//输出：[["a","a","b"],["aa","b"]]
//
//
// 示例 2：
//
//
//输入：s = "a"
//输出：[["a"]]
//
//
//
//
// 提示：
//
//
// 1 <= s.length <= 16
// s 仅由小写英文字母组成
//
// Related Topics 字符串 动态规划 回溯
// 👍 769 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <string>
#include <vector>
using std::string;
using std::vector;

/// 回溯+动态规划预处理回文子串
// 可以预处理 s 的每一个子串 s[i...j] 是否为回文串；
// is_palindrome[i][j] 表示 子串 s[i..j] 是否为回文串；
class Solution {
 public:
  vector<vector<string>> partition(string s) {
    int n = s.size();
    is_palindrome_ = std::vector<vector<bool>>(n, vector<bool>(n, true));
    // 动态规划预处理
    // is_palindrome_[i][j] = true;  i >= j，就是矩阵的左下三角矩阵
    // is_palindrome_[i][j] = s[i] == s[j] && is_palindrome_[i+1][j-1]
    // 因此依赖关系为 依赖 更大的 i，和 更小的 j；
    // 因此动态规划的 i 方向应该从 n-1 到 0；j 方向应该 从 i+1 到 n-1；
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i + 1; j < n; ++j) {
        is_palindrome_[i][j] = (s[i] == s[j] && is_palindrome_[i + 1][j - 1]);
      }
    }
    // 回溯
    vector<string> ans;
    dfs(s, 0, ans);
    return res_;
  }

 private:
  // 从 start 开始找 回文子串，满足则推入 ans
  void dfs(const string& s, int start, vector<string>& ans) {
    if (start > s.size()) return;
    if (start == s.size()) {
      res_.push_back(ans);
      return;
    }
    for (int i = start; i < s.size(); ++i) {
      // [start...i]
      if (is_palindrome_[start][i]) {
        ans.push_back(s.substr(start, i - start + 1));
        dfs(s, i + 1, ans);
        ans.pop_back();
      }
    }
  }
  vector<vector<string>> res_;
  vector<vector<bool>> is_palindrome_;
};
// leetcode submit region end(Prohibit modification and deletion)
