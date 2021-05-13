/*
 * @lc app=leetcode.cn id=890 lang=cpp
 *
 * [890] 查找和替换模式
 */

// leetcode submit region begin(Prohibit modification and deletion)
#include <string>
#include <unordered_map>
#include <vector>
/// 思路：采用双 hash 表，如 xxz 和 aab，<x, a> <z, b> 对应 <a, x> <b, z>
/// 如果 xyz 和 aab，<x, a> <y, a> <z, b> 不对应 <a, x> <b, z>
/// Time: O(n), n 表示所有字符的长度
/// Space: O(两个哈希表的空间)
using std::string;
using std::vector;
class Solution {
 public:
  vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    std::vector<string> match_words;
    for (const auto& word : words) {
      if (is_pattern(word, pattern)) {
        match_words.emplace_back(word);
      }
    }
    return match_words;
  }

 private:
  inline static bool is_pattern(const std::string& word,
                                const std::string& pattern) {
    std::unordered_map<char, char> w_p, p_w;
    if (word.size() != pattern.size()) {
      return false;
    }
    for (size_t i = 0; i < word.size(); ++i) {
      auto w = word[i];
      auto p = pattern[i];
      if (!w_p.count(w)) {
        w_p[w] = p;
      }
      if (!p_w.count(p)) {
        p_w[p] = w;
      }
      if (w_p[w] != p || p_w[p] != w) {
        return false;
      }
    }
    return true;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
