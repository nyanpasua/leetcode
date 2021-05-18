/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode;
/// 假设 A 的长度为 a，B 的长度为 b
/// 公共长度为 c, 如果相交，则 c > 0，否则 c = 0
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    auto a = headA, b = headB;
    while (a != b) {
      if (a == nullptr) {
        a = headB;
      } else {
        a = a->next;
      }
      if (b == nullptr) {
        b = headA;
      } else {
        b = b->next;
      }
    }
    return a;
  }
};
