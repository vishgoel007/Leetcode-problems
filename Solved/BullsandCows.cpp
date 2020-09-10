// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/555/week-2-september-8th-september-14th/3455/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// 1
class Solution {
 public:
  string getHint(string secret, string guess) {
    int bull = 0, cows = 0;

    for (int s = 0; s < secret.length(); s++) {
      if (secret[s] == guess[s]) {
        bull++;
        guess[s] = '*';
        secret[s] = '@';
      }
    }

    for (int s = 0; s < secret.length(); s++) {
      for (int g = 0; g < guess.length(); g++) {
        if (secret[s] == '@') continue;
        if (secret[s] == guess[g]) {
          cows++;
          guess[g] = '*';
          secret[s] = '@';
        }
      }
    }

    string ans = to_string(bull) + 'A' + to_string(cows) + 'B';

    return ans;
  }
};

// 2
class Solution {
 public:
  string getHint(string secret, string guess) {
    vector<int> s(10, 0);
    vector<int> g(10, 0);

    int bull = 0, cows = 0;

    for (int i = 0; i < secret.length(); i++) {
      if (secret[i] == guess[i])
        bull++;
      else {
        g[guess[i] - '0']++;
        s[secret[i] - '0']++;
      }
    }

    for (int i = 0; i < 10; i++) {
      cows += min(s[i], g[i]);
    }

    string ans = to_string(bull) + 'A' + to_string(cows) + 'B';

    return ans;
  }
};