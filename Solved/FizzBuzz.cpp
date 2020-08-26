// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/552/week-4-august-22nd-august-28th/3437/

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> fizzBuzz(int n) {
    vector<string> output;
    if (n < 1) return output;

    for (int i = 1; i <= n; i++) {
      if (i % 3 == 0 && i % 5 == 0)
        output.push_back("FizzBuzz");
      else if (i % 3 == 0)
        output.push_back("Fizz");
      else if (i % 5 == 0)
        output.push_back("Buzz");
      else {
        char c = i + '0';
        string str = "" + c;
        output.push_back(str);
      }
    }
    return output;
  }
};