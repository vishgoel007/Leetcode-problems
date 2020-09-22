// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/556/week-3-september-15th-september-21st/3466/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// can use same grid to mark visit(say -5 value) node instead of extra space
// using backtracking
class Solution {
 public:
  vector<vector<int>> visited;
  vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int rowSize, colSize;

  bool isValidPath(vector<vector<int>>& grid, int row, int col) {
    return !(row < 0 || row >= rowSize || col < 0 || col >= colSize || grid[row][col] == -1 || grid[row][col] == 1 || visited[row][col] == 1);
  }

  int helper(vector<vector<int>>& grid, int row, int col, int remainingVisitedZeros) {
    if (grid[row][col] == 2) {
      if (remainingVisitedZeros == -1) return 1;
      return 0;
    }

    int totalWays = 0;
    for (auto d : dir) {
      int nextRow = row + d[0];
      int nextCol = col + d[1];

      if (!isValidPath(grid, nextRow, nextCol)) continue;

      visited[nextRow][nextCol] = 1;
      totalWays += helper(grid, nextRow, nextCol, remainingVisitedZeros - 1);
      visited[nextRow][nextCol] = 0;
    }

    return totalWays;
  }

  int uniquePathsIII(vector<vector<int>>& grid) {
    rowSize = grid.size(), colSize = grid[0].size();
    visited.resize(rowSize, vector<int>(colSize, 0));

    int totalZeros = 0;
    pair<int, int> startLoc;
    for (int row = 0; row < rowSize; row++) {
      for (int col = 0; col < colSize; col++) {
        if (grid[row][col] == 0) {
          totalZeros++;
        } else if (grid[row][col] == 1) {
          startLoc = {row, col};
        }
      }
    }

    return helper(grid, startLoc.first, startLoc.second, totalZeros);
  }
};