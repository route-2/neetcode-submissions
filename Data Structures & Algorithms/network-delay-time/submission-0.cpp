class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // build directed weighted graph: u -> (v, w)
        vector<vector<pair<int,int>>> adj(n + 1);
        for (auto &e : times) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
        }

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