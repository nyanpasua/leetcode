// 特别地，我们希望可以就地完成转换操作。
// 当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。
// 还需要返回链表中的第一个节点的指针。
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
 public:
  Node* treeToDoublyList(Node* root) {
    if (root == nullptr) return root;
    inorder(root);
    // 如果 cur_ 为空，即 节点数量 <= 1
    if (cur_ == nullptr) {
      head_->left = head_;
      head_->right = head_;
      return head_;
    }
    // 修改 循环指针
    head_->left = cur_;
    cur_->right = head_;
    return head_;
  }

 private:
  void inorder(Node* root) {
    // 可以发现，在中序遍历的过程中，不会破坏二叉树的结构，保证了右子树访问的安全性
    if (root == nullptr) return;
    inorder(root->left);
    // do something
    if (pre_ == nullptr) {
      // 第一个叶子节点
      pre_ = root;
      head_ = root;
    } else {
      // 交换
      cur_ = root;
      cur_->left = pre_;
      pre_->right = cur_;
      pre_ = cur_;
    }
    inorder(root->right);
  }
  Node* cur_ = nullptr;
  Node* pre_ = nullptr;
  Node* head_ = nullptr;
};
