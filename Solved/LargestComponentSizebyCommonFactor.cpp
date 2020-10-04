// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/553/week-5-august-29th-august-31st/3442/

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
  vector<int> dsu;
  int findd(int v) {
    if (dsu[v] == -1) return v;
    return dsu[v] = findd(dsu[v]);
  }
  void unionn(int from, int to) {
    int fromParent = findd(from);
    int toParent = findd(to);
    if (fromParent != toParent)
      dsu[fromParent] = toParent;
  }
  int largestComponentSize(vector<int>& A) {
    int maxEle = *max_element(A.begin(), A.end());
    // store which number in A have a same parent(i.e a common factor)
    dsu.resize(maxEle + 1, -1);

    for (int a : A) {
      for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) {
          unionn(a, i);
          unionn(a / i, a);
        }
      }
    }

    // store the frequency of how many numbers sharing a common factor
    unordered_map<int, int> freq;
    int ans = 1;
    for (int a : A) {
      int parent = findd(a);
      freq[parent]++;
      ans = max(ans, freq[parent]);
    }

    return ans;
  }
};