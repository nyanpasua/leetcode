// 输入：arr = [3,2,1], k = 2
// 输出：[1,2] 或者 [2,1]

#include <queue>
#include <vector>
using std::vector;
class Solution {
 public:
  vector<int> getLeastNumbers(vector<int>& arr, int k) {
    if (arr.size() < k) return {};
    // 大根堆
    std::priority_queue<int, vector<int>> heap;
    for (const auto& e : arr) {
      heap.push(e);
      // 将大数都剔除
      if (heap.size() > k) {
        heap.pop();
      }
    }
    std::vector<int> res(k, 0);
    for (int i = 0; i < k; ++i) {
      res[i] = heap.top();
      heap.pop();
    }
    return res;
  }
};
