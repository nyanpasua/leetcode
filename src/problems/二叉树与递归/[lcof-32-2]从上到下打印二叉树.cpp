// 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
//     3
//   / \
//  9  20
//    /  \
//   15   7
// [
//  [3],
//  [9,20],
//  [15,7]
//]
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <queue>
#include <vector>
using std::vector;

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