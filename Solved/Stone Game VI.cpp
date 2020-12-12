// https://leetcode.com/contest/biweekly-contest-41/problems/stone-game-vi/

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
  static bool compare(pair<int, int>& a, pair<int, int>& b) {
    return a.first > b.first;
  }
  int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
    int len = aliceValues.size();
    vector<pair<int, int>> arr(len);
    for (int i = 0; i < len; i++) {
      arr[i] = {aliceValues[i] + bobValues[i], i};
    }

    sort(arr.begin(), arr.end(), compare);

    int alice = 0, blob = 0;
    for (int i = 0; i < len; i++) {
      if (i & 1)
        blob += bobValues[arr[i].second];
      else
        alice += aliceValues[arr[i].second];
    }

    if (alice > blob) return 1;
    if (alice == blob) return 0;
    return -1;
  }
};