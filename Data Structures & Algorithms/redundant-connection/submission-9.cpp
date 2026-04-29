class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(); // n edges, nodes are 1..n

        // parent[x] = who is the boss/root of x right now
        vector<int> parent(n + 1);

        // size[root] = how many nodes are in this root's group
        vector<int> size(n + 1, 1);

        // at start everyone is alone, so everyone is their own parent
        // like: 1 in its own group, 2 in its own group, etc
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        // try to add edges one by one
        for (auto &e : edges) {
            int a = e[0], b = e[1];

            // if we FAIL to union, it means a and b were already connected
            // so this edge is extra and makes a cycle -> redundant
            if (!unite(parent, size, a, b)) {
                return {a, b};
            }
        }

        return {}; // won't happen for this problem, but just in case
    }

private:
    int findParent(vector<int> &parent, int node) {
        // we keep walking up until we reach the root
        // root means: parent[root] == root
        while (node != parent[node]) {
            // path compression (jumping)
            // make node point closer to root so next time find is faster
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node; // this is the root/boss
    }

    bool unite(vector<int> &parent, vector<int> &size, int a, int b) {
        // find the bosses of a and b
        int pa = findParent(parent, a);
        int pb = findParent(parent, b);

        // if both have same boss, they already in same group
        // meaning there is already a path between them
        // adding this edge creates a cycle -> redundant edge
        if (pa == pb) return false;

        // we want bigger group to stay boss
        // so if pb group is bigger, swap them
        // after this line: pa is always the bigger group's root
        if (size[pb] > size[pa]) swap(pa, pb);

        // attach smaller group (pb) under bigger group (pa)
        // means: pb's boss becomes pa
        parent[pb] = pa;

        // update size of the boss (pa) because pb's whole group joined it
        size[pa] += size[pb];

        return true; // union worked, no cycle
    }
};
//for edges: after union 1->2,
//                       1->3->4
//   so parent of  2,3,4 is 1
//adding 2,4 check pa and pb it's 1 => redundant comp