// 给定一个链表: 1->2->3->4->5, 和 k = 2.
//
// 返回链表 4->5.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/// 采用快慢指针，慢指针不动，先让快指针走 k
/// 步，然后一起走，快指针到末尾，停止，返回慢指针
/// Time: O(n) Space: O(1)
class Solution {
 public:
  ListNode* getKthFromEnd(ListNode* head, int k) {
    if (head == nullptr) return nullptr;
    auto fast = head;
    auto slow = head;
    for (int i = 0; i < k; ++i) {
      fast = fast->next;
    }
    while (fast != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }
    return slow;
  }
};