/*!
 * @brief Given a string, find the length of the longest substring without
repeating characters.
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
 */
#include <map>
#include <string>

int lengthOfLongestSubstring(const std::string& s) {
  auto front = s.cbegin();
  auto back = s.cbegin();
  auto end = s.cend();
  int longest_str_chars = 0;
  std::map<char, int> char_counter = {};
  while ((back <= end) && (end - front >= longest_str_chars)) {
    if (back - front > longest_str_chars) {
      longest_str_chars = back - front;
    }
    if (++char_counter[*(back++)] > 1) {
      while (true) {
        char_counter[(*front)] = 0;
        if (*(front++) == *(back - 1)) {
          break;
        }
      }
      char_counter[*(back - 1)] = 1;
    }
  }
  return longest_str_chars;
}

