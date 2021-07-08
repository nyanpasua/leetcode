//森林中，每个兔子都有颜色。其中一些兔子（可能是全部）告诉你还有多少其他的兔子和自己有相同的颜色。我们将这些回答放在
//answers 数组里。
//
// 返回森林中兔子的最少数量。
//
//
//示例:
//输入: answers = [1, 1, 2]
//输出: 5
//解释:
//两只回答了 "1" 的兔子可能有相同的颜色，设为红色。
//之后回答了 "2" 的兔子不会是红色，否则他们的回答会相互矛盾。
//设回答了 "2" 的兔子为蓝色。
//此外，森林中还应有另外 2 只蓝色兔子的回答没有包含在数组中。
//因此森林中兔子的最少数量是 5: 3 只回答的和 2 只没有回答的。
//
//输入: answers = [10, 10, 10]
//输出: 11
//
//输入: answers = []
//输出: 0
//
//
// 说明:
//
//
// answers 的长度最大为1000。
// answers[i] 是在 [0, 999] 范围内的整数。
//
// Related Topics 贪心 哈希表 数学
// 👍 184 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
//   两只相同颜色的兔子看到的其他同色兔子数必然是相同的。
//   反之，若两只兔子看到的其他同色兔子数不同，那么这两只兔子颜色也不同。
//
//因此，将 answers 中值相同的元素分为一组，对于每一组，
//  计算出兔子的最少数量，然后将所有组的计算结果累加，就是最终的答案。
//
class Solution {
 public:
  int numRabbits(vector<int>& answers) {
    unordered_map<int, int> count;
    for (int y : answers) {
      ++count[y];
    }
    int ans = 0;
    for (auto& [y, x] : count) {
      ans += (x + y) / (y + 1) * (y + 1);
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
