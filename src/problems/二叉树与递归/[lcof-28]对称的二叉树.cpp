// 请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  bool isSymmetric(TreeNode* root) {
    if (root == nullptr) return true;
    return recursion(root->left, root->right);
  }

 private:
  bool recursion(TreeNode* left, TreeNode* right) {
    if (left == nullptr && right != nullptr) return false;
    if (left != nullptr && right == nullptr) return false;
    if (left == nullptr && right == nullptr) return true;
    if (left->val != right->val) return false;
    return recursion(left->right, right->left) &&
           recursion(left->left, right->right);
  }
};
