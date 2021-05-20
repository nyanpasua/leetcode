// 在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s
// 只包含小写字母。
// s = "abaccdeff" 返回 "b"
//
// s = ""
// 返回 " "
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
 public:
  char firstUniqChar(string s) {
    if (s.empty()) return ' ';
    // 查找表
    std::vector<int> mapping(26, 0);
    // 顺序表
    std::vector<char> order;
    order.reserve(26);
    for (int i = 0; i < s.size(); ++i) {
      mapping[s[i] - 'a']++;
      if (mapping[s[i] - 'a'] == 1) {
        order.push_back(s[i]);
      }
    }
    // 遍历顺序表
    for (const auto &ch : order) {
      if (mapping[ch - 'a'] == 1) {
        return ch;
      }
    }
    return ' ';
  }
};
