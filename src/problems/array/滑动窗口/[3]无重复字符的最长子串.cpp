//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
//
//
//
// 示例 1:
//
//
//输入: s = "abcabcbb"
//输出: 3
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
//
//
// 示例 2:
//
//
//输入: s = "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
//
//
// 示例 3:
//
//
//输入: s = "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
//
//
// 示例 4:
//
//
//输入: s = ""
//输出: 0
//
//
//
//
// 提示：
//
//
// 0 <= s.length <= 5 * 104
// s 由英文字母、数字、符号和空格组成
//
// Related Topics 哈希表 双指针 字符串 Sliding Window
// 👍 5462 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <string>
#include <vector>
using std::string;
/// 思路，使用滑动窗口
/// Time: O(n)
/// Space: O(1)，使用一个128维的 vector 记录某字符出现的位置
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int res = 0;
    int i = 0, j = 0;  // [i...j]表示滑动窗的 index 范围
    // 建立一个 vector，存储 字母 -> 最近一次出现的 index + 1
    std::vector<int> mapping(128, -1);
    for (j = 0; j < s.size(); ++j) {
      // 检查 滑动窗 左侧 i 是否需要更新
      // 1. mapping[s[j]] >= i，s[j] 在滑动窗[i, j]范围内已经出现过，i 更新到
      // mapping[s[j]]位置
      // 2. mapping[s[j]] < i，s[j] 出现过或者没有出现过，但都不在滑动窗内，i
      // 保持原位置即可
      // 综上，i 取 max 即可
      i = std::max(i, mapping[s[j]]);
      mapping[s[j]] = j + 1;  // s[j] -> 最近一次出现的 index + 1
      res = std::max(res, j - i + 1);
    }
    // 当 s 为空，不会进入上面的循环，直接返回 0
    return res;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
