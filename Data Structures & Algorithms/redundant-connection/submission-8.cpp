class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> parent(n + 1);
        vector<int> size(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        for (auto &e : edges) {
            if (!unite(parent, size, e[0], e[1])) {
                return {e[0], e[1]}; // this edge made a cycle
            }
        }
        return {};
    }

private:
    int findParent(vector<int> &parent, int node) {
        while (node != parent[node]) {
            parent[node] = parent[parent[node]]; // jump up 2 steps
            node = parent[node];
        }
        return node;
    }

    bool unite(vector<int> &parent, vector<int> &size, int a, int b) {
        int pa = findParent(parent, a);
        int pb = findParent(parent, b);

        if (pa == pb) return false; // already connected -> cycle

        // make sure pa is the bigger component
        if (size[pb] > size[pa]) swap(pa, pb);

        parent[pb] = pa;
        size[pa] += size[pb];
        return true;
    }
};