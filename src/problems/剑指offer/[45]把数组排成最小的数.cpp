// 输入: [3,30,34,5,9]
// 输出: "3033459"
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
using std::string;
using std::vector;
// cpp 仿函数理念
// string: x + y < y + x, 则 x < y
class Solution {
 public:
  string minNumber(vector<int>& nums) {
    std::vector<string> strs;
    for (const auto& num : nums) {
      strs.emplace_back(std::to_string(num));
    }
    std::sort(strs.begin(), strs.end(),
              [](const string& x, const string& y) { return x + y < y + x; });
    return std::accumulate(strs.begin(), strs.end(), string(""));
  }
};
