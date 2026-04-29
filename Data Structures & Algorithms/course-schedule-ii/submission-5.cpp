class Solution {
public:
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> result;
        for(auto & pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        queue<int> q;

        for(int i = 0;i<numCourses;i++){
            if(indegree[i]==0){
                 q.push(i);
            }
        }

        while(!q.empty()){
            int crs = q.front();
            q.pop();

            for(int nei : adj[crs]){
                indegree[nei]--;
                if(indegree[nei]==0){
                    q.push(nei);
                }
            }
            result.push_back(crs);

    }
        if (result.size() != numCourses) {
            return {};
        }

        return result;
    }
};
