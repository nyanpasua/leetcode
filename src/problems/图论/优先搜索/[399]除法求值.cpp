//给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，其中
// equations[i] = [Ai, Bi] 和 values [i] 共同表示等式 Ai / Bi = values[i] 。每个
// Ai 或 Bi 是一个表示单个变量的字符串。
//
// 另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j
// 个问题，请你根据已知条件找出 Cj / Dj = ? 的结果作为答案。
//
// 返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0
// 替代这个答案。如果问题中出现了给定的已知条件中没有出现的字符串，也需要用 -1.0
// 替
//代这个答案。
//
// 注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0
// 的情况，且不存在任何矛盾的结果。
//
//
//
// 示例 1：
//
//
//输入：equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries =
//[["a","c"]
//,["b","a"],["a","e"],["a","a"],["x","x"]]
//输出：[6.00000,0.50000,-1.00000,1.00000,-1.00000]
//解释：
//条件：a / b = 2.0, b / c = 3.0
//问题：a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
//结果：[6.0, 0.5, -1.0, 1.0, -1.0 ]
//
//
// 示例 2：
//
//
//输入：equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0],
// quer ies = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
//输出：[3.75000,0.40000,5.00000,0.20000]
//
//
// 示例 3：
//
//
//输入：equations = [["a","b"]], values = [0.5], queries =
//[["a","b"],["b","a"],["a
//","c"],["x","y"]]
//输出：[0.50000,2.00000,-1.00000,-1.00000]
//
//
//
//
// 提示：
//
//
// 1 <= equations.length <= 20
// equations[i].length == 2
// 1 <= Ai.length, Bi.length <= 5
// values.length == equations.length
// 0.0 < values[i] <= 20.0
// 1 <= queries.length <= 20
// queries[i].length == 2
// 1 <= Cj.length, Dj.length <= 5
// Ai, Bi, Cj, Dj 由小写英文字母与数字组成
//
// Related Topics 深度优先搜索 广度优先搜索 并查集 图 数组 最短路
// 👍 551 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
/// 并查集
class Solution {
 public:
  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& queries) {
    int nvars = 0;
    unordered_map<string, int> variables;

    int n = equations.size();
    for (int i = 0; i < n; i++) {
      if (variables.find(equations[i][0]) == variables.end()) {
        variables[equations[i][0]] = nvars++;
      }
      if (variables.find(equations[i][1]) == variables.end()) {
        variables[equations[i][1]] = nvars++;
      }
    }
    vector<int> f(nvars);
    vector<double> w(nvars, 1.0);
    for (int i = 0; i < nvars; i++) {
      f[i] = i;
    }

    for (int i = 0; i < n; i++) {
      int va = variables[equations[i][0]], vb = variables[equations[i][1]];
      merge(f, w, va, vb, values[i]);
    }
    vector<double> ret;
    for (const auto& q : queries) {
      double result = -1.0;
      if (variables.find(q[0]) != variables.end() &&
          variables.find(q[1]) != variables.end()) {
        int ia = variables[q[0]], ib = variables[q[1]];
        int fa = findf(f, w, ia), fb = findf(f, w, ib);
        if (fa == fb) {
          result = w[ia] / w[ib];
        }
      }
      ret.push_back(result);
    }
    return ret;
  }
  int findf(vector<int>& f, vector<double>& w, int x) {
    if (f[x] != x) {
      int father = findf(f, w, f[x]);
      w[x] = w[x] * w[f[x]];
      f[x] = father;
    }
    return f[x];
  }

  void merge(vector<int>& f, vector<double>& w, int x, int y, double val) {
    int fx = findf(f, w, x);
    int fy = findf(f, w, y);
    f[fx] = fy;
    w[fx] = val * w[y] / w[x];
  }
};

/// BFS+Floyd
// 我们可以将整个问题建模成一张图：给定图中的一些点（变量），
// 以及某些边的权值（两个变量的比值），试对任意两点（两个变量）求出其路径长（两个变量的比值）。
// 可以使用 Floyd 算法，预先计算出任意两点之间的距离。
class Solution1 {
 public:
  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& queries) {
    vector<vector<double>> g(N, vector<double>(N, -1));
    // 建图
    for (int i = 0; i < equations.size(); i++) {
      string a = equations[i][0];
      string b = equations[i][1];
      if (map.find(a) == map.end()) map[a] = map.size();
      if (map.find(b) == map.end()) map[b] = map.size();
      g[map[a]][map[b]] = values[i];
      g[map[b]][map[a]] = 1 / values[i];
    }

    // Floyd
    for (int k = 0; k < N; k++)
      for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
          if (g[i][k] != -1 && g[k][j] != -1) g[i][j] = g[i][k] * g[k][j];

    vector<double> ans;
    for (auto& i : queries) {
      auto a = map.find(i[0]);
      auto b = map.find(i[1]);
      if (a == map.end() || b == map.end())
        ans.push_back(-1);
      else
        ans.push_back(g[a->second][b->second]);
    }
    return ans;
  }

 private:
  static const int N = 50;
  unordered_map<string, int> map;
};
// leetcode submit region end(Prohibit modification and deletion)
