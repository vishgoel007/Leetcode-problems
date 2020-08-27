// https://leetcode.com/problems/group-anagrams/

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<string> > groupAnagrams(vector<string>& strs) {
    vector<vector<string> > ans;
    map<string, vector<string> > mp;

    for (string s : strs) {
      string sortedStr = s;
      sort(sortedStr.begin(), sortedStr.end());
      mp[sortedStr].push_back(s);
    }

    map<string, vector<string> >::iterator it;

    for (it = mp.begin(); it != mp.end(); it++) ans.push_back(it->second);

    return ans;
  }
};