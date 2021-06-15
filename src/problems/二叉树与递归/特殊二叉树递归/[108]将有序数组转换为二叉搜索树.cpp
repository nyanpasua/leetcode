//给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡
//二叉搜索树。
//
// 高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1
// 」的二叉树。
//
//
//
// 示例 1：
//
//
//输入：nums = [-10,-3,0,5,9]
//输出：[0,-3,9,-10,null,5]
//解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：
//
//
//
// 示例 2：
//
//
//输入：nums = [1,3]
//输出：[3,1]
//解释：[1,3] 和 [3,1] 都是高度平衡二叉搜索树。
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums 按 严格递增 顺序排列
//
// Related Topics 树 深度优先搜索
// 👍 779 👎 0

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
struct TreeNode;
/// 二分法
/// left, root, right
// -> root
class Solution {
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return recursion(nums, 0, nums.size() - 1);
  }

 private:
  TreeNode* recursion(const vector<int>& nums, int l, int r) {
    if (l > r) return nullptr;
    // 构造 root
    int mid = l + (r - l) / 2;
    auto root = new TreeNode(nums[mid]);
    // 左子树
    root->left = recursion(nums, l, mid - 1);
    // 右子树
    root->right = recursion(nums, mid + 1, r);
    return root;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
