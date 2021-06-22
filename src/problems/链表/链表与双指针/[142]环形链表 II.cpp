//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//
// 为了表示给定链表中的环，我们使用整数 pos
// 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是
// -1，则在该链表中没有环。注意，po
// s 仅仅是用于标识环的情况，并不会作为参数传递到函数中。
//
// 说明：不允许修改给定的链表。
//
// 进阶：
//
//
// 你是否可以使用 O(1) 空间解决此题？
//
//
//
//
// 示例 1：
//
//
//
//
//输入：head = [3,2,0,-4], pos = 1
//输出：返回索引为 1 的链表节点
//解释：链表中有一个环，其尾部连接到第二个节点。
//
//
// 示例 2：
//
//
//
//
//输入：head = [1,2], pos = 0
//输出：返回索引为 0 的链表节点
//解释：链表中有一个环，其尾部连接到第一个节点。
//
//
// 示例 3：
//
//
//
//
//输入：head = [1], pos = -1
//输出：返回 null
//解释：链表中没有环。
//
//
//
//
// 提示：
//
//
// 链表中节点的数目范围在范围 [0, 104] 内
// -105 <= Node.val <= 105
// pos 的值为 -1 或者链表中的一个有效索引
//
// Related Topics 链表 双指针
// 👍 1037 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/// 双指针
// fast 指针一次走 2 步，slow 指针一次走 1 步
// 设 fast 指针一共走 f 步，slow 指针一共走 s 步，有，
// f = 2s
// 设从头到环入口（不包括入口点）长度为 a，环长度为 b
// 第一次相遇点，有，
// f = s + nb，可得
// s = nb
// f = 2nb
// 也就是说，fast 比 slow 多跑了 nb 步
// 我们希望能使得两指针在 环入口 相遇，因此想办法让
// 两个指针相遇之后，再一起走 a 步即可
// f = a + 2nb, s = a + nb
class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    auto fast = head, slow = head;
    while (true) {
      // fast 走到 链表末端，说明无 环
      if (fast == nullptr || fast->next == nullptr) return nullptr;
      // 先走，再相遇
      fast = fast->next->next;
      slow = slow->next;
      // 第一次相遇
      if (fast == slow) break;
    }
    // fast 移动到 head
    fast = head;
    // 一起走 a 步，相遇即为 环入口
    while (fast != slow) {
      slow = slow->next;
      fast = fast->next;
    }
    return slow;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
