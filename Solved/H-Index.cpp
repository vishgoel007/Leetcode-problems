// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3420/

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int len = citations.size();

    sort(citations.begin(), citations.end());

    for (int i = 0; i < len; i++) {
      if (citations[i] >= len - i) return len - i;
    }
    return 0;
  }
};