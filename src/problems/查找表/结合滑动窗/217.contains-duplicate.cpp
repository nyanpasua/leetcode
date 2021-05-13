/*!
 * @brief https://leetcode-cn.com/problems/contains-duplicate/
 * Time: O(n)
 * Space: O(n)+
 */
bool containsDuplicate(vector<int>& nums) {
  std::unordered_map<int, int> counter;
  for (const auto& num : nums) {
    ++counter[num];
    if (counter[num] > 1) {
      return true;
    }
  }
  return false;
}
