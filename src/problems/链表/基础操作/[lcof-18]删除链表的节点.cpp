// 输入: head = [4,5,1,9], val = 5
//输出: [4,1,9]
//解释: 给定你链表中值为5的第二个节点，那么在调用了你的函数之后，该链表应变为 4
//-> 1 -> 9.
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
  ListNode* deleteNode(ListNode* head, int val) {
    ListNode node(0);
    auto dummy = &node;
    dummy->next = head;
    auto pre = dummy;
    auto cur = head;
    while (cur != nullptr) {
      if (cur->val == val) {
        // 删除操作
        auto next = cur->next;
        pre->next = next;
        // delete cur;
        break;
      } else {
        pre = cur;
        cur = cur->next;
      }
    }
    auto ret = dummy->next;
    return ret;
  }
};
