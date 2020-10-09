//https://leetcode.com/problems/add-two-numbers-ii/

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

  ListNode* addNodeToFront(ListNode* head, int val) {
    ListNode* newNode = new ListNode(val);
    newNode->next = head;
    head = newNode;
    return head;
  }
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    ListNode *curr1 = l1, *curr2 = l2;
    int len1 = listLength(curr1), len2 = listLength(curr2);

    ListNode* temp = NULL;

    while (len1 > 0 && len2 > 0) {
      int value = 0;
      if (len1 >= len2) {
        value += curr1->val;
        curr1 = curr1->next;
        len1--;
      }
      if (len2 > len1) {
        value += curr2->val;
        curr2 = curr2->next;
        len2--;
      }

      temp = addNodeToFront(temp, value);
    }

    ListNode* head = NULL;
    int carry = 0;
    while (temp) {
      int sum = temp->val + carry;
      carry = sum / 10;
      head = addNodeToFront(head, sum % 10);
      temp = temp->next;
    }
    if (carry) head = addNodeToFront(head, carry);

    return head;
  }
};