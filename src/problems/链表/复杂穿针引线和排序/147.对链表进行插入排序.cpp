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
 * 思路：使用插入排序的思路，不过可以不像数组那样反复交换内存，可以直接穿针引线
 * Time: O(n^2)
 * Space: O(1)
 */
class Solution {
 public:
  ListNode* insertionSortList(ListNode* head) {
    if (!head || head->next == nullptr) {
      return head;
    }
    // 分析可知，需要pre节点，因此使用dummy来避免特殊情况
    auto dummy = new ListNode(0);
    dummy->next = head;
    auto i_pre = dummy->next;
    auto i = i_pre->next;
    auto i_next = i->next;
    while (i) {
      // 一个特殊情况，i_pre指针需要特殊处理
      if (i_pre->val <= i->val) {
        i_pre = i;
        i = i_next;
        if (i) {
          i_next = i_next->next;
        }
        continue;
      }
      for (ListNode* j = dummy; j->next != i; j = j->next) {
        if (j->next->val > i->val) {
          // 插入
          i_pre->next = i_next;
          i->next = j->next;
          auto tmp = j;
          tmp->next = i;
          // 更新指针
          i = i_next;
          if (i) {
            i_next = i_next->next;
          }
          break;
        }
      }
    }
    auto ret = dummy->next;
    delete dummy;
    return ret;
  }
};