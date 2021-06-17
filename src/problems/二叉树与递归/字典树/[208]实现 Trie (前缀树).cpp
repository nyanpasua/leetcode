/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// Trie（发音类似 "try"）或者说 前缀树
// 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼
//写检查。
//
//  请你实现 Trie 类：
//
//
//  Trie() 初始化前缀树对象。
//  void insert(String word) 向前缀树中插入字符串 word 。
//  boolean search(String word) 如果字符串 word 在前缀树中，返回
//  true（即，在检索之前已经插入）；否则，返回 false 。 boolean
//  startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix
//  ，返回 true ；否
//则，返回 false 。
//
//
//
//
//  示例：
//
//
//输入
//["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
//[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
//输出
//[null, null, true, false, true, null, true]
//
//解释
// Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // 返回 True
// trie.search("app");     // 返回 False
// trie.startsWith("app"); // 返回 True
// trie.insert("app");
// trie.search("app");     // 返回 True
//
//
//
//
//  提示：
//
//
//  1 <= word.length, prefix.length <= 2000
//  word 和 prefix 仅由小写英文字母组成
//  insert、search 和 startsWith 调用次数 总计 不超过 3 * 104 次
//
//  Related Topics 设计 字典树
//  👍 793 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <string>
#include <vector>
using std::string;
using std::vector;

class Trie {
 public:
  /** Initialize your data structure here. */
  Trie() {
    // do nothing
  }

  /** Inserts a word into the trie. */
  void insert(const string &word) {
    auto node = this;
    for (const auto &ch : word) {
      if (node->next_[ch - 'a'] == nullptr) {
        // ch 不存在
        node->next_[ch - 'a'] = new Trie();
      }
      node = node->next_[ch - 'a'];
    }
    // 此时 node 为最后一个 Trie
    node->is_end_ = true;
  }

  /** Returns if the word is in the trie. */
  bool search(const string &word) {
    auto node = this;
    for (const auto &ch : word) {
      if (node->next_[ch - 'a'] == nullptr) {
        return false;
      }
      node = node->next_[ch - 'a'];
    }
    return node->is_end_;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(const string &prefix) {
    auto node = this;
    for (const auto &ch : prefix) {
      if (node->next_[ch - 'a'] == nullptr) {
        return false;
      }
      node = node->next_[ch - 'a'];
    }
    return true;
  }

 private:
  bool is_end_ = false;
  // 用于记录 该节点 的下一个节点，26 个字母的索引表，如果不是
  // nullptr，说明有这个字母存表 next_[ch - 'a'] != nullptr
  // 访问，因此遍历的时间复杂度为 O(26) -> O(1) 直接访问为 O(1)
  vector<Trie *> next_{vector<Trie *>(26, nullptr)};
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// leetcode submit region end(Prohibit modification and deletion)
