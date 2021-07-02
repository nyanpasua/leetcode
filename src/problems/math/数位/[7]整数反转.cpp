/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

//给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
//
// 如果反转后整数超过 32 位的有符号整数的范围 [−231, 231 − 1] ，就返回 0。
//假设环境不允许存储 64 位整数（有符号或无符号）。
//
//
//
// 示例 1：
//
//
//输入：x = 123
//输出：321
//
//
// 示例 2：
//
//
//输入：x = -123
//输出：-321
//
//
// 示例 3：
//
//
//输入：x = 120
//输出：21
//
//
// 示例 4：
//
//
//输入：x = 0
//输出：0
//
//
//
//
// 提示：
//
//
// -231 <= x <= 231 - 1
//
// Related Topics 数学
// 👍 2855 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <limits>

class Solution {
 public:
  int reverse(int x) {
    // 读取符号位
    int res = 0;
    while (x != 0) {
      // 越界保护
      int digit = x % 10;
      if (res > std::numeric_limits<int>::max() / 10 ||
          res < std::numeric_limits<int>::min() / 10)
        return 0;
      // 最大值 2147483647
      if (res == std::numeric_limits<int>::max() / 10 && digit > 7) return 0;
      // 最小值 -2147483648
      if (res == std::numeric_limits<int>::min() / 10 && digit < -8) return 0;
      res = res * 10 + digit;
      x /= 10;
    }
    return res;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
