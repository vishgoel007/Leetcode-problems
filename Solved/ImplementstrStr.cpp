// https://leetcode.com/problems/implement-strstr/

#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int strStr(string haystack, string needle) {
    int hayLen = haystack.length();
    int nedLen = needle.length();
    if (!nedLen) return 0;

    for (int i = 0; i < hayLen - nedLen + 1; i++) {
      int j = i, k = 0;
      while (haystack[j] == needle[k] && j < hayLen && k < nedLen) {
        j++;
        k++;
      }
      if (k == nedLen) return i;
    }
    return -1;
  }
};
