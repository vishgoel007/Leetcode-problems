// https://leetcode.com/problems/permutation-in-string/

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
  bool checkInclusion(string s1, string s2) {
    int n1 = s1.length(), n2 = s2.length();
    if (n1 > n2) return false;

    vector<int> mp(26);
    for (char c : s1) mp[c - 'a']++;

    int start = 0, end = 0;
    int count = 0;
    while (end < n2) {
      int endInd = s2[end] - 'a';
      if (mp[endInd] > 0) count++;
      mp[endInd]--;
      end++;

      while (count >= n1) {
        int startInd = s2[start] - 'a';
        mp[startInd]++;
        if (mp[startInd] > 0) count--;

        if (end - start == n1) return true;

        start++;
      }
    }

    return false;
  }
};