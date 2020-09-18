// https://leetcode.com/contest/weekly-contest-205/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
struct node {
  int parent;
  int rank;
};
class Solution {
 public:
  int findd(int v, vector<node>& ds) {
    if (ds[v].parent == -1) return v;
    return ds[v].parent = findd(ds[v].parent, ds);
  }
  int isConnected(int from, int to, vector<node>& ds) {
    return findd(from, ds) == findd(to, ds);
  }
  void unionn(int from, int to, vector<node>& ds) {
    int fromParent = findd(from, ds);
    int toParent = findd(to, ds);

    if (ds[fromParent].rank > ds[toParent].rank) {
      ds[toParent].parent = fromParent;
    } else if (ds[fromParent].rank < ds[toParent].rank) {
      ds[fromParent].parent = toParent;
    } else {
      ds[fromParent].parent = toParent;
      ds[toParent].rank++;
    }
  }
  int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    vector<node> dsuA(n, {-1, 0}), dsuB(n, {-1, 0});

    int len = edges.size();
    int ans = 0;
    for (int i = 0; i < len; i++) {
      if (edges[i][0] != 3) continue;
      int src = edges[i][1] - 1;
      int dst = edges[i][2] - 1;
      bool isAliceConnected = isConnected(src, dst, dsuA);
      ans += isAliceConnected;

      // if alice is connected so is bob, as distinct value are given for a type
      if (isAliceConnected) continue;

      unionn(src, dst, dsuA);
      unionn(src, dst, dsuB);
    }

    for (int i = 0; i < len; i++) {
      if (edges[i][0] == 3) continue;

      int src = edges[i][1] - 1;
      int dst = edges[i][2] - 1;

      if (edges[i][0] == 1) {
        bool isAliceConnected = isConnected(src, dst, dsuA);
        ans += isAliceConnected;
        if (isAliceConnected) continue;
        unionn(src, dst, dsuA);
      } else {
        bool isBobConnected = isConnected(src, dst, dsuB);
        ans += isBobConnected;
        if (isBobConnected) continue;
        unionn(src, dst, dsuB);
      }
    }

    int notConnected = 0;
    for (int i = 0; i < dsuB.size(); i++) {
      if (dsuA[i].parent == -1) notConnected++;
      if (dsuB[i].parent == -1) notConnected++;
      if (notConnected > 2) return -1;
    }

    return ans;
  }
};