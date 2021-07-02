// 此题限制了 target = 0
// 注意：答案中不可以包含重复的三元组。
// 输入：nums = [-1,0,1,2,-1,-4]
// 输出：[[-1,-1,2],[-1,0,1]]
#include <algorithm>
#include <vector>
using std::vector;

// 由于此题的暴力解法需要 3 重循环，因此排序一次似乎完全可以接受
// 排序后，外层循环 O(N)，内两层循环可以用双指针 O(N)
// Time: O(N^2)
// Space: O(1) 也有一说为排序需要 O(logN) 的空间复杂度
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.empty()) return {};
    int len = nums.size();
    if (len < 3) return {};
    // 从小到大排序
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); ++i) {
      // 外层循环
      if (nums[i] > 0) break;
      if (i > 0 && nums[i] == nums[i - 1]) continue;  // 去重
      // 双指针找 target 2sum
      int target = -nums[i];
      int l = i + 1;
      int r = len - 1;
      while (l < r) {
        if (nums[l] + nums[r] == target) {
          res.push_back({nums[i], nums[l], nums[r]});
          while (l < r && nums[l] == nums[l + 1]) ++l;  // 去重
          while (l < r && nums[r] == nums[r - 1]) --r;
          ++l;
          --r;
        } else if (nums[l] + nums[r] < target)
          ++l;
        else
          --r;
      }
    }
    return res;
  }
};