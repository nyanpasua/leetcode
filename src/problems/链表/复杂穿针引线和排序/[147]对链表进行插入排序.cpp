/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
 */

//对链表进行插入排序。
//
//
//插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
//每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。
//
//
//
// 插入排序算法：
//
//
// 插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
// 每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
// 重复直到所有输入数据插入完为止。
//
//
//
//
// 示例 1：
//
// 输入: 4->2->1->3
//输出: 1->2->3->4
//
//
// 示例 2：
//
// 输入: -1->5->3->4->0
//输出: -1->0->3->4->5
//
// Related Topics 排序 链表
// 👍 399 👎 0

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
// 思路：使用插入排序的思路，不过可以不像数组那样反复交换内存，可以直接穿针引线
// Time: O(n^2)
// Space: O(1)

class Solution {
 public:
  ListNode* insertionSortList(ListNode* head) {
    // 至少有一个节点
    if (head == nullptr) {
      return head;
    }
    auto node = ListNode(0);
    ListNode* dummy = &node;
    dummy->next = head;
    // sorted 表示每一轮对 curr 排序后，确定插入 curr 的位置
    ListNode* sorted = head;
    ListNode* curr = head->next;
    while (curr != nullptr) {
      // 处理一个特殊情况，如果 sorted 比 curr 值小，说明 curr 位置不需要变化，
      // 直接移动 sorted 到下一个位置即可
      if (sorted->val <= curr->val) {
        sorted = sorted->next;
      } else {
        ListNode *prev = dummy;
        // 循环结束后，prev->next->val > curr->val，
        // 也就是 prev->next 指向第一个比 curr 大的节点
        while (prev->next->val <= curr->val) {
          prev = prev->next;
        }
        // 保存 sorted->next 指向 curr->next
        sorted->next = curr->next;
        // 将 curr 插入 prev 后面，prev->next 前面
        curr->next = prev->next;
        prev->next = curr;
      }
      // 插入结束，将 curr 更新到保存的 sorted->next
      curr = sorted->next;
    }
    return dummy->next;
  }
};

class Solution1 {
 public:
  ListNode* insertionSortList(ListNode* head) {
    if (!head || head->next == nullptr) {
      return head;
    }
    // 分析可知，需要pre节点，因此使用dummy来避免特殊情况
    auto node = ListNode(0);
    auto dummy = &node;
    dummy->next = head;
    auto i_pre = dummy->next;
    auto i = i_pre->next;
    auto i_next = i->next;
    while (i) {
      // 一个特殊情况，i_pre指针需要特殊处理
      if (i_pre->val <= i->val) {
        i_pre = i;
        i = i_next;
        if (i) {
          i_next = i_next->next;
        }
        continue;
      }
      for (ListNode* j = dummy; j->next != i; j = j->next) {
        if (j->next->val > i->val) {
          // 插入
          i_pre->next = i_next;
          i->next = j->next;
          auto tmp = j;
          tmp->next = i;
          // 更新指针
          i = i_next;
          if (i) {
            i_next = i_next->next;
          }
          break;
        }
      }
    }
    return dummy->next;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
