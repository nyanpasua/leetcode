/*!
 * @brief https://leetcode-cn.com/problems/minimum-size-subarray-sum/
 * Time: O(n)
 * Space: O(1)
 */
int minSubArrayLen(int s, vector<int>& nums) {
  int i = 0, j = 0;
  int sum = 0;
  int minlen = INT32_MAX;
  // [i,j]为滑动窗, i,j为当前考察的元素
  while (j <= nums.size() && i < nums.size()) {
    if (sum < s) {
      if (j < nums.size()) {
        sum += nums[j++];
      } else {
        break;
      }
    } else {
      minlen = std::min((j - i), minlen);
      sum -= nums[i++];
    }
  }
  return minlen == INT32_MAX ? 0 : minlen;
}
