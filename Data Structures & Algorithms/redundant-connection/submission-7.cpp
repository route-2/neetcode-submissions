class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
         int n = edges.size();
         vector<int> degree(n+1,0);
          vector<vector<int>> adj(n + 1);
          for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

            degree[u]++;
            degree[v]++;
          }


queue<int> q;
for(int i = 1;i<=n;i++){
    if(degree[i]==1) q.push(i);
}

while(!q.empty()){
    int node = q.front();
    q.pop();
    degree[node]=0;

    for(int nei: adj[node]){
        degree[nei]--;
        if(degree[nei]==1) q.push(nei);
    }
}

for (int i = n- 1; i >= 0; i--){
    int u = edges[i][0], v = edges[i][1];
    //nodes left with degree > 0 are exactly the cycle nodes
    if(degree[u]>0 && degree[v]>0){
        return {u,v};
    }
}



    }
};

/*
time complexity: 
O(V+E)
space complexity: 
O(V+E)
*/
