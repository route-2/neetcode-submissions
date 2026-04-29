class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       const int INF = 1e9;
        unordered_map<int, vector<pair<int,int>>> adj;
        // {u -> {v,w}}
        vector<int> dist(n+1, INF);
        dist[k] = 0;
        //stores {distance, node} in min-heap
priority_queue<pair<int,int>, vector<pair<int,int>>, 
      greater<pair<int,int>>> pq;
      //start building shortest dist to nodes from k
      pq.push({0,k});

      for(int i = 0;i<times.size();i++){
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];
        adj[u].push_back({v,w});
      }

       while (!pq.empty()){
         auto [curDist, node] = pq.top();
            pq.pop();
               // Skip if we already found a better way
              if (curDist > dist[node]) continue;

               for (auto &[neighbor, weight] : adj[node]) {
                  int newDist = curDist + weight;
                  if(newDist<dist[neighbor]){
                    dist[neighbor] = newDist;
                    pq.push({newDist, neighbor});
                  }
               }



       }
       int maxDist = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INF) return -1;
            maxDist = max(maxDist, dist[i]);
        }

        return maxDist;



    }
};
