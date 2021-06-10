//给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
//
// k 是一个正整数，它的值小于或等于链表的长度。
//
// 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
//
// 进阶：
//
//
// 你可以设计一个只使用常数额外空间的算法来解决此问题吗？
// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
//
//
//
//
// 示例 1：
//
//
//输入：head = [1,2,3,4,5], k = 2
//输出：[2,1,4,3,5]
//
//
// 示例 2：
//
//
//输入：head = [1,2,3,4,5], k = 3
//输出：[3,2,1,4,5]
//
//
// 示例 3：
//
//
//输入：head = [1,2,3,4,5], k = 1
//输出：[1,2,3,4,5]
//
//
// 示例 4：
//
//
//输入：head = [1], k = 1
//输出：[1]
//
//
//
//
//
// 提示：
//
//
// 列表中节点的数量在范围 sz 内
// 1 <= sz <= 5000
// 0 <= Node.val <= 1000
// 1 <= k <= sz
//
// Related Topics 链表
// 👍 1130 👎 0

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
  ListNode* reverseList(ListNode* head) {
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
  ListNode* reverseKGroup(ListNode* head, int k) {
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
      pre->next = reverseList(start);
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
