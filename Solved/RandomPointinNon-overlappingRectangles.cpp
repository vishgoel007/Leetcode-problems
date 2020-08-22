// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/552/week-4-august-22nd-august-28th/3433/

#include <math.h>

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int> > R;
  vector<int> prefixArea;

  int calculateArea(vector<int>& v) {
    return (v[2] - v[0] + 1) * (v[3] - v[1] + 1);
  }

  Solution(vector<vector<int> >& rects) {
    R = rects;
    prefixArea.resize(rects.size());
    prefixArea[0] = calculateArea(rects[0]);
    for (int i = 1; i < rects.size(); i++) {
      prefixArea[i] = prefixArea[i - 1] + calculateArea(rects[i]);
    }
    srand(time(NULL));
  }

  vector<int> pick() {
    int random = rand() % (prefixArea[prefixArea.size() - 1]);
    int index = upper_bound(prefixArea.begin(), prefixArea.end(), random) - prefixArea.begin();

    int randomX = (rand() % (R[index][2] - R[index][0] + 1)) + R[index][0];
    int randomY = (rand() % (R[index][3] - R[index][1] + 1)) + R[index][1];
    return vector<int> {randomX, randomY};
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */