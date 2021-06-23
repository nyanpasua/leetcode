// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
// 如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
// 输入: [1,3,2,6,5]
// 输出: true
#include <vector>
#include <limits>
#include <stack>
using std::vector;

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
      --child;
      if (child >= 0 && postorder[child] < root) break;
    }
    if (check(postorder, l, child, r)) {
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
    for (int i = l; i < child; ++i) {
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

