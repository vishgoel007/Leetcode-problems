// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> dp;
  int helper(vector<int>& prices, int fee, int start, bool canBuy) {
    if (start >= prices.size()) return 0;
    if (dp[canBuy][start] != -1) return dp[canBuy][start];

    int maxP = 0;
    maxP = max(maxP, helper(prices, fee, start + 1, canBuy));
    if (canBuy)
      maxP = max(maxP, (-prices[start] - fee) + helper(prices, fee, start + 1, false));
    else
      maxP = max(maxP, prices[start] + helper(prices, fee, start + 1, true));

    return dp[canBuy][start] = maxP;
  }
  int maxProfit(vector<int>& prices, int fee) {
    int len = prices.size();
    dp.resize(2, vector<int>(len + 1, -1));
    return helper(prices, fee, 0, true);
  }
};

// using state machine
class Solution {
 public:
  int maxProfit(vector<int>& prices, int fee) {
    int len = prices.size();
    if (len == 0) return 0;

    int buy = INT_MIN, sell = 0;

    for (int p : prices) {
      int prevSell = sell;
      buy = max(buy, prevSell - p);
      sell = max(sell, buy + p - fee);
    }

    return sell;
  }
};