/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

//设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
//
//
// push(x) —— 将元素 x 推入栈中。
// pop() —— 删除栈顶的元素。
// top() —— 获取栈顶元素。
// getMin() —— 检索栈中的最小元素。
//
//
//
//
// 示例:
//
// 输入：
//["MinStack","push","push","push","getMin","pop","top","getMin"]
//[[],[-2],[0],[-3],[],[],[],[]]
//
//输出：
//[null,null,null,null,-3,null,0,-2]
//
//解释：
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> 返回 -3.
// minStack.pop();
// minStack.top();      --> 返回 0.
// minStack.getMin();   --> 返回 -2.
//
//
//
//
// 提示：
//
//
// pop、top 和 getMin 操作总是在 非空栈 上调用。
//
// Related Topics 栈 设计
// 👍 934 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
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

  int getMin() { return min_.top(); }

 private:
  std::stack<int> data_;
  std::stack<int> min_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// leetcode submit region end(Prohibit modification and deletion)
