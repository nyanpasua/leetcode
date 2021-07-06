// 删除双向链表中的值

struct Node {
  explicit Node(int val) : val(val), pre(nullptr), next(nullptr) {}
  int val;
  Node* pre;
  Node* next;
};

class Solution {
 public:
  Node* deleteNode(Node* head, int target) {
    if (head == nullptr) return head;
    Node node(0);
    auto dummy = &node;
    dummy->next = head;
    head->pre = dummy;
    // 由于双向链表保存了前后，因此无需 pre
    auto cur = head;
    while (cur != nullptr) {
      if (cur->val == target) {
        // 找到 target，删除该节点
        auto pre = cur->pre;
        auto next = cur->next;
        pre->next = next;
        // 这里防止删除末尾节点时，next 为空
        if (next != nullptr) {
          next->pre = pre;
        }
        break;
      }
      cur = cur->next;
    }
    // 恢复首节点指向 nullptr
    if (dummy->next != nullptr) {
      dummy->next->pre = nullptr;
    }
    return dummy->next;
  }
};