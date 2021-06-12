// 输入：nums = [2,7,11,15], target = 9
//输出：[2,7] 或者 [7,2]
#include <vector>
using std::vector;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int i = 0, j = nums.size() - 1;
    std::vector<int> res{};
    while (i <= j) {
      if (nums[i] + nums[j] == target) {
        res.push_back(nums[i]);
        res.push_back(nums[j]);
        break;
      } else if (nums[i] + nums[j] < target) {
        ++i;
      } else {
        --j;
      }
    }
    return res;
  }
};
