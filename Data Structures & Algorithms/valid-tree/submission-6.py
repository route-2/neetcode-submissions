class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) != n-1:
            return False
        

        graph = defaultdict(list)
        for u,v in edges:
            graph[u].append(v)
            graph[v].append(u)
        
        visited = {0}
        queue = deque([(0,-1)])

        while queue:
            node,parent = queue.popleft()
            for neighbor in graph[node]:
                if neighbor == parent:
                    continue
                if neighbor in visited:
                    return False

                visited.add(neighbor)
                queue.append((neighbor,node))
        
        return len(visited) == n







        