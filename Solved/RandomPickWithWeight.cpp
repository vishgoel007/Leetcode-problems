// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3351/

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
  vector<int> prefix;
  Solution(vector<int>& w) {
    srand(time(NULL));
    prefix.resize(w.size(), 0);
    prefix[0] = w[0];
    for (int i = 1; i < w.size(); i++) {
      prefix[i] = prefix[i - 1] + w[i];
    }
  }

  int pickIndex() {
    int random = rand() % prefix[prefix.size() - 1];
    return upper_bound(prefix.begin(), prefix.end(), random) - prefix.begin();
  }
};

// nice way to get pick an item by its probability
class NotASolution {
 public:
  vector<int> wt;
  int totalSum;
  NotASolution(vector<int>& w) {
    wt = w;
    totalSum = 0;
    srand(time(NULL));
    for (int i = 0; i < w.size(); i++) {
      totalSum += w[i];
    }
  }

  int pickIndex() {
    int sum = 0;
    int index = rand() % totalSum;
    int i = 0;
    while (sum < index) {
      sum += wt[i++];
    }
    return max(0, i - 1);
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */