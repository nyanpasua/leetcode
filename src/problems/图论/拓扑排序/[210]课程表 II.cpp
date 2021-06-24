//现在你总共有 n 门课需要选，记为 0 到 n-1。
//
// 在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程
// 1 ，我们用一个匹配来表示他们: [0,1]
//
// 给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。
//
// 可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。
//
// 示例 1:
//
// 输入: 2, [[1,0]]
//输出: [0,1]
//解释: 总共有 2 门课程。要学习课程 1，你需要先完成课程
// 0。因此，正确的课程顺序为 [0,1] 。
//
// 示例 2:
//
// 输入: 4, [[1,0],[2,0],[3,1],[3,2]]
//输出: [0,1,2,3] or [0,2,1,3]
//解释: 总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1
//和课程 2 都应该排在课程 0 之后。      因此，一个正确的课程顺序是 [0,1,2,3]
//。另一个正确的排序是 [0,2,1,3] 。
//
//
// 说明:
//
//
// 输入的先决条件是由边缘列表表示的图形，而不是邻接矩阵。详情请参见图的表示法。
// 你可以假定输入的先决条件中没有重复的边。
//
//
// 提示:
//
//
// 这个问题相当于查找一个循环是否存在于有向图中。如果存在循环，则不存在拓扑排序，因此不可能选取所有课程进行学习。
// 通过 DFS 进行拓扑排序 -
// 一个关于Coursera的精彩视频教程（21分钟），介绍拓扑排序的基本概念。
//
// 拓扑排序也可以通过 BFS 完成。
//
//
// Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序
// 👍 422 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
/// 图论 + 深度优先遍历
class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
    std::reverse(stk_.begin(), stk_.end());
    return stk_;
  }

 private:
  void dfs(int u) {
    visited_[u] = 1;  // 开始搜索
    for (int v : edges_[u]) {
      // 对 顶点 u 的所有 相邻顶点进行遍历
      if (visited_[v] == 1) {
        // 如果 v 也在搜索中，那么就发现环
        valid_ = false;
        vector<int> tmp;
        stk_.swap(tmp);
        return;
      } else if (visited_[v] == 0) {
        // 深度递归遍历
        dfs(v);
      }
    }
    if (!valid_) return;
    // 所有相邻节点都已经深度遍历结束
    visited_[u] = 2;
    stk_.push_back(u);
  }
  // 存放每一条边
  vector<vector<int>> edges_;
  // 存放某一个顶点的状态，0 表示未访问，1 表示正在搜索，2 表示已完成搜索
  vector<int> visited_;
  bool valid_ = true;
  vector<int> stk_;
};
// leetcode submit region end(Prohibit modification and deletion)
