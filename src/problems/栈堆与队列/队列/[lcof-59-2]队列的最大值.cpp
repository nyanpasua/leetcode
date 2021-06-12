// 请定义一个队列并实现函数 max_value 得到队列里的最大值，
// 要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
//
// 若队列为空，pop_front 和 max_value需要返回 -1
//
#include <deque>
class MaxQueue {
 public:
  MaxQueue() {}

  int max_value() {
    if (!max_.empty()) return max_.front();
    return -1;
  }

  void push_back(int value) {
    if (max_.empty() || value <= max_.back())
      max_.push_back(value);
    else {
      do {
        max_.pop_back();
      } while (!max_.empty() && max_.back() < value);
      max_.push_back(value);
    }
    data_.push_back(value);
  }

  int pop_front() {
    if (data_.empty()) return -1;
    if (data_.front() == max_.front()) {
      max_.pop_front();
    }
    auto ret = data_.front();
    data_.pop_front();
    return ret;
  }

 private:
  std::deque<int> data_;
  std::deque<int> max_;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
