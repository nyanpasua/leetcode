// 数字以0123456789101112131415…的格式序列化到一个字符序列中。
// 在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。
//
//请写一个函数，求任意第n位对应的数字。
//
#include <string>
class Solution {
 public:
  int findNthDigit(int n) {
    int digit = 1;
    long start = 1;
    long count = 9;  // count = 9 * digit * start
    while (n > count) {
      digit += 1;
      start *= 10;
      n -= count;
      count = 9 * digit * start;
    }
    // n 所在 digit 和 start
    // 确定所求数位所在的数字
    long num = start + (n - 1) / digit;
    // 确定所求数位在 num 的哪一数位
    // 获得 num 的 第 (n - 1) % digit 个数位，并转化为 int
    return std::to_string(num)[(n - 1) % digit] - '0';
  }
};
