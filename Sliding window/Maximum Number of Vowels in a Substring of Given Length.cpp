// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

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
  int maxVowels(string s, int k) {
    int n = s.length();
    vector<int> mp(26, 0);
    mp['a' - 'a'] = mp['e' - 'a'] = mp['i' - 'a'] = mp['o' - 'a'] = mp['u' - 'a'] = 1;

    int res = 0, count = 0;
    int start = 0, end = 0;

    while (end < n) {
      count += mp[s[end] - 'a'];
      end++;
      k--;
      while (k <= 0) {
        res = max(res, count);
        count -= mp[s[start] - 'a'];
        start++;
        k++;
      }
    }
    return res;
  }
};