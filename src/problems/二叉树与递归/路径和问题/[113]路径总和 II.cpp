/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */

//给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有
//从根节点到叶子节点 路径总和等于给定目标和的路径。
//
// 叶子节点 是指没有子节点的节点。
//
//
//
//
//
// 示例 1：
//
//
//输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
//输出：[[5,4,11,2],[5,8,4,5]]
//
//
// 示例 2：
//
//
//输入：root = [1,2,3], targetSum = 5
//输出：[]
//
//
// 示例 3：
//
//
//输入：root = [1,2], targetSum = 0
//输出：[]
//
//
//
//
// 提示：
//
//
// 树中节点总数在范围 [0, 5000] 内
// -1000 <= Node.val <= 1000
// -1000 <= targetSum <= 1000
//
//
//
// Related Topics 树 深度优先搜索
// 👍 504 👎 0

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

/// 路径和问题
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
    // 到达叶子节点
    if (root->val == target && root->left == nullptr &&
        root->right == nullptr) {
      res->emplace_back(path);
    }
    recursion(root->left, target - root->val, path, res);
    recursion(root->right, target - root->val, path, res);
    return;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
