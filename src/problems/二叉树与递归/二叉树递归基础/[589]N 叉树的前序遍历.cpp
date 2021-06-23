//给定一个 N 叉树，返回其节点值的 前序遍历 。
//
// N 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null
// 分隔（请参见示例）。
//
//
//
//
//
// 进阶：
//
// 递归法很简单，你可以使用迭代法完成此题吗?
//
//
//
// 示例 1：
//
//
//
//
//输入：root = [1,null,3,2,4,null,5,6]
//输出：[1,3,5,6,2,4]
//
//示例 2：
//
//
//
//
//输入：root =
//[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,
// null,13,null,null,14]
//输出：[1,2,3,6,7,11,14,4,8,12,5,9,13,10]
//
//
//
//
// 提示：
//
//
// N 叉树的高度小于或等于 1000
// 节点总数在范围 [0, 10^4] 内
//
//
//
// Related Topics 树
// 👍 165 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

#include <stack>
/// 处理root, children[0...]
// 采用迭代方式，处理 root，[children[...0]] 的顺序入栈，
// 出栈则是 [children[0...]
class Solution {
 public:
  vector<int> preorder(Node* root) {
    if (root == nullptr) return {};
    vector<int> res;
    std::stack<Node*> stk;
    stk.push(root);
    while (!stk.empty()) {
      // 处理 root
      auto node = stk.top();
      stk.pop();
      res.push_back(node->val);
      for (int i = node->children.size() - 1; i >= 0; --i) {
        if (node->children[i]) {
          stk.push(node->children[i]);
        }
      }
    }
    return res;
  }
};

/// [root,children[0...]]
// 递归方式就按上述递归就好
class Solution1 {
 public:
  vector<int> preorder(Node* root) {
    dfs(root);
    return res_;
  }

 private:
  void dfs(Node* root) {
    if (root == nullptr) return;
    res_.push_back(root->val);
    for (int i = 0; i < root->children.size(); ++i) {
      dfs(root->children[i]);
    }
  }
  vector<int> res_;
};
// leetcode submit region end(Prohibit modification and deletion)
