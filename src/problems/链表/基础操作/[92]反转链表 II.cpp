/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

//给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right
//。请你反转从位置 left 到位置 right 的链 表节点，返回 反转后的链表 。
//
//
// 示例 1：
//
//
//输入：head = [1,2,3,4,5], left = 2, right = 4
//输出：[1,4,3,2,5]
//
//
// 示例 2：
//
//
//输入：head = [5], left = 1, right = 1
//输出：[5]
//
//
//
//
// 提示：
//
//
// 链表中节点数目为 n
// 1 <= n <= 500
// -500 <= Node.val <= 500
// 1 <= left <= right <= n
//
//
//
//
// 进阶： 你可以使用一趟扫描完成反转吗？
// Related Topics 链表
// 👍 937 👎 0

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
/// 翻转
// 第 1 步：先将待反转的区域反转；
//第 2 步：把 pre 的 next
//指针指向反转以后的链表头节点，把反转以后的链表的尾节点的 next 指针指向 succ。
//
class Solution {
 private:
  void reverseLinkedList(ListNode *head) {  // 也可以使用递归反转一个链表
    ListNode *pre = nullptr;
    ListNode *cur = head;
    while (cur != nullptr) {
      ListNode *next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
  }

 public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    // 因为头节点有可能发生变化，使用虚拟头节点可以避免复杂的分类讨论
    ListNode *dummyNode = new ListNode(-1);
    dummyNode->next = head;

    ListNode *pre = dummyNode;
    // 第 1 步：从虚拟头节点走 left - 1 步，来到 left 节点的前一个节点
    // 建议写在 for 循环里，语义清晰
    for (int i = 0; i < left - 1; i++) {
      pre = pre->next;
    }

    // 第 2 步：从 pre 再走 right - left + 1 步，来到 right 节点
    ListNode *rightNode = pre;
    for (int i = 0; i < right - left + 1; i++) {
      rightNode = rightNode->next;
    }

    // 第 3 步：切断出一个子链表（截取链表）
    ListNode *leftNode = pre->next;
    ListNode *curr = rightNode->next;

    // 注意：切断链接
    pre->next = nullptr;
    rightNode->next = nullptr;

    // 第 4 步：同第 206 题，反转链表的子区间
    reverseLinkedList(leftNode);

    // 第 5 步：接回到原来的链表中
    pre->next = rightNode;
    leftNode->next = curr;
    return dummyNode->next;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
