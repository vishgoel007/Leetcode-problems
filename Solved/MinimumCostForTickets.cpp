// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/552/week-4-august-22nd-august-28th/3436/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// using bottom up dp
class Solution {
 public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<int> dp(days.back() + 1);
    unordered_set<int> dSet(days.begin(), days.end());
    dp[0] = 0;

    for (int d = 1; d <= days.back(); d++) {
      // if day is not present in days array we dont spend money
      // used previously spent money
      if (dSet.find(d) == dSet.end()) {
        dp[d] = dp[d - 1];
      } else {
        int a = dp[max(d - 1, 0)] + costs[0];
        int b = dp[max(d - 7, 0)] + costs[1];
        int c = dp[max(d - 30, 0)] + costs[2];
        dp[d] = min(a, min(b, c));
      }
    }
    return dp.back();
  }
};

// using top down dp
class Solution1 {
 public:
  vector<int> dp;

  int minCost(vector<int>& days, vector<int>& costs, int index) {
    int len = days.size();

    if (index >= len) return 0;

    if (dp[index] != -1) return dp[index];

    int a = costs[0] + minCost(days, costs, index + 1);

    int i = index;
    while (i < len && days[i] < (days[index] + 7)) i++;
    int b = costs[1] + minCost(days, costs, i);

    int k = index;
    while (k < len && days[k] < (days[index] + 30)) k++;
    int c = costs[2] + minCost(days, costs, k);

    dp[index] = min(a, min(b, c));

    return dp[index];
  }

  int mincostTickets(vector<int>& days, vector<int>& costs) {
    dp.resize(366, -1);
    return minCost(days, costs, 0);
  }
};

// using recursion
class Solution2 {
 public:
  int minCost(vector<int>& days, vector<int>& costs, int index) {
    int len = days.size();

    if (index >= len) return 0;

    int a = costs[0] + minCost(days, costs, index + 1);

    int i = index;
    while (i < len && days[i] < (days[index] + 7)) i++;
    int b = costs[1] + minCost(days, costs, i);

    int k = index;
    while (k < len && days[k] < (days[index] + 30)) k++;
    int c = costs[2] + minCost(days, costs, k);

    return min(a, min(b, c));
  }

  int mincostTickets(vector<int>& days, vector<int>& costs) {
    return minCost(days, costs, 0);
  }
};