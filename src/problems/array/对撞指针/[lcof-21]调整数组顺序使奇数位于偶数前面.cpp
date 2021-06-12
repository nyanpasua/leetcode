// 输入：nums = [1,2,3,4]
// 输出：[1,3,2,4]
// 注：[3,1,2,4] 也是正确的答案之一。
class Solution {
 public:
  vector<int> exchange(vector<int>& nums) {
    int i = 0, j = nums.size() - 1;
    while (i < j) {
      if (nums[i] % 2 == 0) {
        // 偶数
        std::swap(nums[i], nums[j--]);
      } else ++i;
    }
    return nums;
  }
};
