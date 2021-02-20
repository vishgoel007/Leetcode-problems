// https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/562/week-4-october-22nd-october-28th/3509/

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
  ListNode* detectCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    bool isLoop = false;
    while (slow && fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        isLoop = true;
        break;
      }
    }
    if (!isLoop) return NULL;

    slow = head;
    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }

    return slow;
  }
};

// mathemtical explanation
// https://leetcode.com/problems/linked-list-cycle-ii/discuss/44781/Concise-O(n)-solution-by-using-C++-with-Detailed-Alogrithm-Description/219750
