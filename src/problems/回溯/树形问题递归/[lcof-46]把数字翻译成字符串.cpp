// 给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成
// “b”，……，11 翻译成 “l”，……，25 翻译成
// “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
// 输入: 12258
// 输出: 5
// 解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
// 输入：506
// 输出：1
// 解释：<5,0,6>, <5, 06> 不行
#include <string>
using std::string;

class Solution {
 public:
  int translateNum(int num) {
    if (num < 0) return 0;
    auto s = std::to_string(num);
    recursion(s, 0);
    return res_;
  }

 private:
  int res_{0};
  void recursion(const string& s, int index) {
    if (index == s.size()) {
      res_++;
      return;
    }
    // 递推一位
    recursion(s, index + 1);
    // 递推两位
    if (index + 2 <= s.size() && is_valid(s.substr(index, 2)))
      recursion(s, index + 2);
  }
  static bool is_valid(const string& sub) { return sub >= "10" && sub <= "25"; }
};
