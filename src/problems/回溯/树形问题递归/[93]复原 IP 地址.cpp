//给定一个只包含数字的字符串，用以表示一个 IP 地址，返回所有可能从 s 获得的 有效
// IP 地址 。你可以按任何顺序返回答案。
//
// 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导
// 0），整数之间用 '.' 分隔。
//
// 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是
// "0.011.255.245"、"192.168.1.312"
//和 "192.168@1.1" 是 无效 IP 地址。
//
//
//
// 示例 1：
//
//
//输入：s = "25525511135"
//输出：["255.255.11.135","255.255.111.35"]
//
//
// 示例 2：
//
//
//输入：s = "0000"
//输出：["0.0.0.0"]
//
//
// 示例 3：
//
//
//输入：s = "1111"
//输出：["1.1.1.1"]
//
//
// 示例 4：
//
//
//输入：s = "010010"
//输出：["0.10.0.10","0.100.1.0"]
//
//
// 示例 5：
//
//
//输入：s = "101023"
//输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
//
//
//
//
// 提示：
//
//
// 0 <= s.length <= 3000
// s 仅由数字组成
//
// Related Topics 字符串 回溯
// 👍 624 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <string>
#include <vector>
using std::string;
using std::vector;

/// 回溯
class Solution {
 public:
  vector<string> restoreIpAddresses(string s) {
    vector<int> ans;
    recursion(s, 0, ans);
    return res_;
  }

 private:
  void recursion(const string& s, int start, vector<int>& ans) {
    // 递归到底
    if (ans.size() == 4 && start == s.size()) {
      // 满足条件
      res_.push_back(to_string(ans));
      return;
    }
    if (start >= s.size() || ans.size() > 4) return;
    int i = start;
    int num = 0;
    // 不能包含前导 0
    while (num <= 255 && i < s.size()) {
      num = num * 10 + (s[i] - '0');
      if (num < 10 && i > start) {
        break;
      }
      if (num <= 255) {
        ans.push_back(num);
        recursion(s, i + 1, ans);
        ans.pop_back();
      }
      ++i;
    }
  }

  string to_string(const vector<int>& ip) {
    // convert ip to string
    string ans;
    for (int i = 0; i < ip.size(); ++i) {
      ans += std::to_string(ip[i]);
      ans += ".";
    }
    ans.pop_back();  // 移除最后 .
    return ans;
  }

  std::vector<string> res_;
};
// leetcode submit region end(Prohibit modification and deletion)
