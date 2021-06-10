//给定一个经过编码的字符串，返回它解码后的字符串。
//
// 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k
// 次。注意 k 保证为正整数。
//
// 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
//
// 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k
// ，例如不会出现像 3a 或 2[4] 的输入。
//
//
//
// 示例 1：
//
// 输入：s = "3[a]2[bc]"
//输出："aaabcbc"
//
//
// 示例 2：
//
// 输入：s = "3[a2[c]]"
//输出："accaccacc"
//
//
// 示例 3：
//
// 输入：s = "2[abc]3[cd]ef"
//输出："abcabccdcdcdef"
//
//
// 示例 4：
//
// 输入：s = "abc3[cd]xyz"
//输出："abccdcdcdxyz"
//
// Related Topics 栈 深度优先搜索
// 👍 782 👎 0

// leetcode submit region begin(Prohibit modification and deletion)

#include <cctype>
#include <stack>
#include <string>
using std::string;
/// 使用栈
// 括号内嵌套括号，需要从内向外生成与拼接字符串，这与栈的先入后出特性对应
class Solution {
 public:
  string decodeString(string s) {
    stack<int> s_multi;
    stack<string> s_res;
    int multi = 0;
    string res;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '[') {
        // 将 multi 和 res 入栈,暂存前面的字符串
        s_multi.push(multi);
        s_res.push(res);
        // 更新 multi 和 res 为空
        multi = 0;
        res = "";
      } else if (s[i] == ']') {
        // 目前的 res 已经可以和之前的 res 进行拼接
        int cur_multi = s_multi.top();
        s_multi.pop();
        string tmp;
        string last_res = s_res.top();
        for (int i = 0; i < cur_multi; ++i) tmp += res;
        res = last_res + tmp;
        s_res.pop();
      } else if (std::isdigit(s[i])) {
        multi = multi * 10 + (s[i] - '0');
      } else {
        res.append(1, s[i]);
      }
    }
    return res;
  }
};

/// 深度优先遍历
class Solution1 {
 public:
  string decodeString(string s) {
    if (s.empty()) return "";
    idx = 0;
    return recursion(s);
  }

 private:
  size_t idx;
  // 定义递归函数为 从 idx 开始解析 src,并添加结果到返回值
  string recursion(const string& src) {
    if (idx == src.size() || src[idx] == ']') {
      return "";
    }
    auto cur = src[idx];
    string res;
    if (std::isdigit(cur)) {
      // String -> Digits [ String ] String
      // 解析 Digits
      int rep = 0;
      while (idx < src.size() && isdigit(src[idx])) {
        rep = rep * 10 + src[idx++] - '0';
      }
      // 过滤左括号
      ++idx;
      // 解析 String
      string str = recursion(src);
      // 过滤右括号
      ++idx;
      // 构造字符串
      while (rep--) res += str;
    } else {
      res = string(1, cur);
      idx++;
    }
    return res + recursion(src);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
