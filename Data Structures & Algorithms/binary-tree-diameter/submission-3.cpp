/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        // Mental model (same as recursion):
        // - For each node, we want leftHeight and rightHeight.
        // - Diameter candidate that bends at this node = leftHeight + rightHeight (two-arm stretch).
        // - Height we "return upward" = 1 + max(leftHeight, rightHeight) (one-arm height).
        //
        // Recursion gets "children first" naturally.
        // Iterative version must force postorder (children first) using a stack and a visited flag.

        int res = 0;

        // height[node] = height of subtree rooted at node (same value dfs(node) would return).
        unordered_map<TreeNode*, int> height;
        height[nullptr] = 0; // makes missing child height = 0 without special checks

        stack<pair<TreeNode*, bool>> st;
        st.push({root, false});

        while (!st.empty()) {
            auto [node, expanded] = st.top();
            st.pop();

            if (!node) continue;

            if (!expanded) {
                // First time we see this node:
                // push it back as "expanded=true" so we compute it AFTER its children.
                st.push({node, true});

                // Postorder: push children to be processed first.
                st.push({node->right, false});
                st.push({node->left, false});
            } else {
                // Second time we see this node:
                // both children already processed, so their heights are in the map.
                int leftH = height[node->left];
                int rightH = height[node->right];

                // Two-arm stretch through this node gives a diameter candidate.
                res = max(res, leftH + rightH);

                // One-arm height returned to parent.
                height[node] = 1 + max(leftH, rightH);
            }
        }

        return res;
    }
};

/*
Time Complexity: O(n)   // each node processed a constant number of times
Space Complexity: O(n)  // height map + explicit stack (worst case)
*/

/*
Use recursion when the problem is naturally bottom-up and children must be computed before the parent (cleaner and simpler).
Use stack/iterative only if recursion is not allowed or the tree depth may cause stack overflow.
Otherwise, recursion is the preferred and more readable approach.
*/
