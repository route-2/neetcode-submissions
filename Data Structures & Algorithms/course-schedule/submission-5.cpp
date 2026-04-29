class Solution {
    // this map stores each course and the list of courses
    // we must finish before taking it
    unordered_map<int, vector<int>> preMap;

    // this set stores the courses currently in the DFS path
    // if we see the same course again while exploring,
    // that means we found a cycle
    unordered_set<int> visiting;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // first create empty list for every course
        for (int i = 0; i < numCourses; i++) {
            preMap[i] = {};
        }

        // build the adjacency list
        // if [a, b] is given, it means we must take b before a
        // so we store b as prerequisite of a
        for (const auto& prereq : prerequisites) {
            preMap[prereq[0]].push_back(prereq[1]);
        }

        // now try to run DFS on every course
        // even if some are already solved, DFS will return fast
        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c)) {
                // if any course has a cycle, we cannot finish
                return false;
            }
        }

        // if no cycles found, we can finish all courses
        return true;
    }

    bool dfs(int crs) {

        // if this course is already in the current DFS path,
        // that means we came back to it again -> cycle
        if (visiting.count(crs)) {
            return false;
        }

        // if this course has no prerequisites left,
        // it means it is already resolved
        if (preMap[crs].empty()) {
            return true;
        }

        // mark this course as being explored
        visiting.insert(crs);

        // go deep into all its prerequisites
        for (int pre : preMap[crs]) {

            // if any prerequisite fails (cycle found),
            // immediately return false
            if (!dfs(pre)) {
                return false;
            }
        }

        // we finished exploring all prerequisites of this course
        // so remove it from current DFS path
        visiting.erase(crs);

        // clear its prerequisites to mark it as completed
        // next time DFS sees it, it will return true immediately
        preMap[crs].clear();

        return true;
    }
};