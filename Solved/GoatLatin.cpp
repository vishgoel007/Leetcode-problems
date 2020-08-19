// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3429/

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
  string toGoatLatin(string S) {
    int len = S.length();

    int startIndex = 0, lastIndex = len - 1;
    while (startIndex < len && S[startIndex] == ' ') startIndex++;
    while (lastIndex >= 0 && S[lastIndex] == ' ') lastIndex--;
    if (startIndex == len || lastIndex == 0) return "";

    string ans = "";
    string append = "a";
    while (startIndex <= lastIndex) {
      if (isVowel(S[startIndex])) {
        while (startIndex <= lastIndex && S[startIndex] != ' ') ans += S[startIndex++];
      } else {
        string firstChar = "";
        firstChar += S[startIndex];
        startIndex++;
        while (startIndex <= lastIndex && S[startIndex] != ' ') ans += S[startIndex++];
        ans += firstChar;
      }

      ans += ("ma" + append + " ");
      append += "a";
      startIndex++;
    }
    return ans.substr(0, ans.length() - 1);
  }
};