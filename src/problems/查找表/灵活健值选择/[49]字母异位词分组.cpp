//给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
//
// 示例:
//
// 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
//输出:
//[
//  ["ate","eat","tea"],
//  ["nat","tan"],
//  ["bat"]
//]
//
// 说明：
//
//
// 所有输入均为小写字母。
// 不考虑答案输出的顺序。
//
// Related Topics 哈希表 字符串
// 👍 755 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <functional>
#include <vector>
using std::vector;
#include <array>
#include <numeric>
#include <string>
#include <unordered_map>
using std::array;
using std::string;
using std::unordered_map;

/// 使用 string 作为 hash
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> map;

    // 统计string的各字母频次,以频次为key直接加入队列
    for (const auto& s : strs) {
      string sts = string(26, '0');
      for (const auto c : s) ++sts[c - 'a'];
      map[sts].emplace_back(s);
    }
    for (const auto& e : map) res.emplace_back(e.second);

    return res;
  }
};

/// hash 定义
class Solution1 {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    // 自定义对 array<int, 26> 类型的哈希函数
    auto arrayHash =
        [fn = std::hash<int>{}](const array<int, 26>& arr) -> size_t {
      return std::accumulate(arr.begin(), arr.end(), 0u,
                             [&](size_t acc, int num) {
                               // 这里使用 (acc << 1) ^ fn(num) 返回每一个 num
                               // 之和的 hash code，最终获得一个hash code
                               // 如何保证 hash 的唯一性？
                               return (acc << 1) ^ fn(num);
                             });
    };

    unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(
        0, arrayHash);
    for (string& str : strs) {
      array<int, 26> counts{};
      int length = str.length();
      for (int i = 0; i < length; ++i) {
        counts[str[i] - 'a']++;
      }
      mp[counts].emplace_back(str);
    }
    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
      ans.emplace_back(it->second);
    }
    return ans;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
