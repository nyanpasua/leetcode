/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 */

//给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k
//个最小元素（从 1 开始计数）。
//
//
//
// 示例 1：
//
//
//输入：root = [3,1,4,null,2], k = 1
//输出：1
//
//
// 示例 2：
//
//
//输入：root = [5,3,6,2,4,null,null,1], k = 3
//输出：3
//
//
//
//
//
//
// 提示：
//
//
// 树中的节点数为 n 。
// 1 <= k <= n <= 104
// 0 <= Node.val <= 104
//
//
//
//
// 进阶：如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k
// 小的值，你将如何优化算法？ Related Topics 树 深度优先搜索 二叉搜索树 二叉树
// 👍 409 👎 0

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
  int kthSmallest(TreeNode* root, int k) {
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
    // 提前结束
    if (count_ > k_) return;
    // 递归到底
    if (root == nullptr) return;
    recursion(root->left);
    count_++;
    if (count_ == k_) {
      val_ = root->val;
      return;
    }
    recursion(root->right);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
