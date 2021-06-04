// 请根据每日 气温 列表，重新生成一个列表。对应位置的输出为：
// 要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用
// 0 来代替。
//
//例如，给定一个列表temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，
// 你的输出应该是[1, 1, 4, 2, 1, 1, 0, 0]。
//
#include <stack>
#include <vector>
using std::vector;

// Time: O(N) Space: O(N)
class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> res(temperatures.size(), 0);
    // 存储递减栈，存储对应的 idx
    std::stack<int> min_stack;
    for (int i = 0; i < temperatures.size(); ++i) {
      // 先处理
      while (!min_stack.empty() &&
             temperatures[i] > temperatures[min_stack.top()]) {
        res[min_stack.top()] = i - min_stack.top();
        min_stack.pop();
      }
      // 再入栈，这里其实无需任何判断
      min_stack.push(i);
    }
    return res;
  }
};

// 维护一个存储下标的单调栈，从栈底到栈顶的下标对应的温度列表中的温度依次递减。
// 如果一个下标在单调栈里，则表示尚未找到下一次温度更高的下标。
// Time: O(N) Space: O(N)
class Solution1 {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> res(temperatures.size(), 0);
    // 存储递减栈，存储对应的 idx
    std::stack<int> min_stack;
    for (int i = 0; i < temperatures.size(); ++i) {
      // 先处理
      while (!min_stack.empty() &&
             temperatures[i] > temperatures[min_stack.top()]) {
        res[min_stack.top()] = i - min_stack.top();
        min_stack.pop();
      }
      // 再入栈
      if (min_stack.empty() ||
          temperatures[i] <= temperatures[min_stack.top()]) {
        min_stack.push(i);
        continue;
      }
    }
    return res;
  }
};