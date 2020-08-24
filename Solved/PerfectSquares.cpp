// https://leetcode.com/explore/learn/card/queue-stack/231/practical-application-queue/1371/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// using dp
class Solution {
 public:
  int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
      for (int k = 1; k * k < i; k++) {
        // dp[i] --> the least number of perfect squares sum which equal to i
        dp[i] = min(dp[i], dp[i - k * k] + 1);
      }
    }
    return dp[n];
  }
};

// using bfs
class Solution1 {
 public:
  int numSquares(int n) {
    int level = 0;
    int sq = (int)sqrt(n);

    queue<int> q;
    q.push(n);

    while (!q.empty()) {
      level++;
      int size = q.size();
      for (int i = 0; i < size; i++) {
        int curr = q.front();
        q.pop();
        for (int k = sq; k >= 1; k--) {
          int m = k * k;
          if (curr == m)
            return level;
          else if (curr > m)
            q.push(curr - m);
        }
      }
    }
    return level;
  }
};
