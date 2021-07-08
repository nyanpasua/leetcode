//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
//
//
//
// 提示：
//
//
// num1 和num2 的长度都小于 5100
// num1 和num2 都只包含数字 0-9
// num1 和num2 都不包含任何前导零
// 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式
//
// Related Topics 数学 字符串 模拟
// 👍 390 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <string>
using std::string;

class Solution {
 public:
  string addStrings(string num1, string num2) {
    // 从尾部开始加和，和 两数相加类似
    int tail1 = num1.size() - 1;
    int tail2 = num2.size() - 1;
    int carry = 0;
    string res;
    while (tail1 >= 0 || tail2 >= 0 || carry > 0) {
      int n1 = tail1 >= 0 ? num1[tail1--] - '0' : 0;
      int n2 = tail2 >= 0 ? num2[tail2--] - '0' : 0;
      int tmp = n1 + n2 + carry;
      int digit = tmp % 10;
      carry = tmp / 10;
      res.push_back(digit + '0');
    }
    std::reverse(res.begin(), res.end());
    return res;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
