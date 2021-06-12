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
    if (cur_ == nullptr) {
      head_->left = head_;
      head_->right = head_;
      return head_;
    }
    head_->left = cur_;
    cur_->right = head_;
    return head_;
  }

 private:
  void inorder(Node* root) {
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
