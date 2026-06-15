# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if not head:
            return
        cur = head
        # looks like dummy(0) -> head(1) -> 2 -> 3 -> 4 -> 5
        dummy = ListNode(0,head)
        nodes = [dummy]
        while cur:
            nodes.append(cur)
            cur = cur.next
        
        prev = nodes[-(n+1)]
        prev.next = prev.next.next

        return dummy.next
        

        