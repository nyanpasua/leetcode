// 例如输入：
//     4
//   /   \
//  2     7
//  / \   / \
//1   3 6   9
// 镜像输出：
//     4
//   /   \
//  7     2
//  / \   / \
//9   6 3   1

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
  TreeNode* mirrorTree(TreeNode* root) {
    if (root == nullptr) return nullptr;
    return recursion(root);
  }

 private:
  TreeNode* recursion(TreeNode* root) {
    // 递归到底
    if (root == nullptr) return nullptr;
    TreeNode* mirror = new TreeNode(root->val);
    mirror->left = recursion(root->right);
    mirror->right = recursion(root->left);
    return mirror;
  }
};
