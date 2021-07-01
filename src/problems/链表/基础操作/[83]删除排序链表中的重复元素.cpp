/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

//存在一个按升序排列的链表，给你这个链表的头节点 head
//，请你删除所有重复的元素，使每个元素 只出现一次 。
//
// 返回同样按升序排列的结果链表。
//
//
//
// 示例 1：
//
//
//输入：head = [1,1,2]
//输出：[1,2]
//
//
// 示例 2：
//
//
//输入：head = [1,1,2,3,3]
//输出：[1,2,3]
//
//
//
//
// 提示：
//
//
// 链表中节点数目在范围 [0, 300] 内
// -100 <= Node.val <= 100
// 题目数据保证链表已经按升序排列
//
// Related Topics 链表
// 👍 598 👎 0

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
/// 有序链表
// 由于给定的链表是排好序的，因此重复的元素在链表中出现的位置是连续的，
// 因此我们只需要对链表进行一次遍历，就可以删除重复的元素。
//
//具体地，我们从指针 cur
//指向链表的头节点，随后开始对链表进行遍历。如果当前 cur 与
// cur.next 对应的元素相同，那么我们就将
// cur.next 从链表中移除；否则说明链表中已经不存在其它与
// cur 对应的元素相同的节点，因此可以将 cur 指向
// cur.next。
//
//当遍历完整个链表之后，我们返回链表的头节点即可。
//
class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head) {
      return head;
    }
    ListNode* cur = head;
    while (cur->next) {
      if (cur->val == cur->next->val) {
        // 移除 cur->next
        cur->next = cur->next->next;
      } else {
        // cur 指向下一个值
        cur = cur->next;
      }
    }

    return head;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
