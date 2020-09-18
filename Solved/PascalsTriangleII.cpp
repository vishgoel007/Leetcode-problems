// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3421/

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * C(line, i)   = line! / ( (line-i)! * i! )
 * C(line, i-1) = line! / ( (line - i + 1)! * (i-1)! )
 * We can derive following expression from above two expressions.
 * C(line, i) = C(line, i-1) * (line - i + 1) / i
 * So C(line, i) can be calculated from C(line, i-1) in O(1) time 
*/

class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> output;
    int c = 1;
    output.push_back(c);
    for (int i = 1; i <= rowIndex; i++) {
      c = (long)c * (rowIndex - i + 1) / i;
      output.push_back(c);
    }
    return output;
  }
};
