// 输入：
//["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
//[[],[1],[2],[],[3],[]]
//输出：[null,null,null,1.50000,null,2.00000]
// 如何得到一个数据流中的中位数？
// 如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
// 如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
//
// 建立一个 小顶堆 A 和 大顶堆 B ，各保存列表的一半元素
// A 中保存较大的一半元素, B 中保存较小的一半元素
#include <functional>
#include <queue>
#include <vector>
using std::vector;
class MedianFinder {
 public:
  /** initialize your data structure here. */
  MedianFinder() {}

  void addNum(int num) {
    if (min_heap_.size() == max_heap_.size()) {
      max_heap_.push(num);
      min_heap_.push(max_heap_.top());
      max_heap_.pop();
    } else {
      min_heap_.push(num);
      max_heap_.push(min_heap_.top());
      min_heap_.pop();
    }
  }

  double findMedian() {
    if (min_heap_.empty()) return -1;
    if (min_heap_.size() == max_heap_.size())
      return (min_heap_.top() + max_heap_.top()) / 2.0;
    else
      return min_heap_.top();
  }

 private:
  std::priority_queue<int, vector<int>> max_heap_;
  std::priority_queue<int, vector<int>, std::greater<int>> min_heap_;
};

// class MedianFinder {
//  public:
//   /** initialize your data structure here. */
//   MedianFinder() {}
//
//   void addNum(int num) {
//     // 需保证两边数量平衡,约定大根堆数量为 N/2,小根堆数量为 N/2 (+1)
//     if (min_heap_.empty()) {
//       min_heap_.push(num);
//       return;
//     }
//     if (max_heap_.empty()) {
//       if (num <= min_heap_.top()) {
//         max_heap_.push(num);
//       } else {
//         max_heap_.push(min_heap_.top());
//         min_heap_.pop();
//         min_heap_.push(num);
//       }
//       return;
//     }
//     if (max_heap_.size() == min_heap_.size()) {
//       // >= max_heap.top 都往 min_heap 送
//       if (num >= max_heap_.top())
//         min_heap_.push(num);
//       else {
//         min_heap_.push(max_heap_.top());
//         max_heap_.pop();
//         max_heap_.push(num);
//       }
//       return;
//     }
//
//     // min_heap 多一个
//     if (num <= min_heap_.top())
//       max_heap_.push(num);
//     else {
//       max_heap_.push(min_heap_.top());
//       min_heap_.pop();
//       min_heap_.push(num);
//     }
//   }
//
//   double findMedian() {
//     if (min_heap_.empty()) return -1;
//     if (min_heap_.size() == max_heap_.size())
//       return (min_heap_.top() + max_heap_.top()) / 2.0;
//     else
//       return min_heap_.top();
//   }
//
//  private:
//   std::priority_queue<int, vector<int>> max_heap_;
//   std::priority_queue<int, vector<int>, std::greater<int>> min_heap_;
// };

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
