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
    void reorderList(ListNode* head) {
        // If list is empty, nothing to reorder
        if (!head) return;

        // Store pointers to all nodes so we can access any node by index
        // These are NOT copies; they point to the actual linked list nodes
        vector<ListNode*> nodes;

        // Traverse the list and fill the vector
        ListNode* cur = head;
        while (cur) {
            nodes.push_back(cur);
            cur = cur->next;
        }

        // i starts from the front, j starts from the back
        int i = 0;
        int j = nodes.size() - 1;

        // Rewire next pointers: front -> back -> next front -> next back ...
        // We are overwriting the original next pointers on purpose
        while (i < j) {
            nodes[i]->next = nodes[j];   // link front to back
            i++;

            nodes[j]->next = nodes[i];   // link back to next front
            j--;
        }

        // Important: terminate the list
        // Without this, the list may form a cycle
        nodes[i]->next = nullptr;
    }
};
