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
 * 思路：四指针，pre、node1、node2和next，两两交换
 * Time: O(n)
 * Space: O(1)
 */
class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    auto dummy = new ListNode(0);
    dummy->next = head;
    auto pre = dummy;
    while (pre->next && pre->next->next) {
      auto node1 = pre->next;
      auto node2 = node1->next;
      auto next = node2->next;
      node2->next = node1;
      node1->next = next;
      pre->next = node2;
      pre = node1;
    }
    head = dummy->next;
    delete dummy;
    return head;
  }
};