/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按
//任意顺序 返回。
//
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//
//
//
//
//
// 示例 1：
//
//
//输入：digits = "23"
//输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
//
//
// 示例 2：
//
//
//输入：digits = ""
//输出：[]
//
//
// 示例 3：
//
//
//输入：digits = "2"
//输出：["a","b","c"]
//
//
//
//
// 提示：
//
//
// 0 <= digits.length <= 4
// digits[i] 是范围 ['2', '9'] 的一个数字。
//
// Related Topics 深度优先搜索 递归 字符串 回溯算法
// 👍 1354 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <string>
#include <unordered_map>
#include <vector>
using std::string;
using std::unordered_map;
using std::vector;
class Solution {
 private:
  vector<string> res_;
  unordered_map<char, string> digitmap_{
      {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
      {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
  // combination里保存了从digits[0, index-1]翻译得到的一个字母字符串
  // 寻找和digits[index]匹配的字母，获得digits[0, index]翻译得到的字母字符串
  // 注意有些什么参数：digits，用于递归的原始传入；index，用于记录遍历到第几层；
  // combination，用于记录树的上一层得到的字母字符串
  void FindOneCombination(const string& digits, int index,
                          const string& combination) {
    // 递归到底
    if (index == digits.size()) {
      // 找到一个组合
      res_.push_back(combination);
      return;
    }
    auto letters = digitmap_[digits[index]];
    for (const auto& letter : letters) {
      FindOneCombination(digits, index + 1, combination + letter);
    }
    return;  // 这一层的字母尝试完毕，返回上一层
  }

 public:
  vector<string> letterCombinations(string digits) {
    if (digits == "") {
      return vector<string>();
    }
    FindOneCombination(digits, 0, "");
    return res_;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
