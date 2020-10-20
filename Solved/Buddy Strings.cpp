// https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/560/week-2-october-8th-october-14th/3492/

#include <deque>
#include <iostream>
#include <list>
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
  bool buddyStrings(string A, string B) {
    int lenA = A.length();
    int lenB = B.length();
    if (lenA == 0 || lenA != lenB) return 0;

    if (A == B) {
      vector<int> count(26, 0);
      for (char c : A)
        count[c - 'a']++;

      for (int n : count)
        if (n > 1) return true;

      return false;
    } else {
      char ad1 = ' ', ad2 = ' ', bd1 = ' ', bd2 = ' ';
      int count = 0;
      for (int i = 0; i < lenA; i++) {
        if (A[i] != B[i]) {
          count++;
          if (ad1 == ' ') {
            ad1 = A[i];
            bd1 = B[i];
          } else {
            ad2 = A[i];
            bd2 = B[i];
          }
        }
      }
      if (count > 2 || ad1 != bd2 || ad2 != bd1) return 0;
    }

    return 1;
  }
};