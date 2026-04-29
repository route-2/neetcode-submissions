class Solution {

    /*
    in prim’s algo, each “round” does 3 things:

pick the next node u not in mst with smallest minDist

mark u as in mst and add its cost to answer

relax/update minDist for every other node v using u

you need to repeat that whole process until all nodes are picked. that’s why you need the loop that runs n times.
    */
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int INF = 1e9;

        int n = points.size();
        /*
        initially..
        inMST = [false, false, false, false, false]
        minDist = [0, INF, INF, INF, INF]
        ans = 0
        */
        vector<bool> inMST(n,false);
        vector<int> minDist(n,INF);



         minDist[0] = 0;
         long long ans = 0;
         //find the first starting node 
         for(int step = 0;step<n;step++){
            //we reset this for every round
            int u = -1;
            
            for(int j = 0;j<n;j++){
                //we basically find our next node to find cheapest from
                if (!inMST[j] && (u == -1 || minDist[j] < minDist[u])) {
                    u = j;
                }
            }
            
            //once we do we set this as true, update the cost so far till mindist[u]
            inMST[u] = true;
            ans += minDist[u];

            for (int v = 0; v < n; v++){
                //update from u -> all v (0->4) for points = [[0,0],[2,2],[3,3],[2,4],[4,2]]
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
