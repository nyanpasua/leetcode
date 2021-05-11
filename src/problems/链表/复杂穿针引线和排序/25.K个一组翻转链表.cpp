//
// Created by liyingmin on 2020/4/13.
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
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
  ListNode* reverseKGroup(ListNode* head, int k) {
    auto dummy = new ListNode(0);
    dummy->next = head;

    auto pre = dummy;
    auto end = dummy;

    while (end->next != nullptr) {
      for (int i = 0; i < k && end != nullptr; i++) {
        end = end->next;
      }
      if (end == nullptr) {
        break;
      }
      auto start = pre->next;
      auto next = end->next;
      end->next = nullptr;
      pre->next = reverseList(start);
      start->next = next;
      pre = start;

      end = pre;
    }
    auto ret = dummy->next;
    delete dummy;
    return ret;
  }
};