/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 */

//给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
//
// 示例:
//
// 输入: [1,2,3,null,5,null,4]
//输出: [1, 3, 4]
//解释:
//
//   1            <---
//   /   \
//2     3         <---
// \     \
//  5     4       <---
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树
// 👍 485 👎 0

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

/// BFS
// 由于右视图，是每一层序遍历的最后一个节点
class Solution {
 public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) {
      return res;
    }
    std::queue<TreeNode*> queue;
    queue.push(root);
    while (!queue.empty()) {
      int size = queue.size();
      for (int i = 0; i < size; i++) {
        auto node = queue.front();
        queue.pop();
        if (node->left != nullptr) {
          queue.push(node->left);
        }
        if (node->right != nullptr) {
          queue.push(node->right);
        }
        if (i == size - 1) {  //将当前层的最后一个节点放入结果列表
          res.push_back(node->val);
        }
      }
    }
    return res;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
