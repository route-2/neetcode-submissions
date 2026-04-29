class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF = 1e9;
        vector<int> dist(n+1, INF);
        dist[k] = 0;
        

        for (int i = 0; i < n ; ++i){
            for (const auto& time : times){
                 int u = time[0], v = time[1], w = time[2];
                  
                  if (dist[u] != INT_MAX && dist[u] + w < dist[v]){
                     dist[v] = dist[u] + w;
                  }

            }
        }

    int maxDist = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INF) return -1;  // unreachable
            maxDist = max(maxDist, dist[i]);
        }
        return maxDist;

    }
};
