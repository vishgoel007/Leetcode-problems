// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

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
    int ans = 0;
    for (int i = prices.size() - 1; i > 0; i--) {
      int profit = prices[i] - prices[i - 1];
      if (profit > 0) ans += profit;
    }
    return ans;
  }
};