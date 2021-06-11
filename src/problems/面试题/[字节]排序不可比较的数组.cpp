// 有两个数组, 数组的元素“大小”一一对应
// T1间元素不可比较, T2间元素可比较
// 但 T2 数组元素不可移动
// 设计一个排序函数,能排序 T1 数组
#include <algorithm>
#include <utility>
#include <vector>
using std::pair;
using std::vector;
class Solution {
  template <class T1, class T2>
  void sort(vector<T1>& a, const vector<T2>& b) {
    // 重建 pair
    vector<pair<int, T1>> a_wrapper(a.size());
    for (int i = 0; i < a.size(); ++i) {
      a_wrapper[i] = std::make_pair<int, T1>(i, a[i]);
    }
    // 定义比较器
    auto less = [&b](const pair<int, T1>& x, const pair<int, T1>& y) {
      return b[x.first] < b[y.first];
    };
    std::sort(a_wrapper.begin(), a_wrapper.end(), less);
    for (int i = 0; i < a.size(); ++i) {
      a[i] = a_wrapper[i].second;
    }
  }
};
