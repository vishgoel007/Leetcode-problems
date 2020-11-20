// https://leetcode.com/problems/minimum-jumps-to-reach-home/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
    unordered_set<int> set(forbidden.begin(), forbidden.end());
    queue<tuple<bool, int, int>> q;

    int threshold = x;
    for (int f : forbidden) threshold = max(threshold, f);
    threshold += (a + b); // think about it

    vector<vector<int>> visited(2, vector<int>(threshold + 1, 0)); // {backstate, pos}

    q.push({0, 0, 0});    // {isBackState, currentPos, jumpsCount}

    while (!q.empty()) {
      auto curr = q.front();
      q.pop();

      bool isBack = get<0>(curr);
      int pos = get<1>(curr);
      int jumps = get<2>(curr);

      if (pos == x) return jumps;

      if (pos + a <= threshold and !set.count(pos + a) and !visited[0][pos + a]) {
        q.push({0, pos + a, jumps + 1});
        visited[0][pos + a] = true;
      }

      if (!isBack and pos - b >= 0 and !set.count(pos - b) and !visited[1][pos - b]) {
        q.push({1, pos - b, jumps + 1});
        visited[1][pos - b] = true;
      }
    }
    return -1;
  }
};