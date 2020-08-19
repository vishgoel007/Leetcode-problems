// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3428/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Generating solution level by level
 * For example, given N=3 and K=7
 * at the 1st level: [1, 2, 3, 4, 5, 7, 8, 9]
 * at the 2nd level: [18, 29, 70, 81, 92]
 * at the 3rd level: [181, 292, 707, 818, 929]
 */

// Using bfs
class Solution {
 public:
  vector<int> numsSameConsecDiff(int N, int K) {
    if (N == 1) return vector<int> {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    queue<int> q;

    for (int i = 1; i < 10; i++) q.push(i); // level 1

    for (int level = 2; level <= N; level++) {
      int size = q.size();
      for (int i = 1; i <= size; i++) {
        int num = q.front();
        q.pop();
        int lastDigit = num % 10;
        if (K != 0) {
          if (lastDigit - K >= 0) q.push(num * 10 + (lastDigit - K));
          if (lastDigit + K < 10) q.push(num * 10 + (lastDigit + K));
        } else
          q.push(num * 10 + lastDigit);
      }
    }
    vector<int> output;
    while (!q.empty()) {
      output.push_back(q.front());
      q.pop();
    }
    return output;
  }
};

// Using dfs
class Solution1 {
 public:
  vector<int> output;

  void dfs(int n, int k, int num) {
    if (n == 0) {
      output.push_back(num);
      return;
    }

    int lastDigit = num % 10;
    if (k != 0) {
      int subDigit = lastDigit - k;
      if (subDigit >= 0)
        dfs(n - 1, k, num * 10 + subDigit);

      int addDigit = lastDigit + k;
      if (addDigit < 10)
        dfs(n - 1, k, num * 10 + addDigit);
    } else {
      dfs(n - 1, k, num * 10 + lastDigit);
    }

    return;
  }

  vector<int> numsSameConsecDiff(int N, int K) {
    if (N == 1) return vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 1; i <= 9; i++) {
      dfs(N - 1, K, i);
    }
    return output;
  }
};
