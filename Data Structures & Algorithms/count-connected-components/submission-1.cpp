class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visit(n, false);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int res = 0;
        for (int node = 0; node < n; ++node) {
            if (!visit[node]) {
                bfs(adj, visit, node);
                res++;
            }
        }
        return res;

    }


    private:
    void bfs(vector<vector<int>>& adj, vector<bool>& visit, int node){
        queue<int> q;
        q.push(node);
        visit[node] = true;
         while (!q.empty()){
            int cur = q.front();
            q.pop();
            for(int nei : adj[cur]){
                 if (visit[nei]) continue;
                visit[nei] = true;
                q.push(nei);
            }
         }
    }
};
