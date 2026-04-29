class Solution {
public:
    vector<vector<int>> graph;
    vector<int>state;
    vector<int> result;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       graph.resize(numCourses);
        state.resize(numCourses, 0);

        for (auto &p : prerequisites) {
            graph[p[1]].push_back(p[0]); // b -> a
        }

        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c)) {
                return {};
            }
        }

        reverse(result.begin(), result.end());
        return result;

    }

    bool dfs(int crs){
       if (state[crs] == 1) return false;
        if (state[crs] == 2) return true;

        state[crs] = 1;

        for (int nei : graph[crs]) {
            if (!dfs(nei)) return false;
        }

        state[crs] = 2;
        result.push_back(crs);

        return true;
    }
};
