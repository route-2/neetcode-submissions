class Solution {
    // preMap[x] = list of courses you can take AFTER you finish x
    // example: [a, b] means b -> a, so we store a inside preMap[b]
    unordered_map<int, vector<int>> preMap;

    // this is the "current DFS path" (recursion stack)
    // if we see the same course again while it’s still in here -> cycle
    unordered_set<int> visited;

    // we store the order here while finishing DFS (postorder)
    vector<int> res;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        // make sure every course exists in the map (even if it has no outgoing edges)
        for (int i = 0; i < numCourses; i++) {
            preMap[i] = {};
        }

        // build graph: b -> a
        for (const auto& prereq : prerequisites) {
            preMap[prereq[1]].push_back(prereq[0]);
        }

        // try DFS from every course (graph can be disconnected)
        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c)) {
                // cycle found anywhere -> impossible to finish all
                return {};
            }
        }

        // we added courses in "finish time" order, so reverse to get correct topo order
        reverse(res.begin(), res.end());
        return res;
    }

    bool dfs(int crs) {

        // if this course is already in the current DFS path -> cycle
        if (visited.count(crs)) return false;

        // small trick without adding extra arrays:
        // after a course is fully done, we set preMap[crs] = {-1}
        // so if we see {-1}, it means "already processed, skip"
        if (preMap[crs].size() == 1 && preMap[crs][0] == -1) return true;

        // mark as in current path
        visited.insert(crs);

        // go through all courses that depend on this course
        for (int nxt : preMap[crs]) {
            if (!dfs(nxt)) return false;
        }

        // done exploring this node, remove from current path
        visited.erase(crs);

        // now we are fully done with this course (all kids done)
        // add it to result and return to the previous call in the stack
        res.push_back(crs);

        // mark as processed so we don't add it again later
        preMap[crs].clear();
        preMap[crs].push_back(-1);

        return true;
    }
};