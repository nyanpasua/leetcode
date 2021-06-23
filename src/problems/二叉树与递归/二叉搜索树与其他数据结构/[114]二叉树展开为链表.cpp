//给你二叉树的根结点 root ，请你将它展开为一个单链表：
//
//
// 展开后的单链表应该同样使用 TreeNode ，其中 right
// 子指针指向链表中下一个结点，而左子指针始终为 null 。
// 展开后的单链表应该与二叉树 先序遍历 顺序相同。
//
//
//
//
// 示例 1：
//
//
//输入：root = [1,2,5,3,4,null,6]
//输出：[1,null,2,null,3,null,4,null,5,null,6]
//
//
// 示例 2：
//
//
//输入：root = []
//输出：[]
//
//
// 示例 3：
//
//
//输入：root = [0]
//输出：[0]
//
//
//
//
// 提示：
//
//
// 树中结点数在范围 [0, 2000] 内
// -100 <= Node.val <= 100
//
//
//
//
// 进阶：你可以使用原地算法（O(1) 额外空间）展开这棵树吗？
// Related Topics 树 深度优先搜索
// 👍 826 👎 0

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

/// 前序遍历，常数寻找前驱
// root,left,right
// 由于前序遍历的迭代方式为：按照 right,left,root 方式去入栈，
// 也就是出栈顺序为 root,left,right
// 该节点的左子树中最后一个被访问的节点是左子树中的最右边的节点，也是该节点的前驱节点。
// 因此，问题转化成寻找当前节点的前驱节点。
// Time: O(N)
// Space: O(1)
class Solution {
 public:
  void flatten(TreeNode* root) {
    TreeNode* curr = root;
    while (curr != nullptr) {
      if (curr->left != nullptr) {
        // 找到左子树的最右边的节点
        // 1.第一次向左走
        auto next = curr->left;
        auto predecessor = next;
        // 2.一直向右找
        while (predecessor->right != nullptr) {
          predecessor = predecessor->right;
        }
        // 前驱的 right 指向 当前节点的 right
        predecessor->right = curr->right;
        curr->left = nullptr;
        // 当前节点的 right 修改为 左节点，相当于左子树右移
        curr->right = next;
      }
      // 更新新的 curr 为 curr 的右节点，因为左子树已经右移了
      curr = curr->right;
    }
  }
};

/// 前序遍历，stack 迭代求解
// root,left,right
// 由于前序遍历的迭代方式为：按照 right,left,root 方式去入栈，
// 也就是出栈顺序为 root,left,right
// Time: O(N)
// Space: O(N)
class Solution1 {
 public:
  void flatten(TreeNode* root) {
    if (root == nullptr) {
      return;
    }
    auto stk = stack<TreeNode*>();
    stk.push(root);
    TreeNode* prev = nullptr;
    while (!stk.empty()) {
      TreeNode* curr = stk.top();
      stk.pop();
      if (prev != nullptr) {
        prev->left = nullptr;
        prev->right = curr;
      }
      TreeNode *left = curr->left, *right = curr->right;
      if (right != nullptr) {
        stk.push(right);
      }
      if (left != nullptr) {
        stk.push(left);
      }
      prev = curr;
    }
  }
};

/// 前序遍历，该方式会导致二叉树结构遭到破坏，无法完成解答
// root,left,right
class Solution_deprecated {
 public:
  void flatten(TreeNode* root) { dfs(root); }

 private:
  void dfs(TreeNode* root) {
    // 由于 root 在遍历过程中，很多场景都会出现
    // nullptr，而不只是最后一个节点才出现 pre_
    // 只记录上一递归遍历过程的访问节点，因此必须一开始就返回，否则会影响 pre_
    // 造成访问越界
    if (root == nullptr) return;
    cur_ = root;
    // 出现 pre_
    if (pre_ != nullptr) {
      // 由于这里 pre_ -> right 将 改变 之前 root 的
      // 右子树，因此二叉树结构会遭到破坏
      pre_->right = cur_;
      // 这里可能会思考为什么最后一个 cur_ 不需要修改 left 为 nullptr
      // 原因是最后一个节点的 left 和 right 本身一定就是指向 nullptr 的
      pre_->left = nullptr;
    }
    pre_ = cur_;
    dfs(cur_->left);
    dfs(cur_->right);
  }
  TreeNode* pre_{nullptr};
  TreeNode* cur_{nullptr};
};
// leetcode submit region end(Prohibit modification and deletion)
