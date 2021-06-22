// 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
// 输出: [3,3,5,5,6,7]
// 解释:
//
//  滑动窗口的位置                最大值
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
//
#include <deque>
#include <queue>
#include <vector>
using std::vector;

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (nums.empty()) return {};
    if (nums.size() < k) return {*std::max_element(nums.begin(), nums.end())};
    vector<int> max_window{};
    max_queue max_q;
    for (int i = 0; i < k; ++i) {
      max_q.push(nums[i]);
    }
    max_window.emplace_back(max_q.max());
    for (int r = k; r < nums.size(); ++r) {
      max_q.push(nums[r]);
      max_q.pop();
      max_window.emplace_back(max_q.max());
    }
    return max_window;
  }

 private:
  class max_queue {
   public:
    int max() { return max_.front(); }
    void pop() {
      if (queue_.front() == max_.front()) {
        max_.pop_front();
      }
      queue_.pop();
    }
    void push(int val) {
      queue_.push(val);
      // max_ 内部满足非严格单调递减
      while (true) {
        if (max_.empty()) {
          max_.push_back(val);
          break;
        }
        // 删除所有比 val 小的元素
        if (max_.back() < val) {
          max_.pop_back();
        } else {
          max_.push_back(val);
          break;
        }
      }
    }

   private:
    std::queue<int> queue_;
    std::deque<int> max_;
  };
};
