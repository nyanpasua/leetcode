// 给定一个由 0 和 1 构成的数组，返回一个最长连续子序列，满足子序列中 0 和 1
// 的数量相等

#include <algorithm>
#include <vector>
using std::vector;

/// 前缀和
// 将 0 改为 -1，问题可以转换为 sum[0...i] 和 sum[0...j] 相等，并且 |j - i| 最大
// 由于 N 个 1/-1，sum 最大为 N，最小为 -N，因此 [-N...0...N] 共 2N + 1 种可能
// 使用一个 2N+1 长度的数组表示和，模拟 hash 查表，遍历 sum
// 数组，每次发现前缀和相等， 更新最大索引 |j - i|
class Solution {
 public:
  int maxSeq(const vector<int>& arr) {
    int counts = arr.size();
    vector<int> sum;
    sum.reserve(counts + 1);
    sum.push_back(0);
    for (const auto& x : arr) {
      // sum[0] == 0, sum[1] == arr[0], sum[2] == arr[0] + arr[1]
      sum.push_back(sum.back() + x * 2 - 1);
    }
    vector<int> temp(counts * 2 + 1, -1);
    int maxlen = 0;
    int startindex = -1, endindex = -1;
    for (int i = 0; i < sum.size(); i++) {
      int index = sum[i] + counts;  // 偏移 N 个位置
      if (temp[index] == -1) {
        // 记录该前缀和 index 第一次出现的索引 i，从这里算起，arr 的 index 就是
        // 这个 i 的值，因为产生该 sum 本身的 arr[i - 1] 并不参与到最终的子序列
        // 而是从 arr[i] 算起
        // arr[] = [1, -1, -1, 1, 1, -1, -1, 1, 1, 1]
        // sum[] = [0,  1,  0,-1, 0,  1,  0,-1, 0, 1, 2]
        temp[index] = i;
      } else {
        // 发现一个前缀和相等的索引 i 和 temp[index]
        int curlen = i - temp[index];
        if (curlen > maxlen) {
          startindex = temp[index];
          endindex = i - 1;  // 这里的 i-1 好理解，sum[i] 实际对应 arr[i - 1]
          maxlen = curlen;
        }
      }
    }
    return maxlen;
  }
};