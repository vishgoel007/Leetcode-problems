// https://leetcode.com/contest/weekly-contest-206/problems/min-cost-to-connect-all-points/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// minimal spanning tree
// prims algo TC O(V*V)
class Solution {
 public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int len = points.size();
    vector<bool> visited(len, 0);
    vector<int> dist(len, INT_MAX);
    int totalCost = 0;

    // assume current min pick element ( i.e source)
    int currMin = 0;

    // 0 t0 len-1, as |V| - 1 edges in MST
    for (int i = 0; i < len - 1; i++) {
      int x = points[currMin][0];
      int y = points[currMin][1];

      // set it visited, means it has been processed
      visited[currMin] = 1;
      for (int node = 0; node < len; node++) {
        // if a vertice has been visited/processed ignore.
        if (visited[node]) continue;

        // distance between all other nodes and currmin picked one
        int distance = abs(x - points[node][0]) + abs(y - points[node][1]);

        //  keep update the minimum distance to reach node
        dist[node] = min(dist[node], distance);
      }

      // get minimun distance among all distances and add it to ans
      /* can use priority queue for the same */
      currMin = min_element(dist.begin(), dist.end()) - dist.begin();
      totalCost += dist[currMin];

      // reset the min distance so that it won't pick again
      dist[currMin] = INT_MAX;
    }
    return totalCost;
  }
};

// using kruskal algo
// giving TLE as it is dense graph
// TIME COMPLEXITY: O(ElogE + ElogV)
// ElogE for sorting E edges in edge_list
// ElogV for applying FIND & UNION operations on E edges having V vertices
struct node {
  int parent;
  int rank;
};
class Solution {
 public:
  vector<node> djs;
  static bool compare(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
  }

  void unionn(int from, int to) {
    int fromParent = findd(from);
    int toParent = findd(to);

    // path by compression
    if (djs[fromParent].rank > djs[toParent].rank) {
      djs[toParent].parent = fromParent;
    } else if (djs[fromParent].rank < djs[toParent].rank) {
      djs[fromParent].parent = toParent;
    } else {    // both have same rank
      djs[fromParent].parent = toParent;
      djs[toParent].rank++;
    }
  }

  int findd(int v) {
    if (djs[v].parent == -1) return v;
    return djs[v].parent = findd(djs[v].parent);
  }

  int minCostConnectPoints(vector<vector<int>>& points) {
    int len = points.size();
    djs.resize(len, {-1, 0});
    vector<vector<int>> edges(len * (len - 1) / 2, vector<int>(3));

    int it = 0;
    for (int i = 0; i < len; i++) {
      int x = points[i][0];
      int y = points[i][1];
      for (int j = i + 1; j < len; j++) {
        int distance = abs(x - points[j][0]) + abs(y - points[j][1]);
        edges[it++] = {distance, i, j};
      }
    }
    sort(edges.begin(), edges.end(), compare);

    int connectedEdges = 0, index = -1, totalCost = 0;
    while (++index < edges.size() && connectedEdges < len) {
      int distance = edges[index][0];
      int from = edges[index][1];
      int to = edges[index][2];
      if (findd(from) == findd(to)) continue;
      unionn(from, to);
      totalCost += distance;
      connectedEdges++;
    }
    return totalCost;
  }
};

// using priority_queue still tle
struct node {
  int parent;
  int rank;
};
struct info {
  int src;
  int dst;
  int dist;
};
class Compare {
 public:
  bool operator()(info a, info b) {
    return a.dist > b.dist;
  }
};
class Solution {
 public:
  vector<node> djs;

  void unionn(int from, int to) {
    int fromParent = findd(from);
    int toParent = findd(to);

    // path by compression
    if (djs[fromParent].rank > djs[toParent].rank) {
      djs[toParent].parent = fromParent;
    } else if (djs[fromParent].rank < djs[toParent].rank) {
      djs[fromParent].parent = toParent;
    } else {    // both have same rank
      djs[fromParent].parent = toParent;
      djs[toParent].rank++;
    }
  }

  int findd(int v) {
    if (djs[v].parent == -1) return v;
    return djs[v].parent = findd(djs[v].parent);
  }

  int minCostConnectPoints(vector<vector<int>>& points) {
    int len = points.size();
    djs.resize(len, {-1, 0});
    priority_queue<info, vector<info>, Compare> pq;

    int it = 0;
    for (int i = 0; i < len; i++) {
      int x = points[i][0];
      int y = points[i][1];
      for (int j = i + 1; j < len; j++) {
        int distance = abs(x - points[j][0]) + abs(y - points[j][1]);
        pq.push({i, j, distance});
      }
    }
    int connectedEdges = 0, index = -1, totalCost = 0;
    while (!pq.empty() && connectedEdges < len) {
      info p = pq.top();
      pq.pop();

      if (findd(p.src) == findd(p.dst)) continue;
      unionn(p.src, p.dst);
      totalCost += p.dist;
      connectedEdges++;
    }
    return totalCost;
  }
};
