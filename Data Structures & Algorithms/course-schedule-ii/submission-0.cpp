class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& prerequisites) {
        vector<int> indegree(num,0);
        vector<vector<int>> adj(num);

        for(auto & pre: prerequisites){
            indegree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);

        }

        queue<int> q;
        for(int i = 0;i<num;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int done = 0;
        vector<int> res;

        while(!q.empty()){
            int node = q.front();
            res.push_back(node);
            q.pop();
            done++;
          

            for(int i = 0;i<adj[node].size();i++){
                
                indegree[adj[node][i]]--;
                
                if(indegree[adj[node][i]]==0){
                    q.push(adj[node][i]);
                }
            }
        }
         if (done != num) return {}; // cycle exists
        
        return res;
    }
};
