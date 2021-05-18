#include <string>
#include <vector>
using std::string;

/// 此题采用滑动窗，非常典型
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int i = 0, j = 0;  // [i...j]
    std::vector<int> mapping(128, 0);
    int res = 0;
    for (j = 0; j < s.size(); ++j) {
      // 更新 i
      i = std::max(i, mapping[s[j]]);
      // 更新 mapping
      mapping[s[j]] = j + 1;
      res = std::max(res, j - i + 1);
    }
    return res;
  }
};
