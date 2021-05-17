/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode;
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l2 == nullptr) return l1;
    auto node = ListNode(0);
    auto dummy = &node;
    dummy->next = l1;
    auto pre_l = dummy;
    auto l = l1;
    auto r = l2;
    auto post_r = r->next;
    while (l != nullptr || r != nullptr) {
      if (l == nullptr) {
        // 右侧多余
        pre_l->next = r;
        break;
      } else if (r == nullptr) {
        // 左侧多余，直接返回即可
        break;
      } else if (l->val > r->val) {
        // 左侧比右侧大，将右侧节点插入，并更新指针
        pre_l->next = r;
        r->next = l;
        pre_l = pre_l->next;
        r = post_r;
        // 这里要特别小心这个边界情况
        if (post_r) {
          post_r = post_r->next;
        }
      } else {
        // 左侧比右侧小 或者等于右侧，保持右侧指针不动，左侧移动
        pre_l = l;
        l = l->next;
      }
    }
    return dummy->next;
  }
};
