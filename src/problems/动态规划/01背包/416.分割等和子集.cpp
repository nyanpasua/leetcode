//
// Created by liyingmin on 2020/3/29.
//
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) {
      return false;
    }
    auto capacity = sum / 2;
    // 从nums.size()个元素，能找出一个组合将capacity为sum/2的背包装满，即找到这个子序列
    // memo矩阵
    size_t height = nums.size();
    vector<vector<bool>> memo(height, vector<bool>(capacity + 1, false));
    // base case, memo[i][0]
    for (size_t i = 0; i < height; ++i) {
      memo[i][0] = true;
    }
    // base case, memo[0][c]
    for (int c = 1; c <= capacity; ++c) {
      memo[0][c] = nums[0] == c ? true : false;
    }
    // 状态转移迭代
    for (size_t i = 1; i < height; ++i) {
      for (size_t c = 1; c <= capacity; ++c) {
        memo[i][c] =
            memo[i - 1][c] || (c >= nums[i] ? memo[i - 1][c - nums[i]] : false);
      }
    }
    return memo[height - 1][capacity];
  }
};

// 优化空间复杂度
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) {
      return false;
    }
    auto capacity = sum / 2;
    // 从nums.size()个元素，能找出一个组合将capacity为sum/2的背包装满，即找到这个子序列
    // memo矩阵
    size_t height = nums.size();
    vector<bool> memo(capacity + 1, false);
    // base case, memo[0], c==0, i == 0
    memo[0] = true;
    // base case, memo[c], c >= 1, i == 0
    for (int c = 1; c <= capacity; ++c) {
      memo[c] = nums[0] == c ? true : false;
    }
    // 状态转移迭代
    for (size_t i = 1; i < height; ++i) {
      for (size_t c = capacity; c >= 1; --c) {
        memo[c] = memo[c] || (c >= nums[i] ? memo[c - nums[i]] : false);
      }
    }
    return memo[capacity];
  }
};

// 进一步优化时间复杂度
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) {
      return false;
    }
    auto capacity = sum / 2;
    // 从nums.size()个元素，能找出一个组合将capacity为sum/2的背包装满，即找到这个子序列
    // memo矩阵
    size_t height = nums.size();
    vector<bool> memo(capacity + 1, false);
    // base case, memo[0], c==0, i == 0
    memo[0] = true;
    // base case, memo[c], c >= 1, i == 0
    for (int c = 1; c <= capacity; ++c) {
      memo[c] = nums[0] == c ? true : false;
    }
    // 状态转移迭代
    for (size_t i = 1; i < height; ++i) {
      // c >= nums[i]的时候才需要更新
      for (size_t c = capacity; c >= nums[i]; --c) {
        memo[c] = memo[c] || memo[c - nums[i]];
      }
    }
    return memo[capacity];
  }
};