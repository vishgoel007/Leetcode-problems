// https://leetcode.com/problems/roman-to-integer/

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int romanToInt(string s) {
    map<char, int> mp;
    int result = 0, i = 0;
    int len = s.length();
    mp['I'] = 1, mp['V'] = 5, mp['X'] = 10, mp['L'] = 50, mp['C'] = 100, mp['D'] = 500, mp['M'] = 1000;

    while (i < len) {
      if (i < len - 1 && mp[s[i]] < mp[s[i + 1]]) {
        result += (mp[s[i + 1]] - mp[s[i]]);
        i += 2;
      } else {
        result += mp[s[i]];
        i++;
      }
    }

    return result;
  }
};