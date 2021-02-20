// https://leetcode.com/contest/biweekly-contest-34/problems/count-all-possible-routes/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Bottom up dp
class Solution {
 public:
  vector<vector<long long>> dp;
  int mod = 1e9 + 7;

  int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    int len = locations.size();
    vector<vector<long long>> dp(len + 1, vector<long long>(fuel + 1, 0));
    long long ans = start == finish ? 1 : 0;

    dp[start][0] = 1;

    for (int fuelLeft = 1; fuelLeft <= fuel; fuelLeft++) {
      for (int st = 0; st < len; st++) {
        for (int fin = 0; fin < len; fin++) {
          if (st == fin) continue;
          int fuelNeeded = abs(locations[fin] - locations[st]);
          if (fuelNeeded <= fuelLeft) {
            dp[st][fuelLeft] = (dp[st][fuelLeft] + dp[fin][fuelLeft - fuelNeeded]) % mod;
          }
        }
      }
      ans = (ans + dp[finish][fuelLeft]) % mod;
    }
    return ans;
  }
};

// Top down dp
// TC : O(fuel*n^2)
// SC : O(fuel * n)
class Solution {
 public:
  vector<vector<long long>> dp;
  int mod = 1e9 + 7;

  int ways(vector<int>& loc, int start, int finish, int fuel) {
    if (start == loc.size() || start < 0 || fuel < 0) return 0;
    long long ans = 0;
    if (fuel >= 0 && finish == start) ans = 1;

    if (dp[start][fuel] != -1) return dp[start][fuel];

    for (int i = 0; i < loc.size(); i++) {
      if (i != start) {
        ans += (long long)(ways(loc, i, finish, fuel - abs(loc[start] - loc[i])) % mod);
      }
    }
    return dp[start][fuel] = ans % mod;
  }

  int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    int len = locations.size();
    dp.resize(len + 1, vector<long long>(201, -1));
    return ways(locations, start, finish, fuel);
  }
};

// Using recursion
class Solution {
 public:
  int mod = 1e9 + 7;
  int ways(vector<int>& loc, int start, int finish, int fuel) {
    if (start == loc.size() || start < 0 || fuel < 0) return 0;
    long long ans = 0;
    if (fuel >= 0 && finish == start) ans = 1;

    for (int i = 0; i < loc.size(); i++) {
      if (i != start) {
        ans += (long long)(ways(loc, i, finish, fuel - abs(loc[start] - loc[i])) % mod);
      }
    }
    return ans % mod;
  }

  int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    int len = locations.size();
    return ways(locations, start, finish, fuel);
  }
};