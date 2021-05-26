
// 求解 a 的 n 次方

class Solution {
 public:
  int power(int a, int n) { return recursion(a, n); }

 private:
  int recursion(int a, int n) {
    if (n == 1) return a;
    if (n == 2) return a * a;
    auto res = recursion(a, n / 2);
    if (n % 2)
      return a * res * res;
    else
      return res * res;
  }
};
