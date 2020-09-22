// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/556/week-3-september-15th-september-21st/3467/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Method 1
class Solution {
 public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    int len = trips.size();
    vector<vector<int>> passengers;
    for (int i = 0; i < len; i++) {
      passengers.push_back({trips[i][1], trips[i][0]});
      passengers.push_back({trips[i][2], -trips[i][0]});
    }

    sort(passengers.begin(), passengers.end());

    int totalPassengers = 0;
    for (int i = 0; i < passengers.size(); i++) {
      totalPassengers += passengers[i][1];
      if (totalPassengers > capacity) return false;
    }
    return true;
  }
};

// Method 2
class Solution {
 public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    int len = trips.size();
    int maxEle = -1;
    for (int i = 0; i < len; i++) {
      maxEle = max(maxEle, trips[i][2]);
    }
    vector<int> passengersAtTimestamp(maxEle + 1, 0);
    for (int i = 0; i < len; i++) {
      // passengers boarded at start timestamp
      passengersAtTimestamp[trips[i][1]] += trips[i][0];

      // passengers deboarded at end timestamp
      passengersAtTimestamp[trips[i][2]] -= trips[i][0];
    }

    int totalPersons = 0;
    for (int i = 0; i <= maxEle; i++) {
      totalPersons += passengersAtTimestamp[i];
      if (totalPersons > capacity) return false;
    }
    return true;
  }
};
