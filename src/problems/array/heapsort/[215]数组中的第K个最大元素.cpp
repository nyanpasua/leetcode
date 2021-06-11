/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// leetcode submit region begin(Prohibit modification and deletion)
#include <functional>
#include <queue>
#include <random>
using std::vector;

/// 快速排序
// Time: 平均O(N) 最差 O(N^2)
// Space: O(logN) 最差 O(N)
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    return quick_sort(nums, 0, nums.size() - 1, k - 1);
  }

 private:
  int partition(vector<int>& nums, int l, int r) {
    // 随机化轴值
    // Will be used to obtain a seed for the random number engine
    std::random_device rd;
    // Standard mersenne_twister_engine seeded with rd()
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(l, r);
    int picked = distrib(gen);
    std::swap(nums[l], nums[picked]);
    auto v = nums[l];
    int i = l + 1;
    int j = l;
    // [l+1...j] >= v; [j+1...i-1]<v;
    //                               i
    // [ 2  7  5  8  9  3  -1  1  -2 ]
    //   l              j          r
    while (i <= r) {
      if (nums[i] >= v) {
        std::swap(nums[i++], nums[++j]);
      } else {
        ++i;
      }
    }
    //                               i
    // [ 3  7  5  8  9  2  -1  1  -2 ]
    //   l              j          r
    std::swap(nums[j], nums[l]);
    return j;
  }
  int quick_sort(vector<int>& nums, int l, int r, int k) {
    // partition
    int p = partition(nums, l, r);
    // 根据 partition 结果递归 quick_sort
    if (p == k) {
      return nums[p];
    } else if (p < k) {
      return quick_sort(nums, p + 1, r, k);
    } else {
      return quick_sort(nums, l, p - 1, k);
    }
  }
};

/// 堆
// 采用 size 为 k 的 minheap 来维护稳定的 Top(min)
// n 个数找 topk, 等价于: pop 出 n-k 个最小的数, minheap 中剩余的 top(min)
// 就是最后的 topk
// 1. 建立 k-elements minheap, emplace k elements, O(klogk)
// 2. 继续 emplace n-k 个 element, 每添加一个(k+1 minheap, O(logk)), 就 pop
// 出一个 min, (n-k)logk
// Time: O(nlogk)
// Space: O(k)
class Solution1 {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    // move-aware class
    // 小根堆
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
