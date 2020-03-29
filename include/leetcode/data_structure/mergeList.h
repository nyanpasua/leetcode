//
// Created by liyingmin on 2020/3/26.
//

#ifndef LEETCODE_INCLUDE_LEETCODE_DATA_STRUCTURE_MERGELIST_H_
#define LEETCODE_INCLUDE_LEETCODE_DATA_STRUCTURE_MERGELIST_H_
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x = 0) : val(x), next(nullptr) {}
};
// 思路：使用自顶向下的归并排序的思路，但是不像数组需要额外内存，链表重连即可
// Time: O(nlogn)
// Space: O(1) + 堆栈内存（栈深度logn）
ListNode* sortList(ListNode* head) {

}


#endif  // LEETCODE_INCLUDE_LEETCODE_DATA_STRUCTURE_MERGELIST_H_
