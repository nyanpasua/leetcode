/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

//给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
//
// 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点
// p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x
// 的深度尽可能大（
//一个节点也可以是它自己的祖先）。”
//
// 例如，给定如下二叉搜索树: root = [6,2,8,0,4,7,9,null,null,3,5]
//
//
//
//
//
// 示例 1:
//
// 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
//输出: 6
//解释: 节点 2 和节点 8 的最近公共祖先是 6。
//
//
// 示例 2:
//
// 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
//输出: 2
//解释: 节点 2 和节点 4 的最近公共祖先是 2,
//因为根据定义最近公共祖先节点可以为节点本身。
//
//
//
// 说明:
//
//
// 所有节点的值都是唯一的。
// p、q 为不同节点且均存在于给定的二叉搜索树中。
//
// Related Topics 树
// 👍 600 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/// 后续遍历
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
// leetcode submit region end(Prohibit modification and deletion)
