//给定一组非负整数
// nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。
//
// 注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。
//
//
//
// 示例 1：
//
//
//输入：nums = [10,2]
//输出："210"
//
// 示例 2：
//
//
//输入：nums = [3,30,34,5,9]
//输出："9534330"
//
//
// 示例 3：
//
//
//输入：nums = [1]
//输出："1"
//
//
// 示例 4：
//
//
//输入：nums = [10]
//输出："10"
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 100
// 0 <= nums[i] <= 109
//
// Related Topics 贪心 字符串 排序
// 👍 735 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <algorithm>
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    std::sort(nums.begin(), nums.end(), [](const int x, const int y) {
      return std::to_string(x) + std::to_string(y) >
             std::to_string(y) + std::to_string(x);
    });
    if (nums[0] == 0) return "0";
    string res;
    for (const auto& num : nums) {
      res += std::to_string(num);
    }
    return res;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
