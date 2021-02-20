// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/556/week-3-september-15th-september-21st/3464/

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if (len == 0) return 0;
    int minEle = prices[0];
    int ans = 0;
    for (int i = 1; i < len; i++) {
      if (prices[i] > minEle) {
        ans = max(ans, prices[i] - minEle);
      } else
        minEle = prices[i];
    }
    return ans;
  }
};