/**
 * Merge two sorted linked lists by "stitching" existing nodes together (no new nodes created).
 *
 * Key idea: use a dummy (fake) head + a moving tail pointer.
 *
 * Visual:
 *   dummy is a real node that never moves:
 *     [0] -> (head of merged list...)
 *      ^
 *      |
 *     dummy
 *
 *   node is a pointer that moves and always points to the current tail:
 *     [0] -> [1] -> [2] -> ...
 *                    ^
 *                    |
 *                   node
 *
 * Why do this?
 * - dummy.next always remembers the head of the merged list (easy return)
 * - node lets us append in O(1) each step without special-casing the first node
 *
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // dummy = fixed anchor node (real object on the stack)
        // dummy.next will become the *real* head of the merged list.
        //
        // Start:
        //   dummy/node
        //      ↓
        //   [0] -> null
        ListNode dummy(0);

        // node = moving "tail" pointer.
        // We attach nodes after node, then advance node forward.
        ListNode* node = &dummy;

        // While both lists still have nodes, pick the smaller front node
        // and attach it to the merged list.
        while (list1 && list2) {

            // Compare current heads:
            //   list1 -> a -> ...
            //   list2 -> b -> ...
            // Attach the smaller one to:
            //   node -> next
            if (list1->val < list2->val) {
                // Stitch list1's current node onto merged list:
                //   node -> next = list1
                //
                // Example:
                //   node -> [0] -> null
                //   list1 -> [1] -> ...
                // becomes:
                //   node -> [0] -> [1] -> ...
                node->next = list1;

                // Advance list1 (we consumed that node)
                list1 = list1->next;
            } else {
                // Same stitch, but using list2's node
                node->next = list2;
                list2 = list2->next;
            }

            // Move tail forward:
            //   node now points to the last node in the merged list
            //
            // Visual after appending:
            //   dummy -> [0] -> [1] -> ...
            //                   ^
            //                   |
            //                  node
            node = node->next;
        }

        // One list is empty now. The other list is already sorted,
        // so we can attach the entire remaining chain in one step.
        //
        // Visual:
        //   merged tail (node) -> null
        //   remaining -> [x] -> [y] -> ...
        // Just do:
        //   node -> next = remaining
        if (list1) {
            node->next = list1;
        } else {
            node->next = list2;
        }

        // dummy.next is the true head of the merged list (skip the fake dummy node)
        //
        // Final:
        //   dummy -> [0] -> [1] -> [2] -> ...
        // Return:          ^
        //                  |
        //               dummy.next
        return dummy.next;
    }
};
