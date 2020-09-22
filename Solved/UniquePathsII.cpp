// https://leetcode.com/problems/unique-paths-ii/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// using recursion
class Solution {
 public:
  int helper(vector<vector<int>>& grid, int row, int col) {
    int rowSize = grid.size(), colSize = grid[0].size();
    if (row >= rowSize || col >= colSize) return 0;
    if (grid[row][col] == 1) return 0;
    if (row == rowSize - 1 && col == colSize - 1) return 1;
    int right = helper(grid, row + 1, col);
    int down = helper(grid, row, col + 1);
    return right + down;
  }
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int rowSize = obstacleGrid.size();
    if (rowSize < 1) return 1;
    int colSize = obstacleGrid[0].size();
    if (colSize < 1) return 1;
    return helper(obstacleGrid, 0, 0);
  }
};

// using top down dp
class Solution {
 public:
  vector<vector<int>> dp;
  int helper(vector<vector<int>>& grid, int row, int col) {
    int rowSize = grid.size(), colSize = grid[0].size();
    if (row >= rowSize || col >= colSize) return 0;
    if (grid[row][col] == 1) return 0;
    if (row == rowSize - 1 && col == colSize - 1) return 1;

    if (dp[row][col] != -1) return dp[row][col];

    int right = helper(grid, row + 1, col);
    int down = helper(grid, row, col + 1);
    return dp[row][col] = right + down;
  }
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int rowSize = obstacleGrid.size();
    if (rowSize < 1) return 1;
    int colSize = obstacleGrid[0].size();
    if (colSize < 1) return 1;
    dp.resize(rowSize + 1, vector<int>(colSize + 1, -1));
    return helper(obstacleGrid, 0, 0);
  }
};

// using bottom up dp
class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int rowSize = obstacleGrid.size();
    if (rowSize < 1) return 1;
    int colSize = obstacleGrid[0].size();
    if (colSize < 1) return 1;
    vector<vector<int>> dp(rowSize + 1, vector<int>(colSize + 1, 0));

    for (int i = 0; i < rowSize; i++) {
      if (obstacleGrid[i][0] == 1) break;
      dp[i][0] = 1;
    }

    for (int i = 0; i < colSize; i++) {
      if (obstacleGrid[0][i] == 1) break;
      dp[0][i] = 1;
    }

    for (int row = 1; row < rowSize; row++) {
      for (int col = 1; col < colSize; col++) {
        if (obstacleGrid[row][col] != 1)
          dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
      }
    }
    return dp[rowSize - 1][colSize - 1];
  }
};