// 输入：nums = [1,1,2]
//输出：
//[[1,1,2],
// [1,2,1],
// [2,1,1]]
#include <algorithm>
#include <unordered_set>
#include <vector>
using std::vector;
class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    dfs(nums, 0);
    return res_;
  }

 private:
  vector<vector<int>> res_;
  void dfs(vector<int>& nums, int index) {
    if (index == nums.size() - 1) {
      // 最后一个 index 已经固定，加入结果
      res_.push_back(nums);
      return;
    }
    std::unordered_set<int> visited;  // 这里其实无需
    for (int j = index; j < nums.size(); ++j) {
      if (visited.find(nums[j]) != visited.end()) {
        // 已经访问过，跳过该数字
        continue;
      }
      visited.insert(nums[j]);
      // 固定 nums[j] 到 index 位置
      std::swap(nums[j], nums[index]);
      // 找下一个固定位
      dfs(nums, index + 1);
      // 还原 nums[j] 到原位置
      std::swap(nums[j], nums[index]);
    }
  }
};