// 在一个数组 nums
// 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
// 输入：nums = [9,1,7,9,7,9,7]
//输出：1
#include <vector>
using std::vector;
// 如下图所示，考虑数字的二进制形式，对于出现三次的数字，各 二进制位
// 出现的次数都是 3 的倍数。 因此，统计所有数字的各二进制位中 1
// 的出现次数，并对 3 求余，结果则为只出现一次的数字。

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int ones = 0, twos = 0;
    for (const auto& num: nums) {
      ones = (ones ^ num) & (~twos);
      twos = (twos ^ num) & (~ones);
    }
    return ones;
  }
};
