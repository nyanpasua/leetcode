/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
 */

//给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key
//对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的
//根节点的引用。
//
// 一般来说，删除节点可分为两个步骤：
//
//
// 首先找到需要删除的节点；
// 如果找到了，删除它。
//
//
// 说明： 要求算法时间复杂度为 O(h)，h 为树的高度。
//
// 示例:
//
//
// root = [5,3,6,2,4,null,7]
// key = 3
//
//    5
//   / \
//  3   6
//          / \   \
//2   4   7
//
//给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
//
//一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
//
//    5
//   / \
//  4   6
//          /     \
//2       7
//
//另一个正确答案是 [5,2,6,null,4,null,7]。
//
//    5
//   / \
//  2   6
//   \   \
//    4   7
//
// Related Topics 树 二叉搜索树 二叉树
// 👍 471 👎 0

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
/// 树的删除操作
// Successor
// 代表的是中序遍历序列的下一个节点。即比当前节点大的最小节点，简称后继节点。
// 先取当前节点的右节点，然后一直取该节点的左节点，直到左节点为空，则最后指向的节点为后继节点。
// Predecessor
// 代表的是中序遍历序列的前一个节点。即比当前节点小的最大节点，简称前驱节点。
// 先取当前节点的左节点，然后取该节点的右节点，直到右节点为空，则最后指向的节点为前驱节点。
// 1.要删除的节点为叶子节点，可以直接删除。
// 2.要删除的节点不是叶子节点且拥有右节点，则该节点可以由该节点的后继节点进行替代，
// 该后继节点位于右子树中较低的位置。然后可以从后继节点的位置递归向下操作以删除后继节点。
// 3.要删除的节点不是叶子节点，且没有右节点但是有左节点。这意味着它的后继节点在它的上面，
// 但是我们并不想返回。我们可以使用它的前驱节点进行替代，然后再递归的向下删除前驱节点。
// Time: O(logN)
// 由于是二叉搜索树，因此节点值都不等
class Solution {
 private:
  int successor(TreeNode* root) {
    root = root->right;
    while (root->left != nullptr) root = root->left;
    return root->val;
  }
  int predecessor(TreeNode* root) {
    root = root->left;
    while (root->right != nullptr) root = root->right;
    return root->val;
  }

 public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return nullptr;

    // delete from the right subtree
    if (key > root->val) root->right = deleteNode(root->right, key);
    // delete from the left subtree
    else if (key < root->val)
      root->left = deleteNode(root->left, key);
    // delete the current node
    else {
      // the node is a leaf
      if (root->left == nullptr && root->right == nullptr) root = nullptr;
      // the node is not a leaf and has a right child
      else if (root->right != nullptr) {
        root->val = successor(root);
        // 删除 root->val, 也就是前驱结点
        root->right = deleteNode(root->right, root->val);
      }
      // the node is not a leaf, has no right child, and has a left child
      else {
        root->val = predecessor(root);
        root->left = deleteNode(root->left, root->val);
      }
    }
    return root;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
