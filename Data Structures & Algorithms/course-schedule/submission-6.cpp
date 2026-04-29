class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // degree[i] = how many prerequisites course i still needs before we can take it
        // (this is basically "incoming edges" count)
        vector<int> degree(numCourses, 0);

        // adj[x] = list of courses that depend on x
        // ex: if prereq is [a, b] (need b before a), then b -> a
        // so from b, we can go to a
        vector<vector<int>> adj(numCourses);

        // build degree + adjacency list
        for (auto& pre : prerequisites) {
            int a = pre[0];  // course we want to take
            int b = pre[1];  // prerequisite course

            // a has one dependencies course 
            degree[b]++;

            // to finish a , we must finish b
            //if we finish b, we have list of courses tha twe can do
            adj[a].push_back(b);
        }

        queue<int> q;

        // start with all courses that have 0 prerequisites
        // these are safe to take right away
        for (int i = 0; i < numCourses; i++) {
            if (degree[i] == 0) {
                q.push(i);
            }
        }

        int finish = 0; // how many courses we were able to take

        // BFS / topological sort (Kahn's algorithm)
        while (!q.empty()) {
            int course = q.front();
            q.pop();

            // we "take" this course now
            finish++;

            // this course might unlock other courses
            for (int nextCourse : adj[course]) {
                degree[nextCourse]--;  // one prereq is now done

                // if nextCourse has no remaining prereqs, we can take it next
                if (degree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        // if we managed to take all courses, no cycle exists
        // if not, some courses were stuck forever -> cycle
        return finish == numCourses;
    }
};