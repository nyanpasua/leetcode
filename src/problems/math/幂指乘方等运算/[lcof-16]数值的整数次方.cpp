// 0001111 --> 15
// 15 --> 7 --> 3 --> 1
// 1 --> 3 --> 7 --> 15
// res *= X --> X 为: x --> x^2 --> x^4 --> x^8
// 1 * x --> x * x^2 --> x^3 * x^4 --> x^7 * x^8

// 1 --> 2 --> 4 --> 8 --> 16
// 1 * x --> x^2 --> x^4 --> x^8 --> x^16

#include <cmath>
#include <limits>
template <class T>
typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type
almost_equal(T x, T y, int ulp) {
  // the machine epsilon has to be scaled to the magnitude of the values used
  // and multiplied by the desired precision in ULPs (units in the last place)
  return std::fabs(x - y) <=
             std::numeric_limits<T>::epsilon() * std::fabs(x + y) * ulp
         // unless the result is subnormal
         || std::fabs(x - y) < std::numeric_limits<T>::min();
}
class Solution {
 public:
  double myPow(double x, int n) {
    if (almost_equal(x, 0.0, 2)) {
      return 0.0;
    }
    long n_b = n;
    if (n_b < 0) {
      x = 1 / x;
      n_b = -n_b;
    }
    double res = 1.0;
    while (n_b > 0) {
      if (n_b & 1) res *= x;
      x *= x;
      n_b >>= 1;
    }
    return res;
  }
};