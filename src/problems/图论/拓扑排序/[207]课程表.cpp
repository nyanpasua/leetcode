//你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
//
// 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中
// prerequisites[i] = [ai, bi] ，表
//示如果要学习课程 ai 则 必须 先学习课程 bi 。
//
//
// 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
//
//
// 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
//
//
//
// 示例 1：
//
//
//输入：numCourses = 2, prerequisites = [[1,0]]
//输出：true
//解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
//
// 示例 2：
//
//
//输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
//输出：false
//解释：总共有 2 门课程。学习课程 1
//之前，你需要先完成​课程 0 ；并且学习课程 0
//之前，你还应先完成课程
// 1 。这是不可能的。
//
//
//
// 提示：
//
//
// 1 <= numCourses <= 105
// 0 <= prerequisites.length <= 5000
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// prerequisites[i] 中的所有课程对 互不相同
//
// Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序
// 👍 850 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
using std::vector;

/// 图算法 + 深度优先遍历
// 拓扑排序，给定一个包含 n 个节点的有向图
// G，我们给出它的节点编号的一种排列，如果满足 对于图 G 中的任意一条有向边
// (u,v)，u 在排列中都出现在 v 的前面； 那么 该排序就是 图 G 的一个拓扑排序。
// 如果 图 G 有环，那么图 G 不存在拓扑排序
// 如果 图 G 无环，那么图 G 的拓扑排序可能不止一种.
// 问题就转换为判断 prerequisites 是不是 图 G 的一种拓扑排序
// Time: O(n+m)
// Space: O(n+m)
class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    edges_.resize(numCourses);
    visited_.resize(numCourses, 0);
    for (const auto& two : prerequisites) {
      // edges_ 的索引对应 顶点，[[1],[2,4],[3]]
      // edges_[0] 表示 顶点 0 -> 顶点 1
      // edges_[1] 表示 顶点 1 -> 顶点 2 和 4
      edges_[two[1]].push_back(two[0]);
    }
    // 遍历每一个顶点
    for (int i = 0; i < numCourses && valid_; ++i) {
      if (!visited_[i]) {
        // 如果未访问，则 开始 dfs
        dfs(i);
      }
    }
    return valid_;
  }

 private:
  void dfs(int u) {
    visited_[u] = 1;  // 开始搜索
    for (int v : edges_[u]) {
      // 对 顶点 u 的所有 相邻顶点进行遍历
      if (visited_[v] == 1) {
        // 如果 v 也在搜索中，那么就发现环
        valid_ = false;
        return;
      } else if (visited_[v] == 0) {
        // 深度递归遍历
        dfs(v);
      }
    }
    if (!valid_) return;
    // 所有相邻节点都已经深度遍历结束
    visited_[u] = 2;
  }
  // 存放每一条边
  vector<vector<int>> edges_;
  // 存放某一个顶点的状态，0 表示未访问，1 表示正在搜索，2 表示已完成搜索
  vector<int> visited_;
  // 是否可以达成 拓扑结构
  bool valid_ = true;
};
// leetcode submit region end(Prohibit modification and deletion)
