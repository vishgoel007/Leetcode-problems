// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3380/

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// can be done using priority queue

class Solution {
 public:
  int nthUglyNumber(int n) {
    vector<int> ugly(n);
    int t2 = 0, t3 = 0, t5 = 0;
    int index = 1;
    ugly[0] = 1;
    int nextUgly = 1;
    while (index < n) {
      ugly[index] = min(ugly[t2] * 2, min(ugly[t3] * 3, ugly[t5] * 5));
      if (ugly[index] == ugly[t2] * 2) t2++;
      if (ugly[index] == ugly[t3] * 3) t3++;
      if (ugly[index] == ugly[t5] * 5) t5++;
      index++;
    }
    return ugly[n - 1];
  }
};