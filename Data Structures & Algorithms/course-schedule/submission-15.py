class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = defaultdict(list) # adjacency list: prereq -> [dependent courses]

        
        
        indegree = [0] * numCourses
        # [0,0]
        # prerequisites[i] = [a, b] means b -> a (must take b before a)
        for course, prereq in prerequisites :
            graph[prereq].append(course)
            indegree[course] += 1 # all a courses
        
        q = deque()
        for crs in range(numCourses):
            if indegree[crs] == 0:
                q.append(crs) # Storing course NUMBER (0, 1, 2, etc.)
            
        
        compl = 0

        while q:
            cur = q.popleft()
            compl+=1 # keep count of completed courses

            for dep in graph[cur]: # for each course that depends on current course
                indegree[dep]-=1

                if indegree[dep] == 0:
                    q.append(dep)
        
        return compl == numCourses
            



      



        
        