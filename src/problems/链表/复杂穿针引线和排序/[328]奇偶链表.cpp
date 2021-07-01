/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
 */

//给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
//
// 请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为
// O(nodes)，nodes 为节点总数。
//
// 示例 1:
//
// 输入: 1->2->3->4->5->NULL
//输出: 1->3->5->2->4->NULL
//
//
// 示例 2:
//
// 输入: 2->1->3->5->6->4->7->NULL
//输出: 2->3->6->7->1->5->4->NULL
//
// 说明:
//
//
// 应当保持奇数节点和偶数节点的相对顺序。
// 链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。
//
// Related Topics 链表
// 👍 436 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
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
 public:
  ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr) {
      return head;
    }
    ListNode* evenHead = head->next;
    // 奇数
    ListNode* odd = head;
    // 偶数
    ListNode* even = evenHead;
    while (even != nullptr && even->next != nullptr) {
      // odd 与其后面的 偶数断开
      odd->next = even->next;
      odd = odd->next;
      // even 与其后面的 奇数断开
      even->next = odd->next;
      even = even->next;
    }
    // 重连
    odd->next = evenHead;
    return head;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
