// https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/564/week-1-november-1st-november-7th/3519/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

    if (n == 1) return {0};

    vector<unordered_set<int>> adj(n);

    for (auto e : edges) {
      adj[e[0]].insert(e[1]);
      adj[e[1]].insert(e[0]);
    }

    queue<int> q;    // hold leaves nodes

    for (int i = 0; i < adj.size(); i++) {
      if (adj[i].size() == 1)
        q.push(i);
    }

    // start removing leaves till two nodes remains which will be centroid nodes
    // there will be at most two centroids in tree like graph
    while (n > 2) {
      int size = q.size();
      n -= size;
      for (int s = 0; s < size; s++) {
        int leave = q.front();
        q.pop();
        for (int neigh : adj[leave]) {
          adj[neigh].erase(leave);
          if (adj[neigh].size() == 1) q.push(neigh);
        }
      }
    }

    vector<int> res;
    while (!q.empty()) {
      res.push_back(q.front());
      q.pop();
    }

    return res;
  }
};