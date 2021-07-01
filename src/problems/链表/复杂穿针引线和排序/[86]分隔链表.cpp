/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */

//给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x
//的节点都出现在 大于或等于 x 的节点之前。
//
// 你应当 保留 两个分区中每个节点的初始相对位置。
//
//
//
// 示例 1：
//
//
//输入：head = [1,4,3,2,5,2], x = 3
//输出：[1,2,2,4,3,5]
//
//
// 示例 2：
//
//
//输入：head = [2,1], x = 2
//输出：[1,2]
//
//
//
//
// 提示：
//
//
// 链表中节点的数目在范围 [0, 200] 内
// -100 <= Node.val <= 100
// -200 <= x <= 200
//
// Related Topics 链表 双指针
// 👍 419 👎 0

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
/// 重连
class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    ListNode small_dummy = ListNode(0);
    auto small = &small_dummy;
    ListNode* smallHead = small;
    ListNode large_dummy = ListNode(0);
    auto large = &large_dummy;
    ListNode* largeHead = large;
    while (head != nullptr) {
      if (head->val < x) {
        // 将 small 的 next 指针指向该节点
        small->next = head;
        small = small->next;
      } else {
        large->next = head;
        large = large->next;
      }
      head = head->next;
    }
    large->next = nullptr;
    // 连接
    small->next = largeHead->next;
    return smallHead->next;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
