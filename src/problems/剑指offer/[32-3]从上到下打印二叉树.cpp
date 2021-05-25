// 请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，
// 第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。
//     3
//   / \
//  9  20
//    /  \
//   15   7
//返回其层次遍历结果：
//
//[
//  [3],
//  [20,9],
//  [15,7]
//]
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <deque>
#include <vector>
class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr) return {};
    deque<TreeNode*> dq;
    dq.push_back(root);
    vector<vector<int>> res;
    bool flag = true;
    while (!dq.empty()) {
      auto level_size = dq.size();
      vector<int> tmp(level_size, 0);
      if (flag) {
        // true
        for (int i = 0; i < level_size; ++i) {
          auto node = dq.front();
          dq.pop_front();
          tmp[i] = node->val;
          if (node->left) dq.push_back(node->left);
          if (node->right) dq.push_back(node->right);
          flag = false;
        }
      } else {
        // 翻转
        for (int i = 0; i < level_size; ++i) {
          auto node = dq.back();
          dq.pop_back();
          tmp[i] = node->val;
          if (node->right) dq.push_front(node->right);
          if (node->left) dq.push_front(node->left);
          flag = true;
        }
      }
      res.push_back(tmp);
    }
    return res;
  }
};
