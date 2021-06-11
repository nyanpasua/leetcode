//给你一个链表数组，每个链表都已经按升序排列。
//
// 请你将所有链表合并到一个升序链表中，返回合并后的链表。
//
//
//
// 示例 1：
//
// 输入：lists = [[1,4,5],[1,3,4],[2,6]]
//输出：[1,1,2,3,4,4,5,6]
//解释：链表数组如下：
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//将它们合并到一个有序链表中得到。
// 1->1->2->3->4->4->5->6
//
//
// 示例 2：
//
// 输入：lists = []
//输出：[]
//
//
// 示例 3：
//
// 输入：lists = [[]]
//输出：[]
//
//
//
//
// 提示：
//
//
// k == lists.length
// 0 <= k <= 10^4
// 0 <= lists[i].length <= 500
// -10^4 <= lists[i][j] <= 10^4
// lists[i] 按 升序 排列
// lists[i].length 的总和不超过 10^4
//
// Related Topics 堆 链表 分治算法
// 👍 1341 👎 0

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
#include <vector>
using std::vector;
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    return recursion(lists, 0, lists.size() - 1);
  }

 private:
  // 递归 merge 从 [l...r] 的有序链表
  ListNode* recursion(vector<ListNode*>& lists, int l, int r) {
    if (l == r) return lists[l];
    if (l > r) return nullptr;
    int mid = l + (r - l) / 2;
    // 注意这里其实都是用返回值进行递归，而 lists 只在递归到底使用
    return merge(recursion(lists, l, mid), recursion(lists, mid + 1, r));
  }

  ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode node(0);
    auto dummy_ret = &node;
    auto head = dummy_ret;
    // 这里用 && 会让问题简单很多
    while (l1 && l2) {
      if (l1->val <= l2->val) {
        head->next = l1;
        l1 = l1->next;
      } else {
        head->next = l2;
        l2 = l2->next;
      }
      head = head->next;
    }
    if (l2) {
      head->next = l2;
    }
    if (l1) {
      head->next = l1;
    }
    l1 = nullptr, l2 = nullptr;
    auto ret = dummy_ret->next;
    return ret;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
