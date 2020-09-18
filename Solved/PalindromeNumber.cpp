// int range -2,147,483,648 to 2,147,483,647

#include <iostream>

using namespace std;

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    int reversed = 0;
    int initial = x;
    while (x) {
      int digit = x % 10;
      x = x / 10;
      if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && digit > 7)) return false;
      reversed = reversed * 10 + digit;
    }
    return reversed == initial;
  }
};