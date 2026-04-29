class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // build directed weighted graph: u -> (v, w)
        /*
        Adj list (each entry stores (neighbor, weight)):

adj[1] = [(2,1), (4,4)]

adj[2] = [(3,1)]

adj[3] = [(4,1)]

adj[4] = []
        */
        vector<vector<pair<int,int>>> adj(n + 1);
        for (auto &e : times) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
        }

        /*
dist = [INF, 0, INF, INF, INF] (1-indexed, dist[1]=0)
Min-heap pq = [(0,1)]
        */

        const int INF = 1e9;
        vector<int> dist(n + 1, INF);
        dist[k] = 0;

        // min-heap of (distance, node)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            // stale entry (we already found a better path)
            if (d > dist[node]) continue;

            for (auto [nei, w] : adj[node]) {
                if (dist[node] + w < dist[nei]) {
                    dist[nei] = dist[node] + w;
                    pq.push({dist[nei], nei});
                }
            }
        }

        // answer is the maximum shortest distance
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INF) return -1;  // unreachable node
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};