/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
 */

//给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
//
//
// 每条从根节点到叶节点的路径都代表一个数字：
//
//
// 例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
//
//
// 计算从根节点到叶节点生成的 所有数字之和 。
//
// 叶节点 是指没有子节点的节点。
//
//
//
// 示例 1：
//
//
//输入：root = [1,2,3]
//输出：25
//解释：
//从根到叶子节点路径 1->2 代表数字 12
//从根到叶子节点路径 1->3 代表数字 13
//因此，数字总和 = 12 + 13 = 25
//
// 示例 2：
//
//
//输入：root = [4,9,0,5,1]
//输出：1026
//解释：
//从根到叶子节点路径 4->9->5 代表数字 495
//从根到叶子节点路径 4->9->1 代表数字 491
//从根到叶子节点路径 4->0 代表数字 40
//因此，数字总和 = 495 + 491 + 40 = 1026
//
//
//
//
// 提示：
//
//
// 树中节点的数目在范围 [1, 1000] 内
// 0 <= Node.val <= 9
// 树的深度不超过 10
//
//
//
// Related Topics 树 深度优先搜索
// 👍 365 👎 0

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
  int sumNumbers(TreeNode* root) {
    if (root == nullptr) return 0;
    recursion(root, 0);
    return res_;
  }

 private:
  int res_;
  void recursion(TreeNode* root, int sum) {
    if (root == nullptr) return;
    sum = sum * 10 + root->val;
    // 到达叶子节点
    if (root->left == nullptr && root->right == nullptr) {
      res_ += sum;
      return;
    }
    // 左右子树
    recursion(root->left, sum);
    recursion(root->right, sum);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
