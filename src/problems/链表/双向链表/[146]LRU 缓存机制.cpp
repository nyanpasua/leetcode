//运用你所掌握的数据结构，设计和实现一个 LRU (最近最少使用) 缓存机制 。
//
//
//
// 实现 LRUCache 类：
//
//
// LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1
// 。 void put(int key, int value)
// 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上
//限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
//
//
//
//
//
//
// 进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？
//
//
//
// 示例：
//
//
//输入
//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//输出
//[null, null, null, 1, null, -1, null, -1, 3, 4]
//
//解释
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // 缓存是 {1=1}
// lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
// lRUCache.get(1);    // 返回 1
// lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
// lRUCache.get(2);    // 返回 -1 (未找到)
// lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
// lRUCache.get(1);    // 返回 -1 (未找到)
// lRUCache.get(3);    // 返回 3
// lRUCache.get(4);    // 返回 4
//
//
//
//
// 提示：
//
//
// 1 <= capacity <= 3000
// 0 <= key <= 3000
// 0 <= value <= 104
// 最多调用 3 * 104 次 get 和 put
//
// Related Topics 设计
// 👍 1436 👎 0

// leetcode submit region begin(Prohibit modification and deletion)

#include <unordered_map>
using std::unordered_map;

struct DLinkedNode {
  int key{0};
  int value{0};
  DLinkedNode *prev{nullptr};
  DLinkedNode *next{nullptr};
  DLinkedNode() = default;
  DLinkedNode(int key, int value) : key{key}, value(value) {}
};
class LRUCache {
 private:
  unordered_map<int, DLinkedNode *> cache_;
  DLinkedNode *head_{nullptr};
  DLinkedNode *tail_{nullptr};
  int size_{0};
  int capacity_{0};

 public:
  LRUCache(int capacity) : capacity_{capacity} {
    // 虚拟头部和尾部
    head_ = new DLinkedNode();
    tail_ = new DLinkedNode();
    head_->next = tail_;
    tail_->prev = head_;
  }

  int get(int key) {
    // 没有该 key 的 node
    if (cache_.count(key) == 0) return -1;
    // 使用哈希定位到 key 的 node,然后移动到头部
    auto node = cache_[key];
    move_front(node);
    return node->value;
  }

  void put(int key, int value) {
    // put 分为两种情况
    // 1. 没有该节点,需要添加到头部,并有可能需要删除尾部节点
    // 2. 有该节点,修改值,并移动到头部

    if (cache_.count(key) == 0) {
      // 创建新节点
      DLinkedNode *node = new DLinkedNode(key, value);
      cache_[key] = node;
      add_front(node);
      ++size_;
      if (size_ > capacity_) {
        auto removed = erase_back();
        cache_.erase(removed->key);
        delete removed;
        --size_;
      }
    } else {
      // key 存在,更新 value
      auto node = cache_[key];
      node->value = value;
      move_front(node);
    }
  }

 private:
  void add_front(DLinkedNode *node) {
    node->prev = head_;
    node->next = head_->next;
    head_->next->prev = node;
    head_->next = node;
  }
  void move_front(DLinkedNode *node) {
    erase(node);
    add_front(node);
  }
  void erase(DLinkedNode *node) {
    // 无需释放，因为不会直接调用 erase，而是会配合 erase + add_front
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }
  DLinkedNode *erase_back() {
    // 外部释放
    DLinkedNode *node = tail_->prev;
    erase(node);
    return node;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// leetcode submit region end(Prohibit modification and deletion)
