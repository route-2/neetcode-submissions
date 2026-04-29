class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int INF = 1e9;

        int n = points.size();
        vector<bool> inMST(n,false);
        vector<int> minDist(n,INF);

         minDist[0] = 0;
         long long ans = 0;

         for(int i = 0;i<n;i++){
            int u = -1;
            for(int j = 0;j<n;j++){
                if (!inMST[j] && (u == -1 || minDist[j] < minDist[u])) {
                    u = j;
                }
            }
            inMST[u] = true;
            ans += minDist[u];

            for (int v = 0; v < n; v++){
                if (!inMST[v]) {
                    int cost = abs(points[u][0] - points[v][0]) +
                               abs(points[u][1] - points[v][1]);
                    minDist[v] = min(minDist[v], cost);
                }
            }
         }
         return (int)ans;
        


        


        
    }
};
