/*!
 * @brief https://leetcode-cn.com/problems/contains-duplicate-ii
 * Time: O(n)
 * Space: O(n)+
 */
bool containsNearbyDuplicate(vector<int>& nums, int k) {
  std::unordered_map<int, int> counter;
  for (size_t i = 0; i < nums.size(); ++i) {
    if (counter.find(nums[i]) != counter.end()) {
      if (i - counter[nums[i]] <= k) {
        return true;
      }
      counter[nums[i]] = i;
    } else {
      counter[nums[i]] = i;
    }
  }
  return false;
}