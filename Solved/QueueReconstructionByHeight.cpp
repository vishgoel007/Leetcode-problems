// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3352/

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
  static bool sortByHeight(vector<int> a, vector<int> b) {
    return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
  }

  vector<vector<int> > reconstructQueue(vector<vector<int> >& people) {
    int len = people.size();
    sort(people.begin(), people.end(), sortByHeight);
    vector<vector<int> > output(len, vector<int>(2, -1));
    for (int i = 0; i < len; i++) {
      int count = people[i][1];
      for (int j = 0; j < len; j++) {
        if (count == 0 && output[j][0] == -1) {
          output[j] = people[i];
          break;
        } else if (count > 0 && (output[j][0] == -1 || output[j][0] >= people[i][0])) {
          count--;
        }
      }
    }

    return output;
  }
};