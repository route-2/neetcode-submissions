"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        intervals.sort(key=lambda i:i.start)
        # 5,10 15,20 0,40
        minHeap = []

        for meeting in intervals:
            start = meeting.start
            end = meeting.end

            if minHeap and minHeap[0] <= start:
                heapq.heappop(minHeap)
            
            heapq.heappush(minHeap, end)

        return len(minHeap)

        


        