// 给你两个非空
// 的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，
// 并且每个节点只能存储一位数字。
//请你将两个数相加，并以相同形式返回一个表示和的链表。
//你可以假设除了数字 0 之外，这两个数都不会以 0开头。
//输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
//输出：[8,9,9,9,0,0,0,1]

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Time: O(N)  Space: O(1) 返回是必须的
struct ListNode;
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr && l2 == nullptr) return nullptr;
    int carry = 0;  // 表示进位
    ListNode node(0);
    auto dummy = &node;
    auto cur = dummy;
    while (l1 || l2 || carry) {
      // l1 和 l2 还没有遍历结束,或者还有进位
      auto sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
      carry = sum / 10;
      cur->next = new ListNode(sum % 10);
      cur = cur->next;
      if (l1) l1 = l1->next;
      if (l2) l2 = l2->next;
    }
    return dummy->next;
  }
};
