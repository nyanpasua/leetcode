// 求 1+2+...+n
// 要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

class Solution {
 public:
  int sumNums(int n) {
    n > 1 && (n += sumNums(n - 1));
    return n;
  }

};

class Solution1 {
 public:
  int sumNums(int n) {
    if (n == 1) return 1;
    return n + sumNums(n - 1);
  }
};
