// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3427/

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> distributeCandies(int candies, int num_people) {
    int count = 1;
    int index = 0;
    vector<int> v(num_people, 0);
    while (candies > 0) {
      if (index == num_people) index = 0;
      if (candies < count) {
        v[index++] += candies;
        candies = 0;
      } else {
        v[index++] += count;
        candies -= count;
        count++;
      }
      
    }
    return v;
  }
};