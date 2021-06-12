//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的
//括号组合。
//
//
//
// 示例 1：
//
//
//输入：n = 3
//输出：["((()))","(()())","(())()","()(())","()()()"]
//
//
// 示例 2：
//
//
//输入：n = 1
//输出：["()"]
//
//
//
//
// 提示：
//
//
// 1 <= n <= 8
//
// Related Topics 字符串 回溯算法
// 👍 1818 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <string>
#include <vector>
using std::string;
using std::vector;

/// 回溯法
// 现有 2n 个位置，每个位置可以放置字符 '(' 或者
// ')'，组成的所有括号组合中，有多少是合法的
// 1) 一个 "合法" 括号组合的左括号数量一定等于右括号数量。
// 2) 对于一个 "合法" 的括号字符串 str，必然对于任何 0 <= i < len(str)
// 都有：子串 str[0, i] 中左括号的数量都大于或等于右括号的数量。
/// 剪枝
// left 表示可以使用的左括号数量，right 表示还可以使用的右括号数量
// 若当前遍历的还可以使用的左括号数 > 还可以使用的右括号数，
// 即 left > right 此时一定不可能生成一个 "合法"
// 的括号字符串，直接回溯到上一层即可。
// if (left < 0 || right < 0) return ;
// if (left > right) return ;
/// 递归
// if (left > 0) trackback(left - 1, right, curStr + "(");
// if (right > 0) trackback(left, right - 1, curStr + ")");
//
class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    trackback(n, n, "");
    return res_;
  }

 private:
  void trackback(int left, int right, string s) {
    // 递归到底
    if (left == 0 && right == 0) {
      res_.emplace_back(s);
    }
    // 剪枝
    if (left < 0 || right < 0) return;
    if (left > right) return;
    if (left > 0) trackback(left - 1, right, s + "(");
    if (right > 0) trackback(left, right - 1, s + ")");
  }
  vector<string> res_;
};
// leetcode submit region end(Prohibit modification and deletion)
