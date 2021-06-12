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
///
class Solution {
 public:
  bool isSubStructure(TreeNode* A, TreeNode* B) {
    if (B == nullptr) return false;
    return recursion(A, B);
  }

 private:
  bool recursion(TreeNode* a, TreeNode* b) {
    if (a == nullptr) return false;
    if (is_same(a, b)) return true;
    return recursion(a->left, b) || recursion(a->right, b);
  }
  bool is_same(TreeNode* a, TreeNode* b) {
    // b 递归到底
    if (b == nullptr) {
      return true;
    }
    if (a == nullptr || a->val != b->val) return false;
    return is_same(a->left, b->left) && is_same(a->right, b->right);
  }
};
