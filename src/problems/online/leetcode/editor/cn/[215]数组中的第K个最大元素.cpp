//在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k
//个最大的元素，而不是第 k 个不同的元素。
//
// 示例 1:
//
// 输入: [3,2,1,5,6,4] 和 k = 2
//输出: 5
//
//
// 示例 2:
//
// 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
//输出: 4
//
// 说明:
//
// 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
// Related Topics 堆 分治算法
// 👍 1064 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
/// NOTE(yingmin) 2021.5.7 rewrite
#include <functional>
#include <queue>
/// 采用 size 为 k 的 minheap 来维护稳定的 Top(min)
/// n 个数找 topk, 等价于: pop 出 n-k 个最小的数, minheap 中剩余的 top(min)
/// 就是最后的 topk
/// 1. 建立 k-elements minheap, emplace k elements, O(klogk)
/// 2. 继续 emplace n-k 个 element, 每添加一个(k+1 minheap, O(logk)), 就 pop
/// 出一个 min, (n-k)logk
/// Time: O(nlogk)
/// Space: O(k)
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    // move-aware class
    auto min_heap = std::priority_queue<int, vector<int>, std::greater<int>>();
    for (const auto& e : nums) {
      min_heap.emplace(e);
      if (min_heap.size() > k) {
        min_heap.pop();
      }
    }
    return min_heap.top();
  }
};
// leetcode submit region end(Prohibit modification and deletion)
