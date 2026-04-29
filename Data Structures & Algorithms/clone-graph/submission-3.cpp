/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        mp[node] = new Node(node->val);
        q.push(node);

        while(!q.empty()){
            Node* cur = q.front();
            q.pop();

            for(Node * nei: cur->neighbors){
                if(mp.find(nei)==mp.end()){
                    mp[nei] = new Node(nei->val);
                    q.push(nei);
                }
                mp[cur]->neighbors.push_back(mp[nei]);
            }
           
            
           
        }
        return mp[node];



        
    }
};
