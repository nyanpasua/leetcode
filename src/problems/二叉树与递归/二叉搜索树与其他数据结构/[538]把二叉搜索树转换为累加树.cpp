//给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater
// Sum Tree），使每个节点 node 的新值等于原树中大于或等于
// node.val 的值之和。
//
// 提醒一下，二叉搜索树满足下列约束条件：
//
//
// 节点的左子树仅包含键 小于 节点键的节点。
// 节点的右子树仅包含键 大于 节点键的节点。
// 左右子树也必须是二叉搜索树。
//
//
// 注意：本题和 1038:
// https://leetcode-cn.com/problems/binary-search-tree-to-greater-s
// um-tree/ 相同
//
//
//
// 示例 1：
//
//
//
// 输入：[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
//输出：[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
//
//
// 示例 2：
//
// 输入：root = [0,null,1]
//输出：[1,null,1]
//
//
// 示例 3：
//
// 输入：root = [1,0,2]
//输出：[3,3,2]
//
//
// 示例 4：
//
// 输入：root = [3,2,4,1]
//输出：[7,9,4,10]
//
//
//
//
// 提示：
//
//
// 树中的节点数介于 0 和 104 之间。
// 每个节点的值介于 -104 和 104 之间。
// 树中的所有值 互不相同 。
// 给定的树为二叉搜索树。
//
// Related Topics 树 深度优先搜索 二叉搜索树 递归
// 👍 541 👎 0

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
/// 二叉搜索树
// 考虑左节点，本节点 + 父节点sum + 右子树sum
// 考虑右节点，本节点 + 右子树sum（右子树sum为右子树最靠左的节点）
// 因此采用 [right,root,left] 方式自底向上遍历最为合适
// 仔细分析发现，无论任何节点，其 val = val + pre->val

class Solution {
 public:
  TreeNode* convertBST(TreeNode* root) {
    // 原地操作
    dfs(root);
    return root;
  }

 private:
  void dfs(TreeNode* root) {
    if (root == nullptr) return;
    // right
    dfs(root->right);
    // root
    root->val = root->val + (pre_ ? pre_->val : 0);
    pre_ = root;
    // left
    dfs(root->left);
  }
  TreeNode* pre_{nullptr};
};
// leetcode submit region end(Prohibit modification and deletion)
