// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    ListNode* curr = head;

    while (curr) {
      ListNode* node = curr;
      bool isDuplicate = false;
      while (curr->next && node->val == curr->next->val) {
        curr = curr->next;
        isDuplicate = true;
      }
      curr = curr->next;
      if (isDuplicate) node->next = curr;
    }
    return head;
  }
};