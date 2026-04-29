class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n,INT_MAX);
        dist[k-1] = 0;
        

        for (int i = 0; i < n - 1; ++i){
            for (const auto& time : times){
                 int u = time[0] - 1, v = time[1] - 1, w = time[2];
                  
                  if (dist[u] != INT_MAX && dist[u] + w < dist[v]){
                     dist[v] = dist[u] + w;
                  }

            }
        }

     int maxDist = *max_element(dist.begin(), dist.end());
      return maxDist == INT_MAX ? -1 : maxDist;  

    }
};
