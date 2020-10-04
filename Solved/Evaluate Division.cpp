// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/557/week-4-september-22nd-september-28th/3474/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Node {
  string dst;
  double wt;
};

/** 
 * Time Complexity - O(Q * (V + E)), where Q - Quereis, V - Number of Vertices, E - Number Edges (length of values).
 * Space Complexity - O(V + E)
*/
// using DFS
class Solution {
 public:
  unordered_map<string, vector<Node>> graph;
  double DFS(string src, string dst, unordered_set<string>& visited) {
    if (graph.find(src) == graph.end() || graph.find(dst) == graph.end()) return -1.0;

    if (src == dst) return 1.0;

    visited.insert(src);
    for (Node n : graph[src]) {
      if (!visited.count(n.dst)) {
        visited.insert(n.dst);
        double ans = DFS(n.dst, dst, visited);
        if (ans != -1.0)    // if found destination
          return ans * n.wt;
      }
    }
    return -1.0;
  }

  vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    int elen = equations.size(), qlen = queries.size();
    vector<double> res(qlen, -1);
    for (int i = 0; i < elen; i++) {
      graph[equations[i][0]].push_back({equations[i][1], values[i]});
      graph[equations[i][1]].push_back({equations[i][0], (double)1 / values[i]});
    }
    for (int i = 0; i < qlen; i++) {
      unordered_set<string> visited;
      res[i] = DFS(queries[i][0], queries[i][1], visited);
    }
    return res;
  }
};

// using BFS
class Solution {
 public:
  unordered_map<string, vector<Node>> graph;
  double BFS(string src, string dst, unordered_set<string> visited = {}) {
    if (graph.find(src) == graph.end() || graph.find(dst) == graph.end()) return -1.0;

    if (src == dst) return 1.0;

    queue<Node> q;
    q.push({src, 1.0});
    visited.insert(src);

    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        Node curr = q.front();
        q.pop();
        if (curr.dst == dst) return curr.wt;
        for (Node n : graph[curr.dst]) {
          if (!visited.count(n.dst)) {
            visited.insert(n.dst);
            q.push({n.dst, curr.wt * n.wt});
          }
        }
      }
    }
    return -1.0;
  }
  vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    int elen = equations.size(), qlen = queries.size();
    vector<double> res(qlen, -1);
    for (int i = 0; i < elen; i++) {
      graph[equations[i][0]].push_back({equations[i][1], values[i]});
      graph[equations[i][1]].push_back({equations[i][0], (double)1 / values[i]});
    }
    for (int i = 0; i < qlen; i++) {
      res[i] = BFS(queries[i][0], queries[i][1]);
    }
    return res;
  }
};

// using union and find
class UnionFind {
 public:
  unordered_map<string, string> parent;
  unordered_map<string, double> vals;

  void _initialise(string& s) {
    if (vals.count(s)) return;
    parent[s] = s;
    vals[s] = 1.0;
  }

  void _union(string& src, string& dest, double wt) {
    _initialise(src);
    _initialise(dest);
    string srcP = _find(src);
    string destP = _find(dest);
    if (srcP == destP) return;
    parent[srcP] = destP;
    vals[srcP] = vals[dest] * wt / vals[src];
  }

  string _find(string& s) {
    string p = parent[s];
    if (p == s) return p;
    string pp = _find(p);
    vals[s] = vals[s] * vals[p];
    return parent[s] = pp;
  }
};

class Solution {
 public:
  vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    int elen = equations.size();
    UnionFind uf;
    for (int i = 0; i < elen; i++) {
      uf._union(equations[i][0], equations[i][1], values[i]);
    }

    vector<double> res;
    for (auto q : queries) {
      if (!uf.vals.count(q[0]) || !uf.vals.count(q[1])) {
        res.push_back(-1);
        continue;
      }
      string s = uf._find(q[0]), d = uf._find(q[1]);
      if (s != d) {
        res.push_back(-1);
        continue;
      }
      res.push_back(uf.vals[q[0]] / uf.vals[q[1]]);
    }
    return res;
  }
};


// can be done using floyd warshall

// Note
/**
 * Follow up question,
 * What if one more equation is added, solve queries in O(1)
 * Can be done by considering some additional space 
 * and store each src->dst value in dfs e.g
 * store like that
 * a/b = 1
 * c/b = 2
 * a,a = 1
 * a,b = 1
 * a,c = 0.5
 * b,c = ...
 * reference -> https://leetcode.com/problems/evaluate-division/discuss/278276/Java-Union-Find-and-DFS-Query-O(1)
 * https://leetcode.com/problems/evaluate-division/discuss/867030/Python-dfs-O(V%2BE)-explained
 * 
 */