/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
//
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
//
//
//
// 示例 1：
//
//
//输入：head = [1,2,3,4]
//输出：[2,1,4,3]
//
//
// 示例 2：
//
//
//输入：head = []
//输出：[]
//
//
// 示例 3：
//
//
//输入：head = [1]
//输出：[1]
//
//
//
//
// 提示：
//
//
// 链表中节点的数目在范围 [0, 100] 内
// 0 <= Node.val <= 100
//
//
//
//
// 进阶：你能在不修改链表节点值的情况下解决这个问题吗?（也就是说，仅修改节点本身。）
// Related Topics 递归 链表
// 👍 938 👎 0

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

/// 与 K 个一组翻转相同
class Solution {
 public:
  ListNode* swapPairs(ListNode* head) { return reverse_k(head, 2); }

 private:
  ListNode* reverse(ListNode* head) {
    ListNode* left = nullptr;
    auto right = head;
    while (right) {
      auto nxt = right->next;
      right->next = left;
      left = right;
      right = nxt;
    }
    return left;
  }
  ListNode* reverse_k(ListNode* head, int k) {
    auto node = ListNode(0);
    auto dummy = &node;
    dummy->next = head;

    auto pre = dummy;
    auto end = dummy;

    while (end->next != nullptr) {
      // end 指向第 k 个节点
      for (int i = 0; i < k && end != nullptr; i++) {
        end = end->next;
      }
      // 如果 end 为 nullptr，说明最后一组不到 k 个
      if (end == nullptr) {
        break;
      }
      // 记录翻转前的 start，翻转后就是尾结点
      auto start = pre->next;
      // 记录下一组 k 个节点的首节点
      auto next = end->next;
      // 断开这一组 k 个节点 与 后续链表，方便之后 reverse
      end->next = nullptr;
      // !翻转！并且与上一组 [k 个节点] 的尾结点 pre 链接起来
      pre->next = reverse(start);
      // 翻转后的[k 个节点] 与 后续链表重新链接
      start->next = next;
      // pre 指向翻转后的尾结点
      pre = start;
      // end 指向翻转后的尾结点
      end = pre;
    }
    return dummy->next;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
