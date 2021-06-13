/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
 */

//返回与给定的前序和后序遍历匹配的任何二叉树。
//
// pre 和 post 遍历中的值是不同的正整数。
//
//
//
// 示例：
//
// 输入：pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
//输出：[1,2,3,4,5,6,7]
//
//
//
//
// 提示：
//
//
// 1 <= pre.length == post.length <= 30
// pre[] 和 post[] 都是 1, 2, ..., pre.length 的排列
// 每个输入保证至少有一个答案。如果有多个答案，可以返回其中一个。
//
// Related Topics 树
// 👍 173 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <unordered_map>
#include <vector>
using std::unordered_map;
using std::vector;

/// 知道 post 和 pre，无法唯一确定一棵树
// preorder: [root, left, right], [1,2,4,5,3,6,7]
// postorder: [left, right, root], [4,5,2,6,7,3,1]
// 1) preorder 的第一个为 root，
// root + 1 即为 postorder 左子树的最后一个节点
// 2) 递归得到 root->left = build_tree()
// 3) 递归得到 root->right = build_tree()
// 问题在于如何找到左右子树的分界点，分析可知，preorder 的 root，
// 后一个 root + 1 即为 postorder 左子树的最后一个节点
// 以此界点 左侧为左子树，右侧为右子树；因此可以提前建立
// 从 root -> post boundary idx 的 map
class Solution {
 public:
  TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    build_map(post);
    return build_tree(pre, 0, pre.size(), post, 0, post.size());
  }

 private:
  TreeNode* build_tree(const vector<int>& preorder, size_t preorder_begin,
                       size_t preorder_end, const vector<int>& postorder,
                       size_t postorder_begin, size_t postorder_end) {
    if (preorder_begin >= preorder_end || postorder_begin >= postorder_end) {
      return nullptr;
    }
    auto root_info = preorder[preorder_begin];
    auto root = new TreeNode(root_info);
    // 如果这里 preoder_begin + 1 已经大于等于 preorder_end
    if (preorder_begin + 1 >= preorder_end) return root;
    auto boundary = root_boundary_[preorder[preorder_begin + 1]];
    // [1, 2, 4, 5, 3, 6, 7]
    //  0  1  2  3  4  5  6  7
    // [4, 5, 2, 6, 7, 3, 1]
    //           bd          postend
    auto left_node_num = boundary - postorder_begin;
    auto right_node_num = postorder_end - boundary - 1;
    root->left = build_tree(preorder, preorder_begin + 1,
                            preorder_begin + 1 + left_node_num, postorder,
                            boundary - left_node_num, boundary);
    root->right =
        build_tree(preorder, preorder_begin + 1 + left_node_num,
                   preorder_begin + left_node_num + right_node_num + 1,
                   postorder, boundary, boundary + right_node_num);
    return root;
  }
  void build_map(const vector<int>& postorder) {
    size_t idx = 0;
    for (const auto& node : postorder) {
      // 这里用前加
      root_boundary_[node] = ++idx;
    }
  }
  unordered_map<int, size_t> root_boundary_;
};
// leetcode submit region end(Prohibit modification and deletion)
