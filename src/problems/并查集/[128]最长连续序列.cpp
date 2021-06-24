//给定一个未排序的整数数组 nums
//，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
//
//
//
// 进阶：你可以设计并实现时间复杂度为 O(n) 的解决方案吗？
//
//
//
// 示例 1：
//
//
//输入：nums = [100,4,200,1,3,2]
//输出：4
//解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
//
// 示例 2：
//
//
//输入：nums = [0,3,7,2,5,8,4,6,0,1]
//输出：9
//
//
//
//
// 提示：
//
//
// 0 <= nums.length <= 104
// -109 <= nums[i] <= 109
//
// Related Topics 并查集 数组
// 👍 811 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <unordered_map>
#include <vector>
using std::unordered_map;
using std::vector;

/// 并查集
class Solution {
 public:
  unordered_map<int, int> a;
  int find(int x) { return a.count(x) ? a[x] = find(a[x]) : x; }
  int longestConsecutive(vector<int>& nums) {
    for (auto i : nums) a[i] = i + 1;
    int ans = 0;
    for (auto i : nums) {
      int y = find(i + 1);
      ans = max(ans, y - i);
    }
    return ans;
  }
};

/// hash
class Solution1 {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> num_set;
    for (const auto& num : nums) {
      num_set.insert(num);
    }
    int res = 0;
    for (const auto& num : nums) {
      // 这里一定要从 num - 1 找起
      if (!num_set.count(num - 1)) {
        // 如果 num - 1 不存在，说明第一次找这一组连续数
        int cur = num;
        int cur_res = 1;
        while (num_set.count(cur + 1)) {
          cur++;
          cur_res++;
        }
        res = std::max(res, cur_res);
      }
    }
    return res;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
