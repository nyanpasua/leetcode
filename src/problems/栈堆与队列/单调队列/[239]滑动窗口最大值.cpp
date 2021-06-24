//给你一个整数数组 nums，有一个大小为 k
//的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k
//个数字。滑动窗口每次只向右移动一位 。
//
// 返回滑动窗口中的最大值。
//
//
//
// 示例 1：
//
//
//输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
//输出：[3,3,5,5,6,7]
//解释：
//滑动窗口的位置                最大值
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7
//
//
// 示例 2：
//
//
//输入：nums = [1], k = 1
//输出：[1]
//
//
// 示例 3：
//
//
//输入：nums = [1,-1], k = 1
//输出：[1,-1]
//
//
// 示例 4：
//
//
//输入：nums = [9,11], k = 2
//输出：[11]
//
//
// 示例 5：
//
//
//输入：nums = [4,-2], k = 2
//输出：[4]
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// 1 <= k <= nums.length
//
// Related Topics 队列 数组 滑动窗口 单调队列 堆（优先队列）
// 👍 1044 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
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
// leetcode submit region end(Prohibit modification and deletion)
