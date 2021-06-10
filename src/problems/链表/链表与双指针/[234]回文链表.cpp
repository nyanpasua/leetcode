//请判断一个链表是否为回文链表。
//
// 示例 1:
//
// 输入: 1->2
//输出: false
//
// 示例 2:
//
// 输入: 1->2->2->1
//输出: true
//
//
// 进阶：
//你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
// Related Topics 链表 双指针
// 👍 1008 👎 0

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
/// 快慢指针
// 用快慢指针找到链表中点,然后将后半部分翻转
// 遍历两链表判断 val 是否相等
class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    if (head == nullptr) return true;
    auto mid = find_mid(head);
    auto right = reverse(mid->next);
    auto left = head;
    bool ret = true;
    while (ret && right != nullptr) {
      if (left->val != right->val) ret = false;
      left = left->next;
      right = right->next;
    }
    // 还原
    mid->next = reverse(mid->next);
    return ret;
  }

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
  // 如果偶数个,返回第 n/2 个
  // 如果奇数个,返回第 (n+1)/2 个
  ListNode* find_mid(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
