// https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/569/week-1-december-1st-december-7th/3552/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  vector<int> lst;
  Solution(ListNode* head) {
    srand(time(NULL));
    while (head) {
      lst.push_back(head->val);
      head = head->next;
    }
  }

  int getRandom() {
    int ind = rand() % lst.size();
    return lst[ind];
  }
};

// Reservoir Sampling
class Solution {
 public:
  ListNode* node;
  Solution(ListNode* head) {
    srand(time(NULL));
    node = head;
  }

  int getRandom() {
    int res = 0, count = 1;
    ListNode* curr = node;
    while (curr != NULL) {
      if (rand() % count == 0) {
        res = curr->val;
      }
      count++;
      curr = curr->next;
    }
    return res;
  }
};

// explanation
// https://leetcode.com/problems/linked-list-random-node/discuss/85659/Brief-explanation-for-Reservoir-Sampling
