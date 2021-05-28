// 输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
//输出：true
//解释：我们可以按以下顺序执行：
// push(1), push(2), push(3), push(4), pop() -> 4,
// push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
// 输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
//输出：false
//解释：1 不能在 2 之前弹出。
#include <stack>
class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    // 辅助栈模拟操作
    std::stack<int> s;
    int i = 0;
    for (const auto& num : pushed) {
      s.push(num);
      while (!s.empty() && s.top() == popped[i]) {
        s.pop();
        ++i;
      }
    }
    return s.empty();
  }
};
