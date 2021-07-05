// 输入一个整数数组，判断该数组是不是某二叉搜索树的前序遍历结果。
// 如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
// 输入: [3 2 1 4 5]
// 输出: true
// 输入：[4 3 1 2 5]
// 输出：true

#include <limits>
#include <stack>
#include <vector>
using std::vector;

/// 前序遍历
// [root,left,right]
// 对于输入序列，其 第一个 idx 为 root；
// 接着向右为 left 子树，需要找到左右子树的分界，之后递归；
class Solution {
 public:
  bool verifyPreorder(vector<int>& preorder) {
    return recursion(preorder, 0, preorder.size() - 1);
  }

 private:
  bool recursion(const vector<int>& preorder, int l, int r) {
    if (l > r) return true;
    auto root = preorder[l];
    auto child = l;
    while (r >= child) {
      // 寻找右子树，循环结束时，child 为右子树第一个 idx 或者
      // 越界索引为 r + 1 （全是左子树）
      ++child;
      // 这里的 <= r 是为了防止 preorder 数组访问越界
      if (child <= r && preorder[child] > root) break;
    }
    if (check(preorder, l, child, r)) {
      // 递归左子树和右子树
      return recursion(preorder, l + 1, child - 1) &&
             recursion(preorder, child, r);
    } else
      return false;
  }
  bool check(const vector<int>& preorder, int l, int child, int r) {
    // 全是左子树
    if (child > r) return true;
    for (int i = child; i <= r; ++i) {
      // 核心判断，右子树 [child...r] 都应该 > root
      if (preorder[i] <= preorder[l]) return false;
    }
    return true;
  }
};
