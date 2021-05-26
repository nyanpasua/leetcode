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
      if ((bits & n) != 0) ++count;
      bits <<= 1;
    }
    return count;
  }
};
