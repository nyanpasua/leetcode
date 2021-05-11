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
 * 思路：使用自顶向下的归并排序的思路，但是不像数组需要额外内存，链表重连即可
 * Time: O(nlogn)
 * Space: O(1) + 堆栈内存（栈深度logn）
 */
class Solution {
 private:
  // Time: O(n)
  ListNode* FindMidNode(ListNode* head) {
    auto fast = head, slow = head;
    while (fast->next && fast->next && fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
  }
  ListNode* Merge(ListNode* l1, ListNode* l2) {
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
 public:
  ListNode* sortList(ListNode* head) {
    // 递归到底，只剩1个node的时候
    if (!head || !head->next) {
      return head;
    }
    // 找mid和right
    auto mid = FindMidNode(head);
    auto right = mid->next;
    // 断开mid左右两端
    mid->next = nullptr;
    // 递归Merge
    return Merge(sortList(head), sortList(right));

  }
};