class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF = 1e9;
            // dist[i] = shortest time to reach node i from k
    // nodes are 1..n, so we make size n+1 and ignore index 0
    vector<int> dist(n+1, INF);

    // signal starts at node k at time 0
    dist[k] = 0;

    // Bellman-Ford idea:
    // relax all edges many times so shortest paths can "spread"
    // shortest path can have at most (n-1) edges
    // (your loop runs n times, it still works, just one extra round)
    for (int i = 0; i < n; ++i) {

        // go through every directed edge u -> v with time w
        // example time = [1,2,1] means 1 -> 2 takes 1 second
        for (const auto& time : times) {
            int u = time[0], v = time[1], w = time[2];

            // if we can already reach u, try to reach v through u
            // "dist[u] + w" is time to go k -> ... -> u -> v
            // example: if dist[1] = 0 and edge 1->2 has w=1
            // then candidate time to reach 2 is 0+1 = 1
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // after relaxation, dist[i] holds earliest time node i receives signal
    // the whole network is done when the last node receives signal,
    // so we take the maximum dist among all nodes
    int maxDist = 0;
    for (int i = 1; i <= n; ++i) {
        // if any node is still INF, it means unreachable from k
        // example: k=2 but no path to node 1, then dist[1] stays INF
        if (dist[i] == INF) return -1;

        // keep track of the slowest node (last one to get signal)
        //og dist = [inf,0,1,2,3]
        // so we start from 1 index
        //maxDist = max(0,1,2,3) = 3
        maxDist = max(maxDist, dist[i]);
    }

    // this is the minimum time for all nodes to receive signal
    return maxDist;

    }
};
