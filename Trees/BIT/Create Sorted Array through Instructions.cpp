// https://leetcode.com/problems/create-sorted-array-through-instructions/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * using Binary indexed tree(BIT)
 * Note that BIT only supports prefix information querying,
 * so we can only query from start to a certain element, not any interval.
 */

class Solution {
 public:
  // we store the occurrence number of values in an array
  void updateBIT(vector<int>& BIT, int val, int index, int m) {
    index++;
    while (index < m) {
      BIT[index] += val;    // val = 1
      index = index + (index & -index);
    }
  }

  int queryBIT(vector<int>& BIT, int index) {
    index++;
    int count = 0;
    while (index > 0) {
      count += BIT[index];
      index = index - (index & -index);
    }
    return count;
  }

  int createSortedArray(vector<int>& instructions) {
    const int mod = 1e9 + 7;
    int m = 1e5 + 2;
    int len = instructions.size();

    vector<int> BIT(m);
    long res = 0;
    for (int i = 0; i < len; i++) {
      int leftCost = queryBIT(BIT, instructions[i] - 1);

      // total elementsCount - sum of occurrence of ith instruction
      int rightCost = i - queryBIT(BIT, instructions[i]);
      res += min(leftCost, rightCost);
      if (res > mod) res -= mod;

      updateBIT(BIT, 1, instructions[i], m);
    }
    return res;
  }
};

// TODO with segment tree