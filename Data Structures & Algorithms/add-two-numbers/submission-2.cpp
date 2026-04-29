/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Dummy head makes building the answer list easy (no special case for first node)
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;  // cur always points to the last node in the result list

        int carry = 0;          // carry from previous digit addition

        // Keep going while there are digits left in l1 or l2, OR we still have a carry
        while (l1 != nullptr || l2 != nullptr || carry != 0) {

            // If a list ended, treat its digit as 0
            int v1 = (l1 != nullptr) ? l1->val : 0;
            int v2 = (l2 != nullptr) ? l2->val : 0;

            // Add current digits + carry
            int sum = v1 + v2 + carry;

            // New digit is the last digit of sum, new carry is the "tens" part
            carry = sum / 10;
            int digit = sum % 10;

            // Append the new digit node to the result
            cur->next = new ListNode(digit);
            cur = cur->next;

            // Move forward in l1 and l2 if possible
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        // Result starts at dummy->next (dummy itself is just a helper)
        ListNode* res = dummy->next;
        delete dummy;  // free dummy node
        return res;
    }
};

/*
Example: l1 = [9], l2 = [9]  (digits are reversed)

Start:
  carry = 0
  result = dummy

Loop 1:
  v1 = 9, v2 = 9
  sum = 9 + 9 + 0 = 18
  carry = 18 / 10 = 1
  digit = 18 % 10 = 8
  append 8
  l1 = null, l2 = null

Loop 2 (because carry != 0):
  v1 = 0, v2 = 0
  sum = 0 + 0 + 1 = 1
  carry = 1 / 10 = 0
  digit = 1 % 10 = 1
  append 1

Stop (l1 null, l2 null, carry 0)

Result list: [8 -> 1]  which represents 18
*/
