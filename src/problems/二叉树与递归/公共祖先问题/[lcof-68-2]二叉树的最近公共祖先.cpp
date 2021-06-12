// 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// 输出: 3
// 解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
// 一个节点也可以是它自己的祖先
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
struct TreeNode;
// 后序遍历：左右中
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return recursion(root, p, q);
  }

 private:
  TreeNode* recursion(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) return nullptr;
    auto left = recursion(root->left, p, q);
    auto right = recursion(root->right, p, q);
    if (root->val == p->val || root->val == q->val) return root;
    if (left == nullptr) {
      // 右子树找到某一个节点，或者右子树已经返回 root
      return right;
    } else if (right == nullptr) {
      return left;
    } else {
      // 左右子树均找到
      return root;
    }
  }
};
