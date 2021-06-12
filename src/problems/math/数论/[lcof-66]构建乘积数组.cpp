// 给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，
// 其中B[i] 的值是数组 A 中除了下标 i 以外的元素的积,
// 即B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。
// 输入: [1,2,3,4,5]
// 输出: [120,60,40,30,24]
class Solution1 {
 public:
  vector<int> constructArr(vector<int>& a) {
    if (a.empty() || a.size() == 1) return a;
    vector<int> left(a.size(), 1);
    vector<int> right(a.size(), 1);
    left[1] = a.front();
    right[1] = a.back();
    for (int i = 2; i < a.size(); ++i) {
      left[i] = left[i - 1] * a[i - 1];
      right[i] = right[i - 1] * a[a.size() - i];
    }
    vector<int> ret(a.size(), 0);
    for (int i = 0; i < a.size(); ++i) {
      ret[i] = left[i] * right[a.size() - i - 1];
    }
    return ret;
  }
};

class Solution {
 public:
  vector<int> constructArr(vector<int>& a) {
    int len = a.size();
    vector<int> b(len, 1);
    if (len == 0) return b;
    int left = 1, right = 1;
    for (int i = 0; i < len; i++) {
      b[i] *= left;
      left *= a[i];  // 持有左边的所有数的乘积

      b[len - i - 1] *= right;
      right *= a[len - i - 1];  // 持有右边的所有数的乘积
    }
    return b;
  }
};
