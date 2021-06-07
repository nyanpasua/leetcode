//给定一个二叉树，返回其节点值自底向上的层序遍历。
//（即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
//
// 例如：
//给定二叉树 [3,9,20,null,null,15,7],
//
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//
//
// 返回其自底向上的层序遍历为：
//
//
//[
//  [15,7],
//  [9,20],
//  [3]
//]
//
// Related Topics 树 广度优先搜索
// 👍 446 👎 0

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

#include <algorithm>
#include <queue>
#include <vector>
using std::vector;
class Solution {
 public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
    std::reverse(res.begin(), res.end());
    return res;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
