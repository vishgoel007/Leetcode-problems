// https://leetcode.com/contest/weekly-contest-202/problems/three-consecutive-odds/

#include <math.h>

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool threeConsecutiveOdds(vector<int>& arr) {
    int len = arr.size();
    int count = 0;
    for (int i = 0; i < len; i++) {
      if (arr[i] & 1) {
        count++;
      }
      if (count == 3) {
        return true;
      }
      if (arr[i] % 2 == 0) count = 0;
    }
    return false;
  }
};