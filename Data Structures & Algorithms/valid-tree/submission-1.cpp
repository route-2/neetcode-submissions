class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
 if (edges.size() != n - 1) return false;  // Condition 1: Must have exactly n-1 edges

        // Step 1: Build adjacency list
        unordered_map<int, vector<int>> graph;
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Step 2: BFS to check connectivity and cycle detection
        queue<int> q;
        unordered_set<int> visited;

        q.push(0);
        visited.insert(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : graph[node]) {
                if (visited.count(neighbor)) continue;  // Ignore already visited nodes
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }

        // Step 3: Check if all nodes were visited (Graph must be connected)
        return visited.size() == n;
    }
};
