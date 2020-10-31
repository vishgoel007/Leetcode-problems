// https://leetcode.com/contest/weekly-contest-212/problems/path-with-minimum-effort/

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
  int r, c, e;
};

class Compare {
 public:
  bool operator()(node a, node b) {
    return a.e > b.e;
  }
};

class Solution {
 public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    int rowSize = heights.size();
    int colSize = heights[0].size();
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<bool>> visited(rowSize, vector<bool>(colSize, 0));
    int minEffort = INT_MAX;

    priority_queue<node, vector<node>, Compare> q;
    q.push({0, 0, 0});

    while (!q.empty()) {
      node curr = q.top();
      q.pop();

      if (curr.r == rowSize - 1 && curr.c == colSize - 1)
        return curr.e;

      if (visited[curr.r][curr.c]) continue;

      visited[curr.r][curr.c] = 1;

      for (auto d : dir) {
        int rr = curr.r + d[0];
        int cc = curr.c + d[1];
        if (rr >= 0 && rr < rowSize && cc >= 0 && cc < colSize && !visited[rr][cc]) {
          int hh = max(curr.e, abs(heights[curr.r][curr.c] - heights[rr][cc]));
          q.push({rr, cc, hh});
        }
      }
    }
    return minEffort == INT_MAX ? 0 : minEffort;
  }
};

// 
/**
 * can be done using binary search
 * do binary search all efforts (1,10^6)
 * do BFS/DFS of mid value and check if path exist for mid value
 * if exist take min values of all valid mid values
 */