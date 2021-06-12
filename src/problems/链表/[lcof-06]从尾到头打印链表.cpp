/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <vector>
using std::vector;
/// 思路很简单，从尾到头打印，意味着我需要
/// “到底返回”，因此其中一种思路就是采用递归

class Solution2 {
 public:
  vector<int> reversePrint(ListNode* head) {
    if (head == nullptr) return {};
    recursion(head);
    return res_;
  }

 private:
  void recursion(ListNode* head) {
    // 递归到底
    if (head->next == nullptr) {
      res_.emplace_back(head->val);
      return;
    }
    recursion(head->next);
    res_.emplace_back(head->val);
    return;
  }
  std::vector<int> res_{};
};

/// 第二种做法是，可以利用栈的特性，进行反弹
#include <stack>
class Solution {
 public:
  vector<int> reversePrint(ListNode* head) {
    std::stack<int> reverse;
    while (head != nullptr) {
      reverse.push(head->val);
      head = head->next;
    }
    std::vector<int> res(reverse.size(), 0);
    auto num = reverse.size();
    for (int i = 0; i < num; ++i) {
      res[i] = reverse.top();
      reverse.pop();
    }
    return res;
  }
};
