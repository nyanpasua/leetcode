// 一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
// 请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
// 输入：nums = [4,1,4,6]
// 输出：[1,6] 或 [6,1]
#include <vector>
using std::vector;

class Solution {
 public:
  vector<int> singleNumbers(vector<int>& nums) {
    int xor_res = 0;
    for (const auto& num : nums) {
      xor_res ^= num;
    }
    int flag = 1;
    // must add (), == precedence before &
    //   while ((flag & xor_res) == 0) {
    //     flag <<= 1;
    //   }
    flag = xor_res & ((xor_res - 1) ^ -1);
    int num1 = 0, num2 = 0;
    for (const auto& num : nums) {
      if (num & flag)
        num1 ^= num;
      else
        num2 ^= num;
    }
    return {num1, num2};
  }
};
