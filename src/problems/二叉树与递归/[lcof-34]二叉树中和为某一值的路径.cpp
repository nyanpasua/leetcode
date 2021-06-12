// 示例:
//给定如下二叉树，以及目标和target = 22，
//
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \    / \
//        7    2  5   1
//返回:
//
//[
//   [5,4,11,2],
//   [5,8,4,5]
//]
//

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
  vector<vector<int>> pathSum(TreeNode* root, int target) {
    vector<vector<int>> res{};
    std::vector<int> path{};
    recursion(root, target, path, &res);
    return res;
  }

 private:
  void recursion(TreeNode* root, int target, vector<int> path,
                 vector<vector<int>>* res) {
    // 递归到底
    if (root == nullptr) return;
    path.emplace_back(root->val);
    if (root->val == target && root->left == nullptr &&
        root->right == nullptr) {
      res->emplace_back(path);
    }
    recursion(root->left, target - root->val, path, res);
    recursion(root->right, target - root->val, path, res);
    return;
  }
};
