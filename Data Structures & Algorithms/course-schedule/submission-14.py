class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = defaultdict(list)
        
        
        indegree = [0] * numCourses
        for course, prereq in prerequisites :
            graph[prereq].append(course)
            indegree[course] += 1
        
        q = deque()
        for i in range(numCourses):
            if indegree[i] == 0:
                q.append(i)
            
        
        compl = 0

        while q:
            cur = q.popleft()
            compl+=1

            for dep in graph[cur]:
                indegree[dep]-=1

                if indegree[dep] == 0:
                    q.append(dep)
        
        return compl == numCourses
            



      



        
        