// 你可以将以下二叉树：
//
//    1
//   / \
//  2   3
//     / \
//    4   5
//
//序列化为 "[1,2,3,null,null,4,5]"
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <limits>
#include <queue>
#include <sstream>
#include <string>
using std::string;

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (root == nullptr) return " ";
    std::queue<TreeNode*> q;
    q.push(root);
    std::string res = "[";
    while (!q.empty()) {
      auto node = q.front();
      q.pop();
      if (node != nullptr) {
        res += std::to_string(node->val) + ",";
        q.push(node->left);
        q.push(node->right);
      } else {
        res += "null,";
      }
    }
    res[res.size() - 1] = ']';
    return res;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data == " ") return nullptr;
    data[0] = ' ';
    data[data.size() - 1] = ',';
    std::queue<TreeNode*> q;
    std::istringstream ss(data);
    std::string cur;
    std::getline(ss, cur, ',');
    auto root = new TreeNode(std::stoi(cur));
    q.push(root);

    while (!q.empty()) {
      auto node = q.front();
      q.pop();
      // 获取左侧
      if (std::getline(ss, cur, ',')) {
        // 获取有效
        if (cur == "null")
          node->left = nullptr;
        else {
          node->left = new TreeNode(std::stoi(cur));
          q.push(node->left);
        }
      } else
        break;
      // 获取右侧
      if (std::getline(ss, cur, ',')) {
        if (cur == "null")
          node->right = nullptr;
        else {
          node->right = new TreeNode(std::stoi(cur));
          q.push(node->right);
        }
      } else
        break;
    }
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
