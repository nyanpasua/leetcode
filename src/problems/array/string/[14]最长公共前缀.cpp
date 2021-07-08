//编写一个函数来查找字符串数组中的最长公共前缀。
//
// 如果不存在公共前缀，返回空字符串 ""。
//
//
//
// 示例 1：
//
//
//输入：strs = ["flower","flow","flight"]
//输出："fl"
//
//
// 示例 2：
//
//
//输入：strs = ["dog","racecar","car"]
//输出：""
//解释：输入不存在公共前缀。
//
//
//
// 提示：
//
//
// 0 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] 仅由小写英文字母组成
//
// Related Topics 字符串
// 👍 1675 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() < 1 || strs[0].empty()) return "";
    if (strs.size() == 1) return strs[0];
    string res;
    int i = 0;
    bool flag = true;
    while (flag) {
      char ch = strs[0][i];
      for (int j = 1; j < strs.size(); ++j) {
        if (strs[j].size() <= i || strs[j][i] != ch) {
          // 不满足 公共前缀
          flag = false;
          --i;
          break;
        }
      }
      ++i;
    }
    return strs[0].substr(0, i);
  }
};
// leetcode submit region end(Prohibit modification and deletion)
