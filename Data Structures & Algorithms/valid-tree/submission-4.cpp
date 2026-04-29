class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        // -------------------- What is a Tree? --------------------
        // A "tree" (for an undirected graph) means:
        //  1) Connected: every node can reach every other node
        //  2) Acyclic:   no loops / cycles
        //
        // Useful shortcut fact:
        // If an undirected graph has:
        //   - exactly (n - 1) edges
        //   - and it is connected
        // then it MUST be a tree (no cycle).
        //
        // Why? (simple intuition)
        // - To connect n nodes with no wasted edges, you need at least n-1 edges.
        // - If you have MORE than n-1 edges, some edge becomes "extra" and forms a cycle.
        // - If you have LESS than n-1 edges, you can't connect all nodes.
        // So "n-1 edges + connected" => connected with minimum edges => no cycles => tree.

        // -------------------- Rule 1: Must have exactly n - 1 edges --------------------
        // If edges != n-1:
        //  - too few edges  => graph cannot be connected
        //  - too many edges => graph must contain a cycle
        if (edges.size() != n - 1) return false;

        // -------------------- Step 1: Build adjacency list --------------------
        // adjacency list: for each node, store which neighbors it is directly connected to.
        // Example edges: [0-1], [0-2]
        // graph[0] = {1, 2}
        // graph[1] = {0}
        // graph[2] = {0}
        unordered_map<int, vector<int>> graph;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u); // undirected => add both directions
        }

        // -------------------- Step 2: BFS to check connectivity --------------------
        // We start from node 0 and see how many nodes are reachable.
        // If we can reach all n nodes => graph is connected.
        queue<int> q;
        unordered_set<int> visited;

        q.push(0);
        visited.insert(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // explore all neighbors of this node
            for (int neighbor : graph[node]) {

                // If neighbor already visited, skip it.
                // NOTE: This line alone is NOT a full "cycle detector" for undirected graphs
                // (because you'll naturally see your parent again).
                // But we DON'T need explicit cycle detection because:
                //   we already forced edges = n - 1,
                //   so if it's connected, it cannot have a cycle.
                if (visited.count(neighbor)) continue;

                visited.insert(neighbor);
                q.push(neighbor);
            }
        }

        // -------------------- Step 3: Final check --------------------
        // If we visited all nodes => connected.
        // Since edges == n-1 AND connected => guaranteed no cycles => valid tree.
        return visited.size() == n;
    }
};