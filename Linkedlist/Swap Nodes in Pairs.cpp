// https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/572/week-4-december-22nd-december-28th/3579/

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

// recursive
class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* newHead = head->next;
    head->next = swapPairs(head->next->next);
    newHead->next = head;
    return newHead;
  }
};

// iterative
class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* temp = new ListNode(-1);

    ListNode *curr = head, *prev = temp;

    while (curr && curr->next) {
      // nodes to be swapped
      ListNode* first = curr;
      ListNode* second = curr->next;

      // swapping
      prev->next = second;
      first->next = second->next;
      second->next = first;

      // reinitialise
      prev = first;
      curr = first->next;
    }

    return temp->next;
  }
};