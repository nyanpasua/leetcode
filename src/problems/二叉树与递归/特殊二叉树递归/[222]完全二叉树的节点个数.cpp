/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */

//给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
//
// 完全二叉树
// 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层
//为第 h 层，则该层包含 1~ 2h 个节点。
//
//
//
// 示例 1：
//
//
//输入：root = [1,2,3,4,5,6]
//输出：6
//
//
// 示例 2：
//
//
//输入：root = []
//输出：0
//
//
// 示例 3：
//
//
//输入：root = [1]
//输出：1
//
//
//
//
// 提示：
//
//
// 树中节点的数目范围是[0, 5 * 104]
// 0 <= Node.val <= 5 * 104
// 题目数据保证输入的树是 完全二叉树
//
//
//
//
// 进阶：遍历树来统计节点是一种时间复杂度为 O(n)
// 的简单解决方案。你可以设计一个更快的算法吗？ Related Topics 树 二分查找 👍 497
// 👎 0

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

/// 二分搜索
// 如果是满二叉树，则节点个数为 2^h - 1
// 如果最后一层只有 1 个节点，则节点个数为 2^(h - 1)
// 因此只需在 [2^(h-1), 2^h -1] 之间二分判断
// 如果 第 k 个 节点存在，则节点个数一定 >= k，向右侧进一步二分，反之向左侧
// 如何判断第 k 个节点是否存在呢？
// 假如 判断 第 5 和 6 个节点
//     1
//   /  \
//  2    3
// / \  /
// 4 5  6
// 5 的二进制表示为 00000101，后两位 0和1
// 6 的二进制表示为 00000110，后两位 1和0
// 0 表示移动到左子节点，1 表示移动到右子节
class Solution {
 public:
  int countNodes(TreeNode* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    auto level = depth(root);
    int left = 1 << (level - 1);
    int right = (1 << level) - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (exists(root, level - 1, mid)) {
        // 第 mid 节点存在，节点数 >= mid
        left = mid + 1;
      } else {
        // 第 mid 节点不存在
        right = mid - 1;
      }
    }
    return right;
  }

 private:
  bool exists(TreeNode* root, int level, int k) {
    int bits = 1 << (level - 1);
    TreeNode* node = root;
    while (node != nullptr && bits > 0) {
      if (!(bits & k)) {
        node = node->left;
      } else {
        node = node->right;
      }
      bits >>= 1;
    }
    return node != nullptr;
  }

  int depth(TreeNode* root) {
    int level = 0;
    while (root != nullptr) {
      root = root->left;
      ++level;
    }
    return level;
  }
};

/// 递归
// 使用完全二叉树的性质
// 1.如果根节点的左子树深度等于右子树深度，则说明左子树为满二叉树
//     1
//   /  \
//  2    3
// / \  /
// 4 5  6
// 2.如果根节点的左子树深度大于右子树深度，则说明右子树为满二叉树
//      1
//    /  \
//   2    3
//  / \  / \
//  4 5  6 7
// /
// 8
// 3.知道子树是满二叉树，那么就可以轻松得到该子树的节点数目 (1 << depth) - 1
// Time: O(logN*logN)
// Space: O(logN) 栈深度
class Solution1 {
 public:
  int countNodes(TreeNode* root) {
    if (root == nullptr) return 0;
    int left_depth = depth(root->left);
    int right_depth = depth(root->right);
    if (left_depth == right_depth) {
      // 左子树满二叉树
      // + 1 为 root 节点本身
      return countNodes(root->right) + (1 << left_depth);
    } else {
      return countNodes(root->left) + (1 << right_depth);
    }
  }

 private:
  int depth(TreeNode* root) {
    // 由于对任何一棵子树，都是完全二叉树，
    // 因此只要判断左子树即可知道深度
    int level = 0;
    while (root != nullptr) {
      root = root->left;
      level += 1;
    }
    return level;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
