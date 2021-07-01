/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */

//给你一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y
//平面上的一个点。求最多有多少个点在同一条直线上。
//
//
//
// 示例 1：
//
//
//输入：points = [[1,1],[2,2],[3,3]]
//输出：3
//
//
// 示例 2：
//
//
//输入：points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
//输出：4
//
//
//
//
// 提示：
//
//
// 1 <= points.length <= 300
// points[i].length == 2
// -104 <= xi, yi <= 104
// points 中的所有点 互不相同
//
// Related Topics 几何 哈希表 数学
// 👍 332 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <string>
#include <unordered_map>
#include <vector>
using std::string;
using std::unordered_map;
using std::vector;
/// 枚举直线+哈希表统计
// Time: O(N^2*logm), m 为坐标值最大差
class Solution {
 public:
  int maxPoints(vector<vector<int>>& ps) {
    int n = ps.size();
    int ans = 1;
    for (int i = 0; i < n; i++) {
      std::unordered_map<string, int> map;
      // 由当前点 i 发出的直线所经过的最多点数量
      int max = 0;
      for (int j = i + 1; j < n; j++) {
        int x1 = ps[i][0], y1 = ps[i][1], x2 = ps[j][0], y2 = ps[j][1];
        int a = x1 - x2, b = y1 - y2;
        int k = gcd(a, b);
        // 为了避免精度问题，我们直接使用字符串进行保存，同时需要将 斜率 约干净
        string key = std::to_string(a / k) + "_" + std::to_string(b / k);
        map[key]++;
        max = std::max(max, map[key]);
      }
      ans = std::max(ans, max + 1);
    }
    return ans;
  }
  int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
};
// leetcode submit region end(Prohibit modification and deletion)
