// https://leetcode.com/contest/biweekly-contest-33/problems/minimum-number-of-vertices-to-reach-all-nodes/

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int> >& edges) {
    vector<int> mp(n, 0), output;
    int len = edges.size();
    for (int i = 0; i < len; i++) {
      mp[edges[i][1]] = 1;
    }
    for (int i = 0; i < n; i++) {
      if (mp[i] != 1) output.push_back(i);
    }
    return output;
  }
};