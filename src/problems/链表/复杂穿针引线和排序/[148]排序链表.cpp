//给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。 
//
// 进阶： 
//
// 
// 你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？ 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [4,2,1,3]
//输出：[1,2,3,4]
// 
//
// 示例 2： 
//
// 
//输入：head = [-1,5,3,4,0]
//输出：[-1,0,3,4,5]
// 
//
// 示例 3： 
//
// 
//输入：head = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目在范围 [0, 5 * 104] 内 
// -105 <= Node.val <= 105 
// 
// Related Topics 排序 链表 
// 👍 1169 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
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
    // mid 为左侧链表最后一个节点
    auto mid = FindMidNode(head);
    // right 为右侧链表第一个节点
    auto right = mid->next;
    // 断开左右侧链表
    mid->next = nullptr;
    // 递归 Merge，左侧链表 head，右侧链表 right
    return Merge(sortList(head), sortList(right));

  }
};
//leetcode submit region end(Prohibit modification and deletion)
