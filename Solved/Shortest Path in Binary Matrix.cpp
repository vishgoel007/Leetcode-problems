// https://leetcode.com/problems/shortest-path-in-binary-matrix/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// using DFS
// TLE
class Solution {
 public:
  int minPath = INT_MAX;
  vector<vector<int>> dir = {{1, 1}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}};

  void DFS(vector<vector<int>>& grid, int row, int col, int pathLen) {
    int rowSize = grid.size();
    int colSize = grid[0].size();

    if (row == rowSize - 1 && col == colSize - 1) {
      minPath = min(minPath, pathLen);
      return;
    }

    for (auto d : dir) {
      int r = row + d[0];
      int c = col + d[1];
      if (r < 0 || r >= rowSize || c < 0 || c >= colSize || grid[r][c] != 0) continue;
      grid[r][c] = 5;
      DFS(grid, r, c, pathLen + 1);
      grid[r][c] = 0;
    }
  }
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int rowSize = grid.size();
    int colSize = grid[0].size();
    if (grid[0][0] != 0 | grid[rowSize - 1][colSize - 1] != 0) return -1;

    DFS(grid, 0, 0, 1);
    return minPath == INT_MAX ? -1 : minPath;
  }
};

// using BFS
class Solution {
 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int rowSize = grid.size();
    int colSize = grid[0].size();

    if (grid[0][0] != 0 || grid[rowSize - 1][colSize - 1] != 0) return -1;

    vector<vector<int>> dir = {{1, 1}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}};
    queue<pair<int, int>> q;

    q.push({0, 0});
    
    // set visited
    grid[0][0] = 5;
    int level = 0;

    while (!q.empty()) {
      level++;
      int size = q.size();
      for (int s = 0; s < size; s++) {
        auto curr = q.front();
        q.pop();
        if (curr.first == rowSize - 1 && curr.second == colSize - 1) return level;
        for (auto d : dir) {
          int r = curr.first + d[0];
          int c = curr.second + d[1];
          if (r < 0 || r >= rowSize || c < 0 || c >= colSize || grid[r][c] != 0) continue;
          q.push({r, c});
          grid[r][c] = 5;
        }
      }
    }
    return -1;
  }
};