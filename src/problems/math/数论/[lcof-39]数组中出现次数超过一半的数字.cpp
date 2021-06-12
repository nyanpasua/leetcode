// 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
// 你可以假设数组是非空的，并且给定的数组总是存在多数元素。

class Solution1 {
 public:
  int majorityElement(vector<int>& nums) {
    // 摩尔投票
    int votes = 1, x = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (votes == 0) {
        x = nums[i];
        ++votes;
      } else if (nums[i] == x)
        ++votes;
      else
        --votes;
    }
    return x;
  }
};

/// 此思路没有三路快排序，因此在重复很多的时候会超时
class Solution2 {
 public:
  int majorityElement(vector<int>& nums) {
    // 由于排序后中点的值一定是返回值,因此可以考虑采用快速排序的思路
    quickSort(nums, 0, nums.size() - 1);
    return nums[nums.size() / 2];
  }

 private:
  size_t partition(vector<int>& nums, int l, int r) {
    int i = l + 1;
    int j = l;
    auto v = nums[l];
    // [l+1...j] < v; [j+1...i-1]>=v;
    while (i <= r) {
      if (nums[i] >= v) {
        ++i;
      } else {
        std::swap(nums[i++], nums[++j]);
      }
    }
    std::swap(nums[j], nums[l]);
    return j;
  }

  void quickSort(vector<int>& nums, int l, int r) {
    if (l >= r) {
      return;
    }
    auto p = partition(nums, l, r);
    if (p == nums.size() / 2) return;
    quickSort(nums, l, p - 1);
    quickSort(nums, p + 1, r);
  }
};

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    // 由于排序后中点的值一定是返回值,因此可以考虑采用快速排序的思路
    quickSort3Ways(nums, 0, nums.size() - 1);
    return nums[nums.size() / 2];
  }

 private:
  std::pair<size_t, size_t> partition3way(vector<int>& nums, int l, int r) {
    size_t lt = l;
    size_t gt = r + 1;
    size_t i = l + 1;
    auto v = nums[l];
    while (i < gt) {
      if (nums[i] == v) {
        ++i;
      } else if (nums[i] < v) {
        std::swap(nums[i++], nums[++lt]);
      } else {
        std::swap(nums[i], nums[--gt]);
      }
    }
    std::swap(nums[lt], nums[l]);
    return std::pair<size_t, size_t>{lt, gt};
  }

  void quickSort3Ways(vector<int>& nums, int l, int r) {
    if (l >= r) {
      return;
    }
    auto p = partition3way(nums, l, r);
    if (p.first <= nums.size() / 2 && p.second >= nums.size() / 2) return;
    quickSort3Ways(nums, l, p.first - 1);
    quickSort3Ways(nums, p.second, r);
  }
};
