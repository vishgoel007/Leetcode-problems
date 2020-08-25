// https://leetcode.com/contest/biweekly-contest-33/problems/detect-cycles-in-2d-grid/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// using BFS
class Solution1 {
 public:
  vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

  bool BFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, char val, int row, int col) {
    queue<pair<int, int>> q;
    q.push(make_pair(row, col));
    while (!q.empty()) {
      pair<int, int> p = q.front();
      q.pop();

      if (visited[p.first][p.second]) return 1;

      visited[p.first][p.second] = 1;

      for (int d = 0; d < 4; d++) {
        int r = p.first + directions[d][0];
        int c = p.second + directions[d][1];
        if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == val && !visited[r][c]) {
          q.push(make_pair(r, c));
        }
      }
    }
    return 0;
  }

  bool containsCycle(vector<vector<char>>& grid) {
    int rowSize = grid.size();
    if (rowSize < 1) return 0;
    int colSize = grid[0].size();
    if (colSize < 1) return 0;

    queue<pair<int, int>> q;
    vector<vector<bool>> visited(rowSize, vector<bool>(colSize, 0));

    for (int row = 0; row < rowSize; row++) {
      for (int col = 0; col < colSize; col++) {
        if (!visited[row][col]) {
          if (BFS(grid, visited, grid[row][col], row, col)) return 1;
        }
      }
    }

    return 0;
  }
};

// using DFS
class Solution {
 public:
  vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

  bool DFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col, int prevRow, int prevCol) {
    visited[row][col] = 1;

    for (int d = 0; d < 4; d++) {
      int r = row + directions[d][0];
      int c = col + directions[d][1];
      if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == grid[row][col] && !(prevRow == r && prevCol == c)) {
        if (visited[r][c]) return true;
        if (DFS(grid, visited, r, c, row, col)) return true;
      }
    }
    return 0;
  }

  bool containsCycle(vector<vector<char>>& grid) {
    int rowSize = grid.size();
    if (rowSize < 1) return 0;
    int colSize = grid[0].size();
    if (colSize < 1) return 0;

    vector<vector<bool>> visited(rowSize, vector<bool>(colSize, 0));

    for (int row = 0; row < rowSize; row++) {
      for (int col = 0; col < colSize; col++) {
        if (!visited[row][col]) {
          if (DFS(grid, visited, row, col, -1, -1)) return 1;
        }
      }
    }
    return 0;
  }
};