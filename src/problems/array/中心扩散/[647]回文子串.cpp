//给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
//
// 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
//
//
//
// 示例 1：
//
// 输入："abc"
//输出：3
//解释：三个回文子串: "a", "b", "c"
//
//
// 示例 2：
//
// 输入："aaa"
//输出：6
//解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
//
//
//
// 提示：
//
//
// 输入的字符串长度不会超过 1000 。
//
// Related Topics 字符串 动态规划
// 👍 613 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <string>
using std::string;

/// 中心扩散法
// Time: O(N^2)
// Space: O(1)
class Solution {
 public:
  int countSubstrings(string s) {
    for (int i = 0; i < s.size(); ++i) {
      // 以 s[i] 为中心
      palindrome(s, i, i);
      // 以 s[i] s[i+1] 为中心
      palindrome(s, i, i + 1);
    }
    return res_;
  }

 private:
  void palindrome(const string& s, int l, int r) {
    // 防止索引越界
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
      // 向两边展开
      l--;
      r++;
      ++res_;
    }
  }
  int res_{0};
};
// leetcode submit region end(Prohibit modification and deletion)
