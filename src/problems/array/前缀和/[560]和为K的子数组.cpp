//给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
//
// 示例 1 :
//
//
//输入:nums = [1,1,1], k = 2
//输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
//
//
// 说明 :
//
//
// 数组的长度为 [1, 20,000]。
// 数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。
//
// Related Topics 数组 哈希表
// 👍 960 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
#include <unordered_map>
using std::unordered_map;
using std::vector;

/// 前缀和 + hash 表
class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    // 记录 前缀和 sum -> 个数 的 hash 表
    unordered_map<int,int> m;
    int sum = 0;
    int count = 0;
    m[0] = 1;  // 空数组和为 0
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      if (m.count(sum - k)) count += m[sum-k];
      ++m[sum];
    }
    return count;
  }
};

/// 暴力遍历，会超时
// 这道题很容易走入 动态规划
// 的思路，但实际上动态规划不太好解这套题，因为问题本身不是最值问题，
// 而且还需要连续子数组，背包的思路也不好用。
// 因此考虑一些单纯的双指针或者 hash 表的思路
// 遍历数组,求和的过程统计 sum  == k 的数量
//
class Solution1 {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int sum{0};
    int count{0};
    for (int end = 0; end < nums.size(); ++end) {
      sum = 0;
      for (int start = end; start >= 0; --start) {
        sum += nums[start];
        if (sum == k) ++count;
      }
    }
    return count;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
