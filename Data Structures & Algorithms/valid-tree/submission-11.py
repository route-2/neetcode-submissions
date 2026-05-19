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

        while queue: # We process level-by-level - all neighbors of node 0, 
        # then all neighbors of node 1, etc.
            node,parent = queue.popleft()
            for neighbor in graph[node]:
                if neighbor == parent:
                    continue
                if neighbor in visited: # when we encounter a visited node 
                # that's NOT the parent, it's a cycle!
                    return False

                visited.add(neighbor)
                queue.append((neighbor,node))
        
        return len(visited) == n







        