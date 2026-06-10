"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None
        
        node_map = {}
        queue = deque([node])

        node_map[node] = Node(node.val)

        while queue:
            curr = queue.popleft()

            for neighbor in curr.neighbors:
                if neighbor not in node_map:
                    node_map[neighbor] = Node(neighbor.val)

                    queue.append(neighbor)
            
                node_map[curr].neighbors.append(node_map[neighbor])

        return node_map[node]











        