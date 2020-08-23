// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3349/

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  static bool sortByDescDifference(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
  }

  int twoCitySchedCost(vector<vector<int> >& costs) {
    int len = costs.size();
    int cost = 0;
    vector<pair<int, int> > vec(len);

    for (int i = 0; i < len; i++) {
      vec[i] = make_pair(abs(costs[i][0] - costs[i][1]), i);
    }

    sort(vec.begin(), vec.end(), sortByDescDifference);

    int countA = 0, countB = 0;
    for (int i = 0; i < len; i++) {
      if (countA == len / 2) {
        cost += costs[vec[i].second][1];
      } else if (countB == len / 2) {
        cost += costs[vec[i].second][0];
      } else {
        if (costs[vec[i].second][0] > costs[vec[i].second][1]) {
          cost += costs[vec[i].second][1];
          countB++;
        } else {
          cost += costs[vec[i].second][0];
          countA++;
        }
      }
    }

    return cost;
  }
};