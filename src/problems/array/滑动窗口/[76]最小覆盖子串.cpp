//给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s
//中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
//
// 注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。
//
//
//
// 示例 1：
//
//
//输入：s = "ADOBECODEBANC", t = "ABC"
//输出："BANC"
//
//
// 示例 2：
//
//
//输入：s = "a", t = "a"
//输出："a"
//
//
//
//
// 提示：
//
//
// 1 <= s.length, t.length <= 105
// s 和 t 由英文字母组成
//
//
//
//进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？ Related Topics 哈希表
//双指针 字符串 Sliding Window
// 👍 1183 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <limits>
#include <string>
#include <unordered_map>
#include <vector>
using std::string;
using std::vector;

class Solution1 {
 private:
  std::unordered_map<char, int> ori, cnt;

  bool check() {
    for (const auto& p : ori) {
      if (cnt[p.first] < p.second) {
        return false;
      }
    }
    return true;
  }

 public:
  string minWindow(string s, string t) {
    for (const auto& c : t) {
      ++ori[c];
    }

    int l = 0, r = -1;
    int len = INT_MAX, ansL = -1, ansR = -1;

    while (r < int(s.size())) {
      if (ori.find(s[++r]) != ori.end()) {
        ++cnt[s[r]];
      }
      while (check() && l <= r) {
        if (r - l + 1 < len) {
          len = r - l + 1;
          ansL = l;
        }
        if (ori.find(s[l]) != ori.end()) {
          --cnt[s[l]];
        }
        ++l;
      }
    }

    return ansL == -1 ? string() : s.substr(ansL, len);
  }
};

/// 滑动窗中做记录，会超时
// 使用滑动窗，使用 vector<int>(128, 0)记录每个字符出现的次数
class Solution {
 public:
  Solution() : t_table_{vector<int>(128, 0)}, table_{vector<int>(128, 0)} {}
  string minWindow(string s, string t) {
    build_table(t);
    int i = 0;                 // [i, j]
    int start = -1, end = -1;  // [start, end]
    int min_len = std::numeric_limits<int>::max();
    for (int j = 0; j < s.size(); ++j) {
      ++table_[s[j]];
      // 移动 i
      while (match_t() && i <= j) {
        int cur_len = j - i + 1;
        if (cur_len < min_len) {
          min_len = cur_len;
          start = i;
          end = j;
        }
        --table_[s[i]];
        ++i;
      }
    }
    return start == -1 ? "" : s.substr(start, end - start + 1);
  }

 private:
  bool match_t() {
    for (int i = 0; i < 128; ++i) {
      if (table_[i] < t_table_[i]) return false;
    }
    return true;
  }
  void build_table(const string& t) {
    for (const char i : t) {
      ++t_table_[i];
    }
  }
  vector<int> t_table_;
  vector<int> table_;
};
// leetcode submit region end(Prohibit modification and deletion)
