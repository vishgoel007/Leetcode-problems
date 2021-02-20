// https://leetcode.com/problems/linked-list-cycle/

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
  bool hasCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;

    while (slow && fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) return 1;
    }

    return 0;
  }
};