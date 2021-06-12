// [3,9,20,null,null,15,7]
//     3
//   / \
//  9  20
//    /  \
//   15   7
// return [3,9,20,15,7]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>
#include <queue>
using std::vector;
struct TreeNode;

class Solution {
 public:
  vector<int> levelOrder(TreeNode* root) {
    if (root == nullptr) return {};
    std::queue<TreeNode*> q;
    std::vector<int> res;
    // res.reserve(10000);
    q.push(root);
    while (!q.empty()) {
      auto node = q.front();
      q.pop();
      res.emplace_back(node->val);
      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }
    return res;
  }
};
