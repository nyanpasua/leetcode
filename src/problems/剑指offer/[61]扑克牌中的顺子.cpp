// 从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
// 2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为
// 0 ，可以看成任意数字。A 不能视为 14。
//
#include <vector>
#include <algorithm>
#include <functional>

using std::vector;

class Solution {
 public:
  bool isStraight(vector<int>& nums) {
    // sort
    std::sort(nums.begin(), nums.end());
    // 查重
    int joker = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
      if (nums[i] == 0) {
        joker++;
        continue;
      }
      if (nums[i] == nums[i + 1]) return false;
      
    }
    // 排序后, nums[4] - nums[joker] < 5, joker 为大小王的数量
    return nums.back() - nums[joker] < 5;
  }
};
