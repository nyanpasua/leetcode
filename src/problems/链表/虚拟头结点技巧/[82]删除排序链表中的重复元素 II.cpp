/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 */

//存在一个按升序排列的链表，给你这个链表的头节点 head
//，请你删除链表中所有存在数字重复情况的节点，只保留原始链表中 没有重复出现
//的数字。
//
// 返回同样按升序排列的结果链表。
//
//
//
// 示例 1：
//
//
//输入：head = [1,2,3,3,4,4,5]
//输出：[1,2,5]
//
//
// 示例 2：
//
//
//输入：head = [1,1,1,2,3]
//输出：[2,3]
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
// 👍 636 👎 0

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
// 思路：遍历一遍list，使用3指针，pre，cur，cur->next，删除重复元素
// Time: O(N)
// Space: O(1)

class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head) {
      return head;
    }
    auto node = ListNode(0);
    auto dummy = &node;
    dummy->next = head;
    auto pre = dummy;
    auto cur = dummy->next;
    auto cur_next = cur->next;
    int val = 0;
    while (cur_next) {
      if (cur->val == cur_next->val) {
        // 发现重复元素
        val = cur->val;
        while (cur && cur->val == val) {
          // 删除所有值为 val 的节点
          pre->next = cur->next;
          auto tmp = cur;
          cur = cur->next;
          // 防止删除的 cur 已经位于链表尾部
          if (cur) {
            cur_next = cur->next;
          } else {
            cur_next = nullptr;
          }
          delete tmp;
        }
      } else {
        // 没有出现重复元素，直接移动 3 指针
        pre = cur;
        cur = cur_next;
        cur_next = cur->next;
      }
    }
    return dummy->next;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
