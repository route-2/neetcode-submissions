class Solution {
public:
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
int n = edges.size();
vector<vector<int>> adj(n+1); // adj[x] = all nodes directly connected to x (the "roads" from x)
    // we add edges one by one; after adding an edge (u,v), we check if it created a loop
    // example edges: (1,2),(1,3),(3,4),(2,4)
    // when we reach (2,4), there is already a path 2->1->3->4, so adding 2->4 makes a cycle
    for (const auto& edge : edges){
        int u = edge[0];
        int v = edge[1];

        // permanently add this edge into the SAME adj list (we are NOT rebuilding adj each time)
        adj[u].push_back(v);
        adj[v].push_back(u);

        // fresh footprints for THIS DFS run only
        // visit[x] = did we step on node x during this single walk?
        vector<bool> visit(n+1,false);

        // start walking from u; if during this walk we ever step on a node twice => loop exists
        // in the (2,4) step: walk 2->1->3->4->2, and that last "2" is already visited => cycle
        // start DFS from u
        // we pass parent = -1 because this is the starting node
        // -1 just means "no parent" (nodes are 1..n, so -1 is safe dummy value)
        // parent is needed so we don't immediately go back on the same edge
        //ex: we created 1-> 2, 2<-1 so we dont want going back 
        // (since graph is undirected and edges are stored both ways)
        if(dfs(u,-1,adj,visit)){
            return {u,v}; // this edge is the one that just closed the loop (redundant)
        }
    }
    return {}; // should not happen for this problem's constraints
}

bool dfs(int node,int parent,vector<vector<int>> &adj,vector<bool>&visit){
    // if we reached a node we already visited in THIS SAME DFS run,
    // that means there are 2 different ways to get here => a cycle
    if (visit[node]) return true;

    // mark footprint: "we've been to this node in this walk"
    visit[node] = true;

    // try all roads leaving this node
    for(int nei : adj[node]){
        // skip the road that immediately goes back to where we came from
        // (undirected graph has both directions, so without this we'd bounce back and falsely detect a cycle)
        if(nei==parent) continue;

        // keep walking; if any deeper call finds a cycle, bubble true up
        if(dfs(nei,node,adj,visit)) return true;
    }

    // explored all reachable paths from here without stepping on an already-visited node
    return false;
}
};