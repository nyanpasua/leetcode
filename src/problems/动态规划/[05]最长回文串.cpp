//
// Created by liyingmin on 2020/3/30.
//

#include <string>
#include <vector>
using std::string;
using std::vector;

// 动态规划
// 可以转换为 反序后 LCS 问题
// Time: O(N^2) Space: O(N^2) --> O(N)
class Solution1 {
 public:
  string longestPalindrome(string s) {
    string rev_s(s.rbegin(), s.rend());
    auto length = s.size();
    // dp 数组,记录每个位置最长公共子串的长度
    vector<vector<int>> dp(length + 1, vector<int>(length + 1, 0));
    // i 方向为 s, j 方向为 rev_s
    // 状态转移
    int max_end = 0;  // 记录最长公共子串的结尾 idx post
    int max_len = 0;  // 记录最长公共子串长度
    for (int i = 1; i <= length; ++i) {
      for (int j = 1; j <= length; ++j) {
        if (s[i - 1] == rev_s[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
          // 最大值一定出现在这里
          if (dp[i][j] > max_len) max_end = i;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
        max_len = std::max(dp[i][j], max_len);
      }
    }
    return s.substr(max_end - dp[length][length], dp[length][length]);
  }
};

// 时间复杂度 O(N^2)，空间复杂度 O(1)
class Solution {
 private:
  string palindrome(const string& s, int l, int r) {
    // 防止索引越界
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
      // 向两边展开
      l--;
      r++;
    }
    // 返回以 s[l] 和 s[r] 为中心的最长回文串
    return s.substr(l + 1, r - l - 1);
  }

 public:
  string longestPalindrome(string s) {
    string res;
    for (int i = 0; i < s.size(); i++) {
      // 以 s[i] 为中心的最长回文子串
      string s1 = palindrome(s, i, i);
      // 以 s[i] 和 s[i+1] 为中心的最长回文子串
      string s2 = palindrome(s, i, i + 1);
      // res = longest(res, s1, s2)
      res = res.size() > s1.size() ? res : s1;
      res = res.size() > s2.size() ? res : s2;
    }
    return res;
  }
};
