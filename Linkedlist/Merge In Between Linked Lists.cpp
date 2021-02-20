// https://leetcode.com/contest/biweekly-contest-40/problems/merge-in-between-linked-lists/

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
  ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode *curr1 = list1, *curr2 = list2, *prev = NULL;
    bool foundA = false;

    while (curr1 != NULL) {
      if (curr1->val == a) foundA = true;
      if (curr1->val == b) break;

      if (!foundA) prev = curr1;
      curr1 = curr1->next;
    }

    while (curr2->next) curr2 = curr2->next;

    prev->next = list2;
    curr2->next = curr1->next;
    return list1;
  }
};