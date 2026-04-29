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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //dummy → 1 → 2 → 3 → 4 → 5
       //adds a node to head
       ListNode* dummy = new ListNode(0,head);
       //ponter to dummy node
       ListNode* left = dummy;
       //pointer to head og
       ListNode* right = head;

       while(n>0){
        right = right->next;
        n--;
       }
       //right is n steps ahead so basically length - n gives the position for left
       //when right reaches nullptr left is exactly behin the node n
       while(right!=nullptr){
        left = left->next;
        right = right->next;
       }
       //left of next holds addr of n, so we take left->next->next to skip n
       left -> next = left->next->next;
       //dummy node is used for cases we have to delete head node
       //better to update
       return dummy->next;
    }
};