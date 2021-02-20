// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

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

// using prefix sum map method
class Solution {
 public:
  ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = head;

    dummy->next = head;
    int sum = 0;
    unordered_map<int, ListNode*> mp;

    mp[0] = dummy;
    while (curr) {
      sum += curr->val;
      if (mp.find(sum) != mp.end()) {
        ListNode* prev = mp[sum];
        ListNode* temp = prev;

        temp = temp->next;
        int aux = sum + temp->val;
        while (aux != sum) {
          mp.erase(aux);
          temp = temp->next;
          aux += temp->val;
        }

        prev->next = curr->next;
      } else {
        mp[sum] = curr;
      }
      curr = curr->next;
    }

    return dummy->next;
  }
};

// above alternate way (more intuitive )
class Solution {
 public:
  ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* curr = dummy;

    unordered_map<int, ListNode*> mp;

    int sum = 0;
    while (curr) {
      sum += curr->val;
      mp[sum] = curr;
      curr = curr->next;
    }

    sum = 0, curr = dummy;
    while (curr) {
      sum += curr->val;
      curr->next = mp[sum]->next;
      curr = curr->next;
    }

    return dummy->next;
  }
};