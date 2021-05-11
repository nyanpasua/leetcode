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
  void deleteNode(ListNode* node) {
    if (!node) {
      return;
    }
    if (!node->next) {
      delete node;
      node = nullptr;
      return;
    }
    auto delnode = node->next;
    *node = *(node->next);
    delete delnode;
  }
};