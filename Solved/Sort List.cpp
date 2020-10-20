// https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/560/week-2-october-8th-october-14th/3493/

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
  ListNode* getMiddle(ListNode* head) {
    ListNode *mid = head, *fast = head, *midPrev = NULL;
    while (fast && fast->next) {
      midPrev = mid;
      mid = mid->next;
      fast = fast->next->next;
    }
    midPrev->next = NULL;
    return mid;
  }

  ListNode* mergeList(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    ListNode* newHead = new ListNode(-1);
    ListNode* temp = newHead;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        temp->next = l1;
        l1 = l1->next;
      } else {
        temp->next = l2;
        l2 = l2->next;
      }
      temp = temp->next;
    }
    
    temp->next = l1 ? l1 : l2;

    return newHead->next;
  }

  ListNode* merger(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* mid = getMiddle(head);
    ListNode* left = merger(head);
    ListNode* right = merger(mid);
    return mergeList(left, right);
  }
  ListNode* sortList(ListNode* head) {
    return merger(head);
  }
};

// TODO without extra space
// https://leetcode.com/problems/sort-list/discuss/46712/Bottom-to-up(not-recurring)-with-o(1)-space-complextity-and-o(nlgn)-time-complextity