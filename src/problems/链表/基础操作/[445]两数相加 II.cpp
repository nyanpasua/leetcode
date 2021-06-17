/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
 */

//给你两个 非空
//链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
//
// 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
//
//
//
// 进阶：
//
// 如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。
//
//
//
// 示例：
//
// 输入：(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 8 -> 0 -> 7
//
// Related Topics 链表
// 👍 397 👎 0

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
#include <stack>
using std::stack;
/// 栈 + 两数相加
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> s1, s2;
    while (l1) {
      s1.push(l1->val);
      l1 = l1->next;
    }
    while (l2) {
      s2.push(l2->val);
      l2 = l2->next;
    }
    int carry = 0;
    ListNode* ans = nullptr;
    while (!s1.empty() || !s2.empty() || carry != 0) {
      int a = s1.empty() ? 0 : s1.top();
      int b = s2.empty() ? 0 : s2.top();
      if (!s1.empty()) s1.pop();
      if (!s2.empty()) s2.pop();
      int cur = a + b + carry;
      carry = cur / 10;
      cur %= 10;
      auto curnode = new ListNode(cur);
      curnode->next = ans;
      ans = curnode;
    }
    return ans;
  }
};

/// 翻转链表 + 两数相加
class Solution1 {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);
    return reverse(add(l1, l2));
  }

 private:
  ListNode* reverse(ListNode* head) {
    ListNode* left = nullptr;
    auto right = head;
    while (right != nullptr) {
      auto tmp = right->next;
      right->next = left;
      left = right;
      right = tmp;
    }
    return left;
  }
  ListNode* add(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr && l2 == nullptr) return nullptr;
    int carry = 0;  // 表示进位
    ListNode node(0);
    auto dummy = &node;
    auto cur = dummy;
    while (l1 || l2 || carry) {
      // l1 和 l2 还没有遍历结束,或者还有进位
      auto sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
      carry = sum / 10;
      cur->next = new ListNode(sum % 10);
      cur = cur->next;
      if (l1) l1 = l1->next;
      if (l2) l2 = l2->next;
    }
    return dummy->next;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
