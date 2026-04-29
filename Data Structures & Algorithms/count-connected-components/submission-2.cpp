class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // adj[u] = list of neighbors connected to u (undirected graph)
        vector<vector<int>> adj(n);
        vector<bool> visit(n, false);

        // Build adjacency list from edges
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int res = 0; // number of connected components

        // Try to start a BFS from every node
        for (int node = 0; node < n; ++node) {

            // If node not visited yet, it belongs to a NEW separate component
            // (a separate "group" not connected to previously explored nodes)
            if (!visit[node]) {
                bfs(adj, visit, node); // mark all nodes in this component
                res++;                 // count this component once
            }
        }

        return res;
    }

private:
    void bfs(vector<vector<int>>& adj, vector<bool>& visit, int node) {
        queue<int> q;
        q.push(node);
        visit[node] = true; // we discovered this node

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            // Explore all neighbors of cur
            for (int nei : adj[cur]) {
                if (visit[nei]) continue; // already part of this component
                visit[nei] = true;        // mark as reached in this component
                q.push(nei);
            }
        }
    }
};