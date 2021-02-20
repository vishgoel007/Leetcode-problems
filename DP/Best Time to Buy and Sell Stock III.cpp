// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// using prefix/suffix array (divide and conquer)
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if (!len) return 0;

    // prefix store max profit from left till ith
    // suffix store max profit from right till ith
    vector<int> prefix(len, 0), suffix(len, 0);

    int auxMin = prices[0];
    for (int i = 1; i < len; i++) {
      prefix[i] = max(prefix[i - 1], prices[i] - auxMin);
      auxMin = min(auxMin, prices[i]);
    }

    int auxMax = prices[len - 1];
    for (int i = len - 2; i >= 0; i--) {
      suffix[i] = max(suffix[i + 1], auxMax - prices[i]);
      auxMax = max(auxMax, prices[i]);
    }

    int ans = 0;
    for (int i = 0; i < len; i++) {
      ans = max(ans, prefix[i] + suffix[i]);
    }

    return ans;
  }
};

// using top down dp
/**
 * Note : can use map of string also instead 3d vector
 * just convert all the states into string
 */
class Solution {
 public:
  vector<vector<vector<int>>> dp;
  int helper(vector<int>& prices, int start, bool canBuy, int trans) {
    if (start >= prices.size() || trans == 0) return 0;

    if (dp[canBuy][trans][start] != -1) return dp[canBuy][trans][start];

    int maxP = 0;

    // skip current
    maxP = max(maxP, helper(prices, start + 1, canBuy, trans));

    // can buy
    if (canBuy)
      maxP = max(maxP, -prices[start] + helper(prices, start + 1, false, trans));
    // need to sell
    else
      maxP = max(maxP, prices[start] + helper(prices, start + 1, true, trans - 1));

    return dp[canBuy][trans][start] = maxP;
  }

  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    // dp -> (canBuy, transactions, start)
    dp.resize(2, vector<vector<int>>(3, vector<int>(len + 1, -1)));
    return helper(prices, 0, true, 2);
  }
};


// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/749153/Easy-DP-Memoization-as-well-as-bottom-up

// using state machine
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if (len == 0) return 0;

    int buy1 = INT_MIN, sell1 = 0, buy2 = INT_MIN, sell2 = 0;

    for (int i = 0; i < len; i++) {
      buy1 = max(buy1, -prices[i]);
      sell1 = max(sell1, buy1 + prices[i]);
      buy2 = max(buy2, sell1 - prices[i]);
      sell2 = max(sell2, buy2 + prices[i]);
    }
    return sell2;
  }
};
