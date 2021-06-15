//路径
//被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中
//至多出现一次 。该路径 至少包含一个 节点，且不 一定经过根节点。
//
// 路径和 是路径中各节点值的总和。
//
// 给你一个二叉树的根节点 root ，返回其 最大路径和 。
//
//
//
// 示例 1：
//
//
//输入：root = [1,2,3]
//输出：6
//解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6
//
// 示例 2：
//
//
//输入：root = [-10,9,20,null,null,15,7]
//输出：42
//解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42
//
//
//
//
// 提示：
//
//
// 树中节点数目范围是 [1, 3 * 104]
// -1000 <= Node.val <= 1000
//
// Related Topics 树 深度优先搜索 递归
// 👍 1070 👎 0

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
#include <limits>
#include <algorithm>
/// dfs
class Solution {
 public:
  int maxPathSum(TreeNode* root) {
    recursion(root);
    return max_len_;
  }

 private:
  // 后序遍历：left,right,root
  int recursion(TreeNode* root) {
    // 递归到底
    if (root == nullptr) return 0;
    auto left_len = std::max(recursion(root->left), 0);
    auto right_len = std::max(recursion(root->right), 0);
    auto length = root->val + left_len + right_len;
    max_len_ = std::max(max_len_, length);
    // 返回左或者右路径的最大值 + root->val
    // 因为向上递归的路径 只能包含左或者右子树
    return root->val + std::max(left_len, right_len);
  }
  int max_len_{std::numeric_limits<int>::min()};
};
// leetcode submit region end(Prohibit modification and deletion)
