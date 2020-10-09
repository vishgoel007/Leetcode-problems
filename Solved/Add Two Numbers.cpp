// https://leetcode.com/problems/add-two-numbers/

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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* temp = new ListNode(-1);
    ListNode* head = temp;

    int carry = 0;
    while (l1 || l2) {
      int x = l1 ? l1->val : 0;
      int y = l2 ? l2->val : 0;
      int sum = x + y + carry;
      carry = sum / 10;
      temp->next = new ListNode(sum % 10);
      if (l1) l1 = l1->next;
      if (l2) l2 = l2->next;
      temp = temp->next;
    }

    if (carry) temp->next = new ListNode(carry);
    return head->next;
  }
};