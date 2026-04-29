class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+1);

        for( const auto& edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            vector<bool> visit(n+1,false);

            if(dfs(u,-1,adj,visit)){
                return{u,v};
            }
        }
        return {};
    }

    private:
    bool dfs(int node, int parent, vector<vector<int>> &adj,vector<bool>&visit){
       
        visit[node] = true;
        for(int nei : adj[node]){
            if(!visit[nei]){
                if (dfs(nei,node,adj,visit) )return true;
            }
            //visited nei and nei is also not parent
            //then cycle exists
           else if(nei!=parent) {
            return true;
           }
            
        }
        return false;
    }
};
