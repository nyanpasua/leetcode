//给定一个 N 叉树，返回其节点值的 后序遍历 。
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
//输出：[5,6,3,2,4,1]
//
//
// 示例 2：
//
//
//
//
//输入：root =
//[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,
// null,13,null,null,14]
//输出：[2,6,14,11,7,3,12,8,4,13,9,10,5,1]
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
// 👍 151 👎 0

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
/// 后序遍历 + stack
// [children[0...],root] -> 处理 root 进入 front（而不是back），入栈
// children[0...]
class Solution {
 public:
  vector<int> postorder(Node* root) {
    if (root == nullptr) return {};
    std::deque<int> res;
    std::stack<Node*> stk;
    stk.push(root);
    while (!stk.empty()) {
      auto node = stk.top();
      stk.pop();
      res.push_front(node->val);
      for (int i = 0; i < node->children.size(); ++i) {
        if (node->children[i]) {
          stk.push(node->children[i]);
        }
      }
    }
    return vector<int>(res.begin(), res.end());
  }
};

class Solution1 {
 public:
  vector<int> postorder(Node* root) {
    dfs(root);
    return res_;
  }

 private:
  void dfs(Node* root) {
    if (root == nullptr) return;
    for (int i = 0; i < root->children.size(); ++i) {
      dfs(root->children[i]);
    }
    res_.push_back(root->val);
  }
  vector<int> res_;
};
// leetcode submit region end(Prohibit modification and deletion)
