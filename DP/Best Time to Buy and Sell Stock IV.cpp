// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// using top down dp
class Solution {
 public:
  vector<vector<vector<int>>> dp;
  int helper(vector<int>& prices, int start, bool canBuy, int trans) {
    if (start == prices.size() || trans == 0) return 0;

    if (dp[canBuy][trans][start] != -1) return dp[canBuy][trans][start];

    int maxP = 0;
    // skip current
    maxP = max(maxP, helper(prices, start + 1, canBuy, trans));

    if (canBuy)
      maxP = max(maxP, -prices[start] + helper(prices, start + 1, false, trans));
    else
      maxP = max(maxP, prices[start] + helper(prices, start + 1, true, trans - 1));

    return dp[canBuy][trans][start] = maxP;
  }

  int solveForLargeK(vector<int>& prices) {
    int ans = 0;
    for (int i = prices.size() - 1; i > 0; i--) {
      int profit = prices[i] - prices[i - 1];
      if (profit > 0) ans += profit;
    }
    return ans;
  }

  int maxProfit(int k, vector<int>& prices) {
    int len = prices.size();
    if (k >= len) return solveForLargeK(prices);

    // dp -> (canBuy, transactions, start)
    dp.resize(2, vector<vector<int>>(k + 1, vector<int>(len, -1)));
    return helper(prices, 0, true, k);
  }
};

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/Most-consistent-ways-of-dealing-with-the-series-of-stock-problems