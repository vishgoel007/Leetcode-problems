// https://leetcode.com/contest/biweekly-contest-33/problems/thousand-separator/

#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  string thousandSeparator(int n) {
    if (n == 0) return "0";
    int count = 0;
    string ans = "";
    while (n) {
      int d = n % 10;
      ans += to_string(d);
      n /= 10;
      count++;
      if (count == 3 && n) {
        ans += ".";
        count = 0;
      }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
