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
 * 思路：典型的归并排序思路，链表原地穿针引线，注意，归并排序是唯一一个可以对链表进行排序的nlogn级别的排序算法
 * Time: O(n)，递归一层
 * Space: O(1)
 */
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    auto dummy_ret = new ListNode(0);
    auto head = dummy_ret;
    while (l1 && l2) {
      if (l1->val <= l2->val) {
        head->next = l1;
        l1 = l1->next;
      } else {
        head->next = l2;
        l2 = l2->next;
      }
      head = head->next;
    }
    if (l2) {
      head->next = l2;
    }
    if (l1) {
      head->next = l1;
    }
    l1 = NULL, l2 = NULL;
    auto ret = dummy_ret->next;
    delete dummy_ret;
    return ret;
  }
};