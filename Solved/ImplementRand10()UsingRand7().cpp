// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/552/week-4-august-22nd-august-28th/3439/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
 public:
  int rand10() {
    int sum = 0;
    for (int i = 1; i <= 5; i++) sum += (rand7() - 1);
    return 1 + sum % 10;
  }
};
