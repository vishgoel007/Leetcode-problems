// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3303/

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
  int minSum = INT_MAX;

  // my own
  void calculatePath1(vector<vector<int>>& grid, int row, int col, int sum) {
    int rowSize = grid.size();
    int colSize = grid[0].size();

    if (row >= grid.size() || col >= colSize) return;

    if (row == rowSize - 1 && col == colSize - 1) {
      int lastCell = grid[rowSize - 1][colSize - 1];
      minSum = min(minSum, sum + lastCell);
      return;
    }

    calculatePath1(grid, row + 1, col, sum + grid[row][col]);
    calculatePath1(grid, row, col + 1, sum + grid[row][col]);
  }

  int calculatePath2(vector<vector<int>>& grid, int row, int col, int sum) {
    int rowSize = grid.size();
    int colSize = grid[0].size();

    if (row >= grid.size() || col >= colSize) return INT_MAX;

    if (row == rowSize - 1 && col == colSize - 1)
      return grid[row][col];

    int right = calculatePath2(grid, row + 1, col, sum + grid[row][col]);
    int bottom = calculatePath2(grid, row, col + 1, sum + grid[row][col]);
    int minValue = grid[row][col] + min(right, bottom);
    return minValue;
  }

  int minPathSum(vector<vector<int>>& grid) {
    // calculatePath1(grid, 0, 0, 0);
    // return minSum;

    return calculatePath2(grid, 0, 0, 0);
  }
};

// using top down dp
class Solution {
 public:
  int minSum = INT_MAX;
  vector<vector<int>> dp;
  int calculatePath(vector<vector<int>>& grid, int row, int col, int sum) {
    int rowSize = grid.size();
    int colSize = grid[0].size();

    if (row >= grid.size() || col >= colSize) return INT_MAX;

    if (row == rowSize - 1 && col == colSize - 1)
      return grid[row][col];

    if (dp[row][col] != -1) return dp[row][col];

    int right = calculatePath(grid, row + 1, col, sum + grid[row][col]);
    int bottom = calculatePath(grid, row, col + 1, sum + grid[row][col]);

    dp[row][col] = grid[row][col] + min(right, bottom);

    return dp[row][col];
  }

  int minPathSum(vector<vector<int>>& grid) {
    int rowSize = grid.size();
    int colSize = grid[0].size();
    dp.resize(rowSize + 1, vector<int>(colSize + 1, -1));
    return calculatePath(grid, 0, 0, 0);
  }
};

// using bottom up dp
class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int rowSize = grid.size();
    int colSize = grid[0].size();
    vector<vector<int>> dp(rowSize + 1, vector<int>(colSize + 1, -1));

    dp[0][0] = grid[0][0];
    for (int i = 1; i < rowSize; i++) {
      dp[i][0] = dp[i - 1][0] + grid[i - 1][0];
    }

    for (int i = 1; i < colSize; i++) {
      dp[0][i] = dp[0][i - 1] + grid[0][i - 1];
    }

    for (int row = 1; row < rowSize; row++) {
      for (int col = 1; col < colSize; col++) {
        int right = dp[row - 1][col];
        int bottom = dp[row][col - 1];
        dp[row][col] = min(right, bottom) + grid[row][col];
      }
    }

    return dp[rowSize-1][colSize-1];
  }
};