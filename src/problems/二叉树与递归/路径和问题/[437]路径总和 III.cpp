/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 */

//给定一个二叉树，它的每个结点都存放着一个整数值。
//
// 找出路径和等于给定数值的路径总数。
//
// 路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
//
// 二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。
//
// 示例：
//
// root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
//
//      10
//     /  \
//    5   -3
//   / \    \
//  3   2   11
//      / \   \
//3  -2   1
//
//返回 3。和等于 8 的路径有:
//
// 1.  5 -> 3
// 2.  5 -> 2 -> 1
// 3.  -3 -> 11
//
// Related Topics 树
// 👍 879 👎 0

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
#include <vector>
using std::vector;

class Solution {
 public:
  int pathSum(TreeNode* root, int targetSum) {
    upper_recursion(root, targetSum);
    return count_;
  }

 private:
  void upper_recursion(TreeNode* root, int target) {
    if (root == nullptr) return;
    // 对 root 节点调用 recursion
    recursion(root, target);
    upper_recursion(root->left, target);
    upper_recursion(root->right, target);
  }
  void recursion(TreeNode* root, int target) {
    // 递归到底
    if (root == nullptr) return;
    if (root->val == target) {
      count_++;
    }
    recursion(root->left, target - root->val);
    recursion(root->right, target - root->val);
  }
  int count_{0};
};
// leetcode submit region end(Prohibit modification and deletion)
