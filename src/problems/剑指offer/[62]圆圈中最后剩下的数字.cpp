// 例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，
// 则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。
class Solution {
 public:
  int lastRemaining(int n, int m) {
    // f(1, m) = 0;
    // f(n, m) = (f(n - 1) + m) % n
    int f = 0;
    for (int i = 2; i <= n; ++i) {
      f = (f + m) % i;
    }
    return f;
  }
};
