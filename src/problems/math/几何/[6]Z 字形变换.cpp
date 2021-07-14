//将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z
//字形排列。
//
// 比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
//
//
// P   A   H   N
// A P L S I I G
// Y   I   R
//
// 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
//
// 请你实现这个将字符串进行指定行数变换的函数：
//
//
// string convert(string s, int numRows);
//
//
//
// 示例 1：
//
//
//输入：s = "PAYPALISHIRING", numRows = 3
//输出："PAHNAPLSIIGYIR"
//
//示例 2：
//
//
//输入：s = "PAYPALISHIRING", numRows = 4
//输出："PINALSIGYAHRPI"
//解释：
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
//
//
// 示例 3：
//
//
//输入：s = "A", numRows = 1
//输出："A"
//
//
//
//
// 提示：
//
//
// 1 <= s.length <= 1000
// s 由英文字母（小写和大写）、',' 和 '.' 组成
// 1 <= numRows <= 1000
//
// Related Topics 字符串
// 👍 1208 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
/// 几何
// 逐行添加
class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;

    string ret;
    int n = s.size();
    // 这里这个规律需要分析，对于每行，都会存在这个位置的字符添加
    int cycleLen = 2 * numRows - 2;

    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j + i < n; j += cycleLen) {
        ret += s[j + i];
        // 除了第一行和最后一行，存在 j + cycleLen - i 位置的添加可能
        // 举个例子，s = "PAYPALISHIRING", numRows = 4
        // 对于 第 2 行，i = 1，idx : 1:A, 0+6-1:L, 7:S...
        if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
          ret += s[j + cycleLen - i];
      }
    }
    return ret;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
