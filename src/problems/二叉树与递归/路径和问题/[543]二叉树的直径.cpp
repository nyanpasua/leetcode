/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */

//给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。
//
//
//
// 示例 :
//给定二叉树
//
//           1
//         / \
//        2   3
//       / \     
//      4   5
//
//
// 返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。
//
//
//
// 注意：两结点之间的路径长度是以它们之间边的数目表示。
// Related Topics 树
// 👍 723 👎 0

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
#include <algorithm>
/// 后序遍历
// left,right,root
class Solution {
 public:
  int diameterOfBinaryTree(TreeNode* root) {
    dfs(root);
    return max_len_;
  }

 private:
  int max_len_{0};
  int dfs(TreeNode* root) {
    if (root == nullptr) return -1;
    auto left_len = dfs(root->left);
    auto right_len = dfs(root->right);
    max_len_ = std::max(left_len + right_len + 2, max_len_);
    return 1 + std::max(left_len, right_len);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
