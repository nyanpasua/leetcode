/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode;

// 增加一个 left，无需特殊判断
class Solution2 {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* left = nullptr;
    auto right = head;
    while (right) {
      auto nxt = right->next;
      right->next = left;
      left = right;
      right = nxt;
    }
    return left;
  }
};

/// 由于分析可知，当节点个数小于等于1的时候，直接返回
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ///
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    auto cur = head;
    auto next = head->next;
    while (next) {
      auto next_next = next->next;
      next->next = cur;
      cur = next;
      next = next_next;
    }
    head->next = nullptr;
    return cur;
  }
};