/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 */

//计算给定二叉树的所有左叶子之和。
//
// 示例：
//
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//
//在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
//
//
// Related Topics 树
// 👍 318 👎 0

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
// 这道题的关键是如何判断左叶子节点
// 每一层递归将上层的节点传入，root == upper.left && root->left == nullptr &&
// root->right == nullptr
class Solution {
 public:
  int sumOfLeftLeaves(TreeNode* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 0;
    recursion(root->left, root);
    recursion(root->right, root);
    return sum_;
  }

 private:
  void recursion(TreeNode* root, TreeNode* upper) {
    if (root == nullptr) return;
    if (root == upper->left && root->left == nullptr &&
        root->right == nullptr) {
      sum_ += root->val;
    }
    recursion(root->left, root);
    recursion(root->right, root);
  }
  int sum_{0};
};
// leetcode submit region end(Prohibit modification and deletion)
