//二进制手表顶部有 4 个 LED 代表 小时（0-11），底部的 6 个 LED 代表
//分钟（0-59）。每个 LED 代表一个 0 或 1，最低位在右侧。
//
//
//
// 例如，下面的二进制手表读取 "3:25" 。
//
//
//
//
// （图源：WikiMedia - Binary clock samui moon.jpg
// ，许可协议：Attribution-ShareAlike 3.0
// Unported (CC BY-SA 3.0) ）
//
// 给你一个整数 turnedOn ，表示当前亮着的 LED
// 的数量，返回二进制手表可以表示的所有可能时间。你可以 按任意顺序 返回答案。
//
// 小时不会以零开头：
//
//
// 例如，"01:00" 是无效的时间，正确的写法应该是 "1:00" 。
//
//
// 分钟必须由两位数组成，可能会以零开头：
//
//
// 例如，"10:2" 是无效的时间，正确的写法应该是 "10:02" 。
//
//
//
//
// 示例 1：
//
//
//输入：turnedOn = 1
//输出：["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]
//
//
// 示例 2：
//
//
//输入：turnedOn = 9
//输出：[]
//
//
//
//
// 提示：
//
//
// 0 <= turnedOn <= 10
//
// Related Topics 位运算 回溯
// 👍 314 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <string>
#include <vector>
using std::string;
using std::vector;
/// 遍历
// 0-11: 4
// 0-59: 6
// 0111:011111 -> 7:31
class Solution {
 public:
  vector<string> readBinaryWatch(int turnedOn) {
    vector<string> ans;
    for (int h = 0; h < 12; ++h) {
      for (int m = 0; m < 60; ++m) {
        if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
          ans.push_back(std::to_string(h) + ":" + (m < 10 ? "0" : "") +
                        std::to_string(m));
        }
      }
    }
    return ans;
  }

 private:
  //计算二进制中1的个数
  int count1(int n) {
    int res = 0;
    while (n != 0) {
      n = n & (n - 1);
      res++;
    }
    return res;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
