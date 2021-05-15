
// 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min
// 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

/// 设计两个栈，一个栈用于正常维护数据，另一个栈负责保存降序最小值
#include <stack>
class MinStack {
 public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    data_.push(x);
    // 为空 或者
    // x 小于等于 min_ 的栈顶
    if (min_.empty() || x <= min_.top()) {
      min_.push(x);
    }
  }

  void pop() {
    if (data_.top() == min_.top()) {
      min_.pop();
    }
    data_.pop();
  }

  int top() { return data_.top(); }

  int min() { return min_.top(); }

 private:
  std::stack<int> data_;
  std::stack<int> min_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */