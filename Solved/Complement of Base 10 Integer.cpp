// https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3484/

#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int bitwiseComplement(int N) {
    int x = 1;
    while (x <= N) x *= 2;
    return N == 0 ? 1 : (x - 1 - N);
  }
};