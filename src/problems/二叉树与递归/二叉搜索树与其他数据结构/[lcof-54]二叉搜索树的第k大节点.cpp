// 输入: root = [3,1,4,null,2], k = 1
//   3
//  / \
// 1   4
//  \
//   2
//输出: 4
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 中序遍历递增
// 因此 right root left 这样就是递减
class Solution {
 public:
  int kthLargest(TreeNode* root, int k) {
    count_ = 0;
    k_ = k;
    recursion(root);
    return val_;
  }

 private:
  int count_;
  int k_;
  int val_;
  void recursion(TreeNode* root) {
    if (root == nullptr) return;
    recursion(root->right);
    count_++;
    if (count_ == k_) {
      val_ = root->val;
      return;
    }
    recursion(root->left);
  }
};

class Solution1 {
 public:
  int kthLargest(TreeNode* root, int k) {
    recursion(root);
    return val_[val_.size() - k];
  }

 private:
  vector<int> val_;
  void recursion(TreeNode* root) {
    if (root == nullptr) return;
    recursion(root->left);

    val_.push_back(root->val);

    recursion(root->right);
  }
};
