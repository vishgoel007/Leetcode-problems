// https://leetcode.com/problems/container-with-most-water/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int len = height.size();
    int area = -1;
    int frontIndex = 0, backIndex = len - 1;
    while (frontIndex <= backIndex) {
      area = max(area, (backIndex - frontIndex) * min(height[frontIndex], height[backIndex]));
      if (height[frontIndex] >= height[backIndex])
        backIndex--;
      else
        frontIndex++;
    }
    return area;
  }
};