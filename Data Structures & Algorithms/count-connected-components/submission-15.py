class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        graph = defaultdict(list)
        visit = [False] * n

        for u,v in edges:
            graph[u].append(v)
            graph[v].append(u)
        

        def bfs(node):
            q = deque([node])
            visit[node]=True
            while q:
                cur = q.popleft()
                for nei in graph[cur]:
                    if not visit[nei]:
                        visit[nei] = True
                        q.append(nei)
        
        res = 0
        for node in range(n):
            if not visit[node]:
                bfs(node)
                res+=1
        
        return res



        