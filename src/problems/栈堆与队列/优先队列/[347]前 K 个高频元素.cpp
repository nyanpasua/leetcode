//给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k
//高的元素。你可以按 任意顺序 返回答案。
//
//
//
// 示例 1:
//
//
//输入: nums = [1,1,1,2,2,3], k = 2
//输出: [1,2]
//
//
// 示例 2:
//
//
//输入: nums = [1], k = 1
//输出: [1]
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 105
// k 的取值范围是 [1, 数组中不相同的元素的个数]
// 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
//
//
//
//
// 进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。
// Related Topics 堆 哈希表
// 👍 771 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <queue>
#include <random>
#include <unordered_map>
#include <utility>
#include <vector>
using std::pair;
using std::priority_queue;
using std::unordered_map;
using std::vector;

/// 快速排序
// Time: 平均 O(N) 最差 O(N^2)
// Space: O(N) 最好 O(logN)
// 由于快排可以一次定位一个轴值的正确位置，并且其左侧都小于轴值，右侧都大于轴值
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> occurs;
    for (const auto& v : nums) {
      occurs[v]++;
    }

    vector<pair<int, int>> values;
    for (const auto& p : occurs) {
      values.push_back(p);
    }
    quick_sort(values, 0, values.size() - 1, k);
    return res_;
  }

 private:
  vector<int> res_;
  void quick_sort(vector<pair<int, int>>& nums, int l, int r, int k) {
    // 递归到底
    if (l > r) return;

    // partition
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
      if (ge_cmp(nums[i], v)) {
        std::swap(nums[i++], nums[++j]);
      } else {
        ++i;
      }
    }
    //                               i
    // [ 3  7  5  8  9  2  -1  1  -2 ]
    //   l              j          r
    std::swap(nums[j], nums[l]);
    // 根据 partition 结果递归 quick_sort
    // 上图中 j - l == 5
    if (k <= j - l) {
      // 压缩 右侧 r 的范围
      quick_sort(nums, l, j - 1, k);
    } else {
      // 如果 k == j - l + 1，则 [l...j] 就是要找的 topk
      // 如 k == 6，则 [l...j]
      for (int idx = l; idx <= j; ++idx) {
        res_.push_back(nums[idx].first);
      }
      // 如果 k > j - l，则还需要另外找 k - (j - l) 个
      // 如 k == 7，上面循环会找到 6 个，还需要 1 个
      if (k > j - l + 1) {
        quick_sort(nums, j + 1, r, k - (j - l + 1));
      }
    }
  }
  static bool ge_cmp(const pair<int, int>& x, const pair<int, int>& y) {
    return x.second >= y.second;
  }
};

/// 优先队列
// Time: O(Nlogk)
// Space: O(N)
class Solution1 {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    auto greater = [](const pair<int, int>& x, const pair<int, int>& y) {
      return x.second > y.second;
    };
    unordered_map<int, int> occurs;
    for (const auto& i : nums) {
      occurs[i]++;
    }
    // 找出 occur 的 topk
    // 小根堆
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(greater)> q(
        greater);
    for (const auto& p : occurs) {
      q.push(p);
      if (q.size() > k) {
        q.pop();
      }
    }
    vector<int> res;
    res.reserve(k);
    // 优先队列不能遍历
    while (!q.empty()) {
      res.emplace_back(q.top().first);
      q.pop();
    }
    return res;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
