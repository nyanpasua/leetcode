/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

//给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
//
// 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str
// 中的每个非空单词之间存在着双向连接的对应规律。
//
// 示例1:
//
// 输入: pattern = "abba", str = "dog cat cat dog"
//输出: true
//
// 示例 2:
//
// 输入:pattern = "abba", str = "dog cat cat fish"
//输出: false
//
// 示例 3:
//
// 输入: pattern = "aaaa", str = "dog cat cat dog"
//输出: false
//
// 示例 4:
//
// 输入: pattern = "abba", str = "dog dog dog dog"
//输出: false
//
// 说明:
//你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。
// Related Topics 哈希表 字符串
// 👍 350 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  bool wordPattern(string pattern, string words) {
    auto sv = split(words, " ");
    vector<string> word(sv.begin(), sv.end());
    if (word.size() != pattern.size()) {
      return false;
    }
    std::unordered_map<string, char> w_p;
    unordered_map<char, string> p_w;
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

 private:
  std::vector<std::string_view> split(std::string_view strv,
                                      std::string_view delims = " ") {
    std::vector<std::string_view> output;
    size_t first = 0;

    while (first < strv.size()) {
      const auto second = strv.find_first_of(delims, first);

      if (first != second)
        output.emplace_back(strv.substr(first, second - first));

      if (second == std::string_view::npos) break;

      first = second + 1;
    }

    return output;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
