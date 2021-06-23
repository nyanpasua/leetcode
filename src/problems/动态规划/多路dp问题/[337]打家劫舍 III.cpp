//在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。
//除了“根”之外，每栋房子有且只有一个“父“
//房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。
//如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
//
// 计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。
//
// 示例 1:
//
// 输入: [3,2,3,null,3,null,1]
//
//     3
//    / \
//   2   3
//    \   \ 
//     3   1
//
//输出: 7
//解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.
//
// 示例 2:
//
// 输入: [3,4,5,1,3,null,1]
//
//     3
//    / \
//   4   5
//  / \   \ 
// 1   3   1
//
//输出: 9
//解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.
//
// Related Topics 树 深度优先搜索 动态规划
// 👍 883 👎 0

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
#include <algorithm>
#include <unordered_map>
using std::unordered_map;
/// 动态规划+后序遍历
// 此类动态规划只使用一个 dp 数组不够，主要原因是 不使用和使用 会产生两种不同的
// 状态转移 并且都有可能成为最大值。 定义 use 和 nuse 两个数组，其中一个保存
// 使用当前节点 的最大值， 另一个保存 不使用当前节点 的最大值。
//
class Solution {
 public:
  int rob(TreeNode* root) {
    use_[nullptr] = 0;
    nuse_[nullptr] = 0;
    dfs(root);
    return std::max(use_[root], nuse_[root]);
  }
  void dfs(TreeNode* root) {
    if (root == nullptr) return;
    dfs(root->left);
    dfs(root->right);
    // 处理 root
    // 由于是后序遍历，因此其左右孩子都已经保存最大值
    // 使用 root 节点，那么其左右孩子都将不能使用
    use_[root] = root->val + nuse_[root->left] + nuse_[root->right];
    // 不使用 root 节点，那么其左右孩子可以使用也可以不使用，取 max
    nuse_[root] = std::max(use_[root->left], nuse_[root->left]) +
                  std::max(use_[root->right], nuse_[root->right]);
  }

 private:
  unordered_map<TreeNode*, int> use_, nuse_;
};
// leetcode submit region end(Prohibit modification and deletion)
