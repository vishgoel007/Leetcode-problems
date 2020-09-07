// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3324/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Method 1 : By binary search
class Solution1 {
 public:
  bool isPerfectSquare(int num) {
    int low = 1, high = num;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if ((long)mid * mid == num) {
        return true;
      } else if ((long)mid * mid < num) {
        low = (int)mid + 1;
      } else {
        high = (int)mid - 1;
      }
    }
    return false;
  }
};

// Method 4: By finding square root
class Solution2 {
 public:
  bool isPerfectSquare(int num) {
    int i = 1;
    while ((long)i * i < num) i++;
    return !((long)i * i - num);
  }
};

// Method 3: A square number is 1+3+5+7+...

// Method 4: Newton method
