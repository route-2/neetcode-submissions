class Solution {
public:
    vector<vector<int>> graph;
    vector<int> state; // 0 = unvisited, 1 = visiting, 2 = visited

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        state.resize(numCourses, 0);

        for (auto& p : prerequisites) {
            int a = p[0];
            int b = p[1];
            graph[b].push_back(a); // b -> a
        }

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i)) {
                return false;
            }
        }

        return true;
    }

    bool dfs(int node) {
        if (state[node] == 1) {
            return false; // cycle
        }
        if (state[node] == 2) {
            return true; // already processed
        }

        state[node] = 1;

        for (auto nei : graph[node]) {
            if (!dfs(nei)) {
                return false;
            }
        }

        state[node] = 2;
        return true;
    }
};
