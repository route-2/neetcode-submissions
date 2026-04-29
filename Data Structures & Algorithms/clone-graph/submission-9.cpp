/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() : val(0), neighbors(vector<Node*>()) {}
    Node(int _val) : val(_val), neighbors(vector<Node*>()) {}
    Node(int _val, vector<Node*> _neighbors) : val(_val), neighbors(_neighbors) {}
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // empty graph
        if (node == nullptr) return nullptr;

        // mp[original] = cloned copy
        unordered_map<Node*, Node*> mp;

        // dfs returns the cloned node for this original node
        return dfs(node, mp);
    }

private:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& mp) {
        // base case 1: null pointer means "no node"
        if (node == nullptr) return nullptr;

        // base case 2: already cloned, reuse it (stops cycles)
        if (mp.find(node) != mp.end()) return mp[node];
        //reuse clone = reuse the pointer, then attach edges as needed.

        // create the clone for this node (neighbors empty for now)
        Node* copy = new Node(node->val);
        mp[node] = copy;

        // clone all neighbors and connect them
        for (Node* nei : node->neighbors) {
            copy->neighbors.push_back(dfs(nei, mp));
        }

        return copy;
    }
};

/*
time complexity: O(v + e)
space complexity: O(v) for map + O(v) recursion stack worst case
*/