/*!
 * @brief https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
 * Time: O(nlogk)
 * Space: O(k)
 */
#include <functional>
#include <queue>
using std::vector;

/// NOTE(yingmin) 2021.5.7
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
