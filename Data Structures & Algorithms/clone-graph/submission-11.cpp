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

        // mp[original] = cloned copy of original
        unordered_map<Node*, Node*> mp;

        // bfs queue over original nodes
        queue<Node*> q;

        // create the clone of the starting node (same value, empty neighbors for now)
        mp[node] = new Node(node->val);

        // start bfs from the input node
        q.push(node);

        while (!q.empty()) {
            // take one original node to process
            Node* cur = q.front();
            q.pop();

            // loop over all neighbors of this original node
            // (this runs as many times as cur->neighbors.size())
            for (Node* nei : cur->neighbors) {

                // if we have not cloned this neighbor yet, clone it once
                if (mp.find(nei) == mp.end()) {
                    mp[nei] = new Node(nei->val); // clone neighbor node value
                    q.push(nei);                  // later we will process its neighbors too
                }

                // connect the cloned current node to the cloned neighbor
                mp[cur]->neighbors.push_back(mp[nei]);
            }
        }

        // return the cloned version of the start node
        return mp[node];
    }
};

/*
time complexity: O(v + e)
- v nodes, e edges, each processed once during bfs

space complexity: O(v)
- hashmap + queue in worst case
*/