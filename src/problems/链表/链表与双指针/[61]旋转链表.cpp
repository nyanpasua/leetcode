/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

//给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
//
//
//
// 示例 1：
//
//
//输入：head = [1,2,3,4,5], k = 2
//输出：[4,5,1,2,3]
//
//
// 示例 2：
//
//
//输入：head = [0,1,2], k = 4
//输出：[2,0,1]
//
//
//
//
// 提示：
//
//
// 链表中节点的数目在范围 [0, 500] 内
// -100 <= Node.val <= 100
// 0 <= k <= 2 * 109
//
// Related Topics 链表 双指针
// 👍 573 👎 0

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
// 思路：先将链表闭合成环，找到相应的位置断开这个环，确定新的链表头和链表
// Time：O(n)
// Space：O(1)

class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next) {
      return head;
    }
    int n = 1;  // 节点计数
    auto p = head;
    while (p->next) {
      ++n;
      p = p->next;
    }
    // 成环
    p->next = head;
    // 移动 n - k%n 个位置
    for (int i = 0; i < n - (k % n); i++) {
      p = p->next;
      head = head->next;
    }
    // p 是尾结点，head 是头结点
    p->next = nullptr;
    return head;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
