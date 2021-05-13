#ifndef TEST_UTIL_GTEST_HELPER_H_
#define TEST_UTIL_GTEST_HELPER_H_

#include <string>
#include <unordered_map>

namespace horizon {
namespace leetcode {

extern std::unordered_map<std::string, std::string> MYTESTPARAM;
std::unordered_map<std::string, std::string> FilterOwnTestParam(int argc,
                                                                char **argv);

}  // namespace leetcode
}  // namespace horizon

#endif  // TEST_UTIL_GTEST_HELPER_H_
