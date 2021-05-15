// 输入: nums = [5,7,7,8,8,10], target = 8
// 输出: 2

#include <vector>
using std::vector;

/// 二分法
/// Time: O(logn)
/// Space: O(1)
class Solution1 {
 public:
  int search(vector<int>& nums, int target) {
    size_t l = 0;
    size_t r = nums.size();  // [i...j)
    while (l < r) {
      auto mid = l + (r - l) / 2;
      if (nums[mid] < target) {
        // 向右侧找
        l = mid + 1;
      } else if (nums[mid] > target) {
        // 向左侧找
        r = mid;
      } else {
        // 找到，向两边辐射
        int num = 0;
        // <= mid
        // NOTE(yingmin) here just use int type to avoid 0 - 1 = max_size_t
        for (int j = mid; j >= 0; j--) {
          if (nums[j] == target) {
            ++num;
          } else {
            break;
          }
        }
        // > mid
        for (size_t i = mid + 1; i < nums.size(); ++i) {
          if (nums[i] == target) {
            ++num;
          } else {
            break;
          }
        }
        return num;
      }
    }
    // 找不到
    return 0;
  }
};

/// 注意到，辐射这种做法还是太慢了，因为实际上，如果重复元素非常多，还需要继续遍历
/// 因此，可以进一步优化；考虑到，二分可以不断的进行下去，所以，当找到一个
/// target，使用 target + 1 作为左边界，继续进行二分，这样可以找到 target
/// 的右侧区间边界 posttail 使用 target 作为右后边界，继续进行二分，可以找到
/// target 的左侧区间边界，闭区间
/// Time: O(logn) Space: O(1)
class Solution2 {
 public:
  int search(vector<int>& nums, int target) {
    size_t l = 0;
    size_t r = nums.size();  // [i...j)
    // 找右侧边界，开区间
    while (l < r) {
      auto mid = l + (r - l) / 2;
      if (nums[mid] < target) {
        // 向右侧找
        l = mid + 1;
      } else if (nums[mid] > target) {
        // 向左侧找
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    auto right = r;
    l = 0;
    r = right;
    while (l < r) {
      auto mid = l + (r - l) / 2;
      if (nums[mid] < target) {
        // 向右侧找
        l = mid + 1;
      } else if (nums[mid] > target) {
        // 向左侧找
        r = mid;
      } else {
        r = mid;
      }
    }
    auto left = l;
    // 找不到
    return static_cast<int>(right - left);
  }
};

/// 觉得上面还是太啰嗦了，其实可以抽象一下，我需要找 target
/// 的左边界，实际上，就是找 target - 1 的右边界 posttail
/// Time: O(logn) Space: O(1)
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    auto right = SearchRight(nums, target, 0, nums.size());
    auto left = SearchRight(nums, target - 1, 0, right);
    return right - left;
  }

 private:
  int SearchRight(const vector<int>& nums, int target, size_t l, size_t r) {
    // 找右侧边界，开区间
    while (l < r) {
      auto mid = l + (r - l) / 2;
      if (nums[mid] < target) {
        // 向右侧找
        l = mid + 1;
      } else if (nums[mid] > target) {
        // 向左侧找
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return static_cast<int>(r);
  }
};