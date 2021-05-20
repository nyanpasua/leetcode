// 输入: s = "abcdefg", k = 2
// 输出: "cdefgab"
// 输入: s = "lrloseumgh", k = 6
// 输出: "umghlrlose"

#include <string>
using std::string;
// 字符串拼接是最高效的
class Solution {
 public:
  string reverseLeftWords(string s, int n) {
    return s.substr(n) + s.substr(0, n);
  }
};
