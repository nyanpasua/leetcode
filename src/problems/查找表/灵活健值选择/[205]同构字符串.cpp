/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

//给定两个字符串 s 和 t，判断它们是否是同构的。
//
// 如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。
//
// 每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。
//
//
//
// 示例 1:
//
//
//输入：s = "egg", t = "add"
//输出：true
//
//
// 示例 2：
//
//
//输入：s = "foo", t = "bar"
//输出：false
//
// 示例 3：
//
//
//输入：s = "paper", t = "title"
//输出：true
//
//
//
// 提示：
//
//
// 可以假设 s 和 t 长度相同。
//
// Related Topics 哈希表 字符串
// 👍 364 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  bool isIsomorphic(string word, string pattern) {
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
