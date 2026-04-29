/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 * };
 */

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;                  // res = best (max) diameter in edges we've seen anywhere so far
        dfs(root, res);               // run a postorder DFS that computes heights and updates res
        return res;
    }

private:
    // Mental model:
    // - dfs(node) returns "height" of node's subtree (how long the tallest single downward arm is).
    // - At the same node, we also consider a diameter path that bends here:
    //   deepest-left-leaf -> ... -> node -> ... -> deepest-right-leaf
    //   That bending path length in edges is leftHeight + rightHeight.
    int dfs(TreeNode* root, int& res) {
        // Base case: empty subtree has height 0.
        // This is reached when we try to go past a leaf (leaf->left or leaf->right is nullptr).
        if (!root) return 0;

        // Explore left subtree fully, get its height.
        int left = dfs(root->left, res);

        // Explore right subtree fully, get its height.
        int right = dfs(root->right, res);

        // "Two-arm stretch" through this node (one path that bends at this node).
        // left edges down + right edges down.
        res = max(res, left + right);

        // Return "one-arm" height to parent: parent can only extend one direction.
        // +1 counts this current node in the height we're returning upward.
        return 1 + max(left, right);
    }
};

/*
Time Complexity: O(n)   // visit each node once
Space Complexity: O(h)  // recursion stack, h = height of tree (worst O(n) for a skewed tree)
*/
/*

dfs(1)

dfs(2)

dfs(3)

dfs(nullptr) returns 0

dfs(nullptr) returns 0

dfs(3) now computes, returns 1

dfs(2) now computes using left=1, returns 2

dfs(1) now computes using left=2, returns 3
*/