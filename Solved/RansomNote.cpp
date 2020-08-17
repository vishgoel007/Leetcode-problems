// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3318/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> mp;
    int rlen = ransomNote.length();
    int mlen = magazine.length();
    for (int i = 0; i < mlen; i++) mp[magazine[i]]++;
    for (int i = 0; i < rlen; i++) mp[ransomNote[i]]--;

    unordered_map<char, int>::iterator it;

    for (it = mp.begin(); it != mp.end(); it++) {
      if (it->second < 0) return false;
    }
    return true;
  }
};