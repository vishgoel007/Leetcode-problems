// https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/562/week-4-october-22nd-october-28th/3506/

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
  int bagOfTokensScore(vector<int>& tokens, int P) {
    int len = tokens.size();
    sort(tokens.begin(), tokens.end());

    int i = 0, j = len - 1, score = 0, maxScore = 0;

    while (i < len && P < tokens[i]) i++;
    if (i == len) return 0;

    while (i <= j) {
      P = P - tokens[i++];
      score++;
      maxScore = max(maxScore, score);

      if (i < len && score > 0 && P < tokens[i]) {
        P = P + tokens[j--];
        score--;
      }
    }
    return maxScore;
  }
};