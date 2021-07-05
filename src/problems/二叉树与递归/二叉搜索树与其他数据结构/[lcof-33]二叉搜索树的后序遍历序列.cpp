// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
// 如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
// 输入: [1,3,2,6,5]
// 输出: true
#include <vector>
#include <limits>
#include <stack>
using std::vector;

/// 后序遍历
// [left, right, root]
// 因此，对于一个输入序列，其 root 为最右侧 idx，设为 root；
// 其左侧开始为 right 子树，需要找到 left 子树的最后一个 idx；
class Solution1 {
 public:
  bool verifyPostorder(vector<int>& postorder) {
    return recursion(postorder, 0, postorder.size() - 1);
  }

 private:
  bool recursion(vector<int>& postorder, int l, int r) {
    if (l > r) return true;
    auto root = postorder[r];
    auto child = r;
    while (l <= child) {
      // 寻找左子树，循环结束时，child 为左子树最后一个 idx 或者
      // 越界索引为 l-1 （全是右子树）
      --child;
      // 这里的 >= 0 是为了防止 postorder 数组访问越界
      if (child >= 0 && postorder[child] < root) break;
    }
    if (check(postorder, l, child, r)) {
      // 递归左子树和右子树
      return recursion(postorder, l, child) &&
             recursion(postorder, child + 1, r - 1);
    } else
      return false;
  }
  bool check(vector<int>& postorder, int l, int child, int r) {
    if (l > child) {
      // 全是右子树节点
      return true;
    }
    for (int i = l; i <= child; ++i) {
      // 核心判断，左子树 [l...child] 都应该 < root
      if (postorder[i] >= postorder[r]) return false;
    }
    return true;
  }
};

/// 单调栈
// 借助一个单调栈 stack 存储值递增的节点
// 每当遇到值递减的节点 r_i，则通过出栈来更新节点 r_i 的父节点 root
// 每轮判断 r_i 和 root 的值关系
class Solution {
 public:
  bool verifyPostorder(vector<int>& postorder) {
    std::stack<int> nodes;
    int root = std::numeric_limits<int>::max();
    for (int i = postorder.size() - 1; i >=0; --i) {
      if (postorder[i] > root) return false;
      while(!nodes.empty() && nodes.top() > postorder[i]) {
        root = nodes.top();
        nodes.pop();
      }
      nodes.push(postorder[i]);
    }
    return true;
  }

};

