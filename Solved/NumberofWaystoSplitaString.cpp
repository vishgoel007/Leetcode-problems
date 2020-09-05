// https://leetcode.com/contest/biweekly-contest-34/problems/number-of-ways-to-split-a-string/

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
  int numWays(string s) {
    int mod = 1e9 + 7;
    int len = s.length();
    int count1 = 0;

    for (int i = 0; i < len; i++)
      if (s[i] == '1') count1++;

    if (count1 % 3 != 0) return 0;

    if (count1 == 0)
      return (len - 1) * (len - 2) / 2 % mod;

    vector<vector<int>> v;
    int eachOnesCount = 0;
    long long firstCut = 0;
    long long secondCut = 0;
    long long ans = 1;

    for (int i = 0; i < len; i++) {
      if (s[i] == '1') eachOnesCount++;
      if (eachOnesCount == count1 / 3) {
        firstCut++;
      } else if (eachOnesCount == 2 * count1 / 3) {
        secondCut++;
      }
    }
    ans = (long long)(secondCut % mod * firstCut % mod) % mod;

    return ans % mod;
  }
};