// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

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
  vector<int> dp;
  int findMax(vector<int>& p, int buyAt) {
    if (buyAt >= p.size()) return 0;
    if (dp[buyAt] != -1) return dp[buyAt];

    int maxP = 0;
    // if bought at buyAt
    for (int i = buyAt + 1; i < p.size(); i++) {
      // trying to sell on every possible ith day
      if (p[i] > p[buyAt])
        maxP = max(maxP, p[i] - p[buyAt] + findMax(p, i + 2));
    }

    // skip current
    maxP = max(maxP, findMax(p, buyAt + 1));
    dp[buyAt] = maxP;
    return maxP;
  }
  int maxProfit(vector<int>& prices) {
    dp.resize(prices.size() + 5, -1);
    return findMax(prices, 0);
  }
};

// using bottom up dp
class Solution {
 public:
  vector<int> dp;

  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    vector<int> dp(len + 5, 0);
    for (int buyAt = len - 1; buyAt >= 0; buyAt--) {
      int maxP1 = 0;
      for (int sellAt = buyAt + 1; sellAt < len; sellAt++) {
        if (prices[sellAt] > prices[buyAt])
          maxP1 = max(maxP1, prices[sellAt] - prices[buyAt] + dp[sellAt + 2]);
      }
      int maxP2 = max(maxP1, dp[buyAt + 1]);
      dp[buyAt] = max(maxP1, maxP2);
    }
    // for (int n : dp) cout << n << " ";

    return dp[0];
  }
};

// using state machine
/**
 * There are three states noStocks, inHand, sell;
 * How to react to those states
 * noStocks --> either have no stocks or sold in previous state
 * inHand   --> either bought in current state or having from previous state
 * sold     --> when sold in current state
 */
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    int noStock = 0, inHand = -prices[0], sold = 0;
    int prevNoStock, prevInHand, prevSold;
    for (int i = 0; i < len; i++) {
      prevNoStock = noStock;
      prevInHand = inHand;
      prevSold = sold;

      noStock = max(prevNoStock, prevSold);
      inHand = max(prevInHand, prevNoStock - prices[i]);
      sold = prevInHand + prices[i];
    }
    return max(noStock, sold);
  }
};

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/Most-consistent-ways-of-dealing-with-the-series-of-stock-problems