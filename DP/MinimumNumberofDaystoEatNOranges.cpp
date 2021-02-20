// https://leetcode.com/contest/weekly-contest-202/problems/minimum-number-of-days-to-eat-n-oranges/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;


// using top down dp
class Solution1 {
 public:
  unordered_map<int, int> dp;
  int recursive(int n) {
    if (n <= 1) return n;

    if (dp.count(n)) return dp[n];

    int a = n % 2 + recursive(n / 2);
    int b = n % 3 + recursive(n / 3);

    dp[n] = 1 + min(a, b);
    return dp[n];
  }

  int minDays(int n) {
    return recursive(n);
  }
};

// Using recursion
class Solution2 {
 public:
  int recursive(int n) {
    if (n <= 1) return n;
    int a = n % 2 + recursive(n / 2);
    int b = n % 3 + recursive(n / 3);
    return 1 + min(a, b);
  }

  int minDays(int n) {
    return recursive(n);
  }
};

// using BFS
class Solution3 {
 public:
  int minDays(int n) {
    if (n <= 0) return 0;

    unordered_set<int> visited;
    queue<int> q;
    q.push(n);

    int level = 0;

    while (!q.empty()) {
      level++;
      int size = q.size();
      for (int i = 0; i < size; i++) {
        int curr = q.front();
        q.pop();

        if (curr == 1)
          return level;

        if (visited.find(curr) == visited.end()) {
          if (curr % 3 == 0) q.push(curr / 3);
          if (curr % 2 == 0) q.push(curr / 2);
          q.push(curr - 1);
          visited.insert(curr);
        }
      }
    }
    return level;
  }
};