/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */

//给定一个二叉树，返回所有从根节点到叶子节点的路径。
//
// 说明: 叶子节点是指没有子节点的节点。
//
// 示例:
//
// 输入:
//
//   1
//    /   \
//2     3
// \
//  5
//
//输出: ["1->2->5", "1->3"]
//
//解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
// Related Topics 树 深度优先搜索
// 👍 517 👎 0

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
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
 public:
  vector<string> binaryTreePaths(TreeNode* root) {
    if (root == nullptr) return {};
    if (root->left == nullptr && root->right == nullptr) {
      return {std::to_string(root->val)};
    }
    // 这样可以避免首个节点需要判断是否增加 -> 符号
    recursion(root->left, std::to_string(root->val));
    recursion(root->right, std::to_string(root->val));
    return res_;
  }

 private:
  vector<string> res_;
  void recursion(TreeNode* root, string s) {
    if (root == nullptr) return;
    s += ("->" + std::to_string(root->val));
    // 到达叶子节点
    if (root->left == nullptr && root->right == nullptr) {
      res_.push_back(s);
      return;
    }
    recursion(root->left, s);
    recursion(root->right, s);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
