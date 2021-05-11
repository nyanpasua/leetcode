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
/**
 * Time: O()
 * Space: O()
 */
class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    auto dummy = new ListNode(0);
    dummy->next = head;
    auto pre = dummy;
    auto cur = dummy->next;
    while (cur) {
      if (cur->val == val) {
        pre->next = cur->next;
        auto tmp = cur;
        cur = cur->next;
        delete tmp;
      } else {
        pre = cur;
        cur = cur->next;
      }
    }
    auto ret = dummy->next;
    delete dummy;
    return ret;
  }
};