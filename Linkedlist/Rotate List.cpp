// https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3486/

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
  int listLength(ListNode* head) {
    int len = 0;
    while (head) {
      head = head->next;
      len++;
    }
    return len;
  }

  ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next) return NULL;

    int len = listLength(head);
    k = k % len;
    if (k == 0) return head;

    ListNode *prev = head;
    int t = len - k - 1;
    while (t--) prev = prev->next;

    ListNode *curr = prev->next;

    prev->next = NULL;

    ListNode* tmp = curr;
    while (tmp && tmp->next) tmp = tmp->next;
    tmp->next = head;

    return curr;
  }
};