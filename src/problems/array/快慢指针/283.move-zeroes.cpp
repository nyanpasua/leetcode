/*!
 * @brief Given an array nums, write a function to move all 0's to the end of it
 * while maintaining the relative order of the non-zero elements.
 * https://leetcode.com/problems/move-zeroes/
 */

enum RetCode { ERROR_NOT_ZERO_NONE = -1, ERROR_ZERO_NONE = -2 };
int findNextZero(int i, vector<int>& nums) {
  while (i < nums.size()) {
    if (nums[i] == 0) {
      return i;
    }
    ++i;
  }
  return ERROR_ZERO_NONE;
}

int findNextNotZero(int j, vector<int>& nums) {
  while (j < nums.size()) {
    if (nums[j] != 0) {
      return j;
    }
    ++j;
  }
  return ERROR_NOT_ZERO_NONE;
}

void moveZeroes(vector<int>& nums) {
  if (nums.empty()) {
    return;
  }
  int i = 0, j = 0;  // [i, j]
  while (i < nums.size() && j < nums.size()) {
    i = findNextZero(i, nums);
    j = findNextNotZero(i, nums);
    if (j == ERROR_NOT_ZERO_NONE || i == ERROR_ZERO_NONE) {
      break;
    }
    std::swap(nums[i], nums[j]);
    ++i;
  }
}
