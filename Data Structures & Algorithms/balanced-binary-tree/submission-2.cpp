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
    bool isBalanced(TreeNode* root) {
        // dfs(root) returns {balancedFlag, height}
        // balancedFlag is 1 if whole tree is balanced, 0 otherwise
        // so "== 1" just converts that flag into true/false
        return dfs(root)[0] == 1;
    }

private:
    // returns a 2-item vector:
    // [0] = 1 if this subtree is balanced, else 0
    // [1] = height of this subtree
    vector<int> dfs(TreeNode* root) {
        // base case: empty tree
        // empty tree is balanced, and its height is 0
        // this happens when we go past a leaf (leaf->left or leaf->right is nullptr)
        if (!root) return {1, 0};

        // go compute left subtree first (postorder: children before parent)
        vector<int> left = dfs(root->left);

        // go compute right subtree next
        vector<int> right = dfs(root->right);

        // left[0] tells if left subtree is balanced, left[1] is left height
        // right[0] tells if right subtree is balanced, right[1] is right height
        //
        // a node is balanced if:
        // 1) left subtree is balanced
        // 2) right subtree is balanced
        // 3) heights differ by at most 1
        //
        // visual idea at current node:
        //          root
        //         /    \
        //   left subtree  right subtree
        //     height L      height R
        // we need |L - R| <= 1 AND both sides already balanced
        bool balanced = (left[0] == 1 && right[0] == 1) &&
                        (abs(left[1] - right[1]) <= 1);

        // height is "one-arm" downward height:
        // take the taller side and add 1 for the current node
        int height = 1 + max(left[1], right[1]);

        // return both pieces of info upward so parent can use them
        return {balanced ? 1 : 0, height};
    }
};
