// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *ahead = head, *toDelete = head, *prev = NULL;

    for (int i = 1; i <= n; i++) ahead = ahead->next;

    if (!ahead) return head->next;

    while (ahead) {
      prev = toDelete;
      toDelete = toDelete->next;
      ahead = ahead->next;
    }

    prev->next = toDelete->next;
    return head;
  }
};