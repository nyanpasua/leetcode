// 输入：00000000000000000000000000001011
//输出：3
//解释：输入的二进制串 00000000000000000000000000001011中，共有三位为 '1'。
//

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    if (n == 0) return 0;
    int res = 0;
    while (n != 0) {
      // 该运算可以快速定位 n 的下一位 1，直到 n == 0 停止
      n &= (n - 1);
      res++;
    }
    return res;
  }
};

class Solution1 {
 public:
  int hammingWeight(uint32_t n) {
    uint32_t bits = 1;
    int count = 0;
    for (int i = 0; i < 32; ++i) {
      // 通过 & 运算判断每一位是否为 1
      if ((bits & n) != 0) ++count;
      bits <<= 1;
    }
    return count;
  }
};
