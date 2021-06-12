/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 自顶向下的递归
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    min_ = std::min(p->val, q->val);
    max_ = std::max(p->val, q->val);
    return recursion(root, p, q);
  }

 private:
  TreeNode* recursion(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root->val < min_) return recursion(root->right, p, q);
    if (root->val > max_) return recursion(root->left, p, q);
    return root;
  }
  int min_;
  int max_;
};

// 剪枝 + 后序遍历
class Solution3 {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return recursion(root, p, q);
  }

 private:
  TreeNode* recursion(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) return nullptr;
    // 由于是二分搜索树,因此递归路径可以剪枝
    TreeNode *left = nullptr, *right = nullptr;
    if (root->val > std::min(p->val, q->val)) {
      left = recursion(root->left, p, q);
    }
    if (root->val < std::max(p->val, q->val)) {
      right = recursion(root->right, p, q);
    }
    if (root->val == p->val || root->val == q->val) return root;
    // 这一段 ifelse 可以简化
    if (left == nullptr)
      return right;
    else if (right == nullptr)
      return left;
    else
      return root;
  }
};

class Solution2 {
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
    // 这一段 ifelse 可以简化
    if (left == nullptr)
      return right;
    else if (right == nullptr)
      return left;
    else
      return root;
  }
};

// 后序遍历: left right root
class Solution1 {
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
    if (left == nullptr && right == nullptr)
      return nullptr;
    else if (left != nullptr && right == nullptr)
      return left;
    else if (left == nullptr && right != nullptr)
      return right;
    else
      return root;
  }
};
