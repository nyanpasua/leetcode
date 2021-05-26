// 输入: "the sky is blue"
//输出: "blue is sky the"
//输入: " hello world! "
//输出:"world! hello"
//解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
//输入: "a good    example"
//输出:"example good a"
//解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
//

class Solution {
 public:
  string reverseWords(string s) {
    std::string res;
    res.reserve(s.size());
    int i = s.size() - 1, j = i;
    while (i >= 0 && s[i] == ' ') --i;  // i 指向第一个字符
    j = i;
    while (i >= 0) {
      while (i >= 0 && s[i] != ' ') --i;
      res.append(s, i + 1, j - i);
      res.append(" ");
      while (i >= 0 && s[i] == ' ') --i;  // 消除空格
      j = i;
    }
    res.pop_back();
    return res;
  }
};
