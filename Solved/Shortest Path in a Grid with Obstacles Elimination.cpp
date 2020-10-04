// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

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
  int r, c, remObs;
};

class Solution {
 public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    int rowSize = grid.size();
    int colSize = grid[0].size();

    if (grid[0][0] && grid[rowSize - 1][colSize - 1] && k < 2 && rowSize > 1 && colSize > 1)
      return -1;

    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<vector<bool>>> visited(rowSize + 1, vector<vector<bool>>(colSize + 1, vector<bool>(k + 1)));

    queue<Node> q;

    q.push({0, 0, k - grid[0][0]});
    visited[0][0][k - grid[0][0]] = 1;   

    int level = 0;

    while (!q.empty()) {
      level++;
      int size = q.size();
      for (int s = 0; s < size; s++) {
        Node curr = q.front();
        q.pop();
        
        if (curr.r == rowSize - 1 && curr.c == colSize - 1) return level - 1;

        int remObs = curr.remObs;
        for (auto d : dir) {
          int r = curr.r + d[0];
          int c = curr.c + d[1];
          if (r < 0 || r >= rowSize || c < 0 || c >= colSize || (grid[r][c] == 1 && remObs < 1)) continue;
          int obs = remObs - grid[r][c];
          if (!visited[r][c][obs]) {
            q.push({r, c, obs});
            visited[r][c][obs] = 1;
          }
        }
      }
    }
    return -1;
  }
};

/**
 * Nice trick to improve and eliminate some cases
 * https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/discuss/453652/Manhattan-distance-instead-of-normal-goal-check
 */