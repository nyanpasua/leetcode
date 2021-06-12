// 用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和
// deleteHead，分别完成在队列尾部插入整数和在队列头部删除整数的功能。
// (若队列中没有元素，deleteHead 操作返回 -1 )
// 输入：
//["CQueue","appendTail","deleteHead","deleteHead"]
//[[],[3],[],[]]
//输出：[null,null,3,-1]
//
#include <stack>
/// 此题要注意：入队列直接向尾栈 push，而出队列，需要分两种情况：1）如果头栈有元素，直接 pop
/// 2）如果头栈没有元素，需要将 tail 栈中全部元素弹出，进入 head 栈，然后再 pop
class CQueue {
 public:
  CQueue() {}

  void appendTail(int value) { tail_.push(value); }

  int deleteHead() {
    if (!head_.empty()) {
      auto head = head_.top();
      head_.pop();
      return head;
    } else {
      if (tail_.empty()) {
        // tail 为空，则说明队列为空，返回 -1
        return -1;
      } else {
        // 将 tail 栈中所有元素入栈 head
        while (!tail_.empty()) {
          head_.push(tail_.top());
          tail_.pop();
        }
        auto head = head_.top();
        head_.pop();
        return head;
      }
    }
  }

 private:
  std::stack<int> head_;
  std::stack<int> tail_;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */