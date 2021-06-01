
#include <cassert>
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

// by Chris Lomont, the fastest sqrt in the world
class Solution {
 public:
  float sqrt(float x) {
    float xhalf = 0.5f * x;
    int i = *(int*)&x;          // get bits for floating VALUE
    i = 0x5f375a86 - (i >> 1);  // gives initial guess y0
    x = *(float*)&i;            // convert bits BACK to float
    x = x *
        (1.5f - xhalf * x * x);  // Newton step, repeating increases accuracy
    return 1 / x;
  }
};

// by quake3
class Solution3 {
 public:
  float sqrt(float x) {
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = x * 0.5f;
    y = x;
    i = *(long*)&y;             // evil floating point bit level hacking
    i = 0x5f3759df - (i >> 1);  // what the fuck?
    y = *(float*)&i;
    y = y * (threehalfs - (x2 * y * y));  // 1st iteration
    // y   = y * ( threehalfs - ( x2 * y * y ) ); // 2nd iteration, this can be
    // removed

    assert(!isnan(y));  // bk010122 - FPE?
    return 1 / y;
  }
};

// 牛顿迭代法
class Solution2 {
 public:
  float sqrt(float x) {
    float val = x;  //最终
    float last;     //保存上一个计算的值
    do {
      last = val;
      val = (val + x / val) / 2;
    } while (!almost_equal(val, last, 2));
    return val;
  }
};

// 二分法
class Solution1 {
 public:
  float sqrt(float x) {
    if (x < 0.0) return x;
    float low = 0.0, up = x;
    auto mid = low + (up - low) / 2;
    float last = 0.0;
    do {
      if (mid * mid > x) {
        // 向左二分
        up = mid;
      } else {
        // 向右二分
        low = mid;
      }
      last = mid;
      mid = low + (up - low) / 2;
    } while (!almost_equal(last, mid, 2));
    return mid;
  }
};

// refer: https://diducoder.com/sotry-about-sqrt.html
