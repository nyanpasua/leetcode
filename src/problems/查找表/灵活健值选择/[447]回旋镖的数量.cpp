/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 */

//给定平面上 n 对 互不相同 的点 points ，其中 points[i] = [xi, yi] 。回旋镖
//是由点 (i, j, k) 表示的元组 ，其中
// i 和 j 之间的距离和 i 和 k 之间的距离相等（需要考虑元组的顺序）。
//
// 返回平面上所有回旋镖的数量。
//
//
// 示例 1：
//
//
//输入：points = [[0,0],[1,0],[2,0]]
//输出：2
//解释：两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]
//
//
// 示例 2：
//
//
//输入：points = [[1,1],[2,2],[3,3]]
//输出：2
//
//
// 示例 3：
//
//
//输入：points = [[1,1]]
//输出：0
//
//
//
//
// 提示：
//
//
// n == points.length
// 1 <= n <= 500
// points[i].length == 2
// -104 <= xi, yi <= 104
// 所有点都 互不相同
//
// Related Topics 数组 哈希表 数学
// 👍 137 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <unordered_map>
/// hash表
// 用哈希表记录每个点到其他点的距离，每个距离相同的点个数为val
//外层的for循环遍历所有点，作为回旋镖的第一个点，内层循环遍历所有点，
// 计算回旋镖的第一个点和其他点的距离，并记录到哈希表中
//遍历哈希表，从val个距离相同的点中选2个点，作为回旋镖的后两个点，
// 共有val* (val - 1)种情况
//
class Solution {
 public:
  int numberOfBoomerangs(vector<vector<int>>& points) {
    int res = 0;
    for (int i = 0; i < points.size(); i++) {
      std::unordered_map<int, int> hashmap;
      for (int j = 0; j < points.size(); j++) {
        int dx = points[i][0] - points[j][0];
        int dy = points[i][1] - points[j][1];
        int dis = dx * dx + dy * dy;
        hashmap[dis]++;
      }
      for (auto& val_pair : hashmap) {
        auto val = val_pair.second;
        res += val * (val - 1);
      }
    }
    return res;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
