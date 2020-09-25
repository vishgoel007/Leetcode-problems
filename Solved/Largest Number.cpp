// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/557/week-4-september-22nd-september-28th/3472/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;
class Solution {
 public:
  static ll combine(int n1, int n2) {
    ll times = 10;
    while (times <= n2) times *= 10;
    return n1 * times + n2;
  }
  static bool byIntCompartor(int num1, int num2) {
    ll n1 = combine(num1, num2);
    ll n2 = combine(num2, num1);
    return n1 > n2;
  }
  static bool byStringcompartor(int num1, int num2) {
    string str1 = to_string(num1) + to_string(num2);
    string str2 = to_string(num2) + to_string(num1);
    return str1 > str2;
  }
  string largestNumber(vector<int>& nums) {
    int len = nums.size();
    sort(nums.begin(), nums.end(), byStringcompartor);
    // sort(nums.begin(), nums.end(), byIntCompartor);

    string ans = "";
    for (int i = 0; i < len; i++) ans += to_string(nums[i]);
    return ans[0] == '0' ? "0" : ans;
  }
};