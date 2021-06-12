// 请实现 copyRandomList 函数，复制一个复杂链表。
// 在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，
// 还有一个 random 指针指向链表中的任意节点或者 null。
// 输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// 输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
//

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#include <unordered_map>
#include <vector>
class Solution1 {
 public:
  Node* copyRandomList(Node* head) {
    if (head == nullptr) return nullptr;
    auto cur = head->next;
    Node node(0);
    auto dummy = &node;
    auto new_cur = new Node(head->val);
    dummy->next = new_cur;
    std::unordered_map<Node*, int> search;
    search.insert({head, 0});
    std::vector<Node*> table;
    table.push_back(new_cur);
    int count = 0;
    while (cur != nullptr) {
      new_cur->next = new Node(cur->val);
      search.insert({cur, ++count});
      new_cur = new_cur->next;
      table.push_back(new_cur);
      cur = cur->next;
    }
    cur = head;
    new_cur = dummy->next;
    while (cur != nullptr) {
      if (cur->random == nullptr)
        new_cur->random = nullptr;
      else
        new_cur->random = table[search[cur->random]];
      new_cur = new_cur->next;
      cur = cur->next;
    }
    return dummy->next;
  }
};

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (head == nullptr) return nullptr;
    auto cur = head;
    while (cur != nullptr) {
      // 复制构建节点
      // A1->B1->A2->B2->A3->B3->nullptr
      auto tmp = new Node(cur->val);
      auto next = cur->next;
      cur->next = tmp;
      tmp->next = next;
      cur = tmp->next;
    }
    cur = head;
    // 复制 random 位置
    do {
      auto new_cur = cur->next;
      if (cur->random != nullptr) {
        new_cur->random = cur->random->next;
      } else {
        new_cur->random = nullptr;
      }
      cur = cur->next->next;
    } while (cur != nullptr);
    // 拆分
    auto pre = head;
    auto ret = pre->next;
    cur = pre->next;
    while (cur->next != nullptr) {
      pre->next = pre->next->next;
      cur->next = cur->next->next;
      pre = pre->next;
      cur = cur->next;
    }
    // 单独处理 pre
    pre->next = nullptr;
    return ret;
  }
};
