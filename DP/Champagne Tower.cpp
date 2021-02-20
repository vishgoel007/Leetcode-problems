// https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/562/week-4-october-22nd-october-28th/3508/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// bottom up
class Solution {
 public:
  double champagneTower(int poured, int query_row, int query_glass) {
    vector<vector<double>> dp(query_row + 1, vector<double>(query_row + 1, 0.0));

    dp[0][0] = (double)poured;

    for (int r = 0; r < query_row; r++) {
      for (int c = 0; c <= r; c++) {
        double temp = (dp[r][c] - 1.0) / 2.0;
        if (temp > 0.0) {
          dp[r + 1][c] += temp;
          dp[r + 1][c + 1] += temp;
        }
      }
    }
    return min(dp[query_row][query_glass], 1.0);
  }
};

// like pascal triangle
class Solution {
 public:
  double champagneTower(int poured, int query_row, int query_glass) {
    vector<vector<double>> dp(query_row + 1, vector<double>(query_row + 1, 0.0));

    dp[0][0] = (double)poured;

    for (int r = 1; r <= query_row; r++) {
      for (int c = 0; c <= r; c++) {
        if (c == 0)
          dp[r][c] = max(0.0, (dp[r - 1][c] - 1.0) / 2.0);

        else if (c == r)
          dp[r][c] = max(0.0, (dp[r - 1][c - 1] - 1.0) / 2.0);

        else
          dp[r][c] = max(0.0, (dp[r - 1][c - 1] - 1.0) / 2.0) + max(0.0, (dp[r - 1][c] - 1.0) / 2.0);
      }
    }
    return min(dp[query_row][query_glass], 1.0);
  }
};
