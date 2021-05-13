//
// Created by liyingmin on 2020/1/12.
//
/*!
 * @brief https://leetcode-cn.com/problems/group-anagrams
 * Time: O(nmlogm), n = strs.size(), m = sum(strs[i].size())/n
 * Space: O(n*m)+
 */
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

vector<vector<string>> groupAnagrams(vector<string> &strs) {
  std::unordered_map<std::string, std::vector<int>> counter;
  auto copy_strs = strs;
  for (size_t i = 0; i < copy_strs.size(); ++i) {
    std::sort(copy_strs[i].begin(), copy_strs[i].end());
    counter[copy_strs[i]].push_back(i);
  }
  std::vector<std::vector<std::string>> ret;
  for (auto &str_counter : counter) {
    std::vector<std::string> anagrams;
    for (auto &ele : str_counter.second) {
      anagrams.push_back(strs[ele]);
    }
    ret.push_back(anagrams);
  }
  return ret;
}
