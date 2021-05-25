// 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。
// 如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
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
  bool isBalanced(TreeNode* root) {
    if (root == nullptr) return true;
    return recursion(root);
  }

 private:
  bool recursion(TreeNode* root) {
    if (root == nullptr) return true;
    auto depth_left = depth(root->left);
    auto depth_right = depth(root->right);
    return std::abs(depth_left - depth_right) <= 1 && recursion(root->left) &&
           recursion(root->right);
  }
  int depth(TreeNode* root) {
    if (root == nullptr) return 0;
    return std::max(depth(root->left), depth(root->right)) + 1;
  }
};
