/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 */

//给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
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
// 返回锯齿形层序遍历如下：
//
//
//[
//  [3],
//  [20,9],
//  [15,7]
//]
//
// Related Topics 树 广度优先搜索 二叉树
// 👍 462 👎 0

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
class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
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
// leetcode submit region end(Prohibit modification and deletion)
