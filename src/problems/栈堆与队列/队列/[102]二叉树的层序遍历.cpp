//给你一个二叉树，请你返回其按 层序遍历 得到的节点值。
//（即逐层地，从左到右访问所有节点）。
//
//
//
// 示例：
//二叉树：[3,9,20,null,null,15,7],
//
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//
//
// 返回其层序遍历结果：
//
//
//[
//  [3],
//  [9,20],
//  [15,7]
//]
//
// Related Topics 树 广度优先搜索
// 👍 890 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

#include <vector>
#include <queue>
using std::vector;
using std::queue;
class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr) return {};
    std::queue<TreeNode*> q;
    q.push(root);
    vector<vector<int>> res;
    while (!q.empty()) {
      // 打印 q 中全部 node
      auto level_size = q.size();
      std::vector<int> tmp(level_size, 0);
      for (int i = 0; i < level_size; ++i) {
        auto node = q.front();
        tmp[i] = node->val;
        q.pop();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
      res.push_back(tmp);
    }

    return res;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
