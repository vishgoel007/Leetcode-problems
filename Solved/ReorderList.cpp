// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3430/

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *reverseList(ListNode *head) {
    ListNode *curr = head, *nxt = NULL, *prev = NULL;
    while (curr) {
      nxt = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nxt;
    }
    return prev;
  }
  void reorderList(ListNode *head) {
    if (!head || !head->next) return;

    ListNode *headPtr = head, *slow = head, *fast = head;
    ListNode *previousToHalf = NULL;
    while (fast && fast->next) {
      previousToHalf = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    previousToHalf->next = NULL;

    ListNode *l2 = reverseList(slow);

    ListNode *l1 = head, *tempL1, *tempL2;
    while (l1) {
      tempL1 = l1->next;
      tempL2 = l2->next;
      l1->next = l2;
      if (!tempL1) break;
      l2->next = tempL1;
      l1 = tempL1;
      l2 = tempL2;
    }
  }
};