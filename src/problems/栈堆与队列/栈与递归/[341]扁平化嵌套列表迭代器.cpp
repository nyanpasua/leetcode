/*
 * @lc app=leetcode.cn id=341 lang=cpp
 *
 * [341] 扁平化嵌套列表迭代器
 */

//给你一个嵌套的整型列表。请你设计一个迭代器，使其能够遍历这个整型列表中的所有整数。
//
// 列表中的每一项或者为一个整数，或者是另一个列表。其中列表的元素也可能是整数或是其他列表。
//
//
//
// 示例 1:
//
// 输入: [[1,1],2,[1,1]]
//输出: [1,1,2,1,1]
//解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是:
//[1,1,2,1,1]。
//
// 示例 2:
//
// 输入: [1,[4,[6]]]
//输出: [1,4,6]
//解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是:
//[1,4,6]。
//
// Related Topics 栈 树 深度优先搜索 设计 队列 迭代器
// 👍 346 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
 public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    stk.emplace(nestedList.begin(), nestedList.end());
  }

  int next() {
    // 由于保证调用 next 之前会调用
    // hasNext，直接返回栈顶列表的当前元素，然后迭代器指向下一个元素
    return stk.top().first++->getInteger();
  }

  bool hasNext() {
    while (!stk.empty()) {
      auto &p = stk.top();
      if (p.first == p.second) {  // 遍历到当前列表末尾，出栈
        stk.pop();
        continue;
      }
      if (p.first->isInteger()) {
        return true;
      }
      // 若当前元素为列表，则将其入栈，且迭代器指向下一个元素
      auto &lst = p.first++->getList();
      stk.emplace(lst.begin(), lst.end());
    }
    return false;
  }

 private:
  // pair
  // 中存储的是列表的当前遍历位置，以及一个尾后迭代器用于判断是否遍历到了列表末尾
  stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>>
      stk;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// leetcode submit region end(Prohibit modification and deletion)
