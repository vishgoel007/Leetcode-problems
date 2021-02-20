// https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/579/week-1-january-1st-january-7th/3593/

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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode *curr = head, *prevToDuplicate = nullptr;

    while (curr) {
      ListNode* node = curr;
      bool isDuplicate = false;
      while (curr->next && node->val == curr->next->val) {
        curr = curr->next;
        isDuplicate = true;
      }
      curr = curr->next;

      if (!isDuplicate)
        prevToDuplicate = node;
      else {
        prevToDuplicate == nullptr ? head = curr : prevToDuplicate->next = curr;
      }
    }
    return head;
  }
};