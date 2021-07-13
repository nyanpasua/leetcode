//累加数是一个字符串，组成它的数字可以形成累加序列。
//
// 一个有效的累加序列必须至少包含 3
// 个数。除了最开始的两个数以外，字符串中的其他数都等于它之前两个数相加的和。
//
// 给定一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是累加数。
//
// 说明: 累加序列里的数不会以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3
// 的情况。
//
// 示例 1:
//
// 输入: "112358"
//输出: true
//解释: 累加序列为: 1, 1, 2, 3, 5, 8 。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 =
//8
//
//
// 示例 2:
//
// 输入: "199100199"
//输出: true
//解释: 累加序列为: 1, 99, 100, 199。1 + 99 = 100, 99 + 100 = 199
//
// 进阶:
//你如何处理一个溢出的过大的整数输入?
// Related Topics 字符串 回溯
// 👍 168 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  void reverse(string& s) {
    int len = s.size();
    int i = 0, j = len - 1;
    while (i < j) {
      char ch = s[i];
      s[i] = s[j];
      s[j] = ch;
      ++i;
      --j;
    }
  }
  string addstr(string a, string b) {
    //将两个字符串所表示的数字内容相加，并将相加结果以字符串形式返回
    int len1 = a.size();
    int len2 = b.size();
    reverse(a);
    reverse(b);
    int ex = 0;
    string res = "";
    int i = 0, j = 0;
    for (; i < len1 || j < len2; ++i, ++j) {
      int x = i < len1 ? (a[i] - '0') : 0;
      int y = j < len2 ? (b[j] - '0') : 0;
      int sum = x + y + ex;
      ex = sum / 10;
      sum %= 10;
      res += (sum + '0');
    }
    if (ex > 0) res += ex + '0';
    reverse(res);
    return res;
  }
  bool judge(string num, int index, string pre, string target) {
    // cout<<"index:"<<index<<",pre:"<<pre<<",target:"<<target<<endl;
    if (index == num.size()) return true;
    int len = target.size();
    //！！累加序列不会以0开头，所以对这部分内容进行注释
    // int id=0;
    // while(id<lent && target[id]=='0')
    //     ++id; //去掉该数字的前置0
    // if(id==lent)
    //     --id;
    // int len=lent-id;
    // target=target.substr(id,len);

    // while(index<num.size() && num[index]=='0')
    //     ++index; //去掉前置0
    // if(index==num.size())
    //     --index;

    if (index + len > num.size()) return false;
    string t = num.substr(index, len);
    if (target != t) {
      return false;
    }
    if (judge(num, index + len, t, addstr(t, pre))) return true;
    return false;
  }
  bool isAdditiveNumber(string num) {
    int len = num.size();
    for (int i = 1; i <= len; ++i) {       //第一个数的长度
      for (int j = 1; i + j < len; ++j) {  //第二个数的长度
        string x = num.substr(0, i);
        string y = num.substr(i, j);
        if (x.size() > 1 && x[0] == '0' || y.size() > 1 && y[0] == '0')
          continue;
        string res = addstr(x, y);  //期待的第三个数
        // cout<<"x:"<<x<<",y:"<<y<<",res:"<<res<<endl;
        if (judge(num, i + j, y, res)) return true;
      }
    }
    return false;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
