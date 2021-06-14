// 输入一个字符串，打印出该字符串中字符的所有排列。
// 你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

// 输入：s = "abc"
// 输出：["abc","acb","bac","bca","cab","cba"]

#include <string>
#include <unordered_set>
#include <vector>
using std::string;
using std::vector;

/// 典型的回溯问题
/// Time: O(N!), N 为字符串 s
/// 的长度；时间复杂度和字符串排列的方案数成线性关系，方案数为
/// N×(N−1)×(N−2)…×2×1
/// Space: O(N^2), 因为栈深度为N, Set
/// 累计存储的字符数量最多为 N + (N-1) + ... + 2 + 1 =
/// (N+1)N/2N+(N−1)+...+2+1=(N+1)N/2
class Solution {
 public:
  vector<string> permutation(string s) {
    dfs(s, 0);
    return res_;
  }

 private:
  std::vector<std::string> res_;
  void dfs(string s, size_t index) {
    // 递归到底，index 为最后一个字母的索引
    if (index == s.size() - 1) {
      // 前面的字母都已经固定，因此直接返回
      res_.push_back(s);
      return;
    }
    // set 存放在每一层递归内部，因为每一层都可能产生重复，需要保证每一层的
    // 固定唯一 如 aabc，如果 <b, aac> -> <a, ac> <a, ac> <c, aa>就会产生重复的
    // <a, ac> 因此在每一层都需要保证该层的固定不重复
    // <b, aac> -> <a, ac> <c, aa> -> <a, c> <c, a> <a, a>
    std::unordered_set<int> visited;
    for (size_t i = index; i < s.size(); ++i) {
      // 深度优先遍历，在 index 位置，进行 for 循环
      // 访问第 i 个字母，如果该字母在 set
      // 中，说明之前已经访问过，则剪枝该重复字母
      if (visited.find(s[i]) != visited.end()) continue;
      visited.insert(s[i]);
      // 固定 s[i] 为第一个字母
      // 这一步比较关键，交换操作，很巧妙的避开了重复拷贝字符串；
      // 比如 abc，我在进行第一层深度优先遍历的时候，需要在开始依次找 a,b,c
      // 三个字母 <a, bc> <b, ac> <c, ab> 而交换就使得我需要固定 b
      // 的时候，直接与 a 进行交换，得到 bac 字符串，将 ac 给到 下一层的 dfs <a,
      // c> <c ,a>
      std::swap(s[i], s[index]);
      dfs(s, index + 1);
    }
  }
};