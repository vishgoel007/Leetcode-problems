// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/557/week-4-september-22nd-september-28th/3470/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// O(N*N)
class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int len = gas.size();

    for (int i = 0; i < len; i++) {
      int netGas = gas[i] - cost[i];
      if (netGas < 0) continue;
      int j = (i + 1) % len;

      while (true) {
        if (i == j) return i;
        netGas += (gas[j] - cost[j]);
        if (netGas < 0) break;
        j = (j + 1) % len;
      }
    }
    return -1;
  }
};

// O(N)
class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int len = gas.size();

    for (int i = 0; i < len; i++) {
      int netGas = gas[i] - cost[i];
      if (netGas < 0) continue;
      int j = (i + 1) % len;

      while (true) {
        if (i == j) return i;
        netGas += (gas[j] - cost[j]);
        if (netGas < 0) {
          /**
             * If car starts at A and can not reach B. Any station between A and B
             * can not reach B.(B is the first station that A can not reach.)
           */
          i = j > i ? j : i;
          break;
        };
        j = (j + 1) % len;
      }
    }
    return -1;
  }
};

// Simplified version O(N)

class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int len = gas.size();
    int totalCost = 0, currentCost = 0;
    int start = 0;

    for (int i = 0; i < len; i++) {
      totalCost += (gas[i] - cost[i]);
      currentCost += (gas[i] - cost[i]);
      if (currentCost < 0) {
        start = i + 1;
        currentCost = 0;
      }
    }
    return totalCost < 0 ? -1 : start;
  }
};
