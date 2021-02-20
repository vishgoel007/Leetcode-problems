// https://leetcode.com/contest/weekly-contest-212/problems/slowest-key/

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
  char slowestKey(vector<int>& releaseTimes, string keysPressed) {
    int len = releaseTimes.size();
    int maxTime = releaseTimes[0], resChar = keysPressed[0];

    for (int i = 1; i < len; i++) {
      int time = releaseTimes[i] - releaseTimes[i - 1];
      if (time > maxTime) {
        resChar = keysPressed[i];
        maxTime = time;
      } else if (time == maxTime) {
        if (keysPressed[i] > resChar) resChar = keysPressed[i];
      }
    }

    return resChar;
  }
};
