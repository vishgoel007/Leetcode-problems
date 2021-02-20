// https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/579/week-1-january-1st-january-7th/3591/

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
  int res = 0;
  void permutate(vector<int>& v, int start) {
    if (start == v.size()) {
      res++;
      return;
    }

    for (int i = start; i < v.size(); i++) {
      swap(v[start], v[i]);
      if (v[start] % (start + 1) == 0 || (start + 1) % v[start] == 0)
        permutate(v, start + 1);
      swap(v[i], v[start]);
    }
  }

  int countArrangement(int n) {
    vector<int> vec;
    for (int i = 1; i <= n; i++) vec.push_back(i);
    permutate(vec, 0);
    return res;
  }
};

// alternate method
// Try every possible number at each position
class Solution {
 public:
  int res = 0;
  vector<bool> vis;
  void permutate(vector<int>& v, int start) {
    if (start == v.size()) {
      res++;
      return;
    }

    for (int i = 1; i < v.size(); i++) {
      if ((v[i] % start == 0 || start % v[i] == 0) && !vis[i]) {
        vis[i] = true;
        permutate(v, start + 1);
        vis[i] = false;
      }
    }
  }

  int countArrangement(int n) {
    vis.resize(n + 1);

    vector<int> vec;
    vec.push_back(-1);
    for (int i = 1; i <= n; i++) vec.push_back(i);

    permutate(vec, 0);
    return res;
  }
};