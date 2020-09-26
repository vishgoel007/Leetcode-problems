// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/557/week-4-september-22nd-september-28th/3473/

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
  int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int len = timeSeries.size();
    if (!len) return len;

    int nextPos = timeSeries[0] + duration, timespent = 0;
    for (int i = 1; i < len; i++) {
      timespent += min(duration, timeSeries[i] - timeSeries[i - 1]);
      nextPos = timeSeries[i] + duration;
    }

    return timespent + duration;
  }
};