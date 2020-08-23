// https://leetcode.com/explore/learn/card/queue-stack/231/practical-application-queue/1374/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// using bfs

class Solution {
 public:
  int numIslands(vector<vector<char> >& grid) {
    int rowSize = grid.size();
    if (rowSize < 1) return 0;
    int colSize = grid[0].size();
    if (colSize < 1) return 0;

    int islands = 0;
    queue<pair<int, int> > q;

    vector<vector<int> > directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    for (int row = 0; row < rowSize; row++) {
      for (int col = 0; col < colSize; col++) {
        if (grid[row][col] == '1') {
          islands++;

          // set visited
          grid[row][col] = '5';

          // insert first node
          q.push(make_pair(row, col));

          // traverse all nodes of current node
          while (!q.empty()) {
            pair<int, int> f = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
              int r = f.first + directions[d][0];
              int c = f.second + directions[d][1];
              if (r >= 0 && r < rowSize && c >= 0 && c < colSize && grid[r][c] == '1') {
                q.push(make_pair(r, c));
                grid[r][c] = '5';
              }
            }
          }
        }
      }
    }

    return islands;
  }
};

// using dfs
class Solution1 {
 public:
  void setAdjacentVisited(vector<vector<char>>& grid, int row, int col, int rowSize, int colSize) {
    if (row < 0 || row >= rowSize || col < 0 || col >= colSize || grid[row][col] != '1')
      return;

    // mark visited
    grid[row][col] = '5';

    // navigate to other directions
    setAdjacentVisited(grid, row - 1, col, rowSize, colSize);
    setAdjacentVisited(grid, row, col - 1, rowSize, colSize);
    setAdjacentVisited(grid, row + 1, col, rowSize, colSize);
    setAdjacentVisited(grid, row, col + 1, rowSize, colSize);
  }

  int numIslands(vector<vector<char>>& grid) {
    int islands = 0;

    int rowSize = grid.size();
    if (rowSize < 1) return 0;

    int colSize = grid[0].size();

    for (int row = 0; row < rowSize; row++) {
      for (int col = 0; col < colSize; col++) {
        // only continue if there is land
        if (grid[row][col] == '1') {
          islands++;
          setAdjacentVisited(grid, row, col, rowSize, colSize);
        }
      }
    }
    return islands;
  }
};
