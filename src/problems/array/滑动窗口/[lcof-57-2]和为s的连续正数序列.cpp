// 输入：target = 15
// 输出：[[1,2,3,4,5],[4,5,6],[7,8]]

#include <vector>
using std::vector;

/// 从 1 开始依次滑动窗遍历
/// 关键在于如何压缩左侧 l 的推进
/// 思考可以从找到一组解 [l...r] 后，由于下一次推进一定包含
/// j + 1，因此 i 应推进到 [l...(l' - 1)] 之和大于等于 r + 1
/// 的 i' 位置
class Solution2 {
 public:
  vector<vector<int>> findContinuousSequence(int target) {
    int l = 1, r = 1;
    std::vector<vector<int>> res{};
    while (l <= (target + 1) / 2) {
      // 从 l 开始找窗口满足条件，如果找到，更新 res 和 r
      auto is_found = find_res(l, target, &res, &r);
      // 如果找到，更新 l，否则 ++l
      if (is_found) {
        update(&l, r + 1);
      } else {
        ++l;
        r = l;
      }
    }
    return res;
  }

 private:
  bool find_res(int l, int target, vector<vector<int>> *res, int *r) {
    int sum = 0;
    auto temp = l;
    while (sum < target) {
      sum += l++;
      if (sum == target) {
        std::vector<int> one_res(l - temp, 0);
        for (int i = temp; i < l; ++i) {
          one_res[i - temp] = i;
        }
        res->emplace_back(one_res);
        *r = l - 1;
        return true;
      }
    }
    return false;
  }
  void update(int *l, int post_r) {
    auto new_l = *l;
    int sum = new_l;
    while (sum < post_r) {
      sum += ++new_l;
    }
    *l = new_l + 1;
  }
};

/// 采用滑动窗 [l...r]
/// if sum > target, l++
/// if sum < target, r++
/// if sum == target, r++, l -> l'
class Solution {
 public:
  vector<vector<int>> findContinuousSequence(int target) {
    if (target == 0) {
      return {};
    }
    std::vector<std::vector<int>> res{};
    int l = 1, r = 1;
    while (r <= (target + 1) / 2) {
      auto temp_sum = sum(l, r);
      if (temp_sum < target) {
        ++r;
      } else if (temp_sum > target) {
        ++l;
      } else {
        // 找到目标
        add_res(&res, l, r);
        update(&l, ++r);
      }
    }
    return res;
  }

 private:
  int sum(int l, int r) {
   /* int sum = 0;
    for (int i = l; i <= r; ++i) {
      sum += i;
    }
    return sum;
   */
    return (l + r) * (r - l + 1) / 2;
  }
  void update(int *l, int post_r) {
    auto new_l = *l;
    int sum = new_l;
    while (sum < post_r) {
      sum += ++new_l;
    }
    *l = new_l + 1;
  }
  void add_res(vector<vector<int>> *res, int l, int r) {
    std::vector<int> one_res(r - l + 1, 0);
    for (int i = l; i <= r; ++i) {
      one_res[i - l] = i;
    }
    res->emplace_back(one_res);
  }
};
