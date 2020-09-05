// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/554/week-1-september-1st-september-7th/3448/

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
  vector<int> partitionLabels(string S) {
    int len = S.length();
    vector<int> mp(27, -1);

    for (int i = 0; i < len; i++) mp[S[i] - 'a'] = i;

    vector<int> output;

    int minStart = 0, maxEnd = mp[S[0] - 'a'];

    for (int i = 1; i < len; i++) {
      if (mp[S[i] - 'a'] == -1) continue;

      int currStart = i;
      int currEnd = mp[S[i] - 'a'];

      mp[S[i] - 'a'] = -1;    // mark visited

      if (currStart <= maxEnd) {
        maxEnd = max(currEnd, maxEnd);
      } else if (currStart > maxEnd) {
        output.push_back(maxEnd - minStart + 1);
        minStart = currStart;
        maxEnd = currEnd;
      }
    }

    output.push_back(maxEnd - minStart + 1);
    return output;
  }
};