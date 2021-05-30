//
// Created by liyingmin on 2020/3/30.
//

#include <string>
using std::string;

// 动态规划
// 可以转换为 反序后 LCS 问题
// Time: O(N^2) Space: O(N^2) --> O(N)
class Solution1 {
 public:
  string longestPalindrome(string s) {

  }
};

// 时间复杂度 O(N^2)，空间复杂度 O(1)
class Solution {
 private:
  string palindrome(const string& s, int l, int r) {
    // 防止索引越界
    while (l >= 0 && r < s.size()
        && s[l] == s[r]) {
      // 向两边展开
      l--; r++;
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