class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses,0);
        queue<int> Q;

        for(auto& prereq : prerequisites){
            int a = prereq[0]; int b = prereq[1];
            adjList[b].push_back(a);
            inDegree[a]++;
        }
        int count = 0;

        for(int i = 0;i<numCourses;i++){
            if(inDegree[i]==0){
                Q.push(i);
            }
        }

        while(!Q.empty()){
            int processed = Q.front();
            Q.pop();
            count++;

            for(auto& dependent : adjList[processed]){
                inDegree[dependent]--;
                if(inDegree[dependent]==0){
                    Q.push(dependent);
                }
            }
        }
        return count == numCourses;
    }
};
