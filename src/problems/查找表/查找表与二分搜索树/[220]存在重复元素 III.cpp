/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

//给你一个整数数组 nums 和两个整数 k 和 t 。请你判断是否存在 两个不同下标 i 和
// j，使得 abs(nums[i] - nums[j]) <= t ，同时又满足 abs(i - j) <= k 。
//
// 如果存在则返回 true，不存在返回 false。
//
//
//
// 示例 1：
//
//
//输入：nums = [1,2,3,1], k = 3, t = 0
//输出：true
//
// 示例 2：
//
//
//输入：nums = [1,0,1,1], k = 1, t = 2
//输出：true
//
// 示例 3：
//
//
//输入：nums = [1,5,9,1,5,9], k = 2, t = 3
//输出：false
//
//
//
// 提示：
//
//
// 0 <= nums.length <= 2 * 104
// -231 <= nums[i] <= 231 - 1
// 0 <= k <= 104
// 0 <= t <= 231 - 1
//
// Related Topics 排序 Ordered Map
// 👍 465 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <set>
#include <unordered_map>
#include <vector>
using std::unordered_map;
using std::vector;

/// 使用 hash
// 如何在 O(1) 找到是否存在 [u-t, u+t] 的相邻元素呢？
// 将 在 索引 k 范围内的数字放到 若干桶中，相同的桶的元素一定满足在
// [u-t,u+t] 范围内。
// 如 t = 3，如此就是
// 0 1 2 3 | 4 5 6 7 | 8 9 10 11 | 12 13 14 15 | …
// 可见 [4,5,6,7] 一定都是满足条件的解，并且，相邻桶就是所有可行解的求解范围。
// 比如 6 的可行解是 [3-9]，一定就在相邻桶里面。
// 如何获得这样的桶划分?
// size = t + 1, 这里 +1 是为了确保 同一个区间桶内的 nums 一定满足条件
// return u >= 0 ? u / size : ((u + 1) / size) - 1;
// idx  -1            0         1         2           3
// ... | -4,-3,-2,-1 | 0 1 2 3 | 4 5 6 7 | 8 9 10 11 | 12 13 14 15 | ...
// Time: O(N) Space: O(min(N,k))
class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    // 记录 桶的 idx 到 nums[i]
    unordered_map<int64_t, int> buckets;
    size_ = t;
    size_++;
    for (int i = 0; i < nums.size(); ++i) {
      int64_t u = nums[i];
      auto idx = get_idx(u);
      if (buckets.count(idx)) {
        return true;
      }
      // 检查相邻桶
      if (buckets.count(idx - 1) && std::abs(u - buckets[idx - 1]) <= t)
        return true;
      if (buckets.count(idx + 1) && std::abs(u - buckets[idx + 1]) <= t)
        return true;
      // 插入新的元素进入桶
      buckets[idx] = nums[i];
      // 删除超过 k 的元素
      if (i >= k) buckets.erase(get_idx(nums[i - k]));
    }
    return false;
  }

 private:
  int64_t size_{};
  int64_t get_idx(int64_t u) {
    return u >= 0 ? u / size_ : ((u + 1) / size_) - 1;
  }
};

/// 使用红黑树 set/map lower_bound
// 维护一个 长度为 k 的 set，当遍历 nums 的过程中，i >= k，就开始每轮删除一个
// nums[i-k]， 这样即可保证 set 里的元素一定是 满足 索引差 <= k 的。
// low_bound(nums[i] - t) 可以找到 第一个 not less than (nums[i] - t) 的 元素，
// 也就是 找到 >= (nums[i]-t) 的元素，如果这个元素 还满足 <=
// (nums[i]+t)，那么就找到 满足要求的解了。
// Time: O(Nlog(min(N,k)))
// Space: O(min(N,k))
class Solution1 {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    std::set<long> st;
    for (int i = 0; i < nums.size(); i++) {
      // lower_bound 时间复杂度为 O(logk)，如何将此复杂度降低为 O(1)
      auto lb = st.lower_bound((long)nums[i] - t);
      if (lb != st.end() && *lb <= (long)nums[i] + t) return true;
      st.insert(nums[i]);
      if (i >= k) st.erase(nums[i - k]);
    }
    return false;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
