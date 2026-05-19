class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:

        parent = list(range(n))

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        
        count = 0

        for u,v in edges:
            root_u = find(u)
            root_v = find(v)

            if root_u != root_v:
                parent[root_u] = root_v
                count+=1
            
        
        return n- count

        


        