// 输入：s = "We are happy."
// 输出："We%20are%20happy."
#include <string>
using std::string;
/// 这个题从 C 的角度讲，应该从后往前 copy
class Solution {
 public:
  string replaceSpace(string s) {
    auto num = find_char(s, ' ');
    auto s_size = s.size();
    s.resize(s_size + 2 * num);
    int j = s.size() - 1;
    for (int i = s_size - 1; i >= 0; --i) {
      if (s[i] == ' ') {
        s[j--] = '0';
        s[j--] = '2';
        s[j--] = '%';
      } else {
        s[j--] = s[i];
      }
    }
    return s;
  }

 private:
  int find_char(const string& s, char ch) {
    int num = 0;
    int pos = 0;
    while (true) {
      pos = s.find(ch, pos);
      if (pos == std::string::npos) {
        break;
      }
      ++pos;
      ++num;
    }
    return num;
  }
};
