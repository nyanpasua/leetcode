// 前序遍历 preorder = [3,9,20,15,7]
// 中序遍历 inorder = [9,3,15,20,7]
//    3
//   / \
//  9  20
//    /  \
//   15   7

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

/// preorder: [root, left, right], [3,9,20,15,7]
/// inorder: [left, root, right], [9,3,15,20,7]
/// 1) preorder 的第一个为 root
/// 2) 递归得到 root->left = build_tree()
/// 3) 递归得到 root->right = build_tree()
/// 问题在于如何找到左右子树的分界点，分析可知，preorder 的 root，在 inorder
/// 中，以此界点 左侧为左子树，右侧为右子树；因此可以提前建立
/// 从 preorder root -> inorder boundary idx 的 map
///
class Solution {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    build_map(preorder, inorder);
    return build_tree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
  }

 private:
  ///
  /// \param preorder
  /// \param preorder_begin from 0
  /// \param preorder_end posttail iterator
  /// \param inorder
  /// \param inorder_begin from 0
  /// \param inorder_end posttail iterator
  /// \return
  TreeNode* build_tree(const vector<int>& preorder, size_t preorder_begin,
                       size_t preorder_end, const vector<int>& inorder,
                       size_t inorder_begin, size_t inorder_end) {
    if (preorder_begin >= preorder_end || inorder_begin >= inorder_end) {
      return nullptr;
    }
    auto root_info = preorder[preorder_begin];
    auto root = new TreeNode(root_info);
    auto boundary = root_boundary_[root_info];
    auto left_node_num = boundary - inorder_begin;
    auto right_node_num = inorder_end - boundary - 1;
    root->left = build_tree(preorder, preorder_begin + 1,
                            preorder_begin + left_node_num + 1, inorder,
                            boundary - left_node_num, boundary);
    root->right =
        build_tree(preorder, preorder_begin + 1 + left_node_num,
                   preorder_begin + 1 + left_node_num + right_node_num, inorder,
                   boundary + 1, boundary + right_node_num + 1);
    return root;
  }
  // 这里建表的复杂度高了
  void build_map_fake(const vector<int>& preorder, const vector<int>& inorder) {
    for (const auto& node : preorder) {
      auto it = std::find(inorder.cbegin(), inorder.cend(), node);
      assert(it != inorder.cend());
      // 建立从 root 到 boundary index 的 map
      // 如 <3, 1> <9, 0>
      root_boundary_[node] = (it - inorder.cbegin());
    }
  }
  void build_map(const vector<int>& preorder, const vector<int>& inorder) {
    size_t idx = 0;
    for (const auto& node : inorder) {
      // 建立从 root 到 boundary index 的 map
      // 如 <3, 1> <9, 0>
      root_boundary_[node] = idx++;
    }
  }

  std::unordered_map<int, size_t> root_boundary_;
};