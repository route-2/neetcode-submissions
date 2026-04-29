class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int node) {
        while (node != parent[node]) {
            parent[node] = parent[parent[node]]; // jump up 2 steps
            node = parent[node];                 // move node up
        }
        return node;
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return false;

        if (size[pb] > size[pa]) swap(pa, pb); // pa is bigger
        parent[pb] = pa;
        size[pa] += size[pb];
        return true;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int components = n; // start: each node alone

        for (auto &e : edges) {
            if (dsu.unite(e[0], e[1])) {
                components--; // only decreases when a real merge happens
            }
        }
        return components;
    }
};