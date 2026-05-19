class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges)!=n-1:
            return False
        
        parent = list(range(n))

        def find(x):
            if parent[x]!=x:
                parent[x] = find(parent[x])
            return parent[x]
        
        for u,v in edges:
            root_u = find(u)
            root_v = find(v)

            if root_u == root_v:
                return False
            
            parent[root_u] = root_v
        
        return True

        