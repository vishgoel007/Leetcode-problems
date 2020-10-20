// https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/561/week-3-october-15th-october-21st/3498/

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
  vector<string> findRepeatedDnaSequences(string s) {
    int len = s.length();
    if (len < 11) return {};
    unordered_set<string> track, aux;

    for (int i = 0; i <= len - 10; i++) {
      string t = s.substr(i, 10);
      if (track.count(t))
        aux.insert(t);
      else
        track.insert(t);
    }

    vector<string> res(aux.begin(), aux.end());
    return res;
  }
};

// using rolling hash
class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    int len = s.length();
    if (len < 11) return {};

    int L = 10, base = 4;
    int baseL = pow(base, L);

    unordered_map<char, int> mp{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
    vector<int> nums(len, 0);

    for (int i = 0; i < len; i++) nums[i] = mp[s[i]];

    unordered_set<int> set;
    unordered_set<string> output;
    int n = 0;

    for (int i = 0; i < len - 9; i++) {
      if (i == 0) {
        for (int k = 0; k < L; k++)
          n = n * base + nums[k];
        set.insert(n);
      } else {
        n = (long)n * base - (long)nums[i - 1] * baseL + nums[i + L - 1];
        if (set.count(n))
          output.insert(s.substr(i, 10));
        else
          set.insert(n);
      }
    }

    return {output.begin(), output.end()};
  }
};