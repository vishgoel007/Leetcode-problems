// https://leetcode.com/problems/unique-paths/

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
  int helper(int rowSize, int colSize, int row, int col) {
    if (row >= rowSize || col >= colSize) return 0;
    if (row == rowSize - 1 && col == colSize - 1) return 1;

    int right = helper(rowSize, colSize, row + 1, col);
    int down = helper(rowSize, colSize, row, col + 1);
    return right + down;
  }
  int uniquePaths(int m, int n) {
    return helper(m, n, 0, 0);
  }
};

// using top down dp
class Solution {
 public:
  vector<vector<int>> dp;
  int helper(int rowSize, int colSize, int row, int col) {
    if (row >= rowSize || col >= colSize) return 0;
    if (row == rowSize - 1 && col == colSize - 1) return 1;

    if (dp[row][col] != -1) return dp[row][col];

    int right = helper(rowSize, colSize, row + 1, col);
    int down = helper(rowSize, colSize, row, col + 1);
    return dp[row][col] = right + down;
  }
  int uniquePaths(int m, int n) {
    dp.resize(m, vector<int>(n, -1));
    return helper(m, n, 0, 0);
  }
};

// using bottom up dp
class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
      dp[i][0] = 1;
    }

    for (int i = 0; i < n; i++) {
      dp[0][i] = 1;
    }

    for (int r = 1; r < m; r++) {
      for (int c = 1; c < n; c++) {
        dp[r][c] = dp[r - 1][c] + dp[r][c];
      }
    }

    return dp[m - 1][n - 1];
  }
};