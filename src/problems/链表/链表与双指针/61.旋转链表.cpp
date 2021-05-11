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
 * 思路：先将链表闭合成环，找到相应的位置断开这个环，确定新的链表头和链表
 * Time：O(n)
 * Space：O(1)
 */
class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next) {
      return head;
    }
    int n = 1;  // 节点计数
    auto p = head;
    while (p->next) {
      ++n;
      p = p->next;
    }
    p->next = head;
    for (int i = 0; i < n - k % n; i++) {
      p = p->next;
      head = head->next;
    }
    p->next = nullptr;
    return head;
  }
};