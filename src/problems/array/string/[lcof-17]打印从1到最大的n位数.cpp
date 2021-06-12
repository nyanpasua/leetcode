// 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出
// 1、2、3 一直到最大的 3 位数 999。
// 输入: n = 1
// 输出: [1,2,3,4,5,6,7,8,9]

class Solution {
 public:
  vector<int> printNumbers(int n) {
    std::string max(n, '9');
    int max_int = std::stoi(max);
    std::vector<int> res(max_int, 0);
    for (int i = 0; i < max_int; ++i) {
      res[i] = i + 1;
    }
    return res;
  }
};
