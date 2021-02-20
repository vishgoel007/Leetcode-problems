// https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/564/week-1-november-1st-november-7th/3517/

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
  void insert(ListNode** sortedHead, ListNode* newNode) {
    if ((*sortedHead) == NULL || (*sortedHead)->val >= newNode->val) {
      newNode->next = (*sortedHead);
      (*sortedHead) = newNode;
      return;
    }

    ListNode *tmp = (*sortedHead), *prev = NULL;
    while (tmp && tmp->val < newNode->val) {
      prev = tmp;
      tmp = tmp->next;
    }
    prev->next = newNode;
    newNode->next = tmp;
  }

  ListNode* insertionSortList(ListNode* head) {
    ListNode *sorted = NULL, *curr = head;

    while (curr) {
      ListNode* newNode = new ListNode(curr->val);
      insert(&sorted, newNode);
      curr = curr->next;
    }
    return sorted;
  }
};