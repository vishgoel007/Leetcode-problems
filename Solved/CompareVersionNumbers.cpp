// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/555/week-2-september-8th-september-14th/3454/

#include <iostream>
#include <istream>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int compareVersion(string version1, string version2) {
    istringstream iss1(version1);
    istringstream iss2(version2);

    vector<int> vers1, vers2;

    for (int i; iss1 >> i;) {
      vers1.push_back(i);
      if (iss1.peek() == '.')
        iss1.ignore();
    }

    for (int i; iss2 >> i;) {
      vers2.push_back(i);
      if (iss2.peek() == '.')
        iss2.ignore();
    }

    int vers1Size = vers1.size();
    int vers2Size = vers2.size();

    vers1Size > vers2Size ? vers2.resize(vers1Size) : vers1.resize(vers2Size);

    for (int i = 0; i < vers1.size(); i++) {
      if (vers1[i] > vers2[i]) return 1;
      if (vers1[i] < vers2[i]) return -1;
    }

    return 0;
  }
};