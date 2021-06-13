/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */

//根据一棵树的中序遍历与后序遍历构造二叉树。
//
// 注意:
//你可以假设树中没有重复的元素。
//
// 例如，给出
//
// 中序遍历 inorder = [9,3,15,20,7]
//后序遍历 postorder = [9,15,7,20,3]
//
// 返回如下的二叉树：
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
//
// Related Topics 树 深度优先搜索 数组
// 👍 516 👎 0

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
#include <unordered_map>
#include <vector>
using std::unordered_map;
using std::vector;
/// 知道 in 和 post
// inorder: [left, root, right], [9,3,15,20,7]
// postorder: [left, right, root], [9,15,7,20,3]
// 1) postorder 的最后一个为 root，在 inorder 中，root
// 左侧为左子树，右侧为右子树
// 2) 递归得到 root->left = build_tree()
// 3) 递归得到 root->right = build_tree()
// 问题在于如何找到左右子树的分界点，分析可知，postorder 的 root，在 inorder
// 中，以此界点 左侧为左子树，右侧为右子树；因此可以提前建立
// 从 postorder root -> inorder boundary idx 的 map
class Solution {
 public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    build_map(postorder, inorder);
    return build_tree(postorder, 0, postorder.size(), inorder, 0,
                      inorder.size());
  }

 private:
  TreeNode* build_tree(const vector<int>& postorder, size_t postorder_begin,
                       size_t postorder_end, const vector<int>& inorder,
                       size_t inorder_begin, size_t inorder_end) {
    if (postorder_begin >= postorder_end || inorder_begin >= inorder_end) {
      return nullptr;
    }
    // 注意这里使用的是 尾后迭代器
    auto root_info = postorder[postorder_end - 1];
    auto root = new TreeNode(root_info);
    auto boundary = root_boundary_[root_info];
    auto left_node_num = boundary - inorder_begin;
    auto right_node_num = inorder_end - boundary - 1;
    root->left =
        build_tree(postorder, postorder_begin, postorder_begin + left_node_num,
                   inorder, boundary - left_node_num, boundary);
    root->right =
        build_tree(postorder, postorder_begin + left_node_num,
                   postorder_begin + left_node_num + right_node_num, inorder,
                   boundary + 1, boundary + right_node_num + 1);
    return root;
  }
  void build_map(const vector<int>& postorder, vector<int>& inorder) {
    size_t idx = 0;
    for (const auto& node : inorder) {
      // 建立从 root 到 boundary index 的 map
      // 如 <3, 1> <9, 0>
      root_boundary_[node] = idx++;
    }
  }

  unordered_map<int, size_t> root_boundary_;
};
// leetcode submit region end(Prohibit modification and deletion)
