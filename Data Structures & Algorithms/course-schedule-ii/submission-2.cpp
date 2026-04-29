class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& prerequisites) {
        vector<int> indegree(num, 0);
        vector<vector<int>> adj(num);

        // pre = [course, prereq]
        for (auto &pre : prerequisites) {
            //Look at the course number pre[0] (like 3), go to indegree[3], and increase the number stored there by 1.
            indegree[pre[0]]++;              // course needs one more prereq
            adj[pre[1]].push_back(pre[0]);   // prereq -> course
        }

        queue<int> q;
        for (int i = 0; i < num; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int done = 0;
        vector<int> res;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            res.push_back(node);
            done++;

            // process courses unlocked by `node`
            for (int next : adj[node]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        if (done != num) return {}; // cycle exists
        return res;
    }
};